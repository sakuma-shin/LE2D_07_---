#include "Player.h"

void Player::Initialize(Model* model, ViewProjection* viewprojection, const Vector3& position) {
	// NULLポインタチェック
	assert(model);
	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;

	// ワールド変換の初期化
	viewprojection_ = viewprojection;

	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;
}

void Player::Update() {
	// 移動入力
	if (Input::GetInstance()->PushKey(DIK_RIGHT) || Input::GetInstance()->PushKey(DIK_LEFT)) {
		// 左右加速
		Vector3 acceleration = {};
		if (Input::GetInstance()->PushKey(DIK_RIGHT)) {
			
			// 左移動中の右入力
			if (velocity_.x < 0.0f) {
				velocity_.x *= (1.0f - kAttenuation);
			}
			
			acceleration.x += kAcceleration;

			if (lrDirection_ != LRDirection::kRight) {
				lrDirection_ = LRDirection::kRight;
			}

		} else if (Input::GetInstance()->PushKey(DIK_LEFT)) {

			if (velocity_.x > 0.0f) {
				velocity_.x *= (1.0f - kAttenuation);
			}

			acceleration.x -= kAcceleration;

			if (lrDirection_ != LRDirection::kLeft) {
				lrDirection_ = LRDirection::kLeft;
			}
		}
		//加速/減速
		velocity_=worldTransform_.Add(velocity_, acceleration);

		//最大速度制限
		velocity_.x = std::clamp(velocity_.x, -kLimitSpeed, kLimitSpeed);
	} else {
		velocity_.x *= (1.0f - kAttenuation);
	} 


	// 移動
	worldTransform_.translation_=worldTransform_.Add(worldTransform_.translation_, velocity_);
	// 行列計算
	worldTransform_.UpdateMatrix();
}

void Player::Draw() { model_->Draw(worldTransform_, *viewprojection_, texturehandle_); }