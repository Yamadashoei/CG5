#include "WorldTransformEx.h"

using namespace KamataEngine;
using namespace KamataEngine::MathUtility;

// Scale, Rotation, and Translate行列からWorld 行列を計算
// そして定数バッファの転送も行う
void WorldTransformEx::UpdateMatrix() {
	// World変換行列を計算し、matWorld_に格納する
	matWorld_ = MakeAffineMatrix();
	// 定数バッファに転送する
	TransferMatrix();
}

Matrix4x4 WorldTransformEx::MakeAffineMatrix() {
	// Scale Matrixを作成
	Matrix4x4 matScale = MakeScaleMatrix(scale_);

	// Rotation Matrixを作成
	Matrix4x4 matRotX = MakeRotateXMatrix(rotation_.x);
	Matrix4x4 matRotY = MakeRotateYMatrix(rotation_.y);
	Matrix4x4 matRotZ = MakeRotateZMatrix(rotation_.z);
	Matrix4x4 matRot = matRotX * matRotY * matRotZ;

	// Translation Matrixを作成
	Matrix4x4 matTrans = MakeTranslateMatrix(translation_);

	// Wolrd Matrixを計算
	Matrix4x4 matWorld = matScale * matRot * matTrans;

	return matWorld;
}
