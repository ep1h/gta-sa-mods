/**
 * @file datatypes.h
 * @brief Common GTA San Andreas data types.
 */
#ifndef DATA_H_
#define DATA_H_

#include <stdint.h>
#include "c_cpp_compat.h"
#include "enums.h"

typedef struct CMatrixLink CMatrixLink;
typedef struct RwLinkList RwLinkList;
typedef struct RwResEntry RwResEntry;
typedef struct RwFrame RwFrame;
typedef struct RpAtomic RpAtomic;
typedef struct RpClump RpClump;
typedef struct CShadowData CShadowData;
typedef struct CVehicle CVehicle;
typedef struct CPedIntelligence CPedIntelligence;
typedef struct CPlayerData CPlayerData;
typedef struct AnimBlendFrameData AnimBlendFrameData;
typedef struct CPedStat CPedStat;
typedef struct FxSystem_c FxSystem_c;
typedef struct CFire CFire;

typedef struct CPed CPed;
typedef struct CMatrix CMatrix;
typedef struct CEntity CEntity;
typedef struct CPhysical CPhysical;
typedef struct CAEAudioEntity CAEAudioEntity;

typedef struct CCamera CCamera;

typedef struct CKeyboardState
{
    int16_t FKeys[12];
    int16_t standardKeys[256];
    int16_t esc;
    int16_t insert;
    int16_t del;
    int16_t home;
    int16_t end;
    int16_t pgup;
    int16_t pgdn;
    int16_t up;
    int16_t down;
    int16_t left;
    int16_t right;
    int16_t scroll;
    int16_t pause;
    int16_t numlock;
    int16_t div;
    int16_t mul;
    int16_t sub;
    int16_t add;
    int16_t enter;
    int16_t decimal;
    int16_t num1;
    int16_t num2;
    int16_t num3;
    int16_t num4;
    int16_t num5;
    int16_t num6;
    int16_t num7;
    int16_t num8;
    int16_t num9;
    int16_t num0;
    int16_t back;
    int16_t tab;
    int16_t capslock;
    int16_t extenter;
    int16_t lshift;
    int16_t rshift;
    int16_t shift;
    int16_t lctrl;
    int16_t rctrl;
    int16_t lmenu;
    int16_t rmenu;
    int16_t lwin;
    int16_t rwin;
    int16_t apps;
} CKeyboardState;

typedef struct CControllerState
{
    int16_t LeftStickX;
    int16_t LeftStickY;
    int16_t RightStickX;
    int16_t RightStickY;
    int16_t LeftShoulder1;
    int16_t LeftShoulder2;
    int16_t RightShoulder1;
    int16_t RightShoulder2;
    int16_t DPadUp;
    int16_t DPadDown;
    int16_t DPadLeft;
    int16_t DPadRight;
    int16_t Start;
    int16_t Select;
    int16_t ButtonSquare;
    int16_t ButtonTriangle;
    int16_t ButtonCross;
    int16_t ButtonCircle;
    int16_t ShockButtonL;
    int16_t ShockButtonR;
    int16_t m_bChatIndicated;
    int16_t m_bPedWalk;
    int16_t m_bVehicleMouseLook;
    int16_t m_bRadioTrackSkip;
} CControllerState;

typedef struct CPad
{
    CControllerState NewState;
    CControllerState OldState;
    int16_t SteeringLeftRightBuffer[10];
    int DrunkDrivingBufferUsed;
    CControllerState PCTempKeyState;
    CControllerState PCTempJoyState;
    CControllerState PCTempMouseState;
    char Phase;
    char _pad109;
    int16_t Mode;
    int16_t ShakeDur;
    int16_t DisablePlayerControls;
    char ShakeFreq;
    char bHornHistory[5];
    char iCurrHornHistory;
    char JustOutOfFrontEnd;
    char bApplyBrakes;
    char bDisablePlayerEnterCar;
    char bDisablePlayerDuck;
    char bDisablePlayerFireWeapon;
    char bDisablePlayerFireWeaponWithL1;
    char bDisablePlayerCycleWeapon;
    char bDisablePlayerJump;
    char bDisablePlayerDisplayVitalStats;
    int LastTimeTouched;
    int AverageWeapon;
    int AverageEntries;
    int NoShakeBeforeThis;
    char NoShakeFreq;
    char _pad131[3];
} CPad;

typedef struct CVector
{
    float x;
    float y;
    float z;
} CVector;

typedef struct CVector2D
{
    float x;
    float y;
} CVector2D;

typedef struct CSimpleTransform
{
    CVector m_vPosn;
    float m_fAngle;
} CSimpleTransform;

typedef struct RwV3d
{
    float x;
    float y;
    float z;
} RwV3d;

typedef struct CQuaternion
{
    CVector imag;
    float real;
} CQuaternion;

typedef struct CMatrix
{
    CVector right;
    int _pad0;
    CVector top;
    int _pad1;
    CVector at;
    int _pad2;
    CVector pos;
    int _pad3;
    CMatrix* m_pAttachMatrix;
    int m_bAttachMatrixTemporary;
} CMatrix;

typedef struct CMatrixLink
{
    CMatrix mat;
    int m_pOwner;
    CMatrixLink* m_pPrev;
    CMatrixLink* m_pNext;
} CMatrixLink;

typedef struct RwObject
{
    char type;
    char subType;
    char flags;
    char privateFlags;
    RwFrame* parent;
} RwObject;


#pragma pack(push, 8)
typedef struct TYPES_UNALIGNED RwLLLink
{
    RwLinkList* next;
    RwLinkList* prev;
} RwLLLink;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct RwLinkList
{
    RwLLLink link;
} RwLinkList;
#pragma pack(pop)

#pragma pack(push, 8)
typedef struct RwObjectHasFrame
{
    RwObject object;
    RwLLLink lFrame;
    int sync;
} RwObjectHasFrame;
#pragma pack(pop)
#pragma pack(push, 8)


#pragma pack(push, 1)
typedef struct RwTexDictionary
{
    RwObject object;
    RwLinkList texturesInDict;
    RwLLLink lInInstance;
} RwTexDictionary;
#pragma pack(pop)


#pragma pack(push, 1)
typedef struct RwRaster
{
    void* parent;
    char* cpPixels;
    int palette;
    int width;
    int height;
    int depth;
    int stride;
    int16_t nOffsetX;
    int16_t nOffsetY;
    char cType;
    uint8_t cFlags;
    char privateFlags;
    uint8_t cFormat;
    int originalPixels;
    int originalWidth;
    int originalHeight;
    int oriiginalStride;
} RwRaster;
#pragma pack(pop)

#pragma pack(push, 8)
typedef struct RwTexture
{
    RwRaster* raster;
    RwTexDictionary* dict;
    RwLLLink lInDictionary;
    char name[32];
    char mask[32];
    unsigned int filterAddressing;
    int refCount;
} RwTexture;
#pragma pack(pop)

typedef struct RwRect
{
    float x1;
    float y1;
    float x2;
    float y2;
} RwRect;

#pragma pack(push, 1)
typedef struct RwRGBA
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
} RwRGBA;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct RwSurfaceProperties
{
    float ambient;
    float flags;
    float diffuse;
} RwSurfaceProperties;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct RpMaterial
{
    RwTexture* texture;
    RwRGBA color;
    int pipeline;
    RwSurfaceProperties surfaceProps;
    int16_t refCount;
    int16_t pad;
} RpMaterial;
#pragma pack(pop)


#pragma pack(push, 1)
typedef struct RpMaterialList
{
    RpMaterial** materials;
    int numMaterials;
    int space;
} RpMaterialList;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct RwTexCoords
{
    float u;
    float v;
} RwTexCoords;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct RpMesh
{
    uint16_t* indices;
    int numIndices;
    RpMaterial* material;
} RpMesh;
#pragma pack(pop)


#pragma pack(push, 1)
typedef struct RpMeshHeader
{
    int flags;
    int16_t numMeshes;
    int16_t serialNum;
    int totalIndicesInMesh;
    int firstMeshOffset;
    RpMesh meshes[2];
} RpMeshHeader;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct RwSphere
{
    RwV3d center;
    float radius;
} RwSphere;
#pragma pack(pop)


#pragma pack(push, 1)
typedef struct RpMorphTarget
{
    int parentGeom;
    RwSphere boundingSphere;
    RwV3d* verts;
    int normals;
} RpMorphTarget;
#pragma pack(pop)


#pragma pack(push, 8)
typedef struct RpGeometry
{
    int object;
    TYPES_ALIGNAS(8) int flags;
    int16_t lockedSinceLastInst;
    int16_t refCount;
    int numTriangles;
    int numVertices;
    int numMorphTargets;
    int numTexCoordSets;
    RpMaterialList matList;
    int triangles;
    RwRGBA* preLitLum;
    RwTexCoords* texCoords[8];
    RpMeshHeader* mesh;
    RwResEntry* resEntry;
    RpMorphTarget* morphTarget;
} RpGeometry;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct RpInterpolator
{
    int flags;
    int16_t startMorphTarget;
    int16_t endMorphTarget;
    int time;
    int recipTime;
    int position;
} RpInterpolator;
#pragma pack(pop)

#pragma pack(push, 8)
typedef struct RwV2d
{
    float x;
    float y;
} RwV2d;
#pragma pack(pop)

typedef struct TYPES_UNALIGNED RpAtomic
{
    RwObjectHasFrame object;
    RwResEntry* repEntry;
    RpGeometry* geometry;
    RwSphere boundingSphere;
    void* worldBoundingSphere[4];
    RpClump* clump;
    RwLLLink inClumpLink;
    RpAtomic*(__cdecl* renderCallback)(RpAtomic*);
    RpInterpolator interpolator;
    int16_t renderFrame;
    int16_t pad;
    RwLinkList llWorldSectorsInAtomic;
    int pipeline;
    char field_70;
} RpAtomic;
#pragma pack(pop)


typedef union ClumpAtomicUnion {
    RwObject* m_pRwObject;
    RpAtomic* m_pRwAtomic;
    RpClump* m_pRwClump;
} ClumpAtomicUnion;

typedef struct CReference
{
    int m_pNext;
    CEntity** m_ppEntity;
} CReference;

typedef struct CPlaceable
{
    void* vtbl;
    CSimpleTransform m_SimpleCoors;
    CMatrixLink* m_pMatrix;
} CPlaceable;

typedef struct CEntity
{
    CPlaceable placeable;
    ClumpAtomicUnion object;
    int m_nFlags;
    uint16_t m_nRandomSeed;
    uint16_t m_nModelIndex;
    CReference* m_pReferences;
    void* m_pStreamingLink;
    uint16_t m_nLastScanCode;
    char m_iplIndex;
    char m_nbInterior;
    CEntity* m_pLod;
    char m_bNumLodChildren;
    char m_bNumLodChildrenRendered;
    char m_nTypeStatus;
    char _pad0;
} CEntity;

typedef struct CPhysical
{
    CEntity entity;
    float field_34;
    int m_dwLastCollisionTime;
    int m_dwFlags;
    CVector m_vecMoveSpeed;
    CVector m_vecTurnSpeed;
    CVector m_vecFrictionMoveSpeed;
    CVector m_vecFrictionTurnSpeed;
    CVector m_vecForce;
    CVector m_vecTorque;
    float m_fMass;
    float m_fTurnMass;
    int m_fVelocityFrequency;
    float m_fAirResistance;
    float m_fElasticity;
    float m_fBuoyancyConstant;
    CVector m_vecCentreOfMass;
    int m_pCollisionList;
    int m_pMovingList;
    char m_bFakePhysics;
    char m_nNumEntitiesCollided;
    char m_nContactSurface;
    char field_BB;
    int m_apCollidedEntities[6];
    float m_fMovingSpeed;
    int m_fDamageIntensity;
    int m_pDamageEntity;
    RwV3d m_vLastCollisionDirection;
    CVector m_vecLastCollisionPosn;
    uint16_t m_nDamagedPart;
    uint16_t field_FA;
    CPhysical* m_pAttachedTo;
    RwV3d m_vAttachOffset;
    RwV3d m_vAttachRotation;
    CQuaternion m_qAttachRotation;
    int EntityIgnoredCollision;
    float m_fContactSurfaceBrightness;
    float m_fDynamicLighting;
    CShadowData* m_pShadowData;
} CPhysical;

typedef struct CAESound
{
    uint16_t m_wBankSlotId;
    uint16_t m_wSoundIdInSlot;
    CAEAudioEntity* m_pBaseAudio;
    CEntity* m_pPhysicalEntity;
    unsigned __int32 m_dwEvent;
    float m_fMaxVolume;
    float m_fVolume;
    float m_fSoundDistance;
    float m_fSpeed;
    float field_20;
    CVector m_vCurrPosn;
    CVector m_vPrevPosn;
    uint16_t m_dwLastFrameUpdate;
    int m_dwCurrTimeUpdate;
    int m_dwPrevTimeUpdate;
    float m_fCurrCamDist;
    float m_fPrevCamDist;
    float m_fTimeScale;
    int8_t field_54;
    int8_t field_55;
    uint16_t m_nIndividualEnvironment;
    uint16_t m_wIsUsed;
    uint16_t field_5A;
    uint16_t m_wPlayPercentage;
    uint16_t field_5E;
    float m_fFinalVolume;
    float m_fFrequency;
    uint16_t m_wPlayingState;
    int8_t field_6A[2];
    float m_fSoundHeadRoom;
    uint16_t field_70;
    uint16_t field_72;
} CAESound;

typedef struct CAEAudioEntity
{
    void* vmt;
    CVehicle* m_pEntity;
    CAESound sound;
} CAEAudioEntity;

typedef struct CAETwinLoopSoundEntity
{
    CAEAudioEntity audio;
    int16_t m_wBankSlotId;
    int16_t m_wSoundType[2];
    char _pad1[2];
    CAEAudioEntity* m_pAudioEntity;
    uint16_t field_88;
    int16_t field_8A;
    int16_t field_8C;
    int16_t m_wPlayTimeMin;
    int16_t m_wPlayTimeMax;
    char _pad2[2];
    int m_dwTimeToSwapSounds;
    char m_bPlayingFirstSound;
    char _pad3;
    int16_t m_wStartingPlayPercentage[2];
    int16_t field_9E;
    CAESound* m_apSounds[2];
} CAETwinLoopSoundEntity;

typedef struct CAEPedAudioEntity
{
    CAEAudioEntity vmt;
    uint8_t field_7C;
    char field_7D;
    uint16_t field_7E;
    int field_80;
    float field_84;
    float field_88;
    char field_8C[8];
    CPed* m_pPed;
    char field_98;
    char field_99[3];
    CAESound* field_9C;
    uint16_t field_A0;
    CAESound* field_A4;
    CAETwinLoopSoundEntity m_85F438;
    CAESound* field_150;
    float field_154;
    float field_158;
} CAEPedAudioEntity;

typedef struct CAEPedSpeechAudioEntity
{
    CAEAudioEntity dummy;
    char field_7C[20];
    char field_90;
    char field_91;
    int16_t m_nAudioPedType;
    int16_t m_nVoiceId;
    int16_t m_nAudioGender;
    char m_bTalking;
    char m_bEnableSpeech;
    char m_bEnableSpeechForScripts;
    char m_nVocalEnableFlag;
    char field_9C;
    char field_9D;
    char field_9E;
    char field_9F;
    CAESound* m_pSound;
    int16_t field_A4;
    int16_t field_A6;
    int16_t field_A8;
    int16_t field_AA;
    float m_fVoiceVolume;
    int16_t m_nPhraseId;
    int16_t field_B2;
    int field_B4[19];
} CAEPedSpeechAudioEntity;

typedef struct CAEPedWeaponAudioEntity
{
    CAEAudioEntity e;
    char m_bPlayedMiniGunFireSound;
    char field_7D;
    char field_7E;
    char field_7F;
    char m_nChainsawSoundState;
    char field_81[3];
    int m_dwFlameThrowerLastPlayedTime;
    int m_dwSpraycanLastPlayedTime;
    int m_dwExtinguisherLastPlayedTime;
    int m_dwMiniGunFireSoundPlayedTime;
    int m_dwTimeChainsaw;
    uint16_t m_dwTimeLastFired;
    CAESound* m_pSounds;
    char m_bActive;
    char field_A1[3];
    CPed* m_pPed;
} CAEPedWeaponAudioEntity;

typedef struct CPedAcquaintance
{
    int respect;
    int like;
    int field_8;
    int dislike;
    int hate;
} CPedAcquaintance;

typedef struct LimbOrienation
{
    float yaw;
    float pitch;
} LimbOrienation;

typedef struct CPedIK
{
    CPed* ThisPed;
    LimbOrienation m_torsoOrien;
    float m_fSlopePitch;
    float m_fSlopePitchLimitMult;
    float m_fSlopeRoll;
    float m_fBodyRoll;
    int m_flags;
} CPedIK;

typedef struct CWeapon
{
    eWeaponType m_nType;
    int m_nState;
    int m_nAmmoInClip;
    int m_nTotalAmmo;
    int m_nShotTimer;
    char field_14;
    char m_bNoModel;
    char field_16;
    char field_17;
    FxSystem_c* m_pFxSystem;
} CWeapon;

typedef struct CPed
{
    CPhysical physical;
    CAEPedAudioEntity m_pedAudio;
    CAEPedSpeechAudioEntity m_pedSpeech;
    CAEPedWeaponAudioEntity m_weaponAudio;
    char field_43C[36];
    char field_460[8];
    int field_468;
    int m_nPedFlags[4];
    CPedIntelligence* m_pIntelligence;
    CPlayerData* m_pPlayerData;
    char m_nCreatedBy;
    char _pad0[3];
    AnimBlendFrameData* m_apPedBones[19];
    int m_dwAnimGroup;
    CVector2D m_vAnimMovingShiftLocal;
    CPedAcquaintance m_acquaintance;
    RpClump* m_pWeaponObject;
    RwFrame* m_pGunflashObject;
    int m_pGogglesObject;
    int8_t* m_pGogglesState;
    uint16_t m_nWeaponGunflashStateLeftHand;
    uint16_t field_506;
    uint16_t m_nWeaponGunflashStateRightHand;
    uint16_t field_50A;
    CPedIK m_pedIK;
    int field_52C;
    ePedState m_nPedState;
    int m_dwMoveState;
    int field_538;
    int field_53C;
    float m_fHealth;
    float m_fMaxHealth;
    float m_fArmour;
    int m_dwTimeTillWeNeedThisPed;
    CVector2D m_vAnimMovingShift;
    float m_fCurrentRotation;
    float m_fAimingRotation;
    float m_fHeadingChangeRate;
    int m_dwMoveAnim;
    int field_568;
    RwV3d field_56C;
    RwV3d field_578;
    int m_pContactEntity;
    float m_pLastVehicle;
    CVehicle* m_pVehicle;
    int field_590;
    int field_594;
    int m_nPedType;
    CPedStat* m_pStats;
    CWeapon m_aWeapons[13];
    eWeaponType m_nSavedWeapon;
    eWeaponType m_nDelayedWeapon;
    int m_dwDelayedWeaponAmmo;
    char m_nActiveWeaponSlot;
    char m_nWeaponShootingRate;
    char m_nWeaponAccuracy;
    char _pad;
    int m_pTargetedObject;
    float field_720;
    float field_724;
    float field_728;
    char m_nWeaponSkill;
    char m_nFightingStyle;
    char m_nAllowedAttackMoves;
    char field_72F;
    CFire* m_pFire;
    int field_734;
    CEntity* m_pLookAtEntity;
    float m_fLookHeading;
    int m_dwWeaponModelId;
    int field_744;
    int m_dwLookTime;
    int field_74C;
    int m_dwTimeWhenDead;
    char m_nBodypartToRemove;
    char field_755;
    uint16_t m_nMoneyCount;
    float field_758;
    int field_75C;
    char m_nLastWeaponDamage;
    char field_761[3];
    int m_pLastEntityDamaged;
    int field_768;
    CVector m_vTurretOffset;
    int m_fTurretAngleA;
    int m_fTurretAngleB;
    int m_dwTurretPosnMode;
    int m_dwTurretAmmo;
    int m_pCoverPoint;
    int m_pEnex;
    float m_fRemovalDistMultiplier;
    uint16_t m_wSpecialModelIndex;
    char field_796[2];
    int field_798;
} CPed;

#pragma pack(push, 1)
typedef struct CRGBA
{
    RwRGBA rgba;
} CRGBA;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct CFontChar
{
    char m_cLetter;
    char _pad0[3];
    CVector2D m_vPosn;
    int m_fWidth;
    float m_fHeigth;
    RwRGBA m_color;
    float m_fWrap;
    float m_fSlant;
    CVector2D m_vSlanRefPoint;
    char m_bContainImages;
    char m_nFontStyle;
    char m_bPropOn;
    char _pad1;
    int16_t m_wFontTexture;
    char m_nOutline;
    char _pad2;
} CFontChar;
#pragma pack(pop)

typedef struct CCam
{
    uint8_t m_bBelowMinDist;
    uint8_t m_bBehindPlayerDesired;
    uint8_t m_bCamLookingAtVector;
    uint8_t m_bCollisionChecksOn;
    uint8_t m_bFixingBeta;
    uint8_t m_bTheHeightFixerVehicleIsATrain;
    uint8_t m_bLookBehindCamWasInFront;
    uint8_t m_bLookingBehind;
    uint8_t m_bLookingLeft;
    uint8_t m_bLookingRight;
    uint8_t m_bResetStatics;
    uint8_t m_bRotating;
    uint16_t m_wMode;
    int16_t _pad;
    uint32_t m_dwFinishTime;
    uint32_t m_dwDoCollisionChecksOnFrameNum;
    uint32_t m_dwDoCollisionCheckEveryNumOfFrames;
    uint32_t m_dwFrameNumWereAt;
    uint32_t m_dwRunningVectorArrayPos;
    int m_dwRunningVectorCounter;
    uint32_t m_dwDirectionWasLooking;
    float m_fMaxRoleAngle;
    float m_fRoll;
    float m_fRollSpeed;
    float m_fSyphonModeTargetZOffSet;
    float m_fAmountFractionObscured;
    float m_fAlphaSpeedOverOneFrame;
    float m_fBetaSpeedOverOneFrame;
    float m_fBufferedTargetBeta;
    float m_fBufferedTargetOrientation;
    float m_fBufferedTargetOrientationSpeed;
    float m_fCamBufferedHeight;
    float m_fCamBufferedHeightSpeed;
    float m_fCloseInPedHeightOffset;
    float m_fCloseInPedHeightOffsetSpeed;
    float m_fCloseInCarHeightOffset;
    float m_fCloseInCarHeightOffsetSpeed;
    float m_fDimensionOfHighestNearCar;
    float m_fDistanceBeforeChanges;
    float m_fFovSpeedOverOneFrame;
    float m_fMinDistAwayFromCamWhenInterPolating;
    float m_fPedBetweenCameraHeightOffset;
    float m_fPlayerInFrontSyphonAngleOffSet;
    float m_fRadiusForDead;
    float m_fRealGroundDist;
    float m_fTargetBeta;
    float m_fTimeElapsedFloat;
    float m_fTilt;
    float m_fTiltSpeed;
    float m_fTransitionBeta;
    float m_fTrueBeta;
    float m_fTrueAlpha;
    float m_fInitialPlayerOrientation;
    float m_fVerticalAngle;
    float m_fAlphaSpeed;
    float m_fFOV;
    float m_fFOVSpeed;
    float m_fHorizontalAngle;
    float m_fBetaSpeed;
    float m_fDistance;
    float m_fDistanceSpeed;
    float m_fCaMinDistance;
    float m_fCaMaxDistance;
    float m_fSpeedVar;
    float m_fCameraHeightMultiplier;
    float m_fTargetZoomGroundOne;
    float m_fTargetZoomGroundTwo;
    float m_fTargetZoomGroundThree;
    float m_fTargetZoomOneZExtra;
    float m_fTargetZoomTwoZExtra;
    float m_fTargetZoomTwoInteriorZExtra;
    float m_fTargetZoomThreeZExtra;
    float m_fTargetZoomZCloseIn;
    float m_fMinRealGroundDist;
    float m_fTargetCloseInDist;
    float m_fBeta_Targeting;
    float m_fX_Targetting;
    float m_fY_Targetting;
    CVehicle* m_pCarWeAreFocussingOn;
    CVehicle* m_pCarWeAreFocussingOnI;
    float m_fCamBumpedHorz;
    float m_fCamBumpedVert;
    float m_dwCamBumpedTime;
    CVector m_vSourceSpeedOverOneFrame;
    CVector m_vTargetSpeedOverOneFrame;
    CVector m_vUpOverOneFrame;
    CVector m_vTargetCoorsForFudgeInter;
    CVector m_vCamFixedModeVector;
    CVector m_vCamFixedModeSource;
    CVector m_vCamFixedModeUpOffSet;
    CVector m_vLastAboveWaterCamPosition;
    CVector m_vBufferedPlayerBodyOffset;
    CVector m_vFront;
    CVector m_vSource;
    CVector m_vSourceBeforeLookBehind;
    CVector m_vUp;
    CVector m_avPreviousVectors[2];
    CVector m_avTargetHistoryPos[4];
    uint32_t m_adwTargetHistoryTime[4];
    uint32_t m_dwCurrentHistoryPoints;
    CEntity* m_pCamTargetEntity;
    float m_fCameraDistance;
    float m_fIdealAlpha;
    float m_fPlayerVelocity;
    CVehicle* m_pLastCarEntered;
    CPed* m_pLastPedLookedAt;
    uint8_t m_bFirstPersonRunAboutActive; // TODO: bool in cpp?
    char _pad238[3];
} CCam;

typedef struct CQueuedMode
{
    int16_t Mode;
    int16_t __padding0;
    float Duration;
    int16_t MinZoom;
    int16_t MaxZoom;
} CQueuedMode;

typedef struct CCamPathSplines
{
    float* m_arr_PathData;
} CCamPathSplines;

typedef struct CCamera
{
    CPlaceable placeable;
    uint8_t m_bAboveGroundTrainNodesLoaded;
    uint8_t m_bBelowGroundTrainNodesLoaded;
    uint8_t m_bCamDirectlyBehind;
    uint8_t m_bCamDirectlyInFront;
    uint8_t m_bCameraJustRestored;
    uint8_t m_bcutsceneFinished;
    uint8_t m_bCullZoneChecksOn;
    uint8_t m_bFirstPersonBeingUsed;
    uint8_t m_bJustJumpedOutOf1stPersonBecauseOfTarget;
    uint8_t m_bIdleOn;
    uint8_t m_bInATunnelAndABigVehicle;
    uint8_t m_bInitialNodeFound;
    uint8_t m_bInitialNoNodeStaticsSet;
    uint8_t m_bIgnoreFadingStuffForMusic;
    uint8_t m_bPlayerIsInGarage;
    uint8_t m_bPlayerWasOnBike;
    uint8_t m_bJustCameOutOfGarage;
    uint8_t m_bJustInitalised;
    uint8_t m_bJust_Switched;
    uint8_t m_bLookingAtPlayer;
    uint8_t m_bLookingAtVector;
    uint8_t m_bMoveCamToAvoidGeom;
    uint8_t m_bObbeCinematicPedCamOn;
    uint8_t m_bObbeCinematicCarCamOn;
    uint8_t m_bRestoreByJumpCut;
    uint8_t m_bUseNearClipScript;
    uint8_t m_bStartInterScript;
    uint8_t m_bStartingSpline;
    uint8_t m_bTargetJustBeenOnTrain;
    uint8_t m_bTargetJustCameOffTrain;
    uint8_t m_bUseSpecialFovTrain;
    uint8_t m_bUseTransitionBeta;
    uint8_t m_bUseScriptZoomValuePed;
    uint8_t m_bUseScriptZoomValueCar;
    uint8_t m_bWaitForInterpolToFinish;
    uint8_t m_bItsOkToLookJustAtThePlayer;
    uint8_t m_bWantsToSwitchWidescreenOff;
    uint8_t m_bWideScreenOn;
    uint8_t m_b1rstPersonRunCloseToAWall;
    uint8_t m_bHeadBob;
    uint8_t m_bVehicleSuspenHigh;
    uint8_t m_bEnable1rstPersonCamCntrlsScript;
    uint8_t m_bAllow1rstPersonWeaponsCamera;
    uint8_t m_bCooperativeCamMode;
    uint8_t m_bAllowShootingWith2PlayersInCar;
    uint8_t m_bDisableFirstPersonInCar;
    uint16_t m_wModeForTwoPlayersSeparateCars;
    uint16_t m_wModeForTwoPlayersSameCarShootingAllowed;
    uint16_t m_wModeForTwoPlayersSameCarShootingNotAllowed;
    uint16_t m_wModeForTwoPlayersNotBothInCar;
    uint8_t m_bGarageFixedCamPositionSet;
    uint8_t m_bDoingSpecialInterPolation;
    uint8_t m_bScriptParametersSetForInterPol;
    uint8_t m_bFading;
    uint8_t m_bMusicFading;
    uint8_t m_bMusicFadedOut;
    uint8_t m_bFailedCullZoneTestPreviously;
    uint8_t m_bFadeTargetIsSplashScreen;
    uint8_t m_bWorldViewerBeingUsed;
    uint8_t m_bTransitionJUSTStarted;
    uint8_t m_bTransitionState;
    uint8_t m_nActiveCam;
    char __padding0[2];
    uint32_t m_dwCamShakeStart;
    uint32_t m_dwFirstPersonCamLastInputTime;
    uint32_t m_dwLongestTimeInMill;
    uint32_t m_dwNumberOfTrainCamNodes;
    uint32_t m_dwTimeLastChange;
    uint32_t m_dwTimeWeLeftIdle_StillNoInput;
    uint32_t m_dwTimeWeEnteredIdle;
    uint32_t m_dwTimeTransitionStart;
    uint32_t m_dwTransitionDuration;
    uint32_t m_dwTransitionDurationTargetCoors;
    uint32_t m_dwBlurBlue;
    uint32_t m_dwBlurGreen;
    uint32_t m_dwBlurRed;
    uint32_t m_dwBlurType;
    uint32_t m_dwWorkOutSpeedThisNumFrames;
    uint32_t m_dwNumFramesSoFar;
    uint32_t m_dwCurrentTrainCamNode;
    uint32_t m_dwMotionBlur;
    uint32_t m_dwMotionBlurAddAlpha;
    uint32_t m_dwCheckCullZoneThisNumFrames;
    uint32_t m_dwZoneCullFrameNumWereAt;
    uint32_t m_dwWhoIsInControlOfTheCamera;
    uint32_t m_nCarZoom;
    float m_fCarZoomBase;
    float m_fCarZoomTotal;
    float m_fCarZoomSmoothed;
    float m_fCarZoomValueScript;
    uint32_t m_dwPedZoom;
    float m_fPedZoomBase;
    float m_fPedZoomTotal;
    uint32_t m_fPedZoomSmoothed;
    float m_fPedZoomValueScript;
    float m_fCamFrontXNorm;
    float m_fCamFrontYNorm;
    float m_fDistanceToWater;
    float m_fHeightOfNearestWater;
    float m_fFOVDuringInter;
    float m_fLODDistMultiplier;
    float m_fGenerationDistMultiplier;
    float m_fAlphaSpeedAtStartInter;
    float m_fAlphaWhenInterPol;
    float m_fAlphaDuringInterPol;
    float m_fBetaDuringInterPol;
    float m_fBetaSpeedAtStartInter;
    float m_fBetaWhenInterPol;
    float m_fFOVWhenInterPol;
    float m_fFOVSpeedAtStartInter;
    float m_fStartingBetaForInterPol;
    float m_fStartingAlphaForInterPol;
    float m_fPedOrientForBehindOrInFront;
    float m_fCameraAverageSpeed;
    float m_fCameraSpeedSoFar;
    float m_fCamShakeForce;
    float m_fFovForTrain;
    float m_fFOV_Wide_Screen;
    float m_fNearClipScript;
    float m_fOldBetaDiff;
    float m_fPositionAlongSpline;
    float m_fScreenReductionPercentage;
    float m_fScreenReductionSpeed;
    float m_fAlphaForPlayerAnim1rstPerson;
    float m_fOrientation;
    float m_fPlayerExhaustion;
    float m_fSoundDistUp;
    float m_fSoundDistUpAsRead;
    float m_fSoundDistUpAsReadOld;
    float m_fAvoidTheGeometryProbsTimer;
    uint16_t m_wAvoidTheGeometryProbsDirn;
    uint16_t __padding1;
    float m_fWideScreenReductionAmount;
    float m_fStartingFOVForInterPol;
    CCam m_aCams[3];
    void* m_pToGarageWeAreIn;
    void* m_pToGarageWeAreInForHackAvoidFirstPerson;
    CQueuedMode m_playerMode;
    CQueuedMode m_playerWeaponMode;
    CVector m_vPreviousCameraPosition;
    CVector m_vRealPreviousCameraPosition;
    CVector m_vAimingTargetCoors;
    CVector m_vFixedModeVector;
    CVector m_vFixedModeSource;
    CVector m_vFixedModeUpOffSet;
    CVector m_vCutSceneOffset;
    CVector m_vStartingSourceForInterPol;
    CVector m_vStartingTargetForInterPol;
    CVector m_vStartingUpForInterPol;
    CVector m_vSourceSpeedAtStartInter;
    CVector m_vTargetSpeedAtStartInter;
    CVector m_vUpSpeedAtStartInter;
    CVector m_vSourceWhenInterPol;
    CVector m_vTargetWhenInterPol;
    CVector m_vUpWhenInterPol;
    CVector m_vClearGeometryVec;
    CVector m_vGameCamPos;
    CVector m_vSourceDuringInter;
    CVector m_vTargetDuringInter;
    CVector m_vUpDuringInter;
    CVector m_vAttachedCamOffset;
    CVector m_vAttachedCamLookAt;
    float m_fAttachedCamAngle;
    void* m_pRwCamera;
    void* m_pTargetEntity;
    void* m_pAttachedEntity;
    CCamPathSplines m_aPathArray[4];
    char m_bMirrorActive;
    char m_bResetOldMatrix;
    char __padding2[2];
    CMatrix m_mCameraMatrix;
    CMatrix m_mCameraMatrixOld;
    CMatrix m_mViewMatrix;
    CMatrix m_mMatInverse;
    CMatrix m_mMatMirrorInverse;
    CMatrix m_mMatMirror;
    CVector m_avFrustumNormals[4];
    CVector field_B54[4];
    CVector field_B84[4];
    float field_BB4[4];
    float field_BC4[4];
    CVector field_BD4;
    int field_BE0;
    int field_BE4;
    int field_BE8;
    int field_BEC;
    int field_BF0;
    int field_BF4;
    int field_BF8;
    float m_fFadeAlpha;
    float field_C00;
    float m_fFadeDuration;
    float field_C08;
    float field_C0C;
    int field_C10;
    int field_C14;
    int field_C18;
    int field_C1C;
    int field_C20;
    int field_C24;
    int field_C28;
    int field_C2C;
    int16_t m_wFadeInOutFlag;
    int16_t field_C32;
    int field_C34;
    int16_t field_C38;
    int16_t field_C3A;
    int16_t field_C3C;
    int16_t field_C3E;
    int m_dwFadeStartTime;
    int field_C44;
    int m_dwNumExtraEntitiesToIgnore;
    void* m_apExtraEntitiesToIgnore[2];
    float field_C54;
    float field_C58;
    int m_dwTransverseStartTime;
    int m_dwTransverseEndTime;
    CVector m_vTransverseEndPoint;
    CVector m_vTransverseStartPoint;
    char m_nTransverseMode;
    char field_C7D;
    char field_C7E;
    char field_C7F;
    CVector field_C80;
    char field_C8C;
    char field_C8D;
    char field_C8E;
    char field_C8F;
    float field_C90;
    int m_dwStartJiggleTime;
    int m_dwEndJiggleTime;
    int field_C9C;
    int field_CA0;
    int m_dwStartZoomTime;
    int m_dwEndZoomTime;
    float m_fZoomInFactor;
    float m_fZoomOutFactor;
    char m_nZoomMode;
    char field_CB5;
    char field_CB6;
    char field_CB7;
    float field_CB8;
    int field_CBC;
    int field_CC0;
    CVector field_CC4;
    CVector field_CD0;
    char field_CDC;
    char field_CDD;
    char field_CDE;
    char field_CDF;
    CVector field_CE0;
    char field_CEC;
    char m_bBlockZoom;
    char field_CEE;
    char field_CEF;
    char field_CF0;
    char field_CF1;
    char field_CF2;
    char field_CF3;
    char field_CF4[80];
    int field_D44;
    int field_D48;
    int field_D4C;
    int field_D50;
    int field_D54;
    int field_D58;
    int field_D5C;
    int field_D60;
    int field_D64;
    int field_D68;
    int field_D6C;
    int field_D70;
    int field_D74;
} CCamera;

typedef struct D3DMATRIX
{
    union {
        struct
        {
            float _11;
            float _12;
            float _13;
            float _14;
            float _21;
            float _22;
            float _23;
            float _24;
            float _31;
            float _32;
            float _33;
            float _34;
            float _41;
            float _42;
            float _43;
            float _44;
        };
        float m[4][4];
    };
} D3DMATRIX;

#pragma pack(push, 8)
typedef struct CColPoint
{
  CVector point;
  int field_C;
  CVector normal;
  int field_1C;
  char surfaceTypeA;
  char pieceTypeA;
  char lightingA;
  uint8_t surfaceTypeB;
  char pieceTypeB;
  char lightingB;
  char field_26[2];
  float depth;
} CColPoint;
#pragma pack(pop)


#endif /* DATA_H_ */
