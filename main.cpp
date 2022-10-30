#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;

int main() {

	// --1970�N���_�̎R����w�ꗗ�̊i�[-- //
	list<const char*> stationList = {
		"Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno",
		"Uguisudani", "Nippori", "Tabata", "Komagome", "Sugamo",
		"Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo",
		"Shinjuku", "Yoyogi", "Harajuku", "Shibuya", "Ebisu",
		"Meguro", "Gotanda", "Osaki", "Shinagawa", "Tamachi",
		"Hamamatsucho", "Shimbashi", "Yurakucho"
	};

	// --�\������N��-- //
	printf_s("%s\n", "-----1970�N-----");

	// --1970�N���_�̎R����w�ꗗ��\��-- //
	for (list<const char*>::iterator itr = stationList.begin(); itr != stationList.end(); itr++) {
		printf_s("%s\n", *itr);
	}

	// --�����闢�w�����X�g�ɒǉ�-- //
	for (list<const char*>::iterator itr = stationList.begin(); itr != stationList.end(); itr++) {
		if (*itr == "Tabata") {
			itr = stationList.insert(itr, "Nishi-Nippori");
			itr++;
		}
	}

	// --�\������N��-- //
	printf_s("%s\n", "-----2019�N-----");

	// --2019�N���_�̎R����w�ꗗ��\��-- //
	for (list<const char*>::iterator itr = stationList.begin(); itr != stationList.end(); itr++) {
		printf_s("%s\n", *itr);
	}

	// --���փQ�[�g�E�F�C�����X�g�ɒǉ�-- //
	for (list<const char*>::iterator itr = stationList.begin(); itr != stationList.end(); itr++) {
		if (*itr == "Tamachi") {
			itr = stationList.insert(itr, "Takanawa-Gateway");
			itr++;
		}
	}

	// --�\������N��-- //
	printf_s("%s\n", "-----2022�N-----");

	// --2022�N���_�̎R����w�ꗗ��\��-- //
	for (list<const char*>::iterator itr = stationList.begin(); itr != stationList.end(); itr++) {
		printf_s("%s\n", *itr);
	}

	return 0;
}