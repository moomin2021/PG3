#include "Scene4.h"
#include <stdio.h>
#include <stdlib.h>
#include "SceneManager.h"

Scene4::Scene4() :
	cell_(nullptr)
{

}

void Scene4::Initialize(CELL* cell) {
	// セルを保存
	cell_ = cell;
}

void Scene4::Update() {
	printf("--------------------\n");
	printf("削除したい要素の番号を指定してください\n");
	int inputVal;
	scanf_s("%d", &inputVal);

	if (inputVal >= cell_->size()) {
		printf("%d番目の要素が見つかりませんでした\n", inputVal);
	}
	else {
		cell_->DeleteCell(inputVal);
		printf("%d番目の要素を削除しました\n", inputVal);
	}

	SceneManager::SceneChange(0);
}