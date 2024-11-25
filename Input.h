#include <Windows.h>
#include <wrl.h>
#define DIRECTINPUT_VERSION     0x0800
#include <dinput.h>
#include "WinApp.h"

#pragma once
class Input
{
public:
	//namespace省略
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

public:
	//初期化
	void initialize(WinApp* winApp);

	//更新
	void Update();	

private://メンバ変数
	//キーボードのデバイス
	//ComPtr<IDirectInputDevice8> keyboard;

	bool PushKey(BYTE keyNumber);
	bool Triggerkey(BYTE keyNumber);
	//全キーの入力情報を取得する
	BYTE key[256] = {};
	//前回の全キーの状態
	BYTE keyPre[256] = {};

	ComPtr<IDirectInputDevice8>keyboard;
	ComPtr<IDirectInput8>directInput = nullptr;
	//WindowsAPI
	WinApp* winApp = nullptr;
};

