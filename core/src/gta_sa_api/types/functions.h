/**
 * @file functions.h
 * @brief Typedefs and callers for common GTA San Andreas functions.
 */
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "c_cpp_compat.h"
#include "data.h"
#include "enums.h"

typedef int(CC_CDECL* Idle_t)(int);
typedef char(CC_THISCALL* CCam__Process_AimWeapon_t)(CCam* ECX, void* EDX,
                                                     CVector* plyrPosn,
                                                     float a5, float a6,
                                                     float a7);
typedef void(CC_THISCALL* CCamera__Process)(CCamera* ECX, void* EDX);
typedef void(CC_CDECL* CHud__SetHelpMessage)(char* str, char bQuickMessage,
                                             char bPermanent, char bAddToBrief);
typedef char(CC_CDECL* CalcScreenCoors_t)(CVector* point, CVector* a2,
                                          float* a3, float* a4);
typedef int(CC_CDECL* CMessages__AddMessageJumpQ_t)(char* text, int time,
                                                    int16_t flag,
                                                    char bAddToPreviousBrief);
typedef char(CC_CDECL* CWorld__GetIsLineOfSightClear_t)(
    CVector* origin, CVector* target, char buildings, char vehicles, char peds,
    char objects, char dummies, char doSeeThroughCheck,
    char doIgnoreCameraCheck);
typedef CPed*(CC_CDECL* CPools__GetPed)(signed int a1);
typedef char(CC_THISCALL* CEntity__GetIsOnScreen_t)(CEntity* ECX, void* EDX);
typedef char(CC_THISCALL* CPed__Render_t)(CPed* ECX, void* EDX);
typedef int(CC_THISCALL* CPed__GetBonePosition_t)(CPed* ECX, void* EDX,
                                                  CVector* pPoint, int bone_id,
                                                  char bDynamic);
typedef void(CC_THISCALL* CVector__Normalise_t)(CVector* ECX, void* EDX);
typedef void(CC_STDCALL* Render2dStuff_t)(void);
typedef char(CC_STDCALL* c_D3DXMatrixInverse_t)(void* a1_D3DXMATRIX_1,
                                                float* a2,
                                                const void* a3_D3DXMATRIX);
typedef uint32_t (*timeGetTime_t)(void);

typedef CPad*(CC_CDECL* CPad__GetPad_t)(int number);
typedef char(CC_THISCALL* CPad__ExitVehicleJustDown_t)(CPad* ECX, void* EDX);
typedef char(CC_THISCALL* CPad__CycleWeaponLeftJustDown_t)(CPad* ECX,
                                                           void* EDX);
typedef char(CC_THISCALL* CPad__CycleWeaponRightJustDown_t)(CPad* ECX,
                                                            void* EDX);
typedef char(CC_THISCALL* CPad__DuckJustDown_t)(CPad* ECX, void* EDX);
typedef char(CC_THISCALL* CPad__JumpJustDown_t)(CPad* ECX, void* EDX);
typedef char(CC_THISCALL* CPad__SprintJustDown_t)(CPad* ECX, void* EDX);
typedef char(CC_THISCALL* CPad__ConversationYesJustDown_t)(CPad* ECX,
                                                           void* EDX);
typedef char(CC_THISCALL* CPad__ConversationNoJustDown_t)(CPad* ECX, void* EDX);
typedef int(CC_STDCALL* CPad__isStandardKeyJustPressed_t)(uint8_t key);
typedef int(CC_THISCALL* CPad__isTabJustPressed_t)(CPad* ECX, void* EDX);
typedef char(CC_CDECL* CFont__PrintString_t)(float x, float y, char* text);
typedef void(CC_CDECL* CFont__PrintChar_t)(float x, float y, char letter);
typedef void(CC_CDECL* CFont__SetScale_t)(float scaleX, float scaleY);
typedef void(CC_CDECL* CFont__SetSlantRefPoint_t)(float x, float y);
typedef void(CC_CDECL* CFont__SetSlant_t)(float value);
typedef void(CC_CDECL* CFont__SetColor_t)(CRGBA color);
typedef void(CC_CDECL* CFont__SetFontStyle_t)(eFontStyle font);
typedef void(CC_CDECL* CFont__SetAlphaFade_t)(float alpha);
typedef char(CC_CDECL* CFont__SetDropShadowPosition_t)(char value);
typedef char(CC_CDECL* CFont__SetOutlinePosition_t)(char a1);
typedef char(CC_CDECL* CFont__SetBackground_t)(char bBackground,
                                               char bBackgroundOnlyText);
typedef unsigned int(CC_CDECL* CFont__SetBackgroundColor_t)(CRGBA a1);
typedef int(CC_CDECL* CFont__SetAlignment_t)(unsigned __int8 a1);
typedef void(CC_CDECL* CFont__SetDropColor_t)(uint32_t color);
typedef char(CC_CDECL* CFont__SetProp_t)(char a1);
typedef double(CC_CDECL* CFont__GetStringWidth_t)(char* str, char bFull,
                                                  char bScriptText);
typedef void(CC_CDECL* CSprite2d__DrawRect_t)(RwRect* rect, RwRGBA* rgbaColor);
typedef int(CC_CDECL* CSprite2d__DrawCircleAtNearClip_t)(RwV2d* a1,
                                                         float radius,
                                                         RwRGBA* a3,
                                                         signed int angle);
typedef int(CC_CDECL* CSprite2d__Draw2DPolygon_t)(float x1, float y1, float x2,
                                                  float y2, float x3, float y3,
                                                  float x4, float y4,
                                                  RwRGBA* color);
typedef void(CC_THISCALL* CWeapon__DoBulletImpact_t)(
    CWeapon* weapon, void* EDX, CEntity* owner, int victim, CVector* startPoint,
    CVector* endPoint, CColPoint* colPoint, int a7);
typedef char(CC_CDECL* CWeapon__GenerateDamageEvent_t)(
    CPed* victim, CPed* creator, eWeaponType weaponType, int damageFactor,
    int pedPiece, char direction);

#endif /* FUNCTIONS_H_ */
