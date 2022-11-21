#include "NewGameScene.h"
#include "DxLib.h"

// コンストラクタ
NewGameScene::NewGameScene()
#pragma region 初期化リスト

#pragma endregion
{}

// デストラクタ
NewGameScene::~NewGameScene() {

}

// 初期化処理
void NewGameScene::Initialize() {

}

// 更新処理
void NewGameScene::Update() {

}

// 描画処理
void NewGameScene::Draw() {
	// 現在のシーンをデバック表示
	DrawFormatString(0, 0, 0xFFFFFF, "現在のシーンはNewGameシーンです");
}