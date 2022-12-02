#include "Scene0.h"
#include <stdio.h>
#include <stdlib.h>
#include "SceneManager.h"

Scene0::Scene0() :
	selectScene_(0),
	cell_(nullptr)
{

}

void Scene0::Initialize(CELL * cell)
{
	// �Z����ۑ�
	cell_ = cell;
}

void Scene0::Update()
{
	// �v�f�̑���̑I���ꗗ��\��
	printf("--------------------\n");
	printf("[�v�f�̑���]\n");
	printf("1. �v�f�̕\��\n");
	printf("2. �v�f�̑}��\n");

	// �T�C�Y��0�������ꍇ�\�����Ȃ�
	if (cell_->size() != 0) {
		printf("3. �v�f�̕ҏW\n");
		printf("4. �v�f�̍폜\n");
	}

	printf("--------------------\n");
	printf("�����I�����Ă�������\n");

	// ���͂��󂯎��
	int selectVal = 0;
	scanf_s("%d", &selectVal);

	printf("\n");// -> ���s

	// �󂯎�����l�ɂ���ăA�N�V������ς���
	switch (selectVal)
	{
	case 1:
		SceneManager::SceneChange(1);
		break;
	case 2:
		SceneManager::SceneChange(2);
		break;
	case 3:
		if (cell_->size() != 0) {
			SceneManager::SceneChange(3);
			break;
		}
		SceneManager::SceneChange(0);
		break;
	case 4:
		if (cell_->size() != 0) {
			SceneManager::SceneChange(4);
			break;
		}
		SceneManager::SceneChange(0);
		break;
	default:
		SceneManager::SceneChange(0);
		printf("--------------------\n");
		printf("�I���ł��܂���ł���\n");
		printf("--------------------\n\n");
		break;
	}
}
