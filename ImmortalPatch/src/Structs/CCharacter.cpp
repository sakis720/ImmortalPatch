#include <iostream>  
#include "CCharacter.h"  
#include "Offsets.h"  
#include "../main.h"  

namespace CCharacter
{
	void setAnimation(CCharacter* actor, const char* animationName, bool useSkelFileExit)
	{
		using setAnimation_t = void (*)(CCharacter*, const char*, bool);
		static setAnimation_t setAnimation_Func = reinterpret_cast<setAnimation_t>(gameBase + Offsets::setAnimation);
		setAnimation_Func(actor, animationName, useSkelFileExit);
	}
}