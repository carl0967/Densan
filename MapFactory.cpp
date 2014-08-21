#include "MapFactory.h"
#include <fstream>
#include <string>
#include <vector>
#include "DxLib.h"

using std::vector;
using std::string;
using std::fstream;

#define CELL_WIDTH	32		// �Z���̕�
#define CELL_HEIGHT 32		// �Z���̍���


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

Map* MapFactory::CreateMap(std::string fileName){
	const char* fileC = fileName.c_str();
	vector<int> orignal;
//----------1�s��ǂݍ���ŁA�����Z�o
	std::string temp;							// ������i�[�p�ϐ�
	fstream fin(fileC,std::ios::in);							// �X�g���[���쐬
	getline(fin,temp);							// 1�s�ǂ�
	int charNumber = temp.size()+3;				// �������擾(+3�Ńo�b�t�@�ɏ����]�T���������Ă���)
	fin.close();								// �t�@�C�������

  	char* source = new char[charNumber];
	int charSize;			// ���ݍs�̃T�C�Y
	int fileHandle = FileRead_open(fileC);
	int x=0,y=0;
	while(true){
		if(FileRead_gets(source,charNumber,fileHandle)==-1)
			break;
		y++;
		// �X�v���b�g
		vector<string> item = split(source,',');
		x = item.size();
		for(int i=0;i<item.size();i++){
			orignal.push_back(atoi(item[i].c_str()));
		}
	}
	// �񎟌��z�񐶐�
	int **mapdata;
	mapdata = new int*[y];
	for(int i=0;i<y;i++){
		mapdata[i] = new int[x];
	}

	// �f�[�^�i�[
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			mapdata[i][j] = orignal[i*x + j];
		}
	}
	 
	Map *map = new Map(CELL_WIDTH,CELL_HEIGHT,mapdata);
	map->SetMapHeightAndWidth(y,x);
	delete source;
	return map;
}

Map* MapFactory::CreateMap(std::string fileName,std::string backgroundName){
	Map* map = CreateMap(fileName);
	map->SetBackground(backgroundName);
	return map;
}




#if 0
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE prev,LPSTR cmd,int nShowCmd){
	// ���������[�N�m�F�p
	::_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);	

	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	// split�̃e�X�g
	ClearDrawScreen();
	vector<string> v = split("10,10,10,10",',');
	for(int i=0;i<v.size();i++)
		DrawFormatString(0,i*30,GetColor(255,255,255),"%s",v[i].c_str());
	ScreenFlip();
	WaitKey();

	
	// MapFactory�̃e�X�g
	ClearDrawScreen();
	MapFactory factory;
	Map* temp = factory.CreateMap("map.txt","bak.jpg");
	DrawString(100,100,"OK",GetColor(255,255,255));
	ScreenFlip();
	WaitKey();

	// Map�̃e�X�g
	ClearDrawScreen();
	int a = temp->GetMapData(49.5,49.5);
	int b = temp->GetMapData(50.5,50.5);
	DrawFormatString(100,100,GetColor(255,255,255),"a:%d b:%d",a,b);
	ScreenFlip();
	WaitKey();
	int offset = 0;
	while(ProcessMessage()==0 && !CheckHitKey(KEY_INPUT_ESCAPE)){

		// Draw�̃e�X�g
		ClearDrawScreen();
		//temp->Draw();
		temp->Draw(offset);
		if(CheckHitKey(KEY_INPUT_RIGHT)){
			offset++;
			//temp->Scroll(1);
		}
		else if(CheckHitKey(KEY_INPUT_LEFT)){
			offset--;
			//temp->Scroll(-1);
		}
		ScreenFlip();
	}
	// �f�X�g���N�^�̃e�X�g
	delete temp;
	DxLib_End();
}

#endif