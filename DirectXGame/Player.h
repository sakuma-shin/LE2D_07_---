#pragma once
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <cassert>

class Player {
public:

	/*Player();

	~Player();*/
	///< summary>
	/// 初期化
	///</summary>
	void Initialize(Model* model, uint32_t textureHandle,ViewProjection* viewprojection);

	///< summary>
	/// 更新
	///</summary>
	void Update();

	///< summary>
	/// 描画
	///</summary>
	void Draw();

	
private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t texturehandle_ = 0u;

	ViewProjection* viewprojection_ = nullptr;
};
