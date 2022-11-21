#include "TitleScene.h"
#include "DxLib.h"

// コンストラクタ
TitleScene::TitleScene()
#pragma region 初期化リスト

#pragma endregion
{}

// デストラクタ
TitleScene::~TitleScene() {

}

// 初期化処理
void TitleScene::Initialize() {

}

// 更新処理
void TitleScene::Update() {

}

// 描画処理
void TitleScene::Draw() {
	// 現在のシーンをデバック表示
	DrawFormatString(0, 0, 0xFFFFFF, "現在のシーンはTitleシーンです");
}