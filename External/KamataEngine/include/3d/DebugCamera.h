#pragma once
#include <3d\Camera.h>
#include <input\Input.h>

namespace KamataEngine {

/// <summary>
/// デバッグ用カメラ
/// </summary>
class DebugCamera {
	// カメラ注視点までの距離
	static const float distance_;

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="window_width">画面幅</param>
	/// <param name="window_height">画面高さ</param>
	DebugCamera(int window_width, int window_height);

	// 更新
	void Update();

	/// <summary>
	/// カメラを取得
	/// </summary>
	/// <returns>カメラ</returns>
	const Camera& GetCamera() { return camera_; }

	/// <summary>
	/// プロジェクション行列計算用のメンバ設定関数群
	/// </summary>
	void SetFovAngleY(float value) { camera_.fovAngleY = value; }
	void SetAspectRatio(float value) { camera_.aspectRatio = value; }
	void SetNearZ(float value) { camera_.nearZ = value; }
	void SetFarZ(float value) { camera_.farZ = value; }

private:
	// 入力クラスのポインタ
	Input* input_;
	// スケーリング
	float scaleX_ = 1.0f;
	float scaleY_ = 1.0f;
	// カメラ
	Camera camera_;
	// 回転行列
	Matrix4x4 matRot_;

	/// <summary>
	/// 行列更新
	/// </summary>
	void UpdateMatrix();
};

} // namespace KamataEngine