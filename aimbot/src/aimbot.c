/**
 * @file aimbot.c
 * @brief Provides implementation of the aimbot component.
 */
#include "aimbot.h"
#include <gta_sa_api/gta_sa.h>
#include <console/console.h>
#include <ehook.h>

static bool is_inited_ = false;
static void* orig_CCam__Process_AimWeapon;

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
    console_log("handles: ");
    for (uint32_t handle = get_next_streamed_ped_handle_(); handle != 0;
         handle = get_next_streamed_ped_handle_())
    {
        console_log("%x ", handle);
    }
    console_log("\n");

    return gta_sa()->f_CCam__Process_AimWeapon(ccam, EDX, plyrPosn, a5, a6, a7);
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
