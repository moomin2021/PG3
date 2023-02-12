#pragma once
#include "TaskManager.h"
#include "Task.h"
#include <vector>

/// <summary>
/// �^�X�N�Ǘ��V�X�e��
/// </summary>
class TaskManagementSystem
{
private:
	enum SCENE {
		MENU,// -> ���j���[���
		TASKDISPLAY,// -> �^�X�N�\��
		TASKADD,// -> �^�X�N�ǉ�
		TASKDELETE,// -> �^�X�N�̍폜
		TASKEDIT,// -> �^�X�N�ҏW
		TASKMANAGERDISPLAY,// -> �^�X�N�S���ҕ\��
		TASKMANAGERADD,// -> �^�X�N�S���Ғǉ�
		TASKMANAGERDELETE,// -> �^�X�N�S���ҍ폜
		TASKMANAGEREDIT,// -> �^�X�N�S���ҕҏW
	};

private:// ------�����o�ϐ�----- //
	// ���݂̃V�[��
	unsigned short int nowScene_;

	// �^�X�N�ꗗ
	std::vector<Task> tasks_;

	// �S���҈ꗗ
	std::vector<TaskManager> taskManagers_;

public:// -----�����o�֐�----- //
	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

private:// -----�����o�֐�----- //
	/// <summary>
	/// �V�[�����Ƃ̍X�V����
	/// </summary>
	static void (TaskManagementSystem::* sceneTable[])();

	/// <summary>
	/// ���j���[�V�[���̍X�V����
	/// </summary>
	void Menu();

	/// <summary>
	/// �^�X�N�\���V�[���̍X�V����
	/// </summary>
	void TaskDisplay();

	/// <summary>
	/// �^�X�N�ǉ��V�[���̍X�V����
	/// </summary>
	void TaskAdd();

	/// <summary>
	/// �^�X�N�폜�V�[���̍X�V����
	/// </summary>
	void TaskDelete();

	/// <summary>
	/// �^�X�N�ҏW�V�[���X�V����
	/// </summary>
	void TaskEdit();

	/// <summary>
	/// �^�X�N�S���ҕ\��
	/// </summary>
	void TaskManagerDisplay();

	/// <summary>
	/// �^�X�N�S���Ғǉ�
	/// </summary>
	void TaskManagerAdd();

	/// <summary>
	/// �^�X�N�S���ҍ폜
	/// </summary>
	void TaskManagerDelete();

	/// <summary>
	/// �^�X�N�S���ҕҏW
	/// </summary>
	void TaskManagerEdit();
};