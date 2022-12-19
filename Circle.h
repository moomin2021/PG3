#pragma once
#include "IShape.h"

class Circle : public IShape {
	// --メンバ変数-- //
private:
	// 半径
	float radius_;

	// --メンバ関数-- //
public:
	// コンストラクタ
	Circle(float radius);

	// 表示
	void Draw() override;

private:
	// サイズ
	float Size() override;
};