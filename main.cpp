
#include "DxLib.h"
#include<iostream>
#include "GameMain.h"

// プログラムは WinMain から始まります
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
	 ChangeWindowMode( TRUE ),DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK ); // ウィンドウモードに設定etc

	ChangeWindowMode(true);
	if( DxLib_Init() == -1 )		// ＤＸライブラリ初期化処理
	{
		return -1 ;			// エラーが起きたら直ちに終了
	}

	/*

	MapFactory* mapf=new MapFactory();
	Map* map;
	map=mapf->CreateMap("map.txt");
	



	Field* field=new Field(map);




	AObject* character= new Player(1,0,field);
	*/

	//ゲームメイン生成
	GameMain fps;

	//メインループ開始
	fps.GameStart();
	

	DxLib_End();



		
		
}