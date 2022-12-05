#pragma once
#include "Vector2.h"
#include "Key.h"

class Player {
	// --メンバ変数-- //
public:
	// 座標
	Vector2 position_;

	// 半径
	float radius_;

private:
	// キーボード入力
	Key* key_;

	// --メンバ関数-- //
public:
	// コンストラクタ
	Player();

	// 初期化処理
	void Initialize();

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

private:

};