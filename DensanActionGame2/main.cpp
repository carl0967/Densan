
#include "DxLib.h"
#include<iostream>
#include "GameMain.h"

// プログラムは WinMain から始まります
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){

	ChangeWindowMode(true); //ウインドウモードの設定
	if( DxLib_Init() == -1 ) return -1;		// ＤＸライブラリ初期化処理 エラーが起きたら終了
	 SetDrawScreen( DX_SCREEN_BACK ); 

	//ゲームメイン生成
	GameMain fps;

	//メインループ開始
	fps.GameStart();
	

	DxLib_End();

	return 0;



		
		
}