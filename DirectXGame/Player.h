#pragma once
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <cassert>

class Player {
public:

	Player();

	~Player();
	///< summary>
	/// 初期化
	///</summary>
	void Initialize(Model* model, uint32_t textureHandle);

	///< summary>
	/// 更新
	///</summary>
	void Update();

	///< summary>
	/// 描画
	///</summary>
	void Draw();

	void SetModel(Model* model) { this->model_ = model;}
	Model* GetModel() { return model_; }

	void SetTextureHandle(uint32_t textureHandle) { this->texturehandle_ = textureHandle; }
	uint32_t GetTextureHandle() { return texturehandle_; }

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t texturehandle_ = 0u;
};
