#include <Windows.h>
#include <iostream>
#include "Offsets.h"
#include "./Structs/CGhostbuster.h"
#include "./Structs/CActorBase.h"
#include "./Structs/CActor.h"
#include "./Structs/Types.h"
#include "./Enums/EHud.h"
#include "main.h"


void DisplayText(int EHudMessage, const char* text, float duration)
{
	using DisplayText_t = void(*)(int, const char*, float);
	static DisplayText_t DisplayText_Func = reinterpret_cast<DisplayText_t>(gameBase + Offsets::DisplayText);
	DisplayText_Func(EHudMessage, text, duration);
}

void AddLight(Vector3 pos, float radius, Vector3 rgb, float intensity, float duration, float rampUp, float rampDown)
{
	using AddLight_t = void(*)(float, float, float, float, float, Vector3*);
	static AddLight_t AddLight_Func = reinterpret_cast<AddLight_t>(gameBase + Offsets::AddLight);
	AddLight_Func(rgb.x, rgb.y, rgb.z, intensity, radius, &pos);
}

void TestFunc()
{
    while (runprogram)
    {
        if (GetAsyncKeyState(VK_F1) & 1)
        {
        }
    }
}