#include <windows.h>
#include "aimbot.h"

BOOL APIENTRY DllMain(HMODULE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    (void)hinstDLL;
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
    {
        /* Init */
        aimbot_init();
        break;
    }
    case DLL_PROCESS_DETACH:
    {
        if (!lpvReserved)
        {
            /* Destroy */
        }
        aimbot_destroy();
        break;
    }
    default:
    {
        break;
    }
    }
    return TRUE;
}
