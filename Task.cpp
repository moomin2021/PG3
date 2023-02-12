#include "Task.h"
#include <stdio.h>
#include <iostream>

using namespace std;

unsigned short int Task::idCount_ = 0;

void Task::Create()
{
	// �薼����
	InputTitle();

	// ���e����
	InputContent();

	// �D��x����
	SelectPriority();

	// �����̓���
	InputLimit();

	// �B���x�I��
	SelectCompletion();

	cout << "-----���̓��e�Ń^�X�N��ǉ����܂�-----";
	Display();
}

void Task::Display()
{
	// �^�X�N��\��
	cout << "--------------------------------------------------" << endl;
	cout << "ID : " << id_ << endl;
	cout << "�S���� : " << taskManager_.name_ << endl;
	cout << "�薼 : " << title_ << endl;
	cout << "���e :" << content_ << endl;
	cout << "�D��x : " << priority_ << endl;
	cout << "���� : " << limit_.year << " / " << limit_.month << " / " << limit_.day << endl;
	cout << "��� : " << completion_ << endl;
}

void Task::InputTitle()
{
	// �w���\��
	cout << "-----�薼����͂��Ă�������-----" << endl;
	cin >> title_;// -> ���͎󂯎��
}

void Task::InputContent()
{
	// �w���\��
	cout << "-----���e����͂��Ă�������-----" << endl;
	cin >> content_;// -> ���͎󂯎��
}

void Task::SelectPriority()
{
	// �w���\��
	cout << "-----�D��x��I�����Ă�������-----" << endl;
	cout << "1 : ��" << endl;
	cout << "2 : ��" << endl;
	cout << "3 : ��" << endl;

	while (true) {
		string inputStr;// -> ���͕ۑ��p�ϐ�
		cin >> inputStr;// -> ���͎󂯎��

		// ���͂�1��������
		if (inputStr == "1") {
			priority_ = "��";
			break;
		}

		// ���͂�2��������
		else if (inputStr == "2") {
			priority_ = "��";
			break;
		}

		// ���͂�3��������
		else if (inputStr == "3") {
			priority_ = "��";
			break;
		}

		// ���͂��������Ȃ�������
		else {
			// �ēx���͂����Ȃ���
			cout << "�����ȓ��͂ł��B�ē��͂��Ă�������" << endl;
		}
	}
}

void Task::InputLimit()
{
	cout << "-----�����̐ݒ�-----" << endl;
	cout << "�N����͂��Ă�������" << endl;
	cin >> limit_.year;
	cout << "������͂��Ă�������" << endl;
	cin >> limit_.month;
	cout << "������͂��Ă�������" << endl;
	cin >> limit_.day;
}

void Task::SelectCompletion() {
	// �w���\��
	cout << "-----�B���x��I�����Ă�������-----" << endl;
	cout << "1 : �B��" << endl;
	cout << "2 : ���B��" << endl;

	while (true) {
		string inputStr;// -> ���͕ۑ��p�ϐ�
		cin >> inputStr;// -> ���͎󂯎��

		// ���͂�1��������
		if (inputStr == "1") {
			completion_ = "�B��";
			break;
		}

		// ���͂�2��������
		else if (inputStr == "2") {
			completion_ = "���B��";
			break;
		}

		// ���͂��������Ȃ�������
		else {
			// �ēx���͂����Ȃ���
			cout << "�����ȓ��͂ł��B�ē��͂��Ă�������" << endl;
		}
	}
}

void Task::CreateID()
{
	id_ = idCount_;
	idCount_++;
}