#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <functional>

typedef void (*PFunc)(char[]);

void Lottery(char str[]) {
	// --�����_���Ȓl���擾-- //
	int randomValue = rand();

	printf_s("�����_���ŕԂ��ꂽ�l��%d�ł�\n", randomValue);

	// --[����]��[�]���𔻒肷��-- //
	if (strcmp(str, "����") == 0 && randomValue % 2 == 0) printf_s("���ʂ͋����ł����I�������ł��I\n");
	else if (strcmp(str, "�") == 0 && randomValue % 2 == 1) printf_s("���ʂ͊�ł����I�������ł��I\n");
	else printf_s("�c�O�I�n�Y���ł��I\n");
}

std::function<void(PFunc, int, char[])> SetTimeOut = [](PFunc p, int second, char str[]) {
	printf_s("���ʂ�%d��...", second);
	Sleep(second * 1000);
	p(str);
};

int main() {
	PFunc p;

	// --������-- //
	srand(time(nullptr));

	char str[5];
	while (true) {
		// --���̓f�[�^�擾-- //
		printf_s("[�]��[����]�����͂��Ă�������\n");
		scanf_s("%s", str, 5);

		// --���͂����̂�[����]��[�]�Ȃ烋�[�v�𔲂���-- //
		if (strcmp(str, "����") == 0) break;
		if (strcmp(str, "�") == 0) break;

		// --���͂����̂�[����]��[�]�łȂ������ꍇ-- //
		printf_s("�Ԉ�������͂ł��B\n");
	}

	// --���I-- //
	p = Lottery;
	SetTimeOut(p, 3, str);

	return 0;
}