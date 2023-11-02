/**
 * @file aimbot.c
 * @brief Provides implementation of the aimbot component.
 */
#include "aimbot.h"
#include <math.h>
#include <gta_sa_api/gta_sa.h>
#include <console/console.h>
#include <ehook.h>

/** @brief Aimbot configuration */
typedef struct AimCfg
{
    int max_radius;
} AimCfg;

/** @brief Info about aim target */
typedef struct AimTarget
{
    CPed* ped;
    CVector bone_pos;
    CVector screen_pos;
    int screen_dist;
} AimTarget;

static bool is_inited_ = false;
static void* orig_CCam__Process_AimWeapon;
static AimCfg cfg_ = {.max_radius = 500};
static AimTarget target_;

/**
 * @brief Hook of CCam::Process_AimWeapon game funciton. This function is called
 * when player is aiming weapon (not melee, not sniper).
 *
 * @param[in] ccam CCam instance
 * @param[in] EDX EDX register (unused)
 * @param[in] plyrPosn Player position
 * @param[in] a5 Unknown
 * @param[in] a6 Unknown
 * @param[in] a7 Unknown
 *
 * @return Unknown
 */
static char CC_THISCALL h_CCam__Process_AimWeapon_(CCam* ccam, void* EDX,
                                                   CVector* plyrPosn, float a5,
                                                   float a6, float a7);

/**
 * @brief Selects aim target satisfying all conditions. If aim target found,
 *        updates global \p target_ struct and returns true, otherwise returns
 *        false.
 *
 * @return true if aim target found, false otherwise.
 */
static bool select_aim_target_(void);

/**
 * @brief Returns streamed ped handle. Each call returns next streamed ped
 * handle. If there is no more streamed peds, returns 0 and resets ped pool
 * iterator for further calls.
 *
 * @return Next streamed ped handle or 0 if there is no more streamed peds.
 */
static uint32_t get_next_streamed_ped_handle_(void);

static char CC_THISCALL h_CCam__Process_AimWeapon_(CCam* ccam, void* EDX,
                                                   CVector* plyrPosn, float a5,
                                                   float a6, float a7)
{
    if (select_aim_target_())
    {
        /* Draw dot */
        gta_sa()->f_CFont__PrintString(target_.screen_pos.x,
                                       target_.screen_pos.y, "~R~.");
    }

    return gta_sa()->f_CCam__Process_AimWeapon(ccam, EDX, plyrPosn, a5, a6, a7);
}

static bool select_aim_target_(void)
{
    // TODO: Prioritize peds by 3d distance
    // TODO: Prioritize peds rotated to player

    /* Calculate crosshair screen position */
    CVector2D crosshair_screen_pos = {.x = *gta_sa()->crosshair_mult_x_ptr *
                                           *gta_sa()->screen_resolution_x_ptr,
                                      .y = *gta_sa()->crosshair_mult_y_ptr *
                                           *gta_sa()->screen_resolution_y_ptr};
    /* Get local player's bone (neck) position */
    CVector player_neck;
    gta_sa()->f_CPed__GetBonePosition(*gta_sa()->player_ptr_ptr, 0,
                                      &player_neck, 4, 1);

    /* Reset aim target */
    target_.ped = NULL;
    target_.screen_dist = cfg_.max_radius + 1;

    for (uint32_t handle = get_next_streamed_ped_handle_(); handle != 0;
         handle = get_next_streamed_ped_handle_())
    {
        CPed* ped = gta_sa()->f_CPools__GetPed(handle);
        /* Skip if unable to get ped struct */
        if (!ped)
        {
            continue;
        }
        /* Skip local player */
        if (ped == *gta_sa()->player_ptr_ptr)
        {
            continue;
        }
        /* Skip dead peds */
        if (ped->m_nPedState == PED_DEAD || ped->m_nPedState == PED_DIE)
        {
            continue;
        }
        /* Skip peds who not on screen */
        if (!gta_sa()->f_CEntity__GetIsOnScreen((CEntity*)ped, 0))
        {
            continue;
        }
        // TODO: Skip model ids from whitelist
        //       ped->physical.entity.m_nModelIndex

        /* Check obstacles between player and target */
        if (!gta_sa()->f_CWorld__GetIsLineOfSightClear(
                &player_neck,
                &ped->physical.entity.placeable.m_pMatrix->mat.pos, 1, 0, 0, 1,
                0, 1, 0))
        {
            continue;
        }

        /* Check is ped enough close to crosshair */
        /* Get ped's bone (head) position */
        CVector ped_pos;
        CVector ped_screen_pos;
        gta_sa()->f_CPed__GetBonePosition(ped, 0, &ped_pos, 8, 1);
        /* Calculate ped's bone position on screen */
        float unk;
        if (!gta_sa()->f_CalcScreenCoors(&ped_pos, &ped_screen_pos, &unk, &unk))
        {
            continue;
        }
        /* Calc distance between ped's 2d coords and crosshair */
        int screen_dist =
            sqrt(powf(ped_screen_pos.x - crosshair_screen_pos.x, 2) +
                 powf(ped_screen_pos.y - crosshair_screen_pos.y, 2));
        /* Compare distance with max aim radius */
        if (screen_dist > cfg_.max_radius)
        {
            continue;
        }
        /* Check is ped's bone position closer to crosshair than previous */
        if (screen_dist >= target_.screen_dist)
        {
            continue;
        };
        /* Update current aim target struct */
        target_.ped = ped;
        target_.bone_pos = ped_pos;
        target_.screen_pos = ped_screen_pos;
        target_.screen_dist = screen_dist;
    }
    /* Return true if aim target found */
    return target_.ped != NULL;
}

static uint32_t get_next_streamed_ped_handle_(void)
{
    const void* ped_pool = *(gta_sa()->ped_pool_ptr);
    uint32_t ped_pool_bytemap = *(uint32_t*)((uint32_t)ped_pool + 4);

    static uint32_t bytemap_ptr;
    static uint32_t handle_base;
    static bool is_initialized = false;

    if (!is_initialized)
    {
        bytemap_ptr = ped_pool_bytemap;
        handle_base = 0;
        is_initialized = true;
    }

    while (handle_base < 0x8b00)
    {
        uint32_t handle = *(uint32_t*)bytemap_ptr;
        handle &= 0x000000FF;
        ++bytemap_ptr;
        if (handle < 0x80)
        {
            handle += handle_base;
            handle_base += 0x100;
            return handle;
        }
        handle_base += 0x100;
    }

    is_initialized = false;
    return 0;
}

bool aimbot_init(void)
{
    if (!console_init())
    {
        return false;
    }
    if (!gta_sa_init())
    {
        return false;
    }
    /* Hook */
    orig_CCam__Process_AimWeapon =
        eh_overwrite_function_call(gta_sa()->c_CCam__Process_AimWeapon,
                                   (void*)h_CCam__Process_AimWeapon_, 1);
    if (!orig_CCam__Process_AimWeapon)
    {
        gta_sa_destroy();
        console_destroy();
        return false;
    }
    is_inited_ = true;
    console_log("aimbot initialized");
    return true;
}

bool aimbot_destroy(void)
{
    if (!is_inited_)
    {
        return true;
    }
    /* Unhook */
    eh_overwrite_function_call(gta_sa()->c_CCam__Process_AimWeapon,
                               orig_CCam__Process_AimWeapon, 0);
    gta_sa_destroy();
    console_destroy();
    return true;
}
