#include <iostream>
#include <windows.h>
#include "main.h"
#include "SaveFolderFix.h"
#include "Offsets.h"

bool HaveConsole = true;
bool runprogram = true;

char* gameBase = nullptr;

DWORD WINAPI DLLAttach(HMODULE hModule)
{
    if (HaveConsole)
    {
        // Allocate console
        if (!AllocConsole()) {
            MessageBoxA(NULL, "Failed to allocate console.", "Error", MB_OK | MB_ICONERROR);
            return 0; // Abort injection
        }

        // Redirect console I/O
        if (freopen_s((FILE**)stdin, "CONIN$", "r", stdin) != 0 ||
            freopen_s((FILE**)stdout, "CONOUT$", "w", stdout) != 0) {
            MessageBoxA(NULL, "Failed to redirect console I/O.", "Error", MB_OK | MB_ICONERROR);
            FreeConsole();
            return 0; // Abort injection
        }


        // Set console title
        SetConsoleTitleA("ImmortalPatch(WIP) " STR(IP));

        // Print welcome message
        std::cout << "*************************** \n";
        std::cout << " ImmortalPatch is hooked! \n";
        std::cout << "*************************** \n";
        std::cout << "Version: " STR(IP) "\n";
    }

    gameBase = (char*)GetModuleHandle(NULL);

    //TestFunc();
	SaveFix::CreateSaveFolder();

    return 1;
}