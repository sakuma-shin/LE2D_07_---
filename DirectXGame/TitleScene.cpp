#include "TitleScene.h"



void TitleScene::Intialize(Model* model, uint32_t textureHandle, ViewProjection* viewProjection) { 

	model = Model::CreateFromOBJ("titleFont"); 
	textureHandle = TextureManager::Load("white1x1.png");
	viewprojection_ = viewProjection;
	worldTransform_.Initialize();
}

void TitleScene::Update() {

	if (Input::GetInstance()->PushKey(DIK_SPACE)) {

		finished_ = true;
	}
}

 void TitleScene::Draw() {
	 // コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	Model::PreDraw(commandList);

	model_->Draw(worldTransform_, *viewprojection_, textureHandle_);

	Model::PostDraw();
 }
