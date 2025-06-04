#pragma once

#include <d3dx12.h>

class PipelineState {
public:
	// 初期化
	void Create(D3D12_GRAPHICS_PIPELINE_STATE_DESC graphicsPipelineStateDesc);
	// ゲッター
	ID3D12PipelineState* Get();

	// コントラクタ
	PipelineState();
	// デストラクタ
	~PipelineState();

private:
	// パイプラインステート
	ID3D12PipelineState* pipelineState_ = nullptr;
};