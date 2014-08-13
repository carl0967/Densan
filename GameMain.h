#pragma once
#include "Field.h"
#include "Menu.h"
#include <math.h>
#include "DxLib.h"
#include "MapFactory.h"
using namespace std;

class GameMain{
private:
	Field field;//フィールド
	bool Update();
	void Draw();
	void Wait();
public:
	void GameStart();//ゲーム開始時
	void MainLoop();//ループの処理
	GameMain();//コンストラクタ
	int mStartTime;         //測定開始時刻
	int mCount;             //カウンタ
	float mFps;             //fps
	static const int N = 60;//平均を取るサンプル数
	static const int FPS = 60;	//設定したFPS
};