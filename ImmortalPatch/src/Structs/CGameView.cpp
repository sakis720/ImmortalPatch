#include <iostream>  
#include "CGameView.h"  
#include "Offsets.h"  
#include "Types.h"  
#include "../main.h"  

namespace CGameView
{
	void impactCamera(Vector3 dirMag, float hitDuration, float recoveryDuration)
	{
		uintptr_t CGameViewOffset = Offsets::gMainView;
		CGameView* CGameViewIn = *reinterpret_cast<CGameView**>(gameBase + CGameViewOffset);

		using impactCamera_t = void(*)(CGameView*, Vector3, float, float);
		static impactCamera_t impactCamera_Func = reinterpret_cast<impactCamera_t>(gameBase + Offsets::impactCamera);
		impactCamera_Func(CGameViewIn, dirMag, hitDuration, recoveryDuration);
	}

	void shakeCamera(float strength, float duration, float rampUpTime, float rampDownTime, float speed)
	{
		uintptr_t CGameViewOffset = Offsets::gMainView;
		CGameView* CGameViewIn = *reinterpret_cast<CGameView**>(gameBase + CGameViewOffset);

		using shakeCamera_t = void(*)(CGameView*, float, float, float, float, float);
		static shakeCamera_t shakeCamera_Func = reinterpret_cast<shakeCamera_t>(gameBase + Offsets::shakeCamera);
		shakeCamera_Func(CGameViewIn, strength, duration, rampUpTime, rampDownTime, speed);
	}

	void setCameraModeOrbit(CActor::CActor* followTarget, float radius, float rps, float targetHeightPct, float offsetHeight, float transitionTime, float orbitDuration)
	{
		uintptr_t CGameViewOffset = Offsets::gMainView;
		CGameView* CGameViewIn = *reinterpret_cast<CGameView**>(gameBase + CGameViewOffset);

		using setCameraModeOrbit_t = void(*)(CGameView*, CActor::CActor*, float, float, float, float, float, float);
		static setCameraModeOrbit_t setCameraModeOrbit_Func = reinterpret_cast<setCameraModeOrbit_t>(gameBase + Offsets::setCameraModeOrbit);
		setCameraModeOrbit_Func(CGameViewIn, followTarget, radius, rps, targetHeightPct, offsetHeight, transitionTime, orbitDuration);
	}

	void resetCamera()
	{
		uintptr_t CGameViewOffset = Offsets::gMainView;
		CGameView* CGameViewIn = *reinterpret_cast<CGameView**>(gameBase + CGameViewOffset);

		using resetCamera_t = void(*)(CGameView*);
		static resetCamera_t resetCamera_Func = reinterpret_cast<resetCamera_t>(gameBase + Offsets::resetCamera);
		resetCamera_Func(CGameViewIn);
	}
}