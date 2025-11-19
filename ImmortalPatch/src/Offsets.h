#pragma once
#include <iostream>
#include "./Structs/Types.h"

void AddLight(Vector3 pos, float radius, Vector3 rgb, float intensity, float duration, float rampUp, float rampDown);
void* startEffect(const char* effectName, Vector3 pos, Vector3 orient);

void TestFunc();


namespace Offsets //Thanks to Malte0641 for providing most of the offsets!
{
#if STEAM_VER
    static constexpr const uintptr_t gGameBase = 0x23229C0;
    static constexpr const uintptr_t gGame = 0xDCF680;
    static constexpr const uintptr_t getOrient = 0x2BDB50;
    static constexpr const uintptr_t enableActorsInsideMe = 0x4A67F0;
    static constexpr const uintptr_t findActorByName = 0x2DB760;
    static constexpr const uintptr_t exportGlobalVariable = 0x2CED00;
    static constexpr const uintptr_t startPreparedTalking = 0x75A00;
    static constexpr const uintptr_t setGhostbusterHeatlhState = 0xD0280;
    static constexpr const uintptr_t flinch = 0xD18B0;
    static constexpr const uintptr_t Singleton_getRoom = 0x2BDBD0;
    static constexpr const uintptr_t setMusic = 0x411FE0;
    static constexpr const uintptr_t hideHack = 0xEE2D0;
    static constexpr const uintptr_t removeSlimeDecals = 0x30D620;
    static constexpr const uintptr_t dbNarrativeStop = 0x1F8410;
    static constexpr const uintptr_t dbNarrative = 0x1ECEB0;
    static constexpr const uintptr_t findDBEntry = 0x2CF5E0;
    static constexpr const uintptr_t DanteVMInstance = 0x222D41C;
    static constexpr const uintptr_t Singleton_newActor = 0x2C0D50;
    static constexpr const uintptr_t die = 0x3B27B0;
    static constexpr const uintptr_t blockHeroMovement = 0xED660;
    static constexpr const uintptr_t toggleHuntMode = 0xED480;
    static constexpr const uintptr_t enableProtonTorpedo = 0xEDE30;
    static constexpr const uintptr_t setCommandCrossBeam = 0xEC640;
    static constexpr const uintptr_t startFakePackOverheat = 0xED750;
    static constexpr const uintptr_t letterbox = 0x2D87A0;
    static constexpr const uintptr_t queueVideo = 0x2D87E0;
    static constexpr const uintptr_t setMovieCaptureEnable = 0x2D8850;
    static constexpr const uintptr_t allowEnemyAttack = 0x2D8420;
    static constexpr const uintptr_t allowHeroControls = 0x2D8440;
    static constexpr const uintptr_t allowHeroDamage = 0x2D8460;
    static constexpr const uintptr_t play = 0x1C3F0;
    static constexpr const uintptr_t setCameraPathActor = 0x1FF760;
    static constexpr const uintptr_t shatter = 0x49EC70;
    static constexpr const uintptr_t setSimEnable = 0x89940;
    static constexpr const uintptr_t loadCheckpoint = 0x1F81F0;
    static constexpr const uintptr_t setCurrentObjective = 0x1F8200;
    static constexpr const uintptr_t toggleReviveMode = 0xD0EE0;
    static constexpr const uintptr_t chainToLevel = 0x1EF700;
    static constexpr const uintptr_t transferHeroshipTo = 0xD81A0;
    static constexpr const uintptr_t slimeMe = 0xD0F50;
    static constexpr const uintptr_t knockBack = 0xED100;
    static constexpr const uintptr_t pretendToDrive = 0xEAC40;
    static constexpr const uintptr_t mountProtonPack = 0xE4640;
    static constexpr const uintptr_t fakeFireProtonGun = 0xE9060;
    static constexpr const uintptr_t cacheRappel = 0xE1D70;
    static constexpr const uintptr_t forceDeployTrap = 0xE4C80;
    static constexpr const uintptr_t setRappelModeEnable = 0xE1F70;
    static constexpr const uintptr_t startRappelSwing = 0xE21E0;
    static constexpr const uintptr_t isDead = 0x7B170;
    static constexpr const uintptr_t cacheStreamingCinematAndAudio = 0x477500;
    static constexpr const uintptr_t stopStreamingCinemat = 0x477B60;
    static constexpr const uintptr_t playStreamingCinemat = 0x478930;
    static constexpr const uintptr_t cueStreamingCinemat = 0x4779B0;
    static constexpr const uintptr_t cacheStreamingCinemat = 0x476520;
    static constexpr const uintptr_t GTFO = 0x2D11C0;
    static constexpr const uintptr_t cacheSkeletalAnimationByName = 0x2D9AF0;
    static constexpr const uintptr_t enable = 0x2DA340;
    static constexpr const uintptr_t setProtonBeamMaxLength = 0x277A50;
    static constexpr const uintptr_t detonate = 0x690F0;
    static constexpr const uintptr_t attachToActorTag = 0x2BEE80;
    static constexpr const uintptr_t setCurrentTeam = 0x15B20;
    static constexpr const uintptr_t isTrapDeployed = 0xDE370;
    static constexpr const uintptr_t gatherAllDeployedInventoryItems = 0xE4770;
    static constexpr const uintptr_t readyInventoryItem = 0xE3F10;
    static constexpr const uintptr_t enableInventoryItem = 0xE4530;
    static constexpr const uintptr_t isPackOverheated = 0xEA6D0;
    static constexpr const uintptr_t slamGoggleLocation = 0xD51D0;
    static constexpr const uintptr_t setGoggleLocation = 0xD50E0;
    static constexpr const uintptr_t setFacialExpression = 0xCD370;
    static constexpr const uintptr_t stopControllingActor = 0x76FD0;
    static constexpr const uintptr_t warpToActorSeamless = 0xCDA20;
    static constexpr const uintptr_t warpTo = 0x2C4520;
    static constexpr const uintptr_t fakePossession = 0xEC1E0;
    static constexpr const uintptr_t setFlashlightMode = 0xE5AD0;
    static constexpr const uintptr_t toggleflashlight = 0xE3BF0;
    static constexpr const uintptr_t commitSuicide = 0xCE560;
    static constexpr const uintptr_t setHealth = 0x7A890;
    static constexpr const uintptr_t setNothingEquipped = 0xE45A0;
    static constexpr const uintptr_t enableAllLights = 0x2E3810;
    static constexpr const uintptr_t DanteVMaddExport = 0x2CEC90;
    static constexpr const uintptr_t buttonPrompt = 0x2494D0;
    static constexpr const uintptr_t setAllowDamageTally = 0x1F8160;
    static constexpr const uintptr_t fade = 0x1ECCA0;
    static constexpr const uintptr_t displaySplashScreen = 0x1ECD50;
    static constexpr const uintptr_t cacheEffect = 0x35A380;
    static constexpr const uintptr_t startEffect = 0x35A730;
    static constexpr const uintptr_t CreateExplosion = 0x1E9170;
    static constexpr const uintptr_t SetGravity = 0x1ECC40;
    static constexpr const uintptr_t endGame = 0x1EC500;
    static constexpr const uintptr_t AddLight = 0x1ECB20;
    static constexpr const uintptr_t CreateActor = 0x2C0D50;
    static constexpr const uintptr_t DisplayText = 0x2494A0;
    static constexpr const uintptr_t DisplayTextLegacy = 0x2A6C90;
	static constexpr const uintptr_t gLocalHero_STEAM = 0x2322AD8;
    static constexpr const uintptr_t money = 0x1CADCB0;
    static constexpr const uintptr_t static_slewModeChangedCallback = 0x1F9D50;

    //--------------CGhostbuster-----------------

    //--------------CGameView--------------------
    static constexpr const uintptr_t gMainView = 0xDCF988;
    static constexpr const uintptr_t impactCamera = 0x1FF5B0;
    static constexpr const uintptr_t shakeCamera = 0x1FF510;
    static constexpr const uintptr_t setCameraModeOrbit = 0x1FF800;
    static constexpr const uintptr_t resetCamera = 0x1FE7A0;

    //--------------CGameView--------------------
    static constexpr const uintptr_t setAnimation = 0x77440;
    static constexpr const uintptr_t startTalking = 0x75BB0;
    static constexpr const uintptr_t beginWalkTo = 0x7DBB0;
/*
#elif EGS_VER
    static constexpr const uintptr_t Init1 = 0x243740;
    static constexpr const uintptr_t PlayerInit1 = 0xC3090;
    static constexpr const uintptr_t GlobalRegisterFunc1 = 0x2ceb10;
    static constexpr const uintptr_t Interact1 = 0x3B16F0;
    static constexpr const uintptr_t LevelLoader = 0x2DD630;
    static constexpr const uintptr_t Error1 = 0x2D0FD0;
    static constexpr const uintptr_t Register1 = 0x2CF090;
    static constexpr const uintptr_t commitSuicide = 0xCE560;
    static constexpr const uintptr_t setHealth = 0xD0280;
    static constexpr const uintptr_t slimeMe = 0xD0F50;
    static constexpr const uintptr_t mountProtonPack = 0xE4710;
    static constexpr const uintptr_t requestDeployTrap = 0xEC5A0;
    static constexpr const uintptr_t forceDeployTrapAt = 0xE4C80;
    static constexpr const uintptr_t startFakePackOverheat = 0xDD090;
    static constexpr const uintptr_t fakePossession = 0xEC1E0;
    static constexpr const uintptr_t requestTorpedo = 0xEC540;
    static constexpr const uintptr_t enableProtonTorpedo = 0xE6250;
    static constexpr const uintptr_t fakeFireProtonGun = 0xE9060;
    static constexpr const uintptr_t fakeFireIceStream = 0xE90E0;
    static constexpr const uintptr_t fakeFireShotgun = 0xE9160;
    static constexpr const uintptr_t getBodyVel = 0x2C15D0;
    static constexpr const uintptr_t reviveSquadmates = 0xD0E00;
    static constexpr const uintptr_t newActor = 0x2C0B60;
    static constexpr const uintptr_t canFireProtonTorpedo = 0xE6260;
    static constexpr const uintptr_t isTrapDeployed = 0xDE370;
    static constexpr const uintptr_t isPackOverheated = 0xEA6D0;
    static constexpr const uintptr_t isPackAboutToOverheat = 0xEA6F0;
    static constexpr const uintptr_t isHealthy = 0xD05A0;
    static constexpr const uintptr_t isProtonBeamActive = 0xE6170;
    static constexpr const uintptr_t setNothingEquipped = 0xE45A0;
    static constexpr const uintptr_t knockBack = 0xED100;
    static constexpr const uintptr_t setTeam = 0x15B20;
    static constexpr const uintptr_t getTeam = 0x16C90;
    static constexpr const uintptr_t quitLevel = 0x1F80B0;
    static constexpr const uintptr_t restartLevel = 0x1F80C0;
    static constexpr const uintptr_t cancelWalkToOnAllCharacters = 0x1F80F0;
    static constexpr const uintptr_t setCurrentObjective = 0x1F8140;
    static constexpr const uintptr_t defineCheckpoint = 0x1F8110;
    static constexpr const uintptr_t saveCheckpoint = 0x1F8100;
    static constexpr const uintptr_t loadCheckpoint = 0x1F8130;
    static constexpr const uintptr_t endGame = 0x1F8000;
    static constexpr const uintptr_t setGravity = 0x1F81E0;
    static constexpr const uintptr_t resetGravity = 0x1F8220;
    static constexpr const uintptr_t displayDemoSplashScreen = 0x1F8270;
    static constexpr const uintptr_t getBuildDescription = 0x1F8370;
    static constexpr const uintptr_t display = 0x1F7F30;
    static constexpr const uintptr_t displayGhostViewer = 0x1F82A0;
    static constexpr const uintptr_t notifyNewEquipmentAvailable = 0x1F8310;
    static constexpr const uintptr_t playerHasArtifact = 0x1F8010;
    static constexpr const uintptr_t setDisplayColor = 0x1F7f50;
    static constexpr const uintptr_t AddLight = 0x1F8150;
    static constexpr const uintptr_t chainToLevel = 0x1F80D0;
    static constexpr const uintptr_t createExplosion = 0x1E9170;
    static constexpr const uintptr_t createClass = 0x2D5130;
    static constexpr const uintptr_t setFollowActor = 0x7F9b0;
    static constexpr const uintptr_t pickup = 0x7D600;
    static constexpr const uintptr_t constructSScriptWalkInfo = 0x84700;
    static constexpr const uintptr_t beginWalkTo = 0x7F970;
    static constexpr const uintptr_t setFlashlightMode = 0xE3C10;
    static constexpr const uintptr_t getFlashlightMode = 0xE3C30;
    static constexpr const uintptr_t warpTo = 0x2C4330;
    static constexpr const uintptr_t warpToActor = 0x2C42C0;
    static constexpr const uintptr_t freezeAI = 0x7F8E0;
    static constexpr const uintptr_t setAnimation = 0x77440;
    static constexpr const uintptr_t setInvulnerable = 0x7B4E0;
    static constexpr const uintptr_t getPlayingAnimation = 0x30EDF0;
    static constexpr const uintptr_t isDead = 0x7B170;
    static constexpr const uintptr_t isPossessed = 0x7A930;
    static constexpr const uintptr_t setGoggleLocation = 0xD50E0;
    static constexpr const uintptr_t isProtonBeamInFreezeMode = 0xE6220;
    static constexpr const uintptr_t isProtonBeamInBurstMode = 0xE61C0;
    static constexpr const uintptr_t flinch = 0xD18B0;
    static constexpr const uintptr_t enable = 0x2DA150;
    static constexpr const uintptr_t gGameBase = 0x227A770;
    static constexpr const uintptr_t DisplayText = 0x2533C0;
    

    static constexpr const uintptr_t money = 0x1CADCB0; // OUTDATED!!
    static constexpr const uintptr_t slew = 0x1F9C90;
    */
#endif
}