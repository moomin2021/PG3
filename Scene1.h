#pragma once
#include "BaseScene.h"
#include "Cell.h"

class Scene1 : public BaseScene {
	// --�����o�ϐ�-- //
public:

private:
	// �I�����Ă���V�[��
	int selectScene_;

	// �Z��
	CELL* cell_;

	// --�����o�֐�-- //
public:
	// �R���X�g���N�^
	Scene1();

	// ����������
	void Initialize(CELL* cell);

	// �X�V����
	void Update();

private:
	// �e�V�[��
	void Scene0Update();
	void Scene1Update();
	void Scene2Update();
};