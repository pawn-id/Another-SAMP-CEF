#include "main.h"

DWORD WINAPI LibraryWaitingThread(LPVOID lpParam) {
    HMODULE samp_module;
    while ((samp_module = GetModuleHandleA("samp.dll")) == nullptr)
        thread::sleep(100);
    MessageBoxA(NULL, "samp.dll has been loaded!", "samp-asi", MB_OK);
    
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call != DLL_PROCESS_ATTACH)
        return TRUE;

    const auto waiting_thread = CreateThread
    (NULL, 0, LibraryWaitingThread, NULL, NULL, NULL);
    return waiting_thread != NULL ? TRUE : FALSE;
}