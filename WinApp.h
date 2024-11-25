#include <Windows.h>

#pragma once
class WinApp
{
public:
	static const int32_t kCLientWidth = 1280;
	static const int32_t kCLientHeight = 720;

public://�Î⃁���o�֐�
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public://�����o�֐�
	//������
	void Initialize();
	//�X�V
	void Update();
	//�I��
	void Finalize();

private:
	//�E�B���h�E�n���h��
	HWND hwnd = nullptr;

	//getter
	HWND GetHwnd() const { return hwnd; }
	HINSTANCE GetHInstance() const { return wc.hInstance; }

	//�E�B���h�E�N���X�̐ݒ�
	WNDCLASS wc{};
	//���b�Z�[�W�̏���
	bool ProcessMessage();
};

