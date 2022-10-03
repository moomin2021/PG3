#include <stdio.h>
#include <stdlib.h>

// --一般的な賃金体系-- //
int Case1(int value, int hour) {
	return value * hour;
}

// --再帰的な賃金体系-- //
int Case2(int value, int hour) {
	// --時間が0になったら-- //
	if (hour <= 0) {
		return 0;
	}

	return value + Case2(value * 2 - 50, hour - 1);
}

int main() {

	printf("一般的な賃金%d\n", Case1(1072, 8));
	printf("再帰的な賃金%d\n", Case2(100, 8));
	return 0;
}