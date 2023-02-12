#pragma once
#include "TaskManager.h"
#include <string>

struct Date {
	int year;// -> 年
	int month;// -> 月
	int day;// -> 日
};

class Task {

public:// -----メンバ変数----- //
	// ID
	unsigned short int id_;

	// 担当者
	TaskManager taskManager_;

	// 題名
	std::string title_;

	// 内容
	std::string content_;

	// 優先度
	std::string priority_;

	// 期限
	Date limit_;

	// タスクの達成フラグ
	std::string completion_;

private:// -----静的メンバ変数
	// 生成したID数
	static unsigned short int idCount_;

public:// -----メンバ関数----- //
	/// <summary>
	/// タスク生成
	/// </summary>
	void Create();

	/// <summary>
	/// タスク表示
	/// </summary>
	void Display();

	/// <summary>
	/// 題名入力
	/// </summary>
	void InputTitle();

	/// <summary>
	/// 内容入力
	/// </summary>
	void InputContent();

	/// <summary>
	/// 優先度選択
	/// </summary>
	void SelectPriority();

	/// <summary>
	/// 期限入力
	/// </summary>
	void InputLimit();

	/// <summary>
	/// タスク達成選択
	/// </summary>
	void SelectCompletion();

	/// <summary>
	/// IDを生成
	/// </summary>
	void CreateID();

	/// <summary>
	/// 担当者設定
	/// </summary>
	/// <param name="taskManager"></param>
	inline void SetTaskManager(const TaskManager& taskManager) { taskManager_ = taskManager; }
};