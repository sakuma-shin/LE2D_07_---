#include "Input.h"
#include "GameScene.h"
#include "TextureManager.h"
class TitleScene {

public:

	TitleScene();

	~TitleScene();

	void Intialize();

	void Update();

	void Draw();

	Model* GetModel() { return model_; }

	uint32_t GetTextureHandle() { return textureHandle_; }

	ViewProjection* GetViewProjecton() { return viewprojection_; }

	bool IsFinished() const { return finished_; }

private:

	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;


	// 終了フラグ
	bool finished_ = false;

		// ワールド変換データ
	WorldTransform worldTransform_;

	ViewProjection* viewprojection_ = nullptr;

	uint32_t textureHandle_ = 0;

	Model* model_ = nullptr;

};