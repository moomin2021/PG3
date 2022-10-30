#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;

int main() {

	// --1970年時点の山手線駅一覧の格納-- //
	list<const char*> stationList = {
		"Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno",
		"Uguisudani", "Nippori", "Tabata", "Komagome", "Sugamo",
		"Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo",
		"Shinjuku", "Yoyogi", "Harajuku", "Shibuya", "Ebisu",
		"Meguro", "Gotanda", "Osaki", "Shinagawa", "Tamachi",
		"Hamamatsucho", "Shimbashi", "Yurakucho"
	};

	// --表示する年数-- //
	printf_s("%s\n", "-----1970年-----");

	// --1970年時点の山手線駅一覧を表示-- //
	for (list<const char*>::iterator itr = stationList.begin(); itr != stationList.end(); itr++) {
		printf_s("%s\n", *itr);
	}

	// --西日暮里駅をリストに追加-- //
	for (list<const char*>::iterator itr = stationList.begin(); itr != stationList.end(); itr++) {
		if (*itr == "Tabata") {
			itr = stationList.insert(itr, "Nishi-Nippori");
			itr++;
		}
	}

	// --表示する年数-- //
	printf_s("%s\n", "-----2019年-----");

	// --2019年時点の山手線駅一覧を表示-- //
	for (list<const char*>::iterator itr = stationList.begin(); itr != stationList.end(); itr++) {
		printf_s("%s\n", *itr);
	}

	// --高輪ゲートウェイをリストに追加-- //
	for (list<const char*>::iterator itr = stationList.begin(); itr != stationList.end(); itr++) {
		if (*itr == "Tamachi") {
			itr = stationList.insert(itr, "Takanawa-Gateway");
			itr++;
		}
	}

	// --表示する年数-- //
	printf_s("%s\n", "-----2022年-----");

	// --2022年時点の山手線駅一覧を表示-- //
	for (list<const char*>::iterator itr = stationList.begin(); itr != stationList.end(); itr++) {
		printf_s("%s\n", *itr);
	}

	return 0;
}