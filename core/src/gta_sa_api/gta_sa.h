/**
 * @file gta_sa.h
 * @brief API for interacting with GTA San Andreas.
 */
#ifndef GTA_SA_H_
#define GTA_SA_H_

#include <stdbool.h>
#include "types/functions.h"

typedef struct GtaSa
{
    /* Functions */
    Idle_t f_Idle;
    CCam__Process_AimWeapon_t f_CCam__Process_AimWeapon;
    CCamera__Process f_CCamera__Process;
    CHud__SetHelpMessage f_CHud__SetHelpMessage;
    CalcScreenCoors_t f_CalcScreenCoors;
    CMessages__AddMessageJumpQ_t f_CMessages__AddMessageJumpQ;
    CWorld__GetIsLineOfSightClear_t f_CWorld__GetIsLineOfSightClear;
    CPools__GetPed f_CPools__GetPed;
    CEntity__GetIsOnScreen_t f_CEntity__GetIsOnScreen;
    CPed__Render_t f_CPed__Render;
    CPed__GetBonePosition_t f_CPed__GetBonePosition;
    CVector__Normalise_t f_CVector__Normalise;
    Render2dStuff_t f_Render2dStuff;
    c_D3DXMatrixInverse_t f_c_D3DXMatrixInverse;
    timeGetTime_t f_timeGetTime;
    CFont__PrintString_t f_CFont__PrintString;
    CFont__PrintChar_t f_CFont__PrintChar;
    CFont__SetScale_t f_CFont__SetScale;
    CFont__SetSlantRefPoint_t f_CFont__SetSlantRefPoint;
    CFont__SetSlant_t f_CFont__SetSlant;
    CFont__SetColor_t f_CFont__SetColor;
    CFont__SetFontStyle_t f_CFont__SetFontStyle;
    CFont__SetAlphaFade_t f_CFont__SetAlphaFade;
    CFont__SetDropShadowPosition_t f_CFont__SetDropShadowPosition;
    CFont__SetOutlinePosition_t f_CFont__SetOutlinePosition;
    CFont__SetBackground_t f_CFont__SetBackground;
    CFont__SetBackgroundColor_t f_CFont__SetBackgroundColor;
    CFont__SetAlignment_t f_CFont__SetAlignment;
    CFont__SetDropColor_t f_CFont__SetDropColor;
    CFont__SetProp_t f_CFont__SetProp;
    CFont__GetStringWidth_t f_CFont__GetStringWidth;
    CPad__GetPad_t f_CPad__GetPad;
    CPad__ExitVehicleJustDown_t f_CPad__ExitVehicleJustDown;
    CPad__CycleWeaponLeftJustDown_t f_CPad__CycleWeaponLeftJustDown;
    CPad__CycleWeaponRightJustDown_t f_CPad__CycleWeaponRightJustDown;
    CPad__DuckJustDown_t f_CPad__DuckJustDown;
    CPad__JumpJustDown_t f_CPad__JumpJustDown;
    CPad__SprintJustDown_t f_CPad__SprintJustDown;
    CPad__ConversationYesJustDown_t f_CPad__ConversationYesJustDown;
    CPad__ConversationNoJustDown_t f_CPad__ConversationNoJustDown;
    CPad__isStandardKeyJustPressed_t f_CPad__isStandardKeyJustPressed;
    CPad__isTabJustPressed_t f_CPad__isTabJustPressed;
    CSprite2d__DrawRect_t f_CSprite2d__DrawRect;
    CSprite2d__DrawCircleAtNearClip_t f_CSprite2d__DrawCircleAtNearClip;
    CSprite2d__Draw2DPolygon_t f_CSprite2d__Draw2DPolygon;
    CWeapon__DoBulletImpact_t f_CWeapon__DoBulletImpact;
    CWeapon__GenerateDamageEvent_t f_CWeapon__GenerateDamageEvent;

    /* Function calls */
    void* c_CCam__Process_AimWeapon;
    void* c_Render2dStuff;

    /* Data */
    CPad* pads;
    CKeyboardState* CPad__NewKeyState;
    void** ped_pool_ptr;
    CPed** player_ptr_ptr;
    float* fov_ptr;
    uint32_t* screen_resolution_x_ptr;
    uint32_t* screen_resolution_y_ptr;
    CCamera* camera_ptr;
    float* crosshair_mult_x_ptr;
    float* crosshair_mult_y_ptr;
    char* cheat_string;
} GtaSa;


bool gta_sa_init(void);
bool gta_sa_destroy(void);

const GtaSa* gta_sa(void);

#endif /* GTA_SA_H_ */
