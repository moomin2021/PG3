#pragma once
#include "BaseScene.h"

class GamePlayScene : public BaseScene {
	// --メンバ関数-- //
public:
	// コンストラクタ
	GamePlayScene();

	// デストラクタ
	~GamePlayScene();

	// 初期化処理
	void Initialize();

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

private:

	// --メンバ変数-- //
public:

private:

};