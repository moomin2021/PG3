#include <memory>
#include "TaskManagementSystem.h"

int main() {
	// �v���O�����I���t���O
	bool isEnd = false;

	// �^�X�N�Ǘ��V�X�e���N���X
	std::unique_ptr<TaskManagementSystem> taskManagementSystem = std::make_unique<TaskManagementSystem>();

	// ����������
	taskManagementSystem->Initialize();

	while (true) {
		// �X�V����
		taskManagementSystem->Update();

		// �v���O�����I���t���O��[ON]�ɂȂ����烋�[�v�𔲂���
		if (isEnd) return 0;
	}
}