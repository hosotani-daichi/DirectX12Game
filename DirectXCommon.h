#pragma once
#include"WinApp.h"
#include<d3d12.h>
#include<dxgi1_6.h>
#include<wrl.h>
#include<string>
#include<array>
#include<dxcapi.h>
#include<chrono>
#include<thread>
#include"externals/DirectXTex/DirectXTex.h"
class WinApp;

class DirectXCommon
{
public://メンバ変数
	//初期化
	void Initialize(WinApp* winApp);

	Microsoft::WRL::ComPtr<ID3D12Resource>CreateDepthStencilTextureResource(ID3D12Device* device, int32_t width, int32_t height);
	Microsoft::WRL::ComPtr<IDxcBlob>CompileShader(
		//CompilerするShaderファイルへのパス
		const std::wstring& filePath,
		//Compilerに使用するProfile
		const wchar_t* profile);

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> CreateDescriptorHeap(D3D12_DESCRIPTOR_HEAP_TYPE heapType, UINT numDescriptors, bool shaderVisible);
	Microsoft::WRL::ComPtr <ID3D12Resource> CreateBufferResource(Microsoft::WRL::ComPtr <ID3D12Device> device, size_t sizeInBytes);
	Microsoft::WRL::ComPtr<ID3D12Resource>CreateTextureResource(ID3D12Device* device, const DirectX::TexMetadata& metadata);
	//DSV用のヒープでディスクリプタの数１。DSVはshader内で触るものではないので、ShaderVisibleはfalse
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvDescriptorHeap;/* = CreateDescriptorHeap(device.Get(), D3D12_DESCRIPTOR_HEAP_TYPE_DSV, 1, false)*/;

	ID3D12Device* GetDevice() { return device.Get(); };
	ID3D12GraphicsCommandList* GetCommandList()const { return commandList.Get(); }
	//描画前処理
	void PreDraw();
	//描画後処理
	void PostDraw();

	//フェンス値
	UINT64 fenceVal = 0;

	//SRV専用のデスクリプタハンドル取得関数を作成する。
	D3D12_CPU_DESCRIPTOR_HANDLE GetSRVCPUDescriptorHandle(uint32_t index);//SRV用
	D3D12_GPU_DESCRIPTOR_HANDLE GetSRVGPUDescriptorHandle(uint32_t index);

	D3D12_CPU_DESCRIPTOR_HANDLE GetRTVCPUDescriptorHandle(uint32_t index);//RTV用
	D3D12_GPU_DESCRIPTOR_HANDLE GetRTVGPUDescriptorHandle(uint32_t index);

	D3D12_CPU_DESCRIPTOR_HANDLE GetDSVCPUDescriptorHandle(uint32_t index);//DSV用
	D3D12_GPU_DESCRIPTOR_HANDLE GetDSVGPUDescriptorHandle(uint32_t index);

	void UploadTextureData(ID3D12Resource* texture, const DirectX::ScratchImage& mipImages);

	HANDLE fenceEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

private://関数

	//デバイスの生成
	void Device();
	//void CreateDevice();
	//コマンド関連の生成
	void CreateCommand();
	//スワップチェーンの生成
	void CreateSwapChain();
	//深度バッファの生成
	void DepthCreateBufferView();
	//各種デスクリプタヒープの生成
	void CreateAllDescriptorHeap();
	//レンダーターゲットビューの初期化
	void RTVInitialize();
	//深度ステンシルビューの初期化
	void StencilInitialize();
	//フェンスの生成
	void CreateFence();
	//ビューポート矩形の初期化
	void ViewPortInitilize();
	//シザリング矩形の生成
	void CreateSizaling();
	//DCXコンパイラの生成
	void CreateDCX();
	//ImGuiの初期化
	void ImGuiInitilize(WinApp* winApp);

	////FPS固定初期化
	//void InitializeFixFPS();
	////FPS固定更新
	//void UpdateFixFPS();

	HRESULT hr{};

	//WindosAPI
	WinApp* winApp_ = nullptr;

	////記録時間(FPS固定用)
	//std::chrono::steady_clock::time_point reference_;

	//DirectX12デバイス
	Microsoft::WRL::ComPtr<ID3D12Device> device = nullptr;
	//DXGIファクトリ
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory = nullptr;

	//SwapChainからresourceを引っ張ってくる

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvDescriptorHeap = nullptr;

	//Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvDescriptorHeap;

	Microsoft::WRL::ComPtr <IDxcUtils> dxcUtils = nullptr;
	Microsoft::WRL::ComPtr <IDxcCompiler3> dxCompiler = nullptr;
	Microsoft::WRL::ComPtr <IDxcIncludeHandler> includeHander = nullptr;

	//デスクリプタハンドル取得関数の移植
	static D3D12_CPU_DESCRIPTOR_HANDLE GetCPUDescriptorHandle(const Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>& descriptorHeap, uint32_t descriptorSize, uint32_t index);
	static D3D12_GPU_DESCRIPTOR_HANDLE GetGPUDescriptorHandle(const Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>& descriptorHeap, uint32_t descriptorSize, uint32_t index);

	static DirectX::ScratchImage LoadTexture(const std::string& filePath);

	uint32_t desriptorSizeSRV = 0;
	uint32_t desriptorSizeRTV = 0;
	uint32_t desriptorSizeDSV = 0;

	//初期値０でFenceを作る
	Microsoft::WRL::ComPtr<ID3D12Fence> fence = nullptr;

	//スワップチェーンを生成する
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};

	//RTVの設定
	D3D12_RENDER_TARGET_VIEW_DESC rtvDesc{};

	//スワップチェーンの生成
	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain = nullptr;
	//スワップチェーンリソース
	std::array<Microsoft::WRL::ComPtr<ID3D12Resource>, 2>swapChainResources;

	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList = nullptr;

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> srvDescriptorHeap = nullptr;

	D3D12_CPU_DESCRIPTOR_HANDLE rtvHandles[2]{};

	uint64_t fenceValue = 0;

	//ビューポート
	D3D12_VIEWPORT viewport{};
	//シザー四角形
	D3D12_RECT scissorRect{};
	//コマンド関連の初期化
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue = nullptr;
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator = nullptr;
	DirectX::ScratchImage mipImages{};
	const DirectX::TexMetadata& metadata = mipImages.GetMetadata();

	Microsoft::WRL::ComPtr <ID3D12Resource> textureResource = CreateTextureResource(GetDevice(), metadata);

	D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc{};

	Microsoft::WRL::ComPtr <ID3D12DescriptorHeap> descriptorHeap = nullptr;

	Microsoft::WRL::ComPtr <IDXGIAdapter4> useAdapter = nullptr;
	Microsoft::WRL::ComPtr <ID3D12InfoQueue> infoQueue = nullptr;
	Microsoft::WRL::ComPtr<IDxcBlobEncoding> shaderSource = nullptr;
	Microsoft::WRL::ComPtr<IDxcResult> shaderResult = nullptr;
	Microsoft::WRL::ComPtr<IDxcBlobUtf8> shaderError = nullptr;
	Microsoft::WRL::ComPtr<IDxcBlob> shaderBlob = nullptr;
	Microsoft::WRL::ComPtr <ID3D12Resource> resource = nullptr;
};