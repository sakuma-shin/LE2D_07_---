#include "Input.h"
#include "GameScene.h"
#include "TextureManager.h"
class TitleScene {

public:
	void Intialize(Model* model, uint32_t textureHandle, ViewProjection* viewProjection);

	void Update();

	void Draw();

	Model* GetModel() { return model_; }

	uint32_t GetTextureHandle() { return textureHandle_; }

	ViewProjection* GetViewProjecton() { return viewprojection_; }

	bool IsFinished() const { return finished_; }

private:
	// 終了フラグ
	bool finished_ = false;

		// ワールド変換データ
	WorldTransform worldTransform_;

	ViewProjection* viewprojection_ = nullptr;

	uint32_t textureHandle_ = 0;

	Model* model_ = nullptr;
	DirectXCommon* dxCommon_ = nullptr;
};