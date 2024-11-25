#include <Windows.h>

#pragma once
class WinApp
{
public:
	const int32_t kClientWidth = 1280;
	const int32_t kClientHeight = 720;
public://静寂メンバ関数
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public://メンバ関数
	//初期化
	void Initialize();
	//更新
	void Update();
};

