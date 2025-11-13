#pragma once
#include <cstdint>

namespace CCharacter
{
	struct CCharacter
	{
		//placeholder :)
	};

	void setAnimation(CCharacter* actor, const char* animationName, bool useSkelFileExit);
	float startTalking(CCharacter* actor, const char* dbEntryTag);
}