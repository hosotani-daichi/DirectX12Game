#include <Windows.h>

#pragma once
class WinApp
{
public://�Î⃁���o�֐�
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public://�����o�֐�
	//������
	void Initialize();
	//�X�V
	void Update();
};

