#include <iostream>  
#include "CGame.h"  
#include "Offsets.h"  
#include "../main.h"  

namespace CGame
{
	//Copied from IE17
    void enableDebug(bool enabled)
    {
        BYTE* debugFlag = reinterpret_cast<BYTE*>(gameBase + 0x20D4915);
        *debugFlag = enabled ? 1 : 0;
        CGame* debug = *reinterpret_cast<CGame**>(gameBase + Offsets::CGame);

        if (debug)
        {
            BYTE* secondFlag = reinterpret_cast<BYTE*>(reinterpret_cast<uintptr_t>(debug) + 0x1D8);
            *secondFlag = enabled ? 1 : 0;
        }
        else
        {
            std::cerr << "Pointer chain is null.\n";
        }
    }
    
}