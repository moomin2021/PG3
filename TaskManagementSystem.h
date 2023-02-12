#pragma once
#include "TaskManager.h"
#include "Task.h"
#include <vector>

/// <summary>
/// タスク管理システム
/// </summary>
class TaskManagementSystem
{
private:
	enum SCENE {
		MENU,// -> メニュー画面
		TASKDISPLAY,// -> タスク表示
		TASKADD,// -> タスク追加
		TASKDELETE,// -> タスクの削除
		TASKEDIT,// -> タスク編集
		TASKMANAGERDISPLAY,// -> タスク担当者表示
		TASKMANAGERADD,// -> タスク担当者追加
		TASKMANAGERDELETE,// -> タスク担当者削除
		TASKMANAGEREDIT,// -> タスク担当者編集
	};

private:// ------メンバ変数----- //
	// 現在のシーン
	unsigned short int nowScene_;

	// タスク一覧
	std::vector<Task> tasks_;

	// 担当者一覧
	std::vector<TaskManager> taskManagers_;

public:// -----メンバ関数----- //
	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

private:// -----メンバ関数----- //
	/// <summary>
	/// シーンごとの更新処理
	/// </summary>
	static void (TaskManagementSystem::* sceneTable[])();

	/// <summary>
	/// メニューシーンの更新処理
	/// </summary>
	void Menu();

	/// <summary>
	/// タスク表示シーンの更新処理
	/// </summary>
	void TaskDisplay();

	/// <summary>
	/// タスク追加シーンの更新処理
	/// </summary>
	void TaskAdd();

	/// <summary>
	/// タスク削除シーンの更新処理
	/// </summary>
	void TaskDelete();

	/// <summary>
	/// タスク編集シーン更新処理
	/// </summary>
	void TaskEdit();

	/// <summary>
	/// タスク担当者表示
	/// </summary>
	void TaskManagerDisplay();

	/// <summary>
	/// タスク担当者追加
	/// </summary>
	void TaskManagerAdd();

	/// <summary>
	/// タスク担当者削除
	/// </summary>
	void TaskManagerDelete();

	/// <summary>
	/// タスク担当者編集
	/// </summary>
	void TaskManagerEdit();
};