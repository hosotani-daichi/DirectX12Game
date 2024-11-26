#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>

#pragma once
class DirectXCommon
{
public://�����o�֐�
	//������
	void Initialize();
private:
	//DirectX12�f�o�C�X
	Microsoft::WRL::ComPtr<ID3D12Device>device;
	//DXGI�t�@�N�g��
	Microsoft::WRL::ComPtr<IDXGIFactory7>dxgiFactory;
};

