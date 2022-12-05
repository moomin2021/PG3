#include "Bullet.h"
#include "DxLib.h"

Bullet::Bullet() :
	position_{ 0.0f, 0.0f },// -> 座標
	radius_(4.0f),// -> 半径
	moveVec_{ 0.0f, 0.0f },// -> 飛んでいく方向
	speed_(2.0f),// -> 速度
	isAlive_(false)// -> 生存フラグ
{

}

void Bullet::Initialize(Vector2 pos, Vector2 moveVec)
{
	// 生存フラグを[ON]にする
	isAlive_ = true;

	// 座標を設定
	position_ = pos;

	// 飛んでいく方向を設定
	moveVec_ = moveVec;
}

void Bullet::Update()
{
	// 座標の更新
	position_ += moveVec_ * speed_;

	// 弾が画面外に行ったら生存フラグを[OFF]にする
	if (600.0f < position_.x || position_.x < 0.0f) isAlive_ = false;
	if (400.0f < position_.y || position_.y < 0.0f) isAlive_ = false;
}

void Bullet::Draw()
{
	// 生存フラグが[ON]なら描画
	if (isAlive_)
	DrawCircleAA(position_.x, position_.y, radius_, 10, 0xFF2222, true);
}
