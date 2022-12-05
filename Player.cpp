#include "Player.h"
#include "DxLib.h"

Player::Player() :
	position_{0.0f, 0.0f},// -> ���W
	radius_(8.0f)// -> ���a
{
	// �L�[�{�[�h���̓C���X�^���X�ǂݍ���
	key_ = Key::GetInstance();
}

void Player::Initialize()
{
	// ���W
	position_ = { 300.0f, 350.0f };
}

void Player::Update()
{
	 // �ړ�����
	position_.x += key_->PushKey(KEY_INPUT_D) - key_->PushKey(KEY_INPUT_A);
	position_.y += key_->PushKey(KEY_INPUT_S) - key_->PushKey(KEY_INPUT_W);
}

void Player::Draw()
{
	DrawCircleAA(position_.x, position_.y, radius_, 20, 0xFFFFFF, true);
}
