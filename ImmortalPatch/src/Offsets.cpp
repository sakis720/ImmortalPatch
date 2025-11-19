#include <Windows.h>
#include <iostream>
#include "Offsets.h"
#include "./Structs/CGhostbuster.h"
#include "./Structs/CActorBase.h"
#include "./Structs/CActor.h"
#include "./Structs/CGame.h"
#include "./Structs/CCharacter.h"
#include "./Structs/CGameView.h"
#include "./Structs/DanteVirtualMachine.h"
#include "./Structs/Types.h"
#include "./Enums/EHud.h"
#include <optional>
#include "main.h"

void AddLight(Vector3 pos, float radius, Vector3 rgb, float intensity, float duration, float rampUp, float rampDown)
{
	using AddLight_t = void(*)(float, float, float, float, float, Vector3*);
	static AddLight_t AddLight_Func = reinterpret_cast<AddLight_t>(gameBase + Offsets::AddLight);
	AddLight_Func(rgb.x, rgb.y, rgb.z, intensity, radius, &pos);
}

void cacheEffect(const char** effectName)
{
    using cacheEffect_t = void(*)(const char**);
    static cacheEffect_t cacheEffect_Func = reinterpret_cast<cacheEffect_t>(gameBase + Offsets::cacheEffect);
    cacheEffect_Func(effectName);
}

void* startEffect(const char* effectName, Vector3 pos, Vector3 orient)
{
    using startEffect_t = void* (*)(const char*, Vector3, Vector3);
    static startEffect_t startEffect_Func = reinterpret_cast<startEffect_t>(gameBase + Offsets::startEffect);
	cacheEffect(&effectName);
    return startEffect_Func(effectName, pos, orient);
}

/*
void dbSay(std::optional<CCharacter::CCharacter*> speaker, CDialogDatabaseEntry tagID, bool subtitle = false)
{
    if (tagID.tag.ptr == nullptr)
    {
        std::cout << " * **ERROR - dbSay() Dialog Database Entry not found.No dialog played." << std::endl;
        return;
    }
    if (!speaker.has_value())
    {
		CGame::dbNarrative(tagID);
    }
    else
    {
		CCharacter::startTalking(speaker.value(), tagID.tag.ptr);
    }
}
*/

void TestFunc()
{
    while (runprogram)
    {
        if (GetAsyncKeyState(VK_F1) & 1)
        {
            /*
			const CDialogDatabaseEntry* findTag = Dante::findDialogEntryByTag("Diag_Egon_CEM_S_008");
            if (findTag)
            {
				std::cout << "tag found: " << findTag->tag.ptr << " - " << findTag->text.ptr << std::endl;
            }
            else
            {
				std::cout << "tag not found" << std::endl;
            }
            
            CDialogDatabaseEntry* entry = Dante::findDialogEntryByTag("diag_ray_gen_pu_026_a");
            if (entry)
            {
                CGame::dbNarrative(*entry);
				std::cout << "Found dialog entry: " << entry->tag.ptr << " - " << entry->text.ptr << std::endl;
            }
            else
            {
				std::cout << "Dialog entry not found." << std::endl;
            }
            //
            CDialogDatabaseEntry* entry = (CDialogDatabaseEntry*)testemmit;
            CGame::dbNarrative(*entry);
            */
            
        }
    }
}