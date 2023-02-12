#include <memory>
#include "TaskManagementSystem.h"

int main() {
	// プログラム終了フラグ
	bool isEnd = false;

	// タスク管理システムクラス
	std::unique_ptr<TaskManagementSystem> taskManagementSystem = std::make_unique<TaskManagementSystem>();

	// 初期化処理
	taskManagementSystem->Initialize();

	while (true) {
		// 更新処理
		taskManagementSystem->Update();

		// プログラム終了フラグが[ON]になったらループを抜ける
		if (isEnd) return 0;
	}
}