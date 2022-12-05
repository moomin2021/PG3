#pragma once
#include "Vector2.h"
#include "Bullet.h"

enum State {
	Approach,// -> �ߐ�
	Shoot,// -> �ˌ�
	Secession// -> ���E
};

class Enemy {
	// --�����o�ϐ�-- //
public:
	// ���W
	Vector2 position_;

	// ���a
	float radius_;

private:
	// �e�N���X
	Bullet* bullet_;

	// �����t���O
	static bool isAlive_;

	// ���x
	float speed_;

	// �ˌ��̎˒�
	float shootLen_;

	// ���݂̏��
	State nowState_;

	// --�����o�֐�-- //
public:
	// �R���X�g���N�^
	Enemy();

	// �f�X�g���N�^
	~Enemy();

	// ����������
	void Initialize();

	// �X�V����
	void Update(Vector2 playerPos);

	// �`�揈��
	void Draw();

	// �G�l�~�[�̐����t���O�̐ݒ�
	void SetIsAlive(bool flag) { isAlive_ = flag; }

	// �G�l�~�[�̐����t���O���擾
	bool GetIsAlive() { return isAlive_; }

private:
	// �s���֐��|�C���^
	static void (Enemy::* actionTable[]) (Vector2 playerPos);

	// �ߐ�
	void Approach(Vector2 playerPos);

	// �ˌ�
	void Shoot(Vector2 playerPos);

	// ���E
	void Secession(Vector2 playerPos);
};