#include "GameClearScene.h"
#include "DxLib.h"

// コンストラクタ
GameClearScene::GameClearScene()
#pragma region 初期化リスト

#pragma endregion
{}

// デストラクタ
GameClearScene::~GameClearScene() {

}

// 初期化処理
void GameClearScene::Initialize() {

}

// 更新処理
void GameClearScene::Update() {

}

// 描画処理
void GameClearScene::Draw() {
	// 現在のシーンをデバック表示
	DrawFormatString(0, 0, 0xFFFFFF, "現在のシーンはGameClearシーンです");
}