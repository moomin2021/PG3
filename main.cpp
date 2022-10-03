#include <stdio.h>
#include <stdlib.h>

// --一般的な賃金体系-- //
int GeneralWage(int value, int hour) {
	return value * hour;
}

// --再帰的な賃金体系-- //
int RecursiveWage(int value, int hour) {
	// --時間が0になったら-- //
	if (hour <= 0) {
		return 0;
	}

	return value + RecursiveWage(value * 2 - 50, hour - 1);
}

int main() {

	printf("一般的な賃金%d\n", GeneralWage(1072, 8));
	printf("再帰的な賃金%d\n", RecursiveWage(100, 8));

	if (GeneralWage(1072, 8) > RecursiveWage(100, 8)) {
		printf("一般的な賃金の方が高い\n");
	}

	else {
		printf("再帰的な賃金の方が高い\n");
	}

	return 0;
}