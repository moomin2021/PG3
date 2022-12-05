#include "GameScene.h"
#include "DxLib.h"
#include "Vector2.h"
#include <cmath>

bool CircleCol(Vector2 pos1, float r1, Vector2 pos2, float r2) {
	float a = pos1.x - pos2.x;
	float b = pos1.y - pos2.y;
	float c = sqrtf(a * a + b * b);

	if (c <= r1 + r2) return true;
	return false;
}

GameScene::GameScene() :
	key_(nullptr),// -> �L�[�{�[�h
	enemys_(nullptr),// -> �G�l�~�[
	player_(nullptr)// -> �v���C���[
{

}

GameScene::~GameScene()
{
	delete[] enemys_;// -> �G�l�~�[
	delete player_;// -> �v���C���[
}

void GameScene::Initialize()
{
	// �L�[�{�[�h���̓N���X�C���X�^���X�擾
	key_ = Key::GetInstance();

	// �G�l�~�[���I�m��
	enemys_ = new Enemy[maxEnemy_];
	
	// �G�l�~�[������
	for (size_t i = 0; i < maxEnemy_; i++) {
		enemys_[i].Initialize();
	}

	// �G�l�~�[�̐����t���O��[ON]�ɂ���
	enemys_->SetIsAlive(true);

	// �v���C���[���I�m��
	player_ = new Player();

	// �v���C���[������
	player_->Initialize();
}

void GameScene::Update()
{
	// �v���C���[�X�V����
	player_->Update();

	// �����蔻��
	Collision();

	// [R]���������烊�Z�b�g����
	if (key_->TriggerKey(KEY_INPUT_R)) Reset();
}

void GameScene::Draw()
{
	// �G�l�~�[�`�揈��
	for (size_t i = 0; i < maxEnemy_; i++) {
		enemys_[i].Draw();
	}

	// �v���C���[�`�揈��
	player_->Draw();

	// �e�L�X�g�`��
	DrawFormatString(0, 0, 0xFFFFFF, "[W][A][S][D] : �v���C���[�ړ�����");
	DrawFormatString(0, 20, 0xFFFFFF, "�v���C���[���G�ɂԂ���Ɖ�ʏ�̓G�����ׂď�����");
	DrawFormatString(0, 40, 0xFFFFFF, "[R] : ���Z�b�g");
}

void GameScene::Reset()
{
	// �G�l�~�[����������
	for (size_t i = 0; i < maxEnemy_; i++) {
		enemys_[i].Initialize();
	}

	// �G�l�~�[�̐����t���O��[ON]�ɂ���
	enemys_->SetIsAlive(true);

	// �v���C���[����������
	player_->Initialize();
}

void GameScene::Collision() {
	for (size_t i = 0; i < maxEnemy_; i++) {
		// �G�l�~�[�̐����t���O��[OFF]�Ȃ画����s��Ȃ�
		if (enemys_->GetIsAlive() == false) break;

		// �v���C���[�ƃG�l�~�[�̓����蔻��
		if (CircleCol(
			player_->position_, player_->radius_,
			enemys_[i].position_, enemys_[i].radius_)) {

			// �G�l�~�[�̐����t���O��[OFF]�ɂ���
			enemys_->SetIsAlive(false);
			break;
		}
	}
}