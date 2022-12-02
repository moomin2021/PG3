#pragma once
#include "BaseScene.h"
#include "Cell.h"

class Scene3 : public BaseScene {
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
	Scene3();

	// 初期化処理
	void Initialize(CELL* cell);

	// 更新処理
	void Update();

private:

};