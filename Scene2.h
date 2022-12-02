#pragma once
#include "BaseScene.h"
#include "Cell.h"

class Scene2 : public BaseScene {
	// --メンバ変数-- //
public:

private:
	// 選択したシーン
	int selectScene_;

	// セル
	CELL* cell_;

	// --メンバ関数-- //
public:
	// コンストラクタ
	Scene2();

	// 初期化処理
	void Initialize(CELL* cell);

	// 更新処理
	void Update();

private:

};