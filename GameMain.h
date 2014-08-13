#pragma once
#include "Field.h"
#include "Menu.h"
#include <math.h>
#include "DxLib.h"
#include "MapFactory.h"
using namespace std;

class GameMain{
private:
	Field field;//�t�B�[���h
	bool Update();
	void Draw();
	void Wait();
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