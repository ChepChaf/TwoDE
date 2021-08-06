#pragma once

# if defined(_WIN32) && !defined(__GNUC__)
    #ifdef TWODE_DLL
    #define TWO_DLL __declspec(dllexport)
    #else
    #define TWO_DLL __declspec(dllimport)
    #endif
# else
    #ifdef TWODE_DLL
    #define TWO_DLL __attribute__((visibility("default")))
    #else
    #define TWO_DLL
    #endif
#endif