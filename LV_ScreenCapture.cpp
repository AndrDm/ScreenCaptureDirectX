// Project1DLL.cpp : Defines the exported functions for the DLL.
//

#include "stdafx.h"
#include "capture.hpp"
#include <iostream>

#include "pch.h"
#include "framework.h"
#include "LV_ScreenCapture.h"


// This is an example of an exported variable
LV_SC_DLL_API int nProject1DLL = 0;

// This is an example of an exported function.
LV_SC_DLL_API int fnProject1DLL(void)
{
    return 0;
}
