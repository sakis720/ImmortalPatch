#include <iostream>  
#include "CGame.h"  
#include "Offsets.h"  
#include "Types.h"  
#include "../main.h"  

namespace CGame
{
	//Copied from IE17
    void enableDebug(bool enabled)
    {
        BYTE* debugFlag = reinterpret_cast<BYTE*>(gameBase + 0x20D4915);
        *debugFlag = enabled ? 1 : 0;
        CGame* debug = *reinterpret_cast<CGame**>(gameBase + Offsets::gGame);

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

    int slew()
    {
        using slew_callback_t = int(*)();
		static slew_callback_t slew_callback = reinterpret_cast<slew_callback_t>(gameBase + Offsets::static_slewModeChangedCallback);
		return slew_callback();
    }

    void dbNarrative(CDialogDatabaseEntry dbEntry)
    {
        using dbNarrative_t = void(*)(CDialogDatabaseEntry);
        static dbNarrative_t dbNarrative_Func = reinterpret_cast<dbNarrative_t>(gameBase + Offsets::dbNarrative);
		dbNarrative_Func(dbEntry);
    }
    
}