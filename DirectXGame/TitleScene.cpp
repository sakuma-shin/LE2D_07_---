#include "TitleScene.h"
#include "Input.h"
#include "GameScene.h"


void TitleScene::Intialize() {}

void TitleScene::Update() {

	if (Input::GetInstance()->PushKey(DIK_SPACE)) {

		finished_ = true;
	}
}

 void TitleScene::Draw() {
}
