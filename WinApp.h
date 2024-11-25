#include <Windows.h>

#pragma once
class WinApp
{
public:
	static const int32_t kCLientWidth = 1280;
	static const int32_t kCLientHeight = 720;

public://静寂メンバ関数
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public://メンバ関数
	//初期化
	void Initialize();
	//更新
	void Update();
	//終了
	void Finalize();

private:
	//ウィンドウハンドル
	HWND hwnd = nullptr;

	//getter
	HWND GetHwnd() const { return hwnd; }
	HINSTANCE GetHInstance() const { return wc.hInstance; }

	//ウィンドウクラスの設定
	WNDCLASS wc{};
	//メッセージの処理
	bool ProcessMessage();
};

