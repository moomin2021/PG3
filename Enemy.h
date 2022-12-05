#pragma once
#include "Vector2.h"
#include "Bullet.h"

enum State {
	Approach,// -> 近接
	Shoot,// -> 射撃
	Secession// -> 離脱
};

class Enemy {
	// --メンバ変数-- //
public:
	// 座標
	Vector2 position_;

	// 半径
	float radius_;

private:
	// 弾クラス
	Bullet* bullet_;

	// 生存フラグ
	static bool isAlive_;

	// 速度
	float speed_;

	// 射撃の射程
	float shootLen_;

	// 現在の状態
	State nowState_;

	// --メンバ関数-- //
public:
	// コンストラクタ
	Enemy();

	// デストラクタ
	~Enemy();

	// 初期化処理
	void Initialize();

	// 更新処理
	void Update(Vector2 playerPos);

	// 描画処理
	void Draw();

	// エネミーの生存フラグの設定
	void SetIsAlive(bool flag) { isAlive_ = flag; }

	// エネミーの生存フラグを取得
	bool GetIsAlive() { return isAlive_; }

private:
	// 行動関数ポインタ
	static void (Enemy::* actionTable[]) (Vector2 playerPos);

	// 近接
	void Approach(Vector2 playerPos);

	// 射撃
	void Shoot(Vector2 playerPos);

	// 離脱
	void Secession(Vector2 playerPos);
};