#include <iostream>  
#include "CGhostbuster.h"  
#include "Offsets.h"  
#include "../main.h"  

CGhostbuster* flinch(CGhostbuster* actor)
{
    using flinch_t = CGhostbuster*(*)(CGhostbuster*);
    static flinch_t flinch_Func = reinterpret_cast<flinch_t>(gameBase + Offsets::flinch);
	return flinch_Func(actor);
}


/*
CGhostbuster* getLocalPlayer()
{
    CGhostbuster* playerSteam =
        *reinterpret_cast<CGhostbuster**>(gameBase + Offsets::gLocalHero_STEAM);

    uint64_t ptrVal = reinterpret_cast<uint64_t>(playerSteam);

    if (ptrVal == 0x64656E7261452079ULL)
    {
        //std::cout << "Steam offset invalid (Epic detected), using EGS offset" << std::endl;

        CGhostbuster* playerEGS =
            *reinterpret_cast<CGhostbuster**>(gameBase + Offsets::gLocalHero_EGS);

        //std::cout << "Local Player Address (EGS): " << playerEGS << std::endl;
        return playerEGS;
    }

    //std::cout << "Local Player Address (Steam): " << playerSteam << std::endl;
    return playerSteam;
}

CGhostbuster* GetPosition(CGhostbuster* instance)  
{  
   if (instance)  
   { 
	   std::cout << "Ghostbuster Position - X: " << instance->posX << " Y: " << instance->posY << " Z: " << instance->posZ << std::endl;
   }  
   else
   {
	   std::cout << "Invalid CGhostbuster instance." << std::endl;
   }
   return nullptr;  
}
*/