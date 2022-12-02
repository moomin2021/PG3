#pragma once
#include "BaseScene.h"
#include "Cell.h"

class Scene1 : public BaseScene {
	// --メンバ変数-- //
public:

private:
	// 選択しているシーン
	int selectScene_;

	// セル
	CELL* cell_;

	// --メンバ関数-- //
public:
	// コンストラクタ
	Scene1();

	// 初期化処理
	void Initialize(CELL* cell);

	// 更新処理
	void Update();

private:
	// 各シーン
	void Scene0Update();
	void Scene1Update();
	void Scene2Update();
};