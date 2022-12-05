#include "Enemy.h"
#include "DxLib.h"
#include <random>

bool Enemy::isAlive_ = false;

Enemy::Enemy() :
	position_{0.0f, 0.0f},// -> 座標
	radius_(8.0f),// -> 半径
	speed_(0.8f),// -> 速度
	nowState_(State::Approach),// -> 現在の状態
	shootLen_(100.0f)// -> 射撃の射程
{
	// 弾クラスの動的確保
	bullet_ = new Bullet();
}

Enemy::~Enemy() {
	delete bullet_;
}

void Enemy::Initialize()
{
	// ランダムで座標を決定
	std::random_device device;
	std::mt19937 engine(device());
	std::uniform_real_distribution<float> randX(8.0f, 592.0f);
	std::uniform_real_distribution<float> randY(48.0f, 292.0f);

	// 座標設定
	position_ = { randX(engine), randY(engine) };

	// 現在の状態設定
	nowState_ = State::Approach;
}

void Enemy::Update(Vector2 playerPos)
{
	// 行動
	(this->*actionTable[nowState_])(playerPos);
}

void Enemy::Draw()
{
	// 弾の生存フラグが[ON]なら弾を描画する
	if (bullet_->GetIsAlive()) bullet_->Draw();

	// 生存フラグが[ON]なら描画
	if (isAlive_)
	DrawCircleAA(position_.x, position_.y, radius_, 20, 0xFF2222, true);
}

void Enemy::Approach(Vector2 playerPos)
{
	// エネミーからプレイヤーへのベクトル
	Vector2 e2pVec = playerPos - position_;

	// 正規化
	e2pVec.normalize();

	// 座標更新
	position_ += e2pVec * speed_;

	// 一定まで近づいたら状態を変更
	if (Vector2(playerPos - position_).length() <= shootLen_) {
		nowState_ = State::Shoot;
	}

	// 弾の初期化
	bullet_->Initialize(position_, e2pVec);
}

void Enemy::Shoot(Vector2 playerPos)
{
	// 弾の更新処理
	bullet_->Update();

	// 弾のフラグが[OFF]になったら状態を変更
	if (bullet_->GetIsAlive() == false) nowState_ = State::Secession;
}

void Enemy::Secession(Vector2 playerPos)
{
	// プレイヤーからエネミーへのベクトル
	Vector2 p2eVec = position_ - playerPos;

	// 正規化
	p2eVec.normalize();

	// 座標の更新
	position_ += p2eVec * speed_;

	// 画面の枠に触れたら状態を変更
	if (position_.x <= radius_) nowState_ = State::Approach;
	if (position_.x >= 600.0f - radius_) nowState_ = State::Approach;
	if (position_.y <= radius_) nowState_ = State::Approach;
	if (position_.y >= 400.0f - radius_) nowState_ = State::Approach;
}

void (Enemy::* Enemy::actionTable[]) (Vector2 playerPos) = {
	&Enemy::Approach,// -> 近接
	&Enemy::Shoot,// ----> 射撃
	&Enemy::Secession// -> 離脱
};