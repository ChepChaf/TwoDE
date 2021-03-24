#pragma once

#ifdef TWODE_DLL
#define TWO_DLL __declspec(dllexport) 
#else
#define TWO_DLL __declspec(dllimport) 
#endif