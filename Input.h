#include <Windows.h>
#include <wrl.h>
#define DIRECTINPUT_VERSION     0x0800
#include <dinput.h>

#pragma once
class Input
{
public:
	//namespace省略
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

public:
	//初期化
	void initialize(HINSTANCE hInstance, HWND hwnd);

	//更新
	void Update();

private://メンバ変数
	//キーボードのデバイス
	ComPtr<IDirectInputDevice8> keyboard;

	bool PushKey(BYTE KeyNumber);
	bool Triggerkey(BYTE keyNumber);
	//全キーの入力情報を取得する
	BYTE key[256] = {};

};

