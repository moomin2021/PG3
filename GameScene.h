#pragma once
#include "BaseScene.h"
#include "Key.h"
#include "Enemy.h"
#include "Player.h"

class GameScene : public BaseScene {
	// --メンバ変数-- //
public:

private:
	// キーボード入力
	Key* key_;

	Enemy* enemys_;// -> エネミーのクラス
	const int maxEnemy_ = 20;// -> 敵の数

	// プレイヤー
	Player* player_;

	// --メンバ関数-- //
public:
	// コンストラクタ
	GameScene();

	// デストラクタ
	~GameScene();

	// 初期化処理
	void Initialize();

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

private:
	// リセット処理
	void Reset();

	// 当たり判定
	void Collision();
};