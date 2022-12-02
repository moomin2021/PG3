#include "Scene1.h"
#include <stdio.h>
#include <stdlib.h>
#include "SceneManager.h"

Scene1::Scene1() :
	selectScene_(0),
	cell_(nullptr)
{
}

void Scene1::Initialize(CELL* cell)
{
	// �Z����ۑ�
	cell_ = cell;
}

void Scene1::Update()
{
	// �I������Ă���V�[���̃A�N�V����������
	switch (selectScene_)
	{
	case 0:
		Scene0Update();
		break;
	case 1:
		Scene1Update();
		break;
	case 2:
		Scene2Update();
		break;
	default:
		break;
	}
}

void Scene1::Scene0Update()
{
	// �v�f�̕\���̎d���̑I���ꗗ��\��
	printf("--------------------\n");
	printf("[�v�f�̕\��]\n");
	printf("1. �v�f�̈ꗗ�\��\n");
	printf("2. ���Ԃ��w�肵�ėv�f��\��\n");
	printf("9. �v�f�̑���ɖ߂�\n");
	printf("--------------------\n\n");

	printf("�����I�����Ă�������\n");

	// ���͂��󂯎��
	int selectVal = 0;
	scanf_s("%d", &selectVal);
	printf("\n");// -> ���s

	// �󂯎�����l�ɂ���ăA�N�V������ς���
	switch (selectVal)
	{
	case 1:
		selectScene_ = 1;
		break;
	case 2:
		selectScene_ = 2;
		break;
	case 9:
		selectScene_ = 9;
		SceneManager::SceneChange(0);
		break;
	default:
		selectScene_ = 0;
		printf("--------------------\n");
		printf("�I���ł��܂���ł���\n");
		printf("--------------------\n\n");
		break;
	}
}

void Scene1::Scene1Update() {
	// �v�f�ꗗ�\��
	printf("--------------------\n");
	printf("[�v�f�̈ꗗ�\��]\n");
	printf("�v�f�ꗗ: {\n");
	for (size_t i = 0; i < cell_->size(); i++) {
		printf("%d: \"%s\",\n", i, cell_->GetStr(i));
	}
	printf("}\n\n");

	// �v�f���\��
	printf("�v�f��:%d\n", cell_->size());
	printf("--------------------\n");

	// �����\��
	printf("�����I�����Ă�������\n");
	printf("1. �v�f�̕\���ɖ߂�\n");
	printf("2. �v�f�̑���ɖ߂�\n");

	// ���͂��󂯎��
	int inputVal;
	scanf_s("%d", &inputVal);

	switch (inputVal)
	{
	case 1:
		selectScene_ = 0;
		break;
	case 2:
		SceneManager::SceneChange(0);
		break;
	default:
		printf("�I���ł��Ȃ����̂�I�񂾂���[�v�f�̑���]��ʂɖ߂�܂�\n\n");
		SceneManager::SceneChange(0);
		break;
	}
}

void Scene1::Scene2Update() {
	// �w�肳�ꂽ�v�f��\��
	printf("--------------------\n");
	printf("[���Ԃ��w�肵�ėv�f��\��]\n");
	printf("�\���������v�f�̏��Ԃ��w�肵�Ă�������\n");

	// ���͂��󂯎��
	int inputVal = 0;
	scanf_s("%d", &inputVal);
	printf("\n");// -> ���s

	// �Ԃ��Ă������̂�nullptr��������
	if (cell_->GetStr(inputVal) == nullptr) {
		printf("���̗v�f�ԍ��͔͈͊O�ł�\n");
		printf("--------------------\n");
	}
	else {
		printf("%d : %s\n", inputVal, cell_->GetStr(inputVal));
		printf("--------------------\n");
	}

	// �����\��
	printf("�����I�����Ă�������\n");
	printf("1. �v�f�̕\���ɖ߂�\n");
	printf("2. �v�f�̑���ɖ߂�\n");

	// ���͂��󂯎��
	scanf_s("%d", &inputVal);

	switch (inputVal)
	{
	case 1:
		selectScene_ = 0;
		break;
	case 2:
		SceneManager::SceneChange(0);
		break;
	default:
		printf("�I���ł��Ȃ����̂�I�񂾂���[�v�f�̑���]��ʂɖ߂�܂�\n\n");
		SceneManager::SceneChange(0);
		break;
	}
}