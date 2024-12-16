#include "Input.h"
#include <cassert>
//#include <wrl.h>
//#define DIRECTINPUT_VERSION     0x0800
//#include <dinput.h>

#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")

//using namespace Microsoft::WRL;

void Input::Initialize(WinApp* winApp)
{
	HRESULT result;

	//DirectInputのインスタンス生成
	ComPtr<IDirectInput8>directInput = nullptr;
	result = DirectInput8Create(winApp->GetHInstance(), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
	assert(SUCCEEDED(result));

	//キーボードデバイス生成
	//ComPtr<IDirectInputDevice8>keyboard;
	result = directInput->CreateDevice(GUID_SysKeyboard,&keyboard, NULL);
	assert(SUCCEEDED(result));

	//入力データ形式のセット
	result = keyboard->SetDataFormat(&c_dfDIKeyboard);
	assert(SUCCEEDED(result));

	//排他制御レベルのセット
	result = keyboard->SetCooperativeLevel(winApp->GetHwnd(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEEDED(result));

	//借りてきたWinAppのインスタンスを記録
	this->winApp=winApp;

}

void Input::Update()
{

	//前回のキー入力を保存
	memcpy(keyPre, key, sizeof(key));

	////キーボード情報の取得開始
	keyboard->Acquire();
	////全キーの入力情報を取得する
	//BYTE key[256] = {};
	keyboard->GetDeviceState(sizeof(key), key);
}

bool Input::PushKey(BYTE keyNumber)
{
	//指定キーを押していればtrueを返す
	if (key[keyNumber]) {
		return true;
	}
	return false;
}

bool Input::Triggerkey(BYTE keyNumber)
{
	//指定キーを押していればtrueを返す
	if (keyPre[keyNumber]!=0&& keyPre[keyNumber]==0) {
		return true;
	}

	return false;
}
