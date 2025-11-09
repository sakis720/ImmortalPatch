#include <iostream>
#include <windows.h>
#define STR_(X) #X
#define IP v0.01
#define STR(X) STR_(X)

extern bool runprogram;
extern char* gameBase;

DWORD WINAPI DLLAttach(HMODULE hModule);