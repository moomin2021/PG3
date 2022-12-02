#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
	int val;
	struct cell* next;
} CELL;

// �f�[�^��ǉ�����֐��̃v���g�^�C�v�錾
void create(CELL* startCell, int value);

// �ꗗ��\������֐��̃v���g�^�C�v�錾
void index(CELL* startCell);

int main() {
	int val;
	CELL head;
	head.next = nullptr;

	while (true) {
		scanf_s("%d", &val);

		create(&head, val);

		index(&head);
	}

	return 0;
}

void create(CELL* startCell, int value) {
	CELL* newCell;

	newCell = (CELL*)malloc(sizeof(CELL));

	newCell->val = value;
	newCell->next = nullptr;

	while (startCell->next != nullptr) {
		startCell = startCell->next;
	}

	startCell->next = newCell;
}

void index(CELL* startCell) {
	while (startCell->next != nullptr) {
		startCell = startCell->next;
		printf("%d\n", startCell->val);
	}
}