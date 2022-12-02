#include "SceneManager.h"
#include "Scene0.h"
#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"
#include "Scene4.h"
#include <stdio.h>
#include <stdlib.h>

BaseScene* SceneManager::nowScene_ = new Scene0();

CELL SceneManager::cell_;

SceneManager* SceneManager::GetInstance()
{
	// ŠÖ”“àstatic•Ï”‚Æ‚µ‚ÄéŒ¾
	static SceneManager instance;
	return &instance;
}

SceneManager::SceneManager()
{
	nowScene_->Initialize(&cell_);
}

void SceneManager::Update() {
	nowScene_->Update();
}

void SceneManager::SceneChange(int scene)
{
	// ƒƒ‚ƒŠ‰ð•ú
	delete nowScene_;

	switch (scene)
	{
	case 0:
		nowScene_ = new Scene0();
		nowScene_->Initialize(&cell_);
		break;
	case 1:
		nowScene_ = new Scene1();
		nowScene_->Initialize(&cell_);
		break;
	case 2:
		nowScene_ = new Scene2();
		nowScene_->Initialize(&cell_);
		break;
	case 3:
		nowScene_ = new Scene3();
		nowScene_->Initialize(&cell_);
		break;
	case 4:
		nowScene_ = new Scene4();
		nowScene_->Initialize(&cell_);
		break;
	}
}
