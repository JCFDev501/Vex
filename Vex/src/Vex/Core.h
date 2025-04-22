/*
* @file Core.h
 * @brief Defines the VEX_API macro for DLL export/import functionality.
 *
 * This header file ensures that symbols are properly exported when building 
 * the Vex Engine as a DLL and properly imported when using the DLL in other projects. 
 * It also restricts the engine to only compile on Windows platforms.
 *
 * Usage:
 * - Define VEX_PLATFORM_WINDOWS to indicate that the engine is being compiled on Windows.
 * - Define VEX_BUILD_DLL when building the Vex Engine as a dynamic library.
 * - When using the DLL, ensure VEX_BUILD_DLL is undefined to import symbols correctly.
 *
 * @note Vex Engine currently supports only Windows.
 */

#pragma once

// Ensure the platform is Windows
#ifdef VEX_PLATFORM_WINDOWS

    // Determine whether we are exporting or importing symbols for a DLL
    #ifdef VEX_BUILD_DLL
        #define VEX_API __declspec(dllexport) // Export symbols when building the DLL
    #else
        #define VEX_API __declspec(dllimport) // Import symbols when using the DLL
    #endif

#else
    // Compilation is restricted to Windows
    #error Vex only supports Windows!
#endif

#define BIT(x) (1 << x)

