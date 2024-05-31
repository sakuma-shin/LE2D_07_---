#include "Skydome.h"

void Skydome::Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewprojection) {
	// NULLポインタチェック
	assert(model);
	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;
	texturehandle_ = textureHandle;

	// ワールド変換の初期化
	viewprojection_ = viewprojection;

	worldTransform_.Initialize();
}

void Skydome::Update() {

}

void Skydome::Draw() { model_->Draw(worldTransform_, *viewprojection_); }