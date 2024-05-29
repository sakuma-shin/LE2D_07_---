#pragma once

#include "Matrix4x4.h"
#include "Vector3.h"
#include <d3d12.h>
#include <type_traits>
#include <wrl.h>
#include <math.h>

// 定数バッファ用データ構造体
struct ConstBufferDataWorldTransform {
	Matrix4x4 matWorld; // ローカル → ワールド変換行列
};

/// <summary>
/// ワールド変換データ
/// </summary>
class WorldTransform {
public:
	// ローカルスケール
	Vector3 scale_ = {1, 1, 1};
	// X,Y,Z軸回りのローカル回転角
	Vector3 rotation_ = {0, 0, 0};
	// ローカル座標
	Vector3 translation_ = {0, 0, 0};
	// ローカル → ワールド変換行列
	Matrix4x4 matWorld_;
	// 親となるワールド変換へのポインタ
	const WorldTransform* parent_ = nullptr;

	WorldTransform() = default;
	~WorldTransform() = default;

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();
	/// <summary>
	/// 定数バッファ生成
	/// </summary>
	void CreateConstBuffer();
	/// <summary>
	/// マッピングする
	/// </summary>
	void Map();
	/// <summary>
	/// 行列を転送する
	/// </summary>
	void TransferMatrix();
	/// <summary>
	/// 定数バッファの取得
	/// </summary>
	/// <returns>定数バッファ</returns>
	const Microsoft::WRL::ComPtr<ID3D12Resource>& GetConstBuffer() const { return constBuffer_; }
	void UpdateMatrix();

	// 積
	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
	
// 1.X軸回転行列
	Matrix4x4 MakeRotateXMatrix(float radian);

	// 2.Y軸回転行列
	Matrix4x4 MakeRotateYMatrix(float radian);

	// 3.Z軸回転行列
	Matrix4x4 MakeRotateZMatrix(float radian);

	// 回転行列の合成
	Matrix4x4 RotateXYZMatrix(const Vector3& radian);

	// 3次元アフィン変換行列
	Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);


private:
	// 定数バッファ
	Microsoft::WRL::ComPtr<ID3D12Resource> constBuffer_;
	// マッピング済みアドレス
	ConstBufferDataWorldTransform* constMap = nullptr;
	// コピー禁止
	WorldTransform(const WorldTransform&) = delete;
	WorldTransform& operator=(const WorldTransform&) = delete;
};

static_assert(!std::is_copy_assignable_v<WorldTransform>);