#pragma once
#include "Vector2.h"

class Bullet {
	// --メンバ変数-- //
public:
	// 座標
	Vector2 position_;

	// 半径
	float radius_;

private:
	// 飛んでいく方向
	Vector2 moveVec_;

	// 速度
	float speed_;

	// 生存フラグ
	bool isAlive_;

	// --メンバ関数-- //
public:
	// コンストラクタ
	Bullet();

	// 初期化処理
	void Initialize(Vector2 pos, Vector2 moveVec);

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

	// 弾の生存フラグを取得
	bool GetIsAlive() { return isAlive_; }

private:

};