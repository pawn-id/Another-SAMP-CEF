#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include <iostream>
#include <string>

HMODULE CEFLib = NULL;

std::string GetCurrentRunningDir(std::string removedString = "\\gta_sa.exe") {
    char path[2048];
    GetModuleFileNameA(NULL, path, 2048);
    std::string realPath = std::string(path);
    realPath.erase(realPath.end() - removedString.size(), realPath.end());
    return realPath;
}

DWORD WINAPI LibraryWaitingThread(LPVOID lpParam) noexcept {
    
    std::string path = GetCurrentRunningDir();
    if(path.empty()) {
        MessageBoxA(NULL, "What The Fuck? From Where you run this thread?", "Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    SetDllDirectoryA(path.c_str());
    path.append("\\cef\\client.dll");
    CEFLib = LoadLibraryA(path.c_str());
    if(CEFLib != NULL)
        return 0;
    else
        return 1;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) noexcept {
    if (ul_reason_for_call != DLL_PROCESS_ATTACH)
        return TRUE;

#if defined (DEBUG)
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    std::cout << "This works" << std::endl;
#endif  

    const auto waiting_thread = CreateThread
    (NULL, 0, LibraryWaitingThread, NULL, NULL, NULL);
    return waiting_thread != NULL ? TRUE : FALSE;
}