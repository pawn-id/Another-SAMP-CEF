#include <windows.h>
#include <iostream>
#include <fstream>
#include <thread>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    if(ul_reason_for_call !=  DLL_PROCESS_ATTACH)
        return TRUE;
    
    DisableThreadLibraryCalls(hModule);

    MessageBoxA(NULL, "Hello World", "Hello", MB_OK | MB_ICONINFORMATION);

    return TRUE;
}