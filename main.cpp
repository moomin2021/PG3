#include <stdio.h>
#include <stdlib.h>

// --��ʓI�Ȓ����̌n-- //
int Case1(int value, int hour) {
	return value * hour;
}

// --�ċA�I�Ȓ����̌n-- //
int Case2(int value, int hour) {
	// --���Ԃ�0�ɂȂ�����-- //
	if (hour <= 0) {
		return 0;
	}

	return value + Case2(value * 2 - 50, hour - 1);
}

int main() {

	printf("��ʓI�Ȓ���%d\n", Case1(1072, 8));
	printf("�ċA�I�Ȓ���%d\n", Case2(100, 8));
	return 0;
}