#pragma once
#include "Vector2.h"

class Enemy {
	// --メンバ変数-- //
public:
	// 座標
	Vector2 position_;

	// 半径
	float radius_;

private:
	// 生存フラグ
	static bool isAlive_;

	// --メンバ関数-- //
public:
	// コンストラクタ
	Enemy();

	// 初期化処理
	void Initialize();

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

	// エネミーの生存フラグの設定
	void SetIsAlive(bool flag) { isAlive_ = flag; }

	// エネミーの生存フラグを取得
	bool GetIsAlive() { return isAlive_; }

private:

};