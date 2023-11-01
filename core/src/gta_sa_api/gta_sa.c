/**
 * @file gta_sa.c
 */
#include <stdint.h>
#include "gta_sa.h"

typedef enum GtaSaVersion
{
    GTA_SA_VERSION_1_0_US = 0,
    GTA_SA_VERSION_STEAM_06112023,
    GTA_SA_VERSION_COUNT,
    GTA_SA_VERSION_UNKNOWN = GTA_SA_VERSION_COUNT
} GtaSaVersion;

static const GtaSa* gta_sa_ptr_ = 0;
static GtaSa gta_sa_[GTA_SA_VERSION_COUNT] = {
    /* 1.0 US */
    {
        /* Functions */
        .f_Idle = (Idle_t)0x53E920,
        .f_CCam__Process_AimWeapon = (CCam__Process_AimWeapon_t)0x521500,
        .f_CCamera__Process = (CCamera__Process)0x52B730,
        .f_CHud__SetHelpMessage = (CHud__SetHelpMessage)0x588BE0,
        .f_CalcScreenCoors = (CalcScreenCoors_t)0x71DA00,
        .f_CMessages__AddMessageJumpQ = (CMessages__AddMessageJumpQ_t)0x69F1E0,
        .f_CWorld__GetIsLineOfSightClear =
            (CWorld__GetIsLineOfSightClear_t)0x56A490,
        .f_CPools__GetPed = (CPools__GetPed)0x54FF90,
        .f_CEntity__GetIsOnScreen = (CEntity__GetIsOnScreen_t)0x534540,
        .f_CPed__Render = (CPed__Render_t)0x5E7680,
        .f_CPed__GetBonePosition = (CPed__GetBonePosition_t)0x5E4280,
        .f_CVector__Normalise = (CVector__Normalise_t)0x59C910,
        .f_Render2dStuff = (Render2dStuff_t)0x53E230,
        .f_c_D3DXMatrixInverse = (c_D3DXMatrixInverse_t)0x76795B,
        .f_timeGetTime = (timeGetTime_t)0x8174F6,
        .f_CFont__PrintString = (CFont__PrintString_t)0x71A700,
        .f_CFont__PrintChar = (CFont__PrintChar_t)0x718A10,
        .f_CFont__SetScale = (CFont__SetScale_t)0x719380,
        .f_CFont__SetSlantRefPoint = (CFont__SetSlantRefPoint_t)0x719400,
        .f_CFont__SetSlant = (CFont__SetSlant_t)0x719420,
        .f_CFont__SetColor = (CFont__SetColor_t)0x719430,
        .f_CFont__SetFontStyle = (CFont__SetFontStyle_t)0x719490,
        .f_CFont__SetAlphaFade = (CFont__SetAlphaFade_t)0x719500,
        .f_CFont__SetDropShadowPosition =
            (CFont__SetDropShadowPosition_t)0x719570,
        .f_CFont__SetOutlinePosition = (CFont__SetOutlinePosition_t)0x719590,
        .f_CFont__SetBackground = (CFont__SetBackground_t)0x7195C0,
        .f_CFont__SetBackgroundColor = (CFont__SetBackgroundColor_t)0x7195E0,
        .f_CFont__SetAlignment = (CFont__SetAlignment_t)0x719610,
        .f_CFont__SetDropColor = (CFont__SetDropColor_t)0x719510,
        .f_CFont__SetProp = (CFont__SetProp_t)0x7195B0,
        .f_CFont__GetStringWidth = (CFont__GetStringWidth_t)0x71A0E0,
        .f_CPad__GetPad = (CPad__GetPad_t)0x53FB70,
        .f_CPad__ExitVehicleJustDown = (CPad__ExitVehicleJustDown_t)0x540120,
        .f_CPad__CycleWeaponLeftJustDown =
            (CPad__CycleWeaponLeftJustDown_t)0x540610,
        .f_CPad__CycleWeaponRightJustDown =
            (CPad__CycleWeaponRightJustDown_t)0x540640,
        .f_CPad__DuckJustDown = (CPad__DuckJustDown_t)0x540720,
        .f_CPad__JumpJustDown = (CPad__JumpJustDown_t)0x540770,
        .f_CPad__SprintJustDown = (CPad__SprintJustDown_t)0x5407F0,
        .f_CPad__ConversationYesJustDown =
            (CPad__ConversationYesJustDown_t)0x5411D0,
        .f_CPad__ConversationNoJustDown =
            (CPad__ConversationNoJustDown_t)0x541200,
        .f_CPad__isTabJustPressed = (CPad__isTabJustPressed_t)0x744D90,
        .f_CPad__isStandardKeyJustPressed =
            (CPad__isStandardKeyJustPressed_t)0x4D59B0,
        .f_CSprite2d__DrawRect = (CSprite2d__DrawRect_t)0x727B60,
        .f_CSprite2d__DrawCircleAtNearClip =
            (CSprite2d__DrawCircleAtNearClip_t)0x727D60,
        .f_CSprite2d__Draw2DPolygon = (CSprite2d__Draw2DPolygon_t)0x7285B0,
        .f_CWeapon__DoBulletImpact = (CWeapon__DoBulletImpact_t)0x73B550,
        .f_CWeapon__GenerateDamageEvent =
            (CWeapon__GenerateDamageEvent_t)0x73A530,

        /* Function calls */
        .c_CCam__Process_AimWeapon = (void*)0x527A96,
        .c_Render2dStuff = (void*)0x53EB13,

        /* Data */
        .pads = (CPad*)0xB73458,
        .CPad__NewKeyState = (CKeyboardState*)0xB73190,
        .ped_pool_ptr = (void**)0xB74490,
        .player_ptr_ptr = (CPed**)0xB6F5F0,
        .fov_ptr = (float*)0x8D5038,
        .screen_resolution_x_ptr = (uint32_t*)0xC17044,
        .screen_resolution_y_ptr = (uint32_t*)0xC17048,
        .camera_ptr = (CCamera*)0xB6F028,
        .crosshair_mult_x_ptr = (float*)0xB6EC14,
        .crosshair_mult_y_ptr = (float*)0xB6EC10,
        .cheat_string = (char*)0x969110,
    },
    /* Steam */
    {
        /* Functions */
        .f_Idle = (Idle_t)0x54ECC0,
        .f_Render2dStuff = (Render2dStuff_t)0x54E5D0,

        /* Function calls */
        .c_Render2dStuff = (void*)0x54EEC0,
    }};

static bool is_1_0_US_(void);
static GtaSaVersion determine_version_(void);

static bool is_1_0_US_(void)
{
    if ((*(uint8_t*)0x82456F == 0xC3) && (*(uint32_t*)0x824570 == 0x7868606A))
    {
        return true;
    }
    return false;
}
static GtaSaVersion determine_version_(void)
{
    if (is_1_0_US_())
    {
        return GTA_SA_VERSION_1_0_US;
    }
    return GTA_SA_VERSION_UNKNOWN;
}

bool gta_sa_init(void)
{
    GtaSaVersion version = determine_version_();
    if (version == GTA_SA_VERSION_UNKNOWN)
    {
        return false;
    }
    gta_sa_ptr_ = &gta_sa_[version];
    return true;
}

bool gta_sa_destroy(void)
{
    return true;
}

const GtaSa* gta_sa(void)
{
    return gta_sa_ptr_;
}
