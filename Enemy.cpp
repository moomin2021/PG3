#include "Enemy.h"
#include "DxLib.h"
#include <random>

bool Enemy::isAlive_ = false;

Enemy::Enemy() :
	position_{0.0f, 0.0f},// -> 座標
	radius_(8.0f)
{

}

void Enemy::Initialize()
{
	// ランダムで座標を決定
	std::random_device device;
	std::mt19937 engine(device());
	std::uniform_real_distribution<float> randX(8.0f, 592.0f);
	std::uniform_real_distribution<float> randY(48.0f, 292.0f);

	// 座標設定
	position_ = { randX(engine), randY(engine) };
}

void Enemy::Update()
{

}

void Enemy::Draw()
{
	// 生存フラグが[ON]なら描画
	if (isAlive_)
	DrawCircleAA(position_.x, position_.y, radius_, 20, 0xFF2222, true);
}
