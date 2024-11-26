#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>

#pragma once
class DirectXCommon
{
public://メンバ関数
	//初期化
	void Initialize();
private:
	//DirectX12デバイス
	Microsoft::WRL::ComPtr<ID3D12Device>device;
	//DXGIファクトリ
	Microsoft::WRL::ComPtr<IDXGIFactory7>dxgiFactory;
};

