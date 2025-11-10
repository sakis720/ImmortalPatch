#include <iostream>  
#include "CGhostbuster.h"  
#include "Offsets.h"  
#include "../main.h"  

CGhostbuster::CGhostbuster* egon = 0;
CGhostbuster::CGhostbuster* winston = 0;
CGhostbuster::CGhostbuster* venkman = 0;
CGhostbuster::CGhostbuster* ray = 0;
CGhostbuster::CGhostbuster* localPlayer = 0;

namespace CGhostbuster
{
    CGhostbuster* flinch(CGhostbuster* actor)
    {
        using flinch_t = CGhostbuster * (*)(CGhostbuster*);
        static flinch_t flinch_Func = reinterpret_cast<flinch_t>(gameBase + Offsets::flinch);
        return flinch_Func(actor);
    }


    CGhostbuster* getLocalPlayer()
    {
        CGhostbuster* localplayer =
            *reinterpret_cast<CGhostbuster**>(gameBase + Offsets::gLocalHero_STEAM);
        //std::cout << "Local Player Address (Steam): " << localplayer << std::endl;
        return localplayer;
    }

    //Copied from IE17
    void getGhostbusters(char* Buffer, __int64 adr1)
    {
        if (!Buffer) {
            return;
        }
        if (strstr(Buffer, "CGhostbuster Egon") != nullptr) {
            egon = reinterpret_cast<CGhostbuster*>(adr1);
            //std::cout << "Egon Address: 0x" << std::hex << egon << std::endl;
        }
        if (strstr(Buffer, "CGhostbuster Winston") != nullptr) {
            winston = reinterpret_cast<CGhostbuster*>(adr1);
        }
        if (strstr(Buffer, "CGhostbuster Venkman") != nullptr) {
            venkman = reinterpret_cast<CGhostbuster*>(adr1);
        }
        else if (strstr(Buffer, "CGhostbuster Peter") != nullptr) {
            venkman = reinterpret_cast<CGhostbuster*>(adr1);
        }
        if (strstr(Buffer, "CGhostbuster Ray") != nullptr) {
            ray = reinterpret_cast<CGhostbuster*>(adr1);
        }
        else if (strstr(Buffer, "CGhostbuster RayPack") != nullptr) {
            ray = reinterpret_cast<CGhostbuster*>(adr1);
        }

        localPlayer = getLocalPlayer();
    }

    /*
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
}