#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include "WinApp.h"

#pragma once
class DirectXCommon
{
public://メンバ関数
	//初期化
	void Initialize(WinApp* winApp);
	void DeviceInitialize();
	void CommandAllocatorInitialize();
	void SwapChainGenelate();
	void BufferGenelate();
	void DescriptorHeapGenelate();
	void RTVInitialize();
	void DSVInitialize();
	void FenceInitialize();
	void ViewPortInitialize();
	void Rectangle();
	void DXCCompilerGenelate();
	void ImGuiInitialize();

private:
	//DirectX12デバイス
	Microsoft::WRL::ComPtr<ID3D12Device>device;
	//DXGIファクトリ
	Microsoft::WRL::ComPtr<IDXGIFactory7>dxgiFactory;
	//WindowsAPI
	WinApp* winApp = nullptr;
	///<summary>
	///デスクリプターヒープを生成する
	/// </summary>
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>CreateDescriptorHeap(D3D12_DESCRIPTOR_HEAP_TYPE heapType, UINT numDescriptors, bool shaderVisible);
	///<summary>
    ///指定番号のCPUデスクリプタハンドルを取得する
    /// </summary>
	static D3D12_CPU_DESCRIPTOR_HANDLE GetCPUDescriptorHandle(const Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>& descriptorHeap, uint32_t descriptorSize, uint32_t index);
	///<summary>
	///指定番号のGPUデスクリプタハンドルを取得する
	/// </summary>
	static D3D12_GPU_DESCRIPTOR_HANDLE GetGPUDescriptorHandle(const Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>& descriptorHeap, uint32_t descriptorSize, uint32_t index);
	///<summary>
    ///指定番号のGPUデスクリプタハンドルを取得する
    /// </summary>
	D3D12_CPU_DESCRIPTOR_HANDLE GetSRVCPUDescriptorHandle(uint32_t index);
	///<summary>
	///指定番号のGPUデスクリプタハンドルを取得する
	/// </summary>
	D3D12_GPU_DESCRIPTOR_HANDLE GetSRVGPUDescriptorHandle(uint32_t index);
	//スワップチェーンリソース
	std::array<Microsoft::WRL::ComPtr<ID3D12Resource>,2>swapChainResources;

};

