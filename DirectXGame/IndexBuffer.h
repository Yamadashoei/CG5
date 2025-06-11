#pragma once
#include <d3d12.h>

class IndexBuffer {
public:
	// IndexBuffer生成
	void Create(const UINT size, const UINT stride);

	// ゲッター
	ID3D12Resource* Get();
	D3D12_INDEX_BUFFER_VIEW* GetView();

	// コンストラクタ
	IndexBuffer();
	// デストラクタ
	~IndexBuffer();

private:
	ID3D12Resource* indexBuffer_ = nullptr;
	D3D12_INDEX_BUFFER_VIEW indexBufferView_{};
};