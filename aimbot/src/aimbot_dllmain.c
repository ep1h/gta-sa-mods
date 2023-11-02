#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    (void)hinstDLL;
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
    {
        /* Init */
        break;
    }
    case DLL_PROCESS_DETACH:
    {
        if (!lpvReserved)
        {
            /* Destroy */
        }
        break;
    }
    default:
    {
        break;
    }
    }
    return TRUE;
}
