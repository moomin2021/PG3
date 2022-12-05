#include "GameScene.h"
#include "DxLib.h"
#include "Vector2.h"
#include <cmath>

bool CircleCol(Vector2 pos1, float r1, Vector2 pos2, float r2) {
	float a = pos1.x - pos2.x;
	float b = pos1.y - pos2.y;
	float c = sqrtf(a * a + b * b);

	if (c <= r1 + r2) return true;
	return false;
}

GameScene::GameScene() :
	key_(nullptr),// -> キーボード
	enemys_(nullptr),// -> エネミー
	player_(nullptr)// -> プレイヤー
{

}

GameScene::~GameScene()
{
	delete[] enemys_;// -> エネミー
	delete player_;// -> プレイヤー
}

void GameScene::Initialize()
{
	// キーボード入力クラスインスタンス取得
	key_ = Key::GetInstance();

	// エネミー動的確保
	enemys_ = new Enemy[maxEnemy_];
	
	// エネミー初期化
	for (size_t i = 0; i < maxEnemy_; i++) {
		enemys_[i].Initialize();
	}

	// エネミーの生存フラグを[ON]にする
	enemys_->SetIsAlive(true);

	// プレイヤー動的確保
	player_ = new Player();

	// プレイヤー初期化
	player_->Initialize();
}

void GameScene::Update()
{
	// プレイヤー更新処理
	player_->Update();

	// 当たり判定
	Collision();

	// [R]を押したらリセット処理
	if (key_->TriggerKey(KEY_INPUT_R)) Reset();
}

void GameScene::Draw()
{
	// エネミー描画処理
	for (size_t i = 0; i < maxEnemy_; i++) {
		enemys_[i].Draw();
	}

	// プレイヤー描画処理
	player_->Draw();

	// テキスト描画
	DrawFormatString(0, 0, 0xFFFFFF, "[W][A][S][D] : プレイヤー移動操作");
	DrawFormatString(0, 20, 0xFFFFFF, "プレイヤーが敵にぶつかると画面上の敵がすべて消える");
	DrawFormatString(0, 40, 0xFFFFFF, "[R] : リセット");
}

void GameScene::Reset()
{
	// エネミー初期化処理
	for (size_t i = 0; i < maxEnemy_; i++) {
		enemys_[i].Initialize();
	}

	// エネミーの生存フラグを[ON]にする
	enemys_->SetIsAlive(true);

	// プレイヤー初期化処理
	player_->Initialize();
}

void GameScene::Collision() {
	for (size_t i = 0; i < maxEnemy_; i++) {
		// エネミーの生存フラグが[OFF]なら判定を行わない
		if (enemys_->GetIsAlive() == false) break;

		// プレイヤーとエネミーの当たり判定
		if (CircleCol(
			player_->position_, player_->radius_,
			enemys_[i].position_, enemys_[i].radius_)) {

			// エネミーの生存フラグを[OFF]にする
			enemys_->SetIsAlive(false);
			break;
		}
	}
}