#pragma once
#include "TaskManager.h"
#include <string>

struct Date {
	int year;// -> �N
	int month;// -> ��
	int day;// -> ��
};

class Task {

public:// -----�����o�ϐ�----- //
	// ID
	unsigned short int id_;

	// �S����
	TaskManager taskManager_;

	// �薼
	std::string title_;

	// ���e
	std::string content_;

	// �D��x
	std::string priority_;

	// ����
	Date limit_;

	// �^�X�N�̒B���t���O
	std::string completion_;

private:// -----�ÓI�����o�ϐ�
	// ��������ID��
	static unsigned short int idCount_;

public:// -----�����o�֐�----- //
	/// <summary>
	/// �^�X�N����
	/// </summary>
	void Create();

	/// <summary>
	/// �^�X�N�\��
	/// </summary>
	void Display();

	/// <summary>
	/// �薼����
	/// </summary>
	void InputTitle();

	/// <summary>
	/// ���e����
	/// </summary>
	void InputContent();

	/// <summary>
	/// �D��x�I��
	/// </summary>
	void SelectPriority();

	/// <summary>
	/// ��������
	/// </summary>
	void InputLimit();

	/// <summary>
	/// �^�X�N�B���I��
	/// </summary>
	void SelectCompletion();

	/// <summary>
	/// ID�𐶐�
	/// </summary>
	void CreateID();

	/// <summary>
	/// �S���Ґݒ�
	/// </summary>
	/// <param name="taskManager"></param>
	inline void SetTaskManager(const TaskManager& taskManager) { taskManager_ = taskManager; }
};