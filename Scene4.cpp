#include "Scene4.h"
#include <stdio.h>
#include <stdlib.h>
#include "SceneManager.h"

Scene4::Scene4() :
	cell_(nullptr)
{

}

void Scene4::Initialize(CELL* cell) {
	// �Z����ۑ�
	cell_ = cell;
}

void Scene4::Update() {
	printf("--------------------\n");
	printf("�폜�������v�f�̔ԍ����w�肵�Ă�������\n");
	int inputVal;
	scanf_s("%d", &inputVal);

	if (inputVal >= cell_->size()) {
		printf("%d�Ԗڂ̗v�f��������܂���ł���\n", inputVal);
	}
	else {
		cell_->DeleteCell(inputVal);
		printf("%d�Ԗڂ̗v�f���폜���܂���\n", inputVal);
	}

	SceneManager::SceneChange(0);
}