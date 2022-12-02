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
	// セルを保存
	cell_ = cell;
}

void Scene1::Update()
{
	// 選択されているシーンのアクションをする
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
	// 要素の表示の仕方の選択一覧を表示
	printf("--------------------\n");
	printf("[要素の表示]\n");
	printf("1. 要素の一覧表示\n");
	printf("2. 順番を指定して要素を表示\n");
	printf("9. 要素の操作に戻る\n");
	printf("--------------------\n\n");

	printf("操作を選択してください\n");

	// 入力を受け取る
	int selectVal = 0;
	scanf_s("%d", &selectVal);
	printf("\n");// -> 改行

	// 受け取った値によってアクションを変える
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
		printf("選択できませんでした\n");
		printf("--------------------\n\n");
		break;
	}
}

void Scene1::Scene1Update() {
	// 要素一覧表示
	printf("--------------------\n");
	printf("[要素の一覧表示]\n");
	printf("要素一覧: {\n");
	for (size_t i = 0; i < cell_->size(); i++) {
		printf("%d: \"%s\",\n", i, cell_->GetStr(i));
	}
	printf("}\n\n");

	// 要素数表示
	printf("要素数:%d\n", cell_->size());
	printf("--------------------\n");

	// 操作を表示
	printf("操作を選択してください\n");
	printf("1. 要素の表示に戻る\n");
	printf("2. 要素の操作に戻る\n");

	// 入力を受け取る
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
		printf("選択できないものを選んだため[要素の操作]画面に戻ります\n\n");
		SceneManager::SceneChange(0);
		break;
	}
}

void Scene1::Scene2Update() {
	// 指定された要素を表示
	printf("--------------------\n");
	printf("[順番を指定して要素を表示]\n");
	printf("表示したい要素の順番を指定してください\n");

	// 入力を受け取る
	int inputVal = 0;
	scanf_s("%d", &inputVal);
	printf("\n");// -> 改行

	// 返ってきたものがnullptrだったら
	if (cell_->GetStr(inputVal) == nullptr) {
		printf("その要素番号は範囲外です\n");
		printf("--------------------\n");
	}
	else {
		printf("%d : %s\n", inputVal, cell_->GetStr(inputVal));
		printf("--------------------\n");
	}

	// 操作を表示
	printf("操作を選択してください\n");
	printf("1. 要素の表示に戻る\n");
	printf("2. 要素の操作に戻る\n");

	// 入力を受け取る
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
		printf("選択できないものを選んだため[要素の操作]画面に戻ります\n\n");
		SceneManager::SceneChange(0);
		break;
	}
}