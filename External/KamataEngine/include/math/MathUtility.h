#pragma once

#include "Matrix4x4.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace KamataEngine {

namespace MathUtility {

const float PI = 3.141592654f;

// 単項演算子オーバーロード
Vector2 operator+(const Vector2& v);
Vector2 operator-(const Vector2& v);

// 代入演算子オーバーロード
Vector2& operator+=(Vector2& lhv, const Vector2& rhv);
Vector2& operator-=(Vector2& lhv, const Vector2& rhv);
Vector2& operator*=(Vector2& v, float s);
Vector2& operator/=(Vector2& v, float s);

// 零ベクトルを返す
const Vector2 Vector2Zero();

// ノルム(長さ)を求める
float Length(const Vector2& v);

// 単項演算子オーバーロード
Vector3 operator+(const Vector3& v);
Vector3 operator-(const Vector3& v);

// 代入演算子オーバーロード
Vector3& operator+=(Vector3& lhv, const Vector3& rhv);
Vector3& operator-=(Vector3& lhv, const Vector3& rhv);
Vector3& operator*=(Vector3& v, float s);
Vector3& operator/=(Vector3& v, float s);

// 2項演算子オーバーロード
const Vector3 operator+(const Vector3& v1, const Vector3& v2);
const Vector3 operator-(const Vector3& v1, const Vector3& v2);
const Vector3 operator*(const Vector3& v, float s);
const Vector3 operator*(float s, const Vector3& v);
const Vector3 operator/(const Vector3& v, float s);

// 零ベクトルを返す
const Vector3 Vector3Zero();

// 2ベクトルが一致しているか調べる
bool Equal(const Vector3& v1, const Vector3& v2);
// ノルム(長さ)を求める
float Length(const Vector3& v);
// 正規化する
Vector3& Normalize(Vector3& v);
// 内積を求める
float Dot(const Vector3& v1, const Vector3& v2);
// 外積を求める
Vector3 Cross(const Vector3& v1, const Vector3& v2);

// 零ベクトルを返す
const Vector4 Vector4Zero();

// 代入演算子オーバーロード
Matrix4x4& operator*=(Matrix4x4& lhm, const Matrix4x4& rhm);

// 単位行列を求める
Matrix4x4 MakeIdentityMatrix();
// 転置行列を求める
Matrix4x4 Transpose(const Matrix4x4& m);
// 逆行列を求める
Matrix4x4 Inverse(const Matrix4x4& m, float* det = nullptr);

// 拡大縮小行列の作成
Matrix4x4 MakeScaleMatrix(const Vector3& scale);

// 回転行列の作成
Matrix4x4 MakeRotateXMatrix(float angle);
Matrix4x4 MakeRotateYMatrix(float angle);
Matrix4x4 MakeRotateZMatrix(float angle);

// 平行移動行列の作成
Matrix4x4 MakeTranslateMatrix(const Vector2& translate);
Matrix4x4 MakeTranslateMatrix(const Vector3& translate);

// ビュー行列の作成
Matrix4x4 Matrix4LookAtLH(const Vector3& eye, const Vector3& target, const Vector3& up);
// 並行投影行列の作成
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);
// 透視投影行列の作成
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);

// 座標変換（w除算なし）
Vector3 Transform(const Vector3& v, const Matrix4x4& m);
// 座標変換（w除算あり）
Vector3 TransformCoord(const Vector3& v, const Matrix4x4& m);
// ベクトル変換
Vector3 TransformNormal(const Vector3& v, const Matrix4x4& m);

// 2項演算子オーバーロード
Matrix4x4 operator*(const Matrix4x4& m1, const Matrix4x4& m2);
Vector3 operator*(const Vector3& v, const Matrix4x4& m);

// 線形補間
float Lerp(float a, float b, float t);

} // namespace MathUtility

} // namespace KamataEngine
