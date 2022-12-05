#include "Enemy.h"
#include "DxLib.h"
#include <random>

bool Enemy::isAlive_ = false;

Enemy::Enemy() :
	position_{0.0f, 0.0f},// -> ���W
	radius_(8.0f),// -> ���a
	speed_(0.8f),// -> ���x
	nowState_(State::Approach),// -> ���݂̏��
	shootLen_(100.0f)// -> �ˌ��̎˒�
{
	// �e�N���X�̓��I�m��
	bullet_ = new Bullet();
}

Enemy::~Enemy() {
	delete bullet_;
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

	// ���݂̏�Ԑݒ�
	nowState_ = State::Approach;
}

void Enemy::Update(Vector2 playerPos)
{
	// �s��
	(this->*actionTable[nowState_])(playerPos);
}

void Enemy::Draw()
{
	// �e�̐����t���O��[ON]�Ȃ�e��`�悷��
	if (bullet_->GetIsAlive()) bullet_->Draw();

	// �����t���O��[ON]�Ȃ�`��
	if (isAlive_)
	DrawCircleAA(position_.x, position_.y, radius_, 20, 0xFF2222, true);
}

void Enemy::Approach(Vector2 playerPos)
{
	// �G�l�~�[����v���C���[�ւ̃x�N�g��
	Vector2 e2pVec = playerPos - position_;

	// ���K��
	e2pVec.normalize();

	// ���W�X�V
	position_ += e2pVec * speed_;

	// ���܂ŋ߂Â������Ԃ�ύX
	if (Vector2(playerPos - position_).length() <= shootLen_) {
		nowState_ = State::Shoot;
	}

	// �e�̏�����
	bullet_->Initialize(position_, e2pVec);
}

void Enemy::Shoot(Vector2 playerPos)
{
	// �e�̍X�V����
	bullet_->Update();

	// �e�̃t���O��[OFF]�ɂȂ������Ԃ�ύX
	if (bullet_->GetIsAlive() == false) nowState_ = State::Secession;
}

void Enemy::Secession(Vector2 playerPos)
{
	// �v���C���[����G�l�~�[�ւ̃x�N�g��
	Vector2 p2eVec = position_ - playerPos;

	// ���K��
	p2eVec.normalize();

	// ���W�̍X�V
	position_ += p2eVec * speed_;

	// ��ʂ̘g�ɐG�ꂽ���Ԃ�ύX
	if (position_.x <= radius_) nowState_ = State::Approach;
	if (position_.x >= 600.0f - radius_) nowState_ = State::Approach;
	if (position_.y <= radius_) nowState_ = State::Approach;
	if (position_.y >= 400.0f - radius_) nowState_ = State::Approach;
}

void (Enemy::* Enemy::actionTable[]) (Vector2 playerPos) = {
	&Enemy::Approach,// -> �ߐ�
	&Enemy::Shoot,// ----> �ˌ�
	&Enemy::Secession// -> ���E
};