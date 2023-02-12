#include "Task.h"
#include <stdio.h>
#include <iostream>

using namespace std;

unsigned short int Task::idCount_ = 0;

void Task::Create()
{
	// 題名入力
	InputTitle();

	// 内容入力
	InputContent();

	// 優先度入力
	SelectPriority();

	// 期限の入力
	InputLimit();

	// 達成度選択
	SelectCompletion();

	cout << "-----この内容でタスクを追加します-----";
	Display();
}

void Task::Display()
{
	// タスクを表示
	cout << "--------------------------------------------------" << endl;
	cout << "ID : " << id_ << endl;
	cout << "担当者 : " << taskManager_.name_ << endl;
	cout << "題名 : " << title_ << endl;
	cout << "内容 :" << content_ << endl;
	cout << "優先度 : " << priority_ << endl;
	cout << "期限 : " << limit_.year << " / " << limit_.month << " / " << limit_.day << endl;
	cout << "状態 : " << completion_ << endl;
}

void Task::InputTitle()
{
	// 指示表示
	cout << "-----題名を入力してください-----" << endl;
	cin >> title_;// -> 入力受け取り
}

void Task::InputContent()
{
	// 指示表示
	cout << "-----内容を入力してください-----" << endl;
	cin >> content_;// -> 入力受け取り
}

void Task::SelectPriority()
{
	// 指示表示
	cout << "-----優先度を選択してください-----" << endl;
	cout << "1 : 高" << endl;
	cout << "2 : 中" << endl;
	cout << "3 : 小" << endl;

	while (true) {
		string inputStr;// -> 入力保存用変数
		cin >> inputStr;// -> 入力受け取り

		// 入力が1だったら
		if (inputStr == "1") {
			priority_ = "高";
			break;
		}

		// 入力が2だったら
		else if (inputStr == "2") {
			priority_ = "中";
			break;
		}

		// 入力が3だったら
		else if (inputStr == "3") {
			priority_ = "小";
			break;
		}

		// 入力が正しくなかったら
		else {
			// 再度入力をうながす
			cout << "無効な入力です。再入力してください" << endl;
		}
	}
}

void Task::InputLimit()
{
	cout << "-----期限の設定-----" << endl;
	cout << "年を入力してください" << endl;
	cin >> limit_.year;
	cout << "月を入力してください" << endl;
	cin >> limit_.month;
	cout << "日を入力してください" << endl;
	cin >> limit_.day;
}

void Task::SelectCompletion() {
	// 指示表示
	cout << "-----達成度を選択してください-----" << endl;
	cout << "1 : 達成" << endl;
	cout << "2 : 未達成" << endl;

	while (true) {
		string inputStr;// -> 入力保存用変数
		cin >> inputStr;// -> 入力受け取り

		// 入力が1だったら
		if (inputStr == "1") {
			completion_ = "達成";
			break;
		}

		// 入力が2だったら
		else if (inputStr == "2") {
			completion_ = "未達成";
			break;
		}

		// 入力が正しくなかったら
		else {
			// 再度入力をうながす
			cout << "無効な入力です。再入力してください" << endl;
		}
	}
}

void Task::CreateID()
{
	id_ = idCount_;
	idCount_++;
}