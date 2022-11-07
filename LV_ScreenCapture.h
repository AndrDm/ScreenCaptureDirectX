#pragma once
#define LV_SC_DLL_EXPORTS
// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the PROJECT1DLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// PROJECT1DLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LV_SC_DLL_EXPORTS
#define LV_SC_DLL_API __declspec(dllexport)
#else
#define LV_SC_DLL_API __declspec(dllimport)
#endif


extern LV_SC_DLL_API int nProject1DLL;

LV_SC_DLL_API int fnProject1DLL(void);
