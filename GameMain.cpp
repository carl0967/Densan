#include "GameMain.h"

/*ゲームを始める。
Menuクラスでプレイヤーにステージ選択を行ってもらい、
MapFactoryで選択したステージのマップを生成する。
その後Fieldクラスのインスタンスを生成。*/
void GameMain::GameStart(){
	while( ProcessMessage()==0){
	Menu menu;
	string filename;
	menu.Start();

	MapFactory mf;
	Map* map=mf.CreateMap(menu.Select());

	//Fieldクラスのインスタンスを生成
	field=new Field(map);

	MainLoop();
	}
}

/*
▪ ループの処理はここでする。FPSは60になるように調整。
▪ ループ内でFieldのMainLoop()を呼び出して、ゲームのメインループにす
る。*/
void GameMain::MainLoop () {
	while( ProcessMessage()==0  && ClearDrawScreen()==0 && CheckHitKey(KEY_INPUT_ESCAPE)==0 ){
		Update();
		Draw();	
		if(field->MainLoop() == -1)
			break;
		Wait();
		ScreenFlip();
	}
}

GameMain::GameMain(){
	mStartTime = 0;
		mCount = 0;
		mFps = 0;
}

bool GameMain::Update(){
	if( mCount ==  0){ //1フレーム目なら時刻を記憶
		mStartTime = GetNowCount();
	}
	if( mCount == N ){ //60フレーム目なら平均を計算する
		int t = GetNowCount();
		mFps = 1000.f/((t-mStartTime)/(float)N);
		mCount = 0;
		mStartTime = t;
	}
	mCount++;
	return true;
}

//フレームの表示
void GameMain::Draw(){
	DrawFormatString(0, 0, GetColor(255,255,255), "%.1f", mFps);
}

//
void GameMain::Wait(){
	int tookTime = GetNowCount() - mStartTime;	//かかった時間
	int waitTime = mCount*1000/FPS - tookTime;	//待つべき時間
	if( waitTime > 0 ){
		Sleep(waitTime);	//待機
	}
}

/*
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	ChangeWindowMode(TRUE),DxLib_Init(),SetDrawScreen( DX_SCREEN_BACK );

	GameMain fps;
	fps.GameStart();
	fps.MainLoop();

	DxLib_End();
	return 0;
}
*/
