#include "MapFactory.h"
#include <iostream>
#include <vector>
#include "DxLib.h"

using namespace std;



vector<string> split(const string &str, char delim){
	vector<string> res;
	size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != string::npos){
		res.push_back(string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(string(str, current, str.size() - current));
	return res;
}

Map MapFactory::CreateMap(std::string fileName){
	const char* fileC = fileName.c_str();
	vector<int> orignal;
	char source[120];
	int currentLine=0;			// 現在読んでいる行
	int fileHandle = FileRead_open(fileC);
	FileRead_gets(source,120,fileHandle);

	while(source[currentLine]=='\0'){
		// スプリット
		vector<string> item = split(source,',');
		for(int i=0;i<item.size();i++){
			orignal.push_back(atoi(item[i].c_str()));
		}
		if(source[source.size()-1] == '\0')
			break;

		FileRead_gets(source,120,fileHandle);
	}



	Map null(0,0,NULL);
	return null;
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE prev,LPSTR cmd,int nShowCmd){
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();
	vector<string> v = split("10,10,10,10",',');
	for(int i=0;i<v.size();i++)
		DrawFormatString(0,i*30,GetColor(255,255,255),"%s",v[i].c_str());
	ScreenFlip();
	WaitKey();
	DxLib_End();
}