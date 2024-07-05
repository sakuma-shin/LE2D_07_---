#pragma once
#define NOMINMAX
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <algorithm>
#include"Input.h"
#include <cassert>
#include<numbers>
#include"easing.h"

class Player {
public:

	/*Player();

	~Player();*/
	///< summary>
	/// 初期化
	///</summary>
	void Initialize(Model* model,uint32_t textureHandle,ViewProjection* viewProjection, const Vector3& position);

	///< summary>
	/// 更新
	///</summary>
	void Update();

	///< summary>
	/// 描画
	///</summary>
	void Draw();

	const WorldTransform& GetWorldTransform()const { return worldTransform_; };

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

	//旋回開始時の角度
	float turnFirstRotationY_ = 0.0f;
	//旋回タイマー
	float turnTimer_ = 0.0f;

	//旋回時間<秒>
	static inline const float kTimeTurn = 0.3f;

	bool onGround_ = true;

	static inline const float kGravityAcceleration = 0.05f;
	static inline const float kJumpAcceleration = 0.5f;
	static inline const float kLimitFallSpeed = 8.0f;
};
