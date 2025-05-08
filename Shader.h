#pragma once

#include <d3d12.h>
#include <string>

class Shader {
public:
	// シェーダーファイルを読み込み、コンパイル済みデータを生成する
	void Load(const std::wstring& filePath, const std::string& ShaderModel);

	// 生成したコンパイル済みデータを取得する
	ID3DBlob* GetBlob();

	// コンストラクタ
	Shader();
	// デストラクタ
	~Shader();

private:
	ID3DBlob* blob_ = nullptr;
};