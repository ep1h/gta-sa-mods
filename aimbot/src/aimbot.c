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

static char CC_THISCALL h_CCam__Process_AimWeapon_(CCam* ccam, void* EDX,
                                                   CVector* plyrPosn, float a5,
                                                   float a6, float a7)
{
    console_log("h_CCam__Process_AimWeapon\n");
    return gta_sa()->f_CCam__Process_AimWeapon(ccam, EDX, plyrPosn, a5, a6, a7);
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
