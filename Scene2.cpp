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
	// ƒZƒ‹‚ğ•Û‘¶
	cell_ = cell;
}

void Scene2::Update() {
	printf("--------------------\n");
	printf("[ƒŠƒXƒg—v‘f‚Ì‘}“ü]\n");
	printf("—v‘f‚ğ’Ç‰Á‚·‚éêŠ‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢\n");
	printf("ÅŒã”ö‚É’Ç‰Á‚·‚éê‡‚Í[0]‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");

	// “ü—Í‚ğó‚¯æ‚é
	int inputVal;
	scanf_s("%d", &inputVal);

	if (inputVal == 0) {
		// ’Ç‰Á‚·‚é•¶š—ñ‚ğ“ü—Í“Ç‚İ‚İ
		printf("’Ç‰Á‚·‚é—v‘f‚Ì•¶š—ñ‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
		char str[8];
		scanf_s("%s", str, 8);

		cell_->SetStr(str, cell_->size());

		printf("—v‘f\"%s\"‚ª%d”Ô–Ú‚É‘}“ü‚³‚ê‚Ü‚µ‚½\n", str, cell_->size());
		printf("--------------------\n");
	}

	else if (cell_->size() >= inputVal) {
		// ’Ç‰Á‚·‚é•¶š—ñ‚ğ“ü—Í“Ç‚İ‚İ
		printf("’Ç‰Á‚·‚é—v‘f‚Ì•¶š—ñ‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
		char str[8];
		scanf_s("%s", str, 8);

		cell_->SetStr(str, inputVal);

		printf("—v‘f\"%s\"‚ª%d”Ô–Ú‚É‘}“ü‚³‚ê‚Ü‚µ‚½\n", str, inputVal);
		printf("--------------------\n");
	}

	else {
		printf("“ü—Í‚³‚ê‚½—v‘f”Ô†‚Í”ÍˆÍŠO‚Å‚·\n");
		printf("--------------------\n");
	}

	SceneManager::SceneChange(0);
}