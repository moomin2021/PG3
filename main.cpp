#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <functional>

typedef void (*PFunc)(int*);

void CallBack(int* s) {
	printf_s("%d秒間処理が止まります\n", *s);
}

int main() {
	// --初期化-- //
	srand(time(nullptr));

	char str[5];
	while (true) {
		// --入力データ取得-- //
		printf_s("[奇数]か[偶数]か入力してください\n");
		scanf_s("%s", str, 5);

		// --入力したのが[偶数]か[奇数]ならループを抜ける-- //
		if (strcmp(str, "偶数") == 0) break;
		if (strcmp(str, "奇数") == 0) break;

		// --入力したのが[偶数]か[奇数]でなかった場合-- //
		printf_s("間違った入力です。\n");
	}

	// --関数ポインタを用いて一時的に処理を止める-- //
	PFunc p;
	p = CallBack;

	std::function<void(PFunc, int)> fx = [](PFunc p, int second) {
		p(&second);
		Sleep(second * 1000);
	};

	fx(p, 3);

	// --ランダムな値を取得-- //
	int randomValue = rand();

	printf_s("ランダムで返された値は%dです\n", randomValue);

	// --[偶数]か[奇数]かを判定する-- //
	if (randomValue % 2 == 0) printf_s("正解は偶数でした\n");
	else printf_s("正解は奇数でした\n");

	return 0;
}