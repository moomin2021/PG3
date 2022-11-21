#include "SceneManager.h"
#include "DxLib.h"
#include "TitleScene.h"
#include "NewGameScene.h"
#include "GamePlayScene.h"
#include "GameClearScene.h"

// �C���X�^���X�擾
SceneManager* SceneManager::GetInstance() {
    // �֐���static�ϐ��Ƃ��Đ錾
    static SceneManager instance;
    return &instance;
}

SceneManager::SceneManager() :
#pragma region ���������X�g
    myScene_(nullptr),// -> ���݂̃V�[��
    sceneNo_(0)// -> ���݂̃V�[���ԍ�
#pragma endregion
{
    // �L�[�{�[�h���̓N���X�̃C���X�^���X�擾
    key_ = Key::GetInstance();
}

// �f�X�g���N�^
SceneManager::~SceneManager() {
    // ���݂̃V�[������ł͂Ȃ�������
    if (myScene_ != nullptr) {
        // ���݂̃V�[�������������
        delete myScene_;
    }
}

// �V�[����ύX
void SceneManager::ChangeScene(int sceneNo) {
    // ���݂̃V�[������ł͂Ȃ�������
    if (myScene_ != nullptr) {
        // ���݂̃V�[�������������
        delete myScene_;
    }

    // �w�肳�ꂽ�V�[���̃C���X�^���X�����Ə�����
    switch (sceneNo)
    {
    case TITLE:
        myScene_ = new TitleScene();// -> �C���X�^���X����
        myScene_->Initialize();// -> ���݂̃V�[���̏���������
        sceneNo_ = SCENE::TITLE;// -> ���݂̃V�[���ԍ���ύX
        break;
    case NEWGAME:
        myScene_ = new NewGameScene();// -> �C���X�^���X����
        myScene_->Initialize();// -> ���݂̃V�[���̏���������
        sceneNo_ = SCENE::NEWGAME;// -> ���݂̃V�[���ԍ���ύX
        break;
    case GAMEPLAY:
        myScene_ = new GamePlayScene();// -> �C���X�^���X����
        myScene_->Initialize();// -> ���݂̃V�[���̏���������
        sceneNo_ = SCENE::GAMEPLAY;// -> ���݂̃V�[���ԍ���ύX
        break;
    case GAMECLEAR:
        myScene_ = new GameClearScene();// -> �C���X�^���X����
        myScene_->Initialize();// -> ���݂̃V�[���̏���������
        sceneNo_ = SCENE::GAMECLEAR;// -> ���݂̃V�[���ԍ���ύX
        break;
    }
}

// �X�V����
void SceneManager::Update() {
    // [SPACE]�L�[�ŃV�[����ύX
    if (key_->TriggerKey(KEY_INPUT_SPACE)) {
        // ���݂̃V�[���ԍ���i�߂�
        sceneNo_++;

        // ���݂̃V�[���ԍ����ő�l�ȏ�Ȃ�
        if (sceneNo_ > SCENE::GAMECLEAR) {
            // ���݂̃V�[���ԍ���0�ɂ���
            sceneNo_ = 0;
        }

        // �V�[����ύX����
        ChangeScene(sceneNo_);
    }

    // ���݂̃V�[���̍X�V����
    myScene_->Update();
}

// �`�揈��
void SceneManager::Draw() {
    // ���݂̃V�[���̕`�揈��
    myScene_->Draw();
}