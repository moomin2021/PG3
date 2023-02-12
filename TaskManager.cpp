#include "TaskManager.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

unsigned short int TaskManager::idCount_ = 0;

void TaskManager::Create()
{
	// ���O����͂Ŏ󂯎��
	InputName();

	// ����������͂Ŏ󂯎��
	InputAffiliationName();
}

void TaskManager::Display()
{
	cout << "ID : " << id_ << " ���O : " << name_ << " ������ : " << affiliationName_ << endl;
}

void TaskManager::CreateID()
{
	// ID�w��
	id_ = idCount_;

	// �J�E���g�i�s
	idCount_++;
}

void TaskManager::InputName()
{
	// ���[�U�[�ɓ��͕��̐�����\��
	printf_s("-----���O����͂��Ă�������-----\n");

	// ���͂��󂯎��
	cin >> name_;
}

void TaskManager::InputAffiliationName()
{
	// ���[�U�[�ɓ��͕��̐�����\��
	printf_s("-----����������͂��Ă�������-----\n");

	// ���͂��󂯎��
	cin >> affiliationName_;
}