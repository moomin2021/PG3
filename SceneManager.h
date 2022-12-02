#pragma once
#include "BaseScene.h"
#include "Cell.h"

class SceneManager {
	// --メンバ変数-- //
public:

private:
	// 現在のシーン
	static BaseScene* nowScene_;

	// セル
	static CELL cell_;

	// --メンバ関数-- //
public:
	// インスタンス取得
	static SceneManager* GetInstance();

	// 更新処理
	void Update();

	// シーンを切り替える
	static void SceneChange(int scene);

private:
	// コンストラクタ
	SceneManager();

	// --禁止-- //
public:
	// コピーコンストラクタ
	SceneManager(const SceneManager& instance) = delete;

	// 代入演算子
	SceneManager& operator=(const SceneManager& instance) = delete;
};