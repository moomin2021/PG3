#include "Scene3.h"
#include <stdio.h>
#include <stdlib.h>
#include "SceneManager.h"

Scene3::Scene3() :
	cell_(nullptr)
{

}

void Scene3::Initialize(CELL* cell) {
	// セルを保存
	cell_ = cell;
}

void Scene3::Update() {
	printf("--------------------\n");
	printf("[要素の編集]\n");
	printf("編集したい要素の番号を指定してください\n");
	int inputVal;
	scanf_s("%d", &inputVal);

	if (inputVal >= cell_->size()) {
		printf("%d番目の要素が見つかりませんでした\n", inputVal);
	}

	else {
		printf("%d番目の要素の変更する文字列を入力してください\n", inputVal);
		char str[8];
		scanf_s("%s", str, 8);
		cell_->SetChangeStr(str, inputVal);
		printf("%d番目の要素の文字列が\"%s\"に変更されました\n", inputVal, str);
	}
	printf("--------------------\n");
	SceneManager::SceneChange(0);
}