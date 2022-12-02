#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SceneManager.h"

int main() {

	// シーン管理クラス
	SceneManager* scene = SceneManager::GetInstance();

	while (true) {
		scene->Update();
	}

	return 0;

	delete scene;
}