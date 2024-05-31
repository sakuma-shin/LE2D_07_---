#include "Player.h"


void Player::Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewprojection) { 
	//NULLポインタチェック
	assert(model);
	//引数として受け取ったデータをメンバ変数に記録する
	model_ = model;
	texturehandle_ = textureHandle;
	
	//ワールド変換の初期化
	viewprojection_ = viewprojection;

	worldTransform_.Initialize();
}

void Player::Update() { worldTransform_.UpdateMatrix(); }

void Player::Draw() { 
	model_->Draw(worldTransform_, *viewprojection_, texturehandle_); 
}