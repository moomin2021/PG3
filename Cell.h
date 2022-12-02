#pragma once

typedef struct cell {
	// �ۑ����Ă���l
	char str[8];

	// �O�̃Z���|�C���^
	struct cell* prev = nullptr;

	// ���̃Z���̃|�C���^
	struct cell* next = nullptr;

	// ���݂̃T�C�Y��Ԃ�
	int size();

	// �w�肳�ꂽ�v�f�ԍ��̕������Ԃ�
	char* GetStr(int num);

	// �w�肵���v�f�ԍ��ɕ������}��
	void SetStr(char str[8], int val);

	// �w�肵���v�f�ԍ��̕������ύX
	void SetChangeStr(char str[8], int val);

	// �w�肵���v�f�ԍ��̃Z�����폜
	void DeleteCell(int val);
} CELL;