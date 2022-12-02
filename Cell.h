#pragma once

typedef struct cell {
	// 保存している値
	char str[8];

	// 前のセルポインタ
	struct cell* prev = nullptr;

	// 次のセルのポインタ
	struct cell* next = nullptr;

	// 現在のサイズを返す
	int size();

	// 指定された要素番号の文字列を返す
	char* GetStr(int num);

	// 指定した要素番号に文字列を挿入
	void SetStr(char str[8], int val);

	// 指定した要素番号の文字列を変更
	void SetChangeStr(char str[8], int val);

	// 指定した要素番号のセルを削除
	void DeleteCell(int val);
} CELL;