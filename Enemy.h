#pragma once
#include "Vector2.h"

class Enemy {
	// --�����o�ϐ�-- //
public:
	// ���W
	Vector2 position_;

	// ���a
	float radius_;

private:
	// �����t���O
	static bool isAlive_;

	// --�����o�֐�-- //
public:
	// �R���X�g���N�^
	Enemy();

	// ����������
	void Initialize();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

	// �G�l�~�[�̐����t���O�̐ݒ�
	void SetIsAlive(bool flag) { isAlive_ = flag; }

	// �G�l�~�[�̐����t���O���擾
	bool GetIsAlive() { return isAlive_; }

private:

};