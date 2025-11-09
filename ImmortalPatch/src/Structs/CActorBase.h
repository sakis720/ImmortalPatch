#pragma once
#include <cstdint>
#include "Types.h"

struct CActorBase
{
	// fill with actual fields if known, or keep opaque but use pointers only
};

CActorBase* enable(CActorBase* actor, bool flag);
CActorBase* warpTo(CActorBase* actor, Vector3 pos, Vector3 orient);