#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <functional>

typedef void (*PFunc)(int*);

void CallBack(int* s) {
	printf_s("%d�b�ԏ������~�܂�܂�\n", *s);
}

int main() {
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

	// --�֐��|�C���^��p���Ĉꎞ�I�ɏ������~�߂�-- //
	PFunc p;
	p = CallBack;

	std::function<void(PFunc, int)> fx = [](PFunc p, int second) {
		p(&second);
		Sleep(second * 1000);
	};

	fx(p, 3);

	// --�����_���Ȓl���擾-- //
	int randomValue = rand();

	printf_s("�����_���ŕԂ��ꂽ�l��%d�ł�\n", randomValue);

	// --[����]��[�]���𔻒肷��-- //
	if (randomValue % 2 == 0) printf_s("�����͋����ł���\n");
	else printf_s("�����͊�ł���\n");

	return 0;
}