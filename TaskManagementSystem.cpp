#include <stdio.h>
#include <iostream>
#include <string>
#include "TaskManagementSystem.h"

using namespace std;

void TaskManagementSystem::Initialize()
{
	// 現在のシーン
	nowScene_ = MENU;
}

void TaskManagementSystem::Update()
{
	// シーン更新処理
	(this->*sceneTable[nowScene_])();
}

void TaskManagementSystem::Menu()
{
	// 選択一覧表示
	printf_s("-----[メニュー]-----\n");
	printf_s("選択したい操作の番号を入力してください。\n");
	printf_s("1 : タスク表示\n");
	printf_s("2 : タスク追加\n");
	printf_s("3 : タスク削除\n");
	printf_s("4 : タスク編集\n");
	printf_s("5 : タスク担当者表示\n");
	printf_s("6 : タスク担当者追加\n");
	printf_s("7 : タスク担当者削除\n");
	printf_s("8 : タスク担当者編集\n");


	// 入力保存用変数
	string inputStr;

	// 入力待ち
	cin >> inputStr;

	// 入力された値が1だったら
	if (inputStr == "1") {
		// シーンを切り替える
		nowScene_ = TASKDISPLAY;
	}

	// 入力された値が2だった
	else if (inputStr == "2") {
		// シーンを切り替える
		nowScene_ = TASKADD;
	}

	// 入力された値が3だった
	else if (inputStr == "3") {
		// シーンを切り替える
		nowScene_ = TASKDELETE;
	}

	// 入力された値が4だった
	else if (inputStr == "4") {
		// シーンを切り替える
		nowScene_ = TASKEDIT;
	}

	// 入力された値が5だった
	else if (inputStr == "5") {
		// シーンを切り替える
		nowScene_ = TASKMANAGERDISPLAY;
	}

	// 入力された値が6だった
	else if (inputStr == "6") {
		// シーンを切り替える
		nowScene_ = TASKMANAGERADD;
	}

	// 入力された値が7だった
	else if (inputStr == "7") {
		// シーンを切り替える
		nowScene_ = TASKMANAGERDELETE;
	}

	// 入力された値が8だった
	else if (inputStr == "8") {
		// シーンを切り替える
		nowScene_ = TASKMANAGEREDIT;
	}

	// 想定されていない値なら
	else {
		printf_s("無効な値が入力されました。\n\n");
	}
}

void TaskManagementSystem::TaskDisplay()
{
	// タスクが0だったら
	if (taskManagers_.size() == 0) {
		// タスクがないことを表示
		printf_s("現在タスクはありません\n");
		nowScene_ = MENU;
		return;
	}

	for (auto& task : tasks_) {
		task.Display();
	}

	cout << "現在のタスクは以上で全てです" << endl;
	cout << "メニューへ戻る際は[1]を入力してください" << endl;

	while (true) {
		string inputNum;
		cin >> inputNum;

		if (inputNum == "1") {
			nowScene_ = MENU;
			break;
		}
		else {
			cout << "無効な入力です。再入力してください" << endl;
		}
	}
}

void TaskManagementSystem::TaskAdd()
{
	// 担当者が一人もいない場合
	if (taskManagers_.size() == 0) {
		cout << "担当者がいないためタスクの設定ができません" << endl;
		cout << "タスクを追加するには担当者を追加してください" << endl;
		nowScene_ = MENU;// -> メニューに戻る
		return;
	}

	// 設定用タスク定義
	Task task;

	// 指示表示
	cout << "-----担当者のIDを入力してください-----" << endl;

	while (true) {
		int inputNum;// -> 入力保存用変数
		cin >> inputNum;// -> 入力待ち

		// ID発見フラグ
		bool isIDDiscovery = false;

		// 該当する担当者の情報を設定
		for (auto& taskManager : taskManagers_) {
			if (inputNum == taskManager.id_) {
				task.SetTaskManager(taskManager);
				isIDDiscovery = true;
			}
		}

		// 該当するIDを発見したらループを抜ける
		if (isIDDiscovery) break;

		// 該当する担当者がいなかったら
		cout << "入力されたIDの担当者が見つかりませんでした" << endl;
		cout << "再入力してください" << endl;
	}

	// タスク設定
	task.CreateID();
	task.Create();

	// タスク生成
	tasks_.push_back(task);

	// シーン設定
	nowScene_ = MENU;
}

void TaskManagementSystem::TaskDelete()
{
	cout << "削除したいタスクのIDを入力してください" << endl;
	int inputNum = 0;
	cin >> inputNum;

	for (size_t i = 0; i < tasks_.size(); i++) {
		if (tasks_.at(i).id_ == inputNum) {
			tasks_.erase(tasks_.begin() + i);
			break;
		}
	}

	cout << "指定IDのタスクを削除しました" << endl;
	nowScene_ = MENU;
}

void TaskManagementSystem::TaskEdit()
{
	// タスクが一人もいなかったら
	if (tasks_.size() == 0) {
		// タスクがないことを表示
		printf_s("タスクがありません\n");
		nowScene_ = MENU;
		return;
	}

	cout << "-----[タスク編集]-----" << endl;
	cout << "変更したいタスクのIDを入力してください" << endl;

	Task* taskPtr = nullptr;

	while (true) {
		int inputNum;// -> 入力保存用
		cin >> inputNum;// -> 入力受付

		// ID発見フラグ
		bool isIDDiscovery = false;

		// 該当する担当者の情報を設定
		for (auto& task : tasks_) {
			if (inputNum == task.id_) {
				taskPtr = &task;
				isIDDiscovery = true;
			}
		}

		// 該当するIDを発見したらループを抜ける
		if (isIDDiscovery) break;

		// 該当する担当者がいなかったら
		cout << "入力されたIDのタスクが見つかりませんでした" << endl;
		cout << "再入力してください" << endl;
	}

	taskPtr->Create();

	cout << "タスク情報を以下に変更しました" << endl;
	taskPtr->Display();
	nowScene_ = MENU;
}

void TaskManagementSystem::TaskManagerDisplay()
{
	// タスク担当者が一人もいなかったら
	if (taskManagers_.size() == 0) {
		// タスク担当者がいないことを表示
		printf_s("現在担当者がいません\n");
		nowScene_ = MENU;
		return;
	}

	for (auto& taskManager : taskManagers_) {
		taskManager.Display();
	}

	cout << "担当者は以上で全てです" << endl;
	cout << "メニューへ戻る際は[1]を入力してください" << endl;

	while (true) {
		string inputNum;
		cin >> inputNum;

		if (inputNum == "1") {
			nowScene_ = MENU;
			break;
		}
		else {
			cout << "無効な入力です。再入力してください" << endl;
		}
	}
}

void TaskManagementSystem::TaskManagerAdd()
{
	TaskManager addTaskManager;
	addTaskManager.CreateID();
	addTaskManager.Create();

	taskManagers_.push_back(addTaskManager);

	nowScene_ = MENU;
}

void TaskManagementSystem::TaskManagerDelete()
{
	// タスク担当者が一人もいなかったら
	if (taskManagers_.size() == 0) {
		// タスク担当者がいないことを表示
		printf_s("現在担当者がいません\n");
		nowScene_ = MENU;
		return;
	}

	cout << "削除したい担当者のIDを入力してください" << endl;
	int inputNum = 0;
	cin >> inputNum;

	for (size_t i = 0; i < taskManagers_.size(); i++) {
		if (taskManagers_.at(i).id_ == inputNum) {
			taskManagers_.erase(taskManagers_.begin() + i);
			break;
		}
	}

	cout << "指定IDの担当者を削除しました" << endl;
	nowScene_ = MENU;
}

void TaskManagementSystem::TaskManagerEdit()
{
	// タスク担当者が一人もいなかったら
	if (taskManagers_.size() == 0) {
		// タスク担当者がいないことを表示
		printf_s("現在担当者がいません\n");
		nowScene_ = MENU;
		return;
	}

	cout << "-----[タスク担当者編集]-----" << endl;
	cout << "変更したい担当者のIDを入力してください" << endl;

	TaskManager* taskManagerPtr = nullptr;

	while (true) {
		int inputNum;// -> 入力保存用
		cin >> inputNum;// -> 入力受付

		// ID発見フラグ
		bool isIDDiscovery = false;

		// 該当する担当者の情報を設定
		for (auto& taskManager : taskManagers_) {
			if (inputNum == taskManager.id_) {
				taskManagerPtr = &taskManager;
				isIDDiscovery = true;
			}
		}

		// 該当するIDを発見したらループを抜ける
		if (isIDDiscovery) break;

		// 該当する担当者がいなかったら
		cout << "入力されたIDの担当者が見つかりませんでした" << endl;
		cout << "再入力してください" << endl;
	}

	taskManagerPtr->Create();

	cout << "担当者情報を以下に変更しました" << endl;
	taskManagerPtr->Display();
	nowScene_ = MENU;
}

void (TaskManagementSystem::* TaskManagementSystem::sceneTable[])() = {
	&TaskManagementSystem::Menu,// -> 選択画面
	&TaskManagementSystem::TaskDisplay,// -> タスク表示
	&TaskManagementSystem::TaskAdd,// -> タスク追加
	&TaskManagementSystem::TaskDelete,// -> タスク削除
	&TaskManagementSystem::TaskEdit,// -> タスク編集
	&TaskManagementSystem::TaskManagerDisplay,// -> タスク担当者表示
	&TaskManagementSystem::TaskManagerAdd,// -> タスク担当者追加
	&TaskManagementSystem::TaskManagerDelete,// -> タスク担当者削除
	&TaskManagementSystem::TaskManagerEdit,// -> タスク担当者編集
};