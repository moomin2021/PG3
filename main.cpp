#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <functional>

typedef void (*PFunc)(char[]);

void Lottery(char str[]) {
	// --ランダムな値を取得-- //
	int randomValue = rand();

	printf_s("ランダムで返された値は%dです\n", randomValue);

	// --[偶数]か[奇数]かを判定する-- //
	if (strcmp(str, "偶数") == 0 && randomValue % 2 == 0) printf_s("結果は偶数でした！お見事です！\n");
	else if (strcmp(str, "奇数") == 0 && randomValue % 2 == 1) printf_s("結果は奇数でした！お見事です！\n");
	else printf_s("残念！ハズレです！\n");
}



int main() {
	PFunc p;

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

	std::function<void(PFunc, int)> SetTimeOut = [&](PFunc p, int second) {
		printf_s("結果は%d秒後...", second);
		Sleep(second * 1000);
		p(str);
	};

	// --抽選-- //
	p = Lottery;
	SetTimeOut(p, 3);

	return 0;
}