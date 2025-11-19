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

	float startTalking(CCharacter* actor, const char* dbEntryTag)
	{
		using startTalking_t = float (*)(CCharacter*, const char*);
		static startTalking_t startTalking_Func = reinterpret_cast<startTalking_t>(gameBase + Offsets::startTalking);
		return startTalking_Func(actor, dbEntryTag);
	}
	/*
	int beginWalkTo(CCharacter* actor, SScriptWalkInfo* info, bool flushQueue)
	{
		using beginWalkTo_t = int (*)(CCharacter*, SScriptWalkInfo*, bool);
		static beginWalkTo_t beginWalkTo_Func = reinterpret_cast<beginWalkTo_t>(gameBase + Offsets::beginWalkTo);
		return beginWalkTo_Func(actor, info, flushQueue);
	}
	*/
}