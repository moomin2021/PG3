#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell{
	char str[8];
	struct cell* next;
} CELL;

// �f�[�^��ǉ�����֐��̃v���g�^�C�v�錾
void create(CELL* startCell, const char *buf);

// �ꗗ��\������֐��̃v���g�^�C�v�錾
void index(CELL* startCell);

int main() {
	char str[8];
	CELL head;
	head.next = nullptr;

	while (true) {
		scanf_s("%s", str, 8);

		create(&head, str);

		index(&head);
	}

	return 0;
}

void create(CELL* startCell, const char* buf) {
	CELL* newCell;

	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->str, 8, buf);
	newCell->next = nullptr;

	while (startCell->next != nullptr) {
		startCell = startCell->next;
	}

	startCell->next = newCell;
}

void index(CELL* startCell) {
	while (startCell->next != nullptr) {
		startCell = startCell->next;
		printf("%s\n", startCell->str);
	}
}