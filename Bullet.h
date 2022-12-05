#pragma once
#include "Vector2.h"

class Bullet {
	// --�����o�ϐ�-- //
public:
	// ���W
	Vector2 position_;

	// ���a
	float radius_;

private:
	// ���ł�������
	Vector2 moveVec_;

	// ���x
	float speed_;

	// �����t���O
	bool isAlive_;

	// --�����o�֐�-- //
public:
	// �R���X�g���N�^
	Bullet();

	// ����������
	void Initialize(Vector2 pos, Vector2 moveVec);

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

	// �e�̐����t���O���擾
	bool GetIsAlive() { return isAlive_; }

private:

};