#include "Enemy.h"
#include "DxLib.h"
#include <random>

bool Enemy::isAlive_ = false;

Enemy::Enemy() :
	position_{0.0f, 0.0f},// -> ���W
	radius_(8.0f)
{

}

void Enemy::Initialize()
{
	// �����_���ō��W������
	std::random_device device;
	std::mt19937 engine(device());
	std::uniform_real_distribution<float> randX(8.0f, 592.0f);
	std::uniform_real_distribution<float> randY(48.0f, 292.0f);

	// ���W�ݒ�
	position_ = { randX(engine), randY(engine) };
}

void Enemy::Update()
{

}

void Enemy::Draw()
{
	// �����t���O��[ON]�Ȃ�`��
	if (isAlive_)
	DrawCircleAA(position_.x, position_.y, radius_, 20, 0xFF2222, true);
}
