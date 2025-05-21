#pragma once

#include <2d\DebugText.h>
#include <2d\ImGuiManager.h>
#include <2d\Sprite.h>

#include <3d\AxisIndicator.h>
#include <3d\Camera.h>
#include <3d\CircleShadow.h>
#include <3d\DebugCamera.h>
#include <3d\DirectionalLight.h>
#include <3d\LightGroup.h>
#include <3d\Material.h>
#include <3d\Mesh.h>
#include <3d\Model.h>
#include <3d\ObjectColor.h>
#include <3d\PointLight.h>
#include <3d\PrimitiveDrawer.h>
#include <3d\SpotLight.h>
#include <3d\Terrain.h>
#include <3d\TerrainCommon.h>
#include <3d\WorldTransform.h>

#include <audio\Audio.h>

#include <base\DirectXCommon.h>
#include <base\StringUtility.h>
#include <base\TextureManager.h>
#include <base\WinApp.h>

#include <input\Input.h>

#include <math\MathUtility.h>
#include <math\Matrix4x4.h>
#include <math\Vector2.h>
#include <math\Vector3.h>
#include <math\Vector4.h>

namespace KamataEngine {
/// <summary>
/// エンジンの初期化
/// </summary>
/// <param name="title">ウィンドウタイトル</param>
void Initialize(const std::wstring& title = L"LE2X_99_カマタ_タロウ");

/// <summary>
/// エンジンの終了処理
/// </summary>
void Finalize();

/// <summary>
/// エンジンの更新
/// </summary>
/// <returns>終了フラグ</returns>
bool Update();
} // namespace KamataEngine