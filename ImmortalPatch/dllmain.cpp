// dllmain.cpp : Defines the entry point for the DLL application.
#include <windows.h>
#include <iostream>
#include "SaveFolderFix.h"
#include "Offsets.h"
#include "main.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved) {
    switch (reason) {
    case DLL_PROCESS_ATTACH:
        // Disable thread library calls for performance
        {
            HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)DLLAttach, hModule, 0, NULL);
            if (hThread != NULL) {
                CloseHandle(hThread);
            }
        }
        /*
        DisableThreadLibraryCalls(hModule);

        runprogram = true;
        SaveFix::CreateSaveFolder();
        */
        break;

    case DLL_PROCESS_DETACH:
        // Cleanup if needed
        break;
    }
    return TRUE;
}

