#pragma once
#include "BaseScene.h"
#include "Key.h"
#include "Enemy.h"
#include "Player.h"

class GameScene : public BaseScene {
	// --�����o�ϐ�-- //
public:

private:
	// �L�[�{�[�h����
	Key* key_;

	Enemy* enemys_;// -> �G�l�~�[�̃N���X
	const int maxEnemy_ = 20;// -> �G�̐�

	// �v���C���[
	Player* player_;

	// --�����o�֐�-- //
public:
	// �R���X�g���N�^
	GameScene();

	// �f�X�g���N�^
	~GameScene();

	// ����������
	void Initialize();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

private:
	// ���Z�b�g����
	void Reset();

	// �����蔻��
	void Collision();
};