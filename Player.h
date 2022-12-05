#pragma once
#include "Vector2.h"
#include "Key.h"

class Player {
	// --�����o�ϐ�-- //
public:
	// ���W
	Vector2 position_;

	// ���a
	float radius_;

private:
	// �L�[�{�[�h����
	Key* key_;

	// --�����o�֐�-- //
public:
	// �R���X�g���N�^
	Player();

	// ����������
	void Initialize();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

private:

};