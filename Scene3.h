#pragma once
#include "BaseScene.h"
#include "Cell.h"

class Scene3 : public BaseScene {
	// --�����o�ϐ�-- //
public:

private:
	// �I�������V�[��
	int selectScene_;

	// �Z��
	CELL* cell_;

	// --�����o�֐�-- //
public:
	// �R���X�g���N�^
	Scene3();

	// ����������
	void Initialize(CELL* cell);

	// �X�V����
	void Update();

private:

};