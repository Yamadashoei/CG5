#include "Shader.h"
#include <cassert>
#include <d3dcompiler.h>

void Shader::Load(const std::wstring& filePath, const std::string& ShaderModel) {
	ID3DBlob* shaderBlob = nullptr;
	ID3DBlob* errorBlob = nullptr;

	HRESULT hr =
	    D3DCompileFromFile(filePath.c_str(), nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", ShaderModel.c_str(), D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, 0, &shaderBlob, &errorBlob);

	// エラーが発生した場合、止める
	if (FAILED(hr)) {
		if (errorBlob) {
			OutputDebugStringA(reinterpret_cast<char*>(errorBlob->GetBufferPointer()));
			errorBlob->Release();
		}
		assert(false);
	}
	// 生成したShaderBlobを返す
	blob_ = shaderBlob;
}

ID3DBlob* Shader::GetBlob() { return blob_; }

Shader::Shader() {}

Shader::~Shader() {
	if (blob_ != nullptr) {
		blob_->Release();
		blob_ = nullptr;
	}
}