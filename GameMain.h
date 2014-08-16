#pragma once
#include "DxLib.h"
#include "Menu.h"
#include "MapFactory.h"
#include "Field.h"
#include <math.h>
using namespace std;

class GameMain{
private:
	Field* field;//�t�B�[���h
	bool Update();//�t���[���̍X�V
	void Draw();//fps�̕\��
	void Wait();//�ҋ@����
public:
	void GameStart();//�Q�[���J�n��
	void MainLoop();//���[�v�̏���
	GameMain();//�R���X�g���N�^
	int mStartTime;         //����J�n����
	int mCount;             //�J�E���^
	float mFps;             //fps
	static const int N = 60;//���ς����T���v����
	static const int FPS = 60;	//�ݒ肵��FPS
};