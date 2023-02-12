#pragma once
#include <string>

// �^�X�N�S����
class TaskManager {
public:// -----�����o�ϐ�----- //
	// ID
	unsigned short int id_;

	// ������
	std::string affiliationName_;

	// ���O
	std::string name_;

private:// -----�����o�ϐ�----- //
	// ��������ID��
	static unsigned short int idCount_;

public:// -----�����o�֐�----- //
	/// <summary>
	/// �^�X�N�S���҂̍쐬
	/// </summary>
	void Create();

	/// <summary>
	/// �^�X�N�S���҂̕\��
	/// </summary>
	void Display();
	/// <summary>
	/// ID����
	/// </summary>
	void CreateID();

	/// <summary>
	/// ���O�̓��͂��󂯎��
	/// </summary>
	void InputName();

	/// <summary>
	/// �������̓��͂��󂯎��
	/// </summary>
	void InputAffiliationName();
};