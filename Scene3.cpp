#include "Scene3.h"
#include <stdio.h>
#include <stdlib.h>
#include "SceneManager.h"

Scene3::Scene3() :
	cell_(nullptr)
{

}

void Scene3::Initialize(CELL* cell) {
	// �Z����ۑ�
	cell_ = cell;
}

void Scene3::Update() {
	printf("--------------------\n");
	printf("[�v�f�̕ҏW]\n");
	printf("�ҏW�������v�f�̔ԍ����w�肵�Ă�������\n");
	int inputVal;
	scanf_s("%d", &inputVal);

	if (inputVal >= cell_->size()) {
		printf("%d�Ԗڂ̗v�f��������܂���ł���\n", inputVal);
	}

	else {
		printf("%d�Ԗڂ̗v�f�̕ύX���镶�������͂��Ă�������\n", inputVal);
		char str[8];
		scanf_s("%s", str, 8);
		cell_->SetChangeStr(str, inputVal);
		printf("%d�Ԗڂ̗v�f�̕�����\"%s\"�ɕύX����܂���\n", inputVal, str);
	}
	printf("--------------------\n");
	SceneManager::SceneChange(0);
}