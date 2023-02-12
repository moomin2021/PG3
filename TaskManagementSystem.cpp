#include <stdio.h>
#include <iostream>
#include <string>
#include "TaskManagementSystem.h"

using namespace std;

void TaskManagementSystem::Initialize()
{
	// ���݂̃V�[��
	nowScene_ = MENU;
}

void TaskManagementSystem::Update()
{
	// �V�[���X�V����
	(this->*sceneTable[nowScene_])();
}

void TaskManagementSystem::Menu()
{
	// �I���ꗗ�\��
	printf_s("-----[���j���[]-----\n");
	printf_s("�I������������̔ԍ�����͂��Ă��������B\n");
	printf_s("1 : �^�X�N�\��\n");
	printf_s("2 : �^�X�N�ǉ�\n");
	printf_s("3 : �^�X�N�폜\n");
	printf_s("4 : �^�X�N�ҏW\n");
	printf_s("5 : �^�X�N�S���ҕ\��\n");
	printf_s("6 : �^�X�N�S���Ғǉ�\n");
	printf_s("7 : �^�X�N�S���ҍ폜\n");
	printf_s("8 : �^�X�N�S���ҕҏW\n");


	// ���͕ۑ��p�ϐ�
	string inputStr;

	// ���͑҂�
	cin >> inputStr;

	// ���͂��ꂽ�l��1��������
	if (inputStr == "1") {
		// �V�[����؂�ւ���
		nowScene_ = TASKDISPLAY;
	}

	// ���͂��ꂽ�l��2������
	else if (inputStr == "2") {
		// �V�[����؂�ւ���
		nowScene_ = TASKADD;
	}

	// ���͂��ꂽ�l��3������
	else if (inputStr == "3") {
		// �V�[����؂�ւ���
		nowScene_ = TASKDELETE;
	}

	// ���͂��ꂽ�l��4������
	else if (inputStr == "4") {
		// �V�[����؂�ւ���
		nowScene_ = TASKEDIT;
	}

	// ���͂��ꂽ�l��5������
	else if (inputStr == "5") {
		// �V�[����؂�ւ���
		nowScene_ = TASKMANAGERDISPLAY;
	}

	// ���͂��ꂽ�l��6������
	else if (inputStr == "6") {
		// �V�[����؂�ւ���
		nowScene_ = TASKMANAGERADD;
	}

	// ���͂��ꂽ�l��7������
	else if (inputStr == "7") {
		// �V�[����؂�ւ���
		nowScene_ = TASKMANAGERDELETE;
	}

	// ���͂��ꂽ�l��8������
	else if (inputStr == "8") {
		// �V�[����؂�ւ���
		nowScene_ = TASKMANAGEREDIT;
	}

	// �z�肳��Ă��Ȃ��l�Ȃ�
	else {
		printf_s("�����Ȓl�����͂���܂����B\n\n");
	}
}

void TaskManagementSystem::TaskDisplay()
{
	// �^�X�N��0��������
	if (taskManagers_.size() == 0) {
		// �^�X�N���Ȃ����Ƃ�\��
		printf_s("���݃^�X�N�͂���܂���\n");
		nowScene_ = MENU;
		return;
	}

	for (auto& task : tasks_) {
		task.Display();
	}

	cout << "���݂̃^�X�N�͈ȏ�őS�Ăł�" << endl;
	cout << "���j���[�֖߂�ۂ�[1]����͂��Ă�������" << endl;

	while (true) {
		string inputNum;
		cin >> inputNum;

		if (inputNum == "1") {
			nowScene_ = MENU;
			break;
		}
		else {
			cout << "�����ȓ��͂ł��B�ē��͂��Ă�������" << endl;
		}
	}
}

void TaskManagementSystem::TaskAdd()
{
	// �S���҂���l�����Ȃ��ꍇ
	if (taskManagers_.size() == 0) {
		cout << "�S���҂����Ȃ����߃^�X�N�̐ݒ肪�ł��܂���" << endl;
		cout << "�^�X�N��ǉ�����ɂ͒S���҂�ǉ����Ă�������" << endl;
		nowScene_ = MENU;// -> ���j���[�ɖ߂�
		return;
	}

	// �ݒ�p�^�X�N��`
	Task task;

	// �w���\��
	cout << "-----�S���҂�ID����͂��Ă�������-----" << endl;

	while (true) {
		int inputNum;// -> ���͕ۑ��p�ϐ�
		cin >> inputNum;// -> ���͑҂�

		// ID�����t���O
		bool isIDDiscovery = false;

		// �Y������S���҂̏���ݒ�
		for (auto& taskManager : taskManagers_) {
			if (inputNum == taskManager.id_) {
				task.SetTaskManager(taskManager);
				isIDDiscovery = true;
			}
		}

		// �Y������ID�𔭌������烋�[�v�𔲂���
		if (isIDDiscovery) break;

		// �Y������S���҂����Ȃ�������
		cout << "���͂��ꂽID�̒S���҂�������܂���ł���" << endl;
		cout << "�ē��͂��Ă�������" << endl;
	}

	// �^�X�N�ݒ�
	task.CreateID();
	task.Create();

	// �^�X�N����
	tasks_.push_back(task);

	// �V�[���ݒ�
	nowScene_ = MENU;
}

void TaskManagementSystem::TaskDelete()
{
	cout << "�폜�������^�X�N��ID����͂��Ă�������" << endl;
	int inputNum = 0;
	cin >> inputNum;

	for (size_t i = 0; i < tasks_.size(); i++) {
		if (tasks_.at(i).id_ == inputNum) {
			tasks_.erase(tasks_.begin() + i);
			break;
		}
	}

	cout << "�w��ID�̃^�X�N���폜���܂���" << endl;
	nowScene_ = MENU;
}

void TaskManagementSystem::TaskEdit()
{
	// �^�X�N����l�����Ȃ�������
	if (tasks_.size() == 0) {
		// �^�X�N���Ȃ����Ƃ�\��
		printf_s("�^�X�N������܂���\n");
		nowScene_ = MENU;
		return;
	}

	cout << "-----[�^�X�N�ҏW]-----" << endl;
	cout << "�ύX�������^�X�N��ID����͂��Ă�������" << endl;

	Task* taskPtr = nullptr;

	while (true) {
		int inputNum;// -> ���͕ۑ��p
		cin >> inputNum;// -> ���͎�t

		// ID�����t���O
		bool isIDDiscovery = false;

		// �Y������S���҂̏���ݒ�
		for (auto& task : tasks_) {
			if (inputNum == task.id_) {
				taskPtr = &task;
				isIDDiscovery = true;
			}
		}

		// �Y������ID�𔭌������烋�[�v�𔲂���
		if (isIDDiscovery) break;

		// �Y������S���҂����Ȃ�������
		cout << "���͂��ꂽID�̃^�X�N��������܂���ł���" << endl;
		cout << "�ē��͂��Ă�������" << endl;
	}

	taskPtr->Create();

	cout << "�^�X�N�����ȉ��ɕύX���܂���" << endl;
	taskPtr->Display();
	nowScene_ = MENU;
}

void TaskManagementSystem::TaskManagerDisplay()
{
	// �^�X�N�S���҂���l�����Ȃ�������
	if (taskManagers_.size() == 0) {
		// �^�X�N�S���҂����Ȃ����Ƃ�\��
		printf_s("���ݒS���҂����܂���\n");
		nowScene_ = MENU;
		return;
	}

	for (auto& taskManager : taskManagers_) {
		taskManager.Display();
	}

	cout << "�S���҂͈ȏ�őS�Ăł�" << endl;
	cout << "���j���[�֖߂�ۂ�[1]����͂��Ă�������" << endl;

	while (true) {
		string inputNum;
		cin >> inputNum;

		if (inputNum == "1") {
			nowScene_ = MENU;
			break;
		}
		else {
			cout << "�����ȓ��͂ł��B�ē��͂��Ă�������" << endl;
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
	// �^�X�N�S���҂���l�����Ȃ�������
	if (taskManagers_.size() == 0) {
		// �^�X�N�S���҂����Ȃ����Ƃ�\��
		printf_s("���ݒS���҂����܂���\n");
		nowScene_ = MENU;
		return;
	}

	cout << "�폜�������S���҂�ID����͂��Ă�������" << endl;
	int inputNum = 0;
	cin >> inputNum;

	for (size_t i = 0; i < taskManagers_.size(); i++) {
		if (taskManagers_.at(i).id_ == inputNum) {
			taskManagers_.erase(taskManagers_.begin() + i);
			break;
		}
	}

	cout << "�w��ID�̒S���҂��폜���܂���" << endl;
	nowScene_ = MENU;
}

void TaskManagementSystem::TaskManagerEdit()
{
	// �^�X�N�S���҂���l�����Ȃ�������
	if (taskManagers_.size() == 0) {
		// �^�X�N�S���҂����Ȃ����Ƃ�\��
		printf_s("���ݒS���҂����܂���\n");
		nowScene_ = MENU;
		return;
	}

	cout << "-----[�^�X�N�S���ҕҏW]-----" << endl;
	cout << "�ύX�������S���҂�ID����͂��Ă�������" << endl;

	TaskManager* taskManagerPtr = nullptr;

	while (true) {
		int inputNum;// -> ���͕ۑ��p
		cin >> inputNum;// -> ���͎�t

		// ID�����t���O
		bool isIDDiscovery = false;

		// �Y������S���҂̏���ݒ�
		for (auto& taskManager : taskManagers_) {
			if (inputNum == taskManager.id_) {
				taskManagerPtr = &taskManager;
				isIDDiscovery = true;
			}
		}

		// �Y������ID�𔭌������烋�[�v�𔲂���
		if (isIDDiscovery) break;

		// �Y������S���҂����Ȃ�������
		cout << "���͂��ꂽID�̒S���҂�������܂���ł���" << endl;
		cout << "�ē��͂��Ă�������" << endl;
	}

	taskManagerPtr->Create();

	cout << "�S���ҏ����ȉ��ɕύX���܂���" << endl;
	taskManagerPtr->Display();
	nowScene_ = MENU;
}

void (TaskManagementSystem::* TaskManagementSystem::sceneTable[])() = {
	&TaskManagementSystem::Menu,// -> �I�����
	&TaskManagementSystem::TaskDisplay,// -> �^�X�N�\��
	&TaskManagementSystem::TaskAdd,// -> �^�X�N�ǉ�
	&TaskManagementSystem::TaskDelete,// -> �^�X�N�폜
	&TaskManagementSystem::TaskEdit,// -> �^�X�N�ҏW
	&TaskManagementSystem::TaskManagerDisplay,// -> �^�X�N�S���ҕ\��
	&TaskManagementSystem::TaskManagerAdd,// -> �^�X�N�S���Ғǉ�
	&TaskManagementSystem::TaskManagerDelete,// -> �^�X�N�S���ҍ폜
	&TaskManagementSystem::TaskManagerEdit,// -> �^�X�N�S���ҕҏW
};