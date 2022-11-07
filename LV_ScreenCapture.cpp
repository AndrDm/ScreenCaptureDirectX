// Project1DLL.cpp : Defines the exported functions for the DLL.
//
#define _WIN32_DCOM
#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include "framework.h"
#include "LV_ScreenCapture.h"

#include "stdafx.h" //do not change order here
#include "capture.hpp"

// https://www.codeproject.com/Articles/5256890/ScreenCapture-Single-header-DirectX-library
static 	DESKTOPCAPTUREPARAMS LVdp;
int FrameCnt;

void FrameCallback()
{
	FrameCnt++;
}

LV_SC_DLL_API int GetFrameCnt()
{
	return FrameCnt;
}

LV_SC_DLL_API int LV_SetCaptureParams(char* path, int format, int duration, int width, int height, int monitor)
{
	LVdp.HasAudio = 0; //video only
	LVdp.cb = FrameCallback;
	LVdp.nOutput = monitor;
	LVdp.f = std::wstring(path, path + strlen(path));
	switch (format) { //only these supported
		case 0: default: LVdp.VIDEO_ENCODING_FORMAT = MFVideoFormat_HEVC; break;
		case 1: LVdp.VIDEO_ENCODING_FORMAT = MFVideoFormat_H264; break;
		case 2: LVdp.VIDEO_ENCODING_FORMAT = MFVideoFormat_VP80; break;
		case 3: LVdp.VIDEO_ENCODING_FORMAT = MFVideoFormat_VP90; break;
	};
	LVdp.EndMS = duration; //if 0 - until must end
	LVdp.rx.left = 0;
	LVdp.rx.top = 0;
	LVdp.rx.right = width;
	LVdp.rx.bottom = height;

	LVdp.MustEnd = false;

}


LV_SC_DLL_API int LV_StartCapture(char* path, int format)
{
	if FAILED(MFStartup(MF_VERSION)) return 5001;

	int ret = DesktopCapture(LVdp);

	return ret;
}

LV_SC_DLL_API int LV_StopCapture()
{
	LVdp.MustEnd = true;
//	int ret = DesktopCapture(LVdp);
	return 0;
}


// This is an example of an exported function.
LV_SC_DLL_API int RecordTest(char *path)
{
	char buf[256];
	OutputDebugStringA("Start");
	HRESULT ret = S_OK;
	//HRESULT ret = CoInitializeEx(0, COINIT_APARTMENTTHREADED);
	sprintf_s(buf, "CoInitializeEx - ret = %d", ret);
	//S_FALSE 	The COM library is already initialized on this thread.
	OutputDebugStringA(buf);
	ret = MFStartup(MF_VERSION);
	sprintf_s(buf, "MFStartup - ret = %d", ret);
	OutputDebugStringA(buf); //returned 0 - S_OK
	//std::cout << "Capturing screen for 10 seconds...";
	DESKTOPCAPTUREPARAMS dp;

	// To Video
	//dp.VIDEO_ENCODING_FORMAT = MFVideoFormat_H265;
	dp.VIDEO_ENCODING_FORMAT = MFVideoFormat_HEVC;
	//dp.VIDEO_ENCODING_FORMAT = MFVideoFormat_MJPG;
	dp.HasAudio = 0;
	//dp.f = L"C:\\TEMP\\LVcapture.mp4";
	dp.f = std::wstring(path, path + strlen(path));

	dp.EndMS = 10000;
	OutputDebugStringA("StartCapture");
	int ret1 = DesktopCapture(dp);
	sprintf_s(buf, "DesktopCapture - ret = %d", ret1);
	OutputDebugStringA(buf); //returned 0 - S_OK
	OutputDebugStringA("EndCapture");

	//std::cout << "Done.\r\n";

    return 0;
}
