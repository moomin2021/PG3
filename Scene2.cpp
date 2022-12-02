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
	// セルを保存
	cell_ = cell;
}

void Scene2::Update() {
	printf("--------------------\n");
	printf("[リスト要素の挿入]\n");
	printf("要素を追加する場所を指定してください\n");
	printf("最後尾に追加する場合は[0]を入力してください\n");

	// 入力を受け取る
	int inputVal;
	scanf_s("%d", &inputVal);

	if (inputVal == 0) {
		// 追加する文字列を入力読み込み
		printf("追加する要素の文字列を入力してください\n");
		char str[8];
		scanf_s("%s", str, 8);

		cell_->SetStr(str, cell_->size());

		printf("要素\"%s\"が%d番目に挿入されました\n", str, cell_->size());
		printf("--------------------\n");
	}

	else if (cell_->size() >= inputVal) {
		// 追加する文字列を入力読み込み
		printf("追加する要素の文字列を入力してください\n");
		char str[8];
		scanf_s("%s", str, 8);

		cell_->SetStr(str, inputVal);

		printf("要素\"%s\"が%d番目に挿入されました\n", str, inputVal);
		printf("--------------------\n");
	}

	else {
		printf("入力された要素番号は範囲外です\n");
		printf("--------------------\n");
	}

	SceneManager::SceneChange(0);
}