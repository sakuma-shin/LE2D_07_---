#pragma once
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include"Input.h"
#include <cassert>
#include<numbers>
#include<algorithm>

class Player {
public:

	/*Player();

	~Player();*/
	///< summary>
	/// 初期化
	///</summary>
	void Initialize(Model* model,ViewProjection* viewprojection, const Vector3& position);

	///< summary>
	/// 更新
	///</summary>
	void Update();

	///< summary>
	/// 描画
	///</summary>
	void Draw();

	
private:

	enum class LRDirection { 
		kRight,
		kLeft,
	};

	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t texturehandle_ = 0u;

	
	ViewProjection* viewprojection_ = nullptr;

	Vector3 velocity_ = {};

	static inline const float kAcceleration = 0.05f;
	static inline const float kAttenuation = 0.05f;
	static inline const float kLimitSpeed = 8.0f;

	LRDirection lrDirection_ = LRDirection::kRight;
};
