#include "Player.h"
#include "DxLib.h"

Player::Player() :
	position_{0.0f, 0.0f},// -> 座標
	radius_(8.0f)// -> 半径
{
	// キーボード入力インスタンス読み込み
	key_ = Key::GetInstance();
}

void Player::Initialize()
{
	// 座標
	position_ = { 300.0f, 350.0f };
}

void Player::Update()
{
	 // 移動処理
	position_.x += key_->PushKey(KEY_INPUT_D) - key_->PushKey(KEY_INPUT_A);
	position_.y += key_->PushKey(KEY_INPUT_S) - key_->PushKey(KEY_INPUT_W);
}

void Player::Draw()
{
	DrawCircleAA(position_.x, position_.y, radius_, 20, 0xFFFFFF, true);
}
