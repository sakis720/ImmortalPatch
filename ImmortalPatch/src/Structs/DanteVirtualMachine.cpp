#include <iostream>  
#include "Offsets.h"  
#include "../main.h"  
#include "../include/MinHook/include/MinHook.h"
#include "DanteVirtualMachine.h"

//Copied code from IE17
bool DEBUG_MODE = false;

using ExportGlobalVariableType = void(*)(char*, __int64, __int64, __int64);

ExportGlobalVariableType exportGlobalVariable = nullptr;

namespace Logger {
    void logHookCall(char* buffer, __int64 adr1, __int64 adr2, __int64 adr3) {
        std::cout << "Buffer: " << (buffer ? buffer : "NULL") << "\n"
            << "  nativeAddress: 0x" << std::hex << adr1 << "\n"
            << "  program      : 0x" << std::hex << adr2 << "\n"
            << "  returnErrMsg : 0x" << std::hex << adr3 << "\n"
            << std::dec << std::endl;
    }
}

void __stdcall HookedFunction(char* buffer, __int64 adr1, __int64 adr2, __int64 adr3) {
    if (DEBUG_MODE) {
        Logger::logHookCall(buffer, adr1, adr2, adr3);

        if (!buffer) {
            std::cout << "Warning: Buffer is null!" << std::endl;
            return;
        }
    }

    if (exportGlobalVariable) {
        exportGlobalVariable(buffer, adr1, adr2, adr3);
    }
}

namespace HookManager {
    bool initialize() {
        return MH_Initialize() == MH_OK;
    }

    bool createAndEnableHook(void* target) {
        MH_STATUS status = MH_CreateHook(
            target,
            &HookedFunction,
            reinterpret_cast<LPVOID*>(&exportGlobalVariable)
        );

        if (status != MH_OK) {
            MessageBoxA(NULL, "Failed to create hook.", "Error", MB_OK | MB_ICONERROR);
            return false;
        }

        status = MH_EnableHook(target);
        if (status != MH_OK) {
            MessageBoxA(NULL, "Failed to enable hook.", "Error", MB_OK | MB_ICONERROR);
            return false;
        }

        return true;
    }

    void cleanup(void* target) {
        if (target) {
            MH_DisableHook(target);
        }
        MH_Uninitialize();
    }
}

namespace Dante
{
    void displayMessage(int EHudMessage, const char* text, float duration)
    {
        using DisplayText_t = void(*)(int, const char*, float);
        static DisplayText_t DisplayText_Func = reinterpret_cast<DisplayText_t>(gameBase + Offsets::DisplayText);
        DisplayText_Func(EHudMessage, text, duration);
    }
}