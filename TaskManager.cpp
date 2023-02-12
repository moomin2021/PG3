#include "TaskManager.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

unsigned short int TaskManager::idCount_ = 0;

void TaskManager::Create()
{
	// 名前を入力で受け取る
	InputName();

	// 所属名を入力で受け取る
	InputAffiliationName();
}

void TaskManager::Display()
{
	cout << "ID : " << id_ << " 名前 : " << name_ << " 所属名 : " << affiliationName_ << endl;
}

void TaskManager::CreateID()
{
	// ID指定
	id_ = idCount_;

	// カウント進行
	idCount_++;
}

void TaskManager::InputName()
{
	// ユーザーに入力物の説明を表示
	printf_s("-----名前を入力してください-----\n");

	// 入力を受け取る
	cin >> name_;
}

void TaskManager::InputAffiliationName()
{
	// ユーザーに入力物の説明を表示
	printf_s("-----所属名を入力してください-----\n");

	// 入力を受け取る
	cin >> affiliationName_;
}