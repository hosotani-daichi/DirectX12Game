#include <Windows.h>

#pragma once
class WinApp
{
public:
	const int32_t kClientWidth = 1280;
	const int32_t kClientHeight = 720;
public://�Î⃁���o�֐�
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public://�����o�֐�
	//������
	void Initialize();
	//�X�V
	void Update();
};

