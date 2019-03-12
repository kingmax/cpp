#pragma once

#ifdef __DLL_H__
#define MY_DLL_API __declspec(dllexport)
#else
#define MY_DLL_API __declspec(dllimport)
#endif


MY_DLL_API int Mul(int x, int y);
