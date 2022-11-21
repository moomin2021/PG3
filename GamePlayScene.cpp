#include "GamePlayScene.h"
#include "DxLib.h"

// コンストラクタ
GamePlayScene::GamePlayScene()
#pragma region 初期化リスト

#pragma endregion
{}

// デストラクタ
GamePlayScene::~GamePlayScene() {

}

// 初期化処理
void GamePlayScene::Initialize() {

}

// 更新処理
void GamePlayScene::Update() {

}

// 描画処理
void GamePlayScene::Draw() {
	// 現在のシーンをデバック表示
	DrawFormatString(0, 0, 0xFFFFFF, "現在のシーンはGamePlayシーンです");
}