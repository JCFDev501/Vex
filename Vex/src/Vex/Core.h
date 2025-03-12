#pragma once

#ifdef VEX_PLATFORM_WINDOWS
    #ifdef VEX_BUILD_DLL
        #define  VEX_API __declspec(dllexport)
    #else
        #define  VEX_API __declspec(dllimport)
    #endif
#else
    #error Vex only supports windows!
#endif
