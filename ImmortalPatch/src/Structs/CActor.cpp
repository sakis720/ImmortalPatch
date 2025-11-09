#include <iostream>  
#include "CActor.h"  
#include "Offsets.h"  
#include "../main.h"  


CActor* createActor(const char* actor, Vector3 wPos)
{
	using createActor_t = CActor * (*)(const char*, Vector3);
	static createActor_t createActor_Func = reinterpret_cast<createActor_t>(gameBase + Offsets::CreateActor);
	return createActor_Func(actor, wPos);
}