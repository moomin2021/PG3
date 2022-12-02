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
	// セルを保存
	cell_ = cell;
}

void Scene0::Update()
{
	// 要素の操作の選択一覧を表示
	printf("--------------------\n");
	printf("[要素の操作]\n");
	printf("1. 要素の表示\n");
	printf("2. 要素の挿入\n");

	// サイズが0だった場合表示しない
	if (cell_->size() != 0) {
		printf("3. 要素の編集\n");
		printf("4. 要素の削除\n");
	}

	printf("--------------------\n");
	printf("操作を選択してください\n");

	// 入力を受け取る
	int selectVal = 0;
	scanf_s("%d", &selectVal);

	printf("\n");// -> 改行

	// 受け取った値によってアクションを変える
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
		printf("選択できませんでした\n");
		printf("--------------------\n\n");
		break;
	}
}
