#include <stdio.h>
#include <stdlib.h>

// --��ʓI�Ȓ����̌n-- //
int GeneralWage(int value, int hour) {
	return value * hour;
}

// --�ċA�I�Ȓ����̌n-- //
int RecursiveWage(int value, int hour) {
	// --���Ԃ�0�ɂȂ�����-- //
	if (hour <= 0) {
		return 0;
	}

	return value + RecursiveWage(value * 2 - 50, hour - 1);
}

int main() {

	printf("��ʓI�Ȓ���%d\n", GeneralWage(1072, 8));
	printf("�ċA�I�Ȓ���%d\n", RecursiveWage(100, 8));

	if (GeneralWage(1072, 8) > RecursiveWage(100, 8)) {
		printf("��ʓI�Ȓ����̕�������\n");
	}

	else {
		printf("�ċA�I�Ȓ����̕�������\n");
	}

	return 0;
}