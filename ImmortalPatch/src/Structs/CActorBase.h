#pragma once
#include <cstdint>
#include "Types.h"

struct CActorBase
{
	//placeholder :)
};

CActorBase* enable(CActorBase* actor, bool flag);
CActorBase* warpTo(CActorBase* actor, Vector3 pos, Vector3 orient);