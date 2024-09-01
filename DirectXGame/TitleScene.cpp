#include "TitleScene.h"

TitleScene::TitleScene() {}

TitleScene::~TitleScene() {
	delete model_;
	delete sprite_;
}

void TitleScene::Intialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	/*model_ = Model::CreateFromOBJ("titleFont"); */
	titleTextureHandle_ = TextureManager::Load("title.png");
	sprite_ = Sprite::Create(titleTextureHandle_, {1.0f, 1.0f});
	
	viewProjection_.Initialize();
	worldTransform_.Initialize();
}

void TitleScene::Update() {

	if (Input::GetInstance()->PushKey(DIK_SPACE)) {

		finished_ = true;
	}
}

void TitleScene::Draw() {

#pragma endregion

#pragma region 3Dオブジェクト描画
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	///
	sprite_->Draw();
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
	/*Model::PreDraw(commandList);

	model_->Draw(worldTransform_, viewProjection_, textureHandle_);

	Model::PostDraw();*/
}
