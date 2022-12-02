#pragma once
#include "BaseScene.h"
#include "Cell.h"

class SceneManager {
	// --�����o�ϐ�-- //
public:

private:
	// ���݂̃V�[��
	static BaseScene* nowScene_;

	// �Z��
	static CELL cell_;

	// --�����o�֐�-- //
public:
	// �C���X�^���X�擾
	static SceneManager* GetInstance();

	// �X�V����
	void Update();

	// �V�[����؂�ւ���
	static void SceneChange(int scene);

private:
	// �R���X�g���N�^
	SceneManager();

	// --�֎~-- //
public:
	// �R�s�[�R���X�g���N�^
	SceneManager(const SceneManager& instance) = delete;

	// ������Z�q
	SceneManager& operator=(const SceneManager& instance) = delete;
};