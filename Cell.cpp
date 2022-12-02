#include "Cell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int cell::size()
{
	// サイズ
	int size = 0;

	CELL * cell = this;

	while (cell->next != nullptr) {
		// サイズ加算
		size += 1;

		// 次のセルへ移動
		cell = cell->next;
	}

	return size;
}

char* cell::GetStr(int num) {
	// セルの先頭を取得
	CELL* cell = this->next;

	for (size_t i = 0; i < num; i++) {
		cell = cell->next;
	}

	return cell->str;
}

void cell:: SetStr(char str[8], int val) {
	CELL *newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	strcpy_s(newCell->str, 8, str);

	CELL* cell = this;

	for (size_t i = 0; i < val; i++) {
		cell = cell->next;
	}

	if (cell->next == nullptr) {
		cell->next = newCell;
		cell->next->prev = cell;
		cell->next->next = nullptr;
	}
	else {
		CELL* oldCell = cell->next;
		cell->next = newCell;
		cell->next->prev = cell;
		cell->next->next = oldCell;
	}
}

void cell::SetChangeStr(char str[8], int val) {
	CELL* cell = this->next;

	for (size_t i = 0; i < val; i++) {
		cell = cell->next;
	}

	strcpy_s(cell->str, 8, str);
}

void cell::DeleteCell(int val) {
	CELL* cell = this->next;

	for (size_t i = 0; i < val; i++) {
		cell = cell->next;
	}

	if (cell->next == nullptr) {
		cell->prev->next = nullptr;
	}
	else {
		cell->prev->next = cell->next;
		cell->next->prev = cell->prev;
	}
}