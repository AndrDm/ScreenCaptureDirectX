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


#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"wininet.lib")
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"bcrypt.lib")
#pragma comment(lib,"crypt32.lib")
#pragma comment(lib,"Comctl32.lib")
#pragma comment(lib,"Msacm32.lib")
#pragma comment(lib,"Mfplat.lib")
#pragma comment(lib,"mfreadwrite.lib")
#pragma comment(lib,"mfuuid.lib")
#pragma comment(lib, "strmiids.lib")
#pragma comment(lib, "windowscodecs.lib")
#pragma comment(lib, "propsys.lib")
#pragma comment(lib, "wmcodecdspuuid.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "gdiplus.lib")
#pragma comment(lib, "Mf.lib")
#pragma comment(lib, "dxgi.lib")

extern LV_SC_DLL_API int nProject1DLL;

LV_SC_DLL_API int RecordTest(void);
