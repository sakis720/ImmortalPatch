#include <iostream>  
#include "CGhostbuster.h"  
#include "CActorBase.h"  
#include "Offsets.h"  
#include "../main.h"  

CActorBase* enable(CActorBase* actor, bool flag)
{
    uintptr_t CBaseGame = Offsets::gGameBase;
    unsigned __int64 base = (unsigned __int64)(gameBase + CBaseGame);

    using enable_t = CActorBase*(*)(unsigned __int64, CActorBase*, bool);
    static enable_t enable_Func = reinterpret_cast<enable_t>(gameBase + Offsets::enable);
    return enable_Func(base, actor, flag);
}

CActorBase* warpTo(CActorBase* actor, Vector3 pos, Vector3 orient)
{
    using warpTo_t = CActorBase*(*)(CActorBase*, Vector3, Vector3);
    static warpTo_t warpTo_Func = reinterpret_cast<warpTo_t>(gameBase + Offsets::warpTo);
    return warpTo_Func(actor, pos, orient);
}