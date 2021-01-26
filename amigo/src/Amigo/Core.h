#pragma once

#ifdef AMIGO_PLATFORM_WINDOWS
    #ifdef AMIGO_BUILD_DLL
        #define AMIGO_API __declspec(dllexport)
    #else
        #define AMIGO_API __declspec(dllimport)
    #endif
#else
    #error Amigo only supports Windows! 
#endif