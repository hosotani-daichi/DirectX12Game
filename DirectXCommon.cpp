#include "DirectXCommon.h"
#include <cassert>

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")

using namespace Microsoft::WRL;


void DirectXCommon::Initialize(WinApp* winApp)
{

		//NULL検出
	assert(winApp);
	//メンバ変数に記録
	this->winApp = winApp;
}

void DirectXCommon::DeviceInitialize()
{
	HRESULT hr;

}

void DirectXCommon::CommandAllocatorInitialize() {

	//コマンドアロケータを生成する
	Microsoft::WRL::ComPtr <ID3D12CommandAllocator> commandAllocator = nullptr;
	//コマンドリストを生成する
	Microsoft::WRL::ComPtr <ID3D12GraphicsCommandList> commandList = nullptr;
	//コマンドキューを生成する
	Microsoft::WRL::ComPtr <ID3D12CommandQueue> commandQueue = nullptr;

}

void DirectXCommon::SwapChainGenelate() {

	//スワップチェーン生成の設定
	
	//スワップチェーンを生成する
	Microsoft::WRL::ComPtr <IDXGISwapChain4> swapChain = nullptr;
}

void DirectXCommon::BufferGenelate() {

	//深度バッファリソース設定
	//利用するヒープの設定
	//深度値のクリア設定
	//深度バッファ生成
	//リソースの生成
}

void DirectXCommon::DescriptorHeapGenelate() {

	//RTV用のDescriptorSizeを取得しておく
	//SRV用のDescriptorSizeを取得しておく
	//DSV用のDescriptorSizeを取得しておく

	//RTV用のデスクリプタヒープ生成
	//SRV用のデスクリプタヒープ生成
	//DSV用のデスクリプタヒープ生成
}

void DirectXCommon::RTVInitialize() {

	//裏表の2つ分
	for (uint32_t i = 0; i < RTVHandle; ++i) {
		//RTVハンドルを取得

		//レンダーターゲットビューの生成

	}
}

void DirectXCommon::DSVInitialize() {

	//DSV用の設定

	//DSVをデスクリプターヒープの先頭に作る
}

void DirectXCommon::FenceInitialize() {

	//フェンス生成
	Microsoft::WRL::ComPtr <ID3D12Fence> fence = nullptr;
}

void DirectXCommon::ViewPortInitialize() {

	//ビューポート矩形の設定
	D3D12_VIEWPORT viewport{};
}

void DirectXCommon::Rectangle() {

	//シザリング矩形の設定
}

void DirectXCommon::DXCCompilerGenelate() {

	//DXCユーティリティの生成
	//DXCコンパイラの生成

	//デフォルトインクルードハンドラの生成
}

void DirectXCommon::ImGuiInitialize() {

	//バーションチェック
	//コンテキストの生成
	//スタイルの設定
	//Win32用の初期化
	//DirectX12用の初期化
}

Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> DirectXCommon::CreateDescriptorHeap(D3D12_DESCRIPTOR_HEAP_TYPE heapType, UINT numDescriptors, bool shaderVisible)
{
	return Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>();
}

D3D12_CPU_DESCRIPTOR_HANDLE DirectXCommon::GetCPUDescriptorHandle(const Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>& descriptorHeap, uint32_t descriptorSize, uint32_t index)
{
	return D3D12_CPU_DESCRIPTOR_HANDLE();
}

D3D12_GPU_DESCRIPTOR_HANDLE DirectXCommon::GetGPUDescriptorHandle(const Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>& descriptorHeap, uint32_t descriptorSize, uint32_t index)
{
	return D3D12_GPU_DESCRIPTOR_HANDLE();
}

D3D12_CPU_DESCRIPTOR_HANDLE DirectXCommon::GetSRVCPUDescriptorHandle(uint32_t index)
{
	return GetCPUDescriptorHandle(srvDescriptorHeap, descriptorSizeSRV, index);
}

D3D12_GPU_DESCRIPTOR_HANDLE DirectXCommon::GetSRVGPUDescriptorHandle(uint32_t index)
{
	return D3D12_GPU_DESCRIPTOR_HANDLE();
}
