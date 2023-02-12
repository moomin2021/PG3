#pragma once
#include <string>

// タスク担当者
class TaskManager {
public:// -----メンバ変数----- //
	// ID
	unsigned short int id_;

	// 所属名
	std::string affiliationName_;

	// 名前
	std::string name_;

private:// -----メンバ変数----- //
	// 生成したID数
	static unsigned short int idCount_;

public:// -----メンバ関数----- //
	/// <summary>
	/// タスク担当者の作成
	/// </summary>
	void Create();

	/// <summary>
	/// タスク担当者の表示
	/// </summary>
	void Display();
	/// <summary>
	/// ID生成
	/// </summary>
	void CreateID();

	/// <summary>
	/// 名前の入力を受け取る
	/// </summary>
	void InputName();

	/// <summary>
	/// 所属名の入力を受け取る
	/// </summary>
	void InputAffiliationName();
};