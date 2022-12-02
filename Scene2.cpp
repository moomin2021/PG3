#include "Scene2.h"
#include <stdio.h>
#include <stdlib.h>
#include "SceneManager.h"

Scene2::Scene2() :
	selectScene_(0),
	cell_(nullptr) 
{

}

void Scene2::Initialize(CELL* cell) {
	// �Z����ۑ�
	cell_ = cell;
}

void Scene2::Update() {
	printf("--------------------\n");
	printf("[���X�g�v�f�̑}��]\n");
	printf("�v�f��ǉ�����ꏊ���w�肵�Ă�������\n");
	printf("�Ō���ɒǉ�����ꍇ��[0]����͂��Ă�������\n");

	// ���͂��󂯎��
	int inputVal;
	scanf_s("%d", &inputVal);

	if (inputVal == 0) {
		// �ǉ����镶�������͓ǂݍ���
		printf("�ǉ�����v�f�̕��������͂��Ă�������\n");
		char str[8];
		scanf_s("%s", str, 8);

		cell_->SetStr(str, cell_->size());

		printf("�v�f\"%s\"��%d�Ԗڂɑ}������܂���\n", str, cell_->size());
		printf("--------------------\n");
	}

	else if (cell_->size() >= inputVal) {
		// �ǉ����镶�������͓ǂݍ���
		printf("�ǉ�����v�f�̕��������͂��Ă�������\n");
		char str[8];
		scanf_s("%s", str, 8);

		cell_->SetStr(str, inputVal);

		printf("�v�f\"%s\"��%d�Ԗڂɑ}������܂���\n", str, inputVal);
		printf("--------------------\n");
	}

	else {
		printf("���͂��ꂽ�v�f�ԍ��͔͈͊O�ł�\n");
		printf("--------------------\n");
	}

	SceneManager::SceneChange(0);
}