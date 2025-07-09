#pragma once
#include "KamataEngine.h"

class WorldTransformEx : public KamataEngine::WorldTransform {

public:
	// Affine変換行列の生成と定数バッファへの転送行う
	void UpdateMatrix();

	// Affine変換行列の生成
	KamataEngine::Matrix4x4 MakeAffineMatrix();
};