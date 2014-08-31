/*
画像のファイル名とグラフィックハンドルの関連付けを管理するクラス
まだ読み込んだことのないファイル名のみ読み込む
*/
#pragma once
#include "DxLib.h"

class LoadGraphic{
public :
	LoadGraphic();
	int Load(char* file_name);
private:
	int count;
	int g_handles[20]; 
	char* file_names[20];
};