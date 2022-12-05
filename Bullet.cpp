#include "Bullet.h"
#include "DxLib.h"

Bullet::Bullet() :
	position_{ 0.0f, 0.0f },// -> ���W
	radius_(4.0f),// -> ���a
	moveVec_{ 0.0f, 0.0f },// -> ���ł�������
	speed_(2.0f),// -> ���x
	isAlive_(false)// -> �����t���O
{

}

void Bullet::Initialize(Vector2 pos, Vector2 moveVec)
{
	// �����t���O��[ON]�ɂ���
	isAlive_ = true;

	// ���W��ݒ�
	position_ = pos;

	// ���ł���������ݒ�
	moveVec_ = moveVec;
}

void Bullet::Update()
{
	// ���W�̍X�V
	position_ += moveVec_ * speed_;

	// �e����ʊO�ɍs�����琶���t���O��[OFF]�ɂ���
	if (600.0f < position_.x || position_.x < 0.0f) isAlive_ = false;
	if (400.0f < position_.y || position_.y < 0.0f) isAlive_ = false;
}

void Bullet::Draw()
{
	// �����t���O��[ON]�Ȃ�`��
	if (isAlive_)
	DrawCircleAA(position_.x, position_.y, radius_, 10, 0xFF2222, true);
}
