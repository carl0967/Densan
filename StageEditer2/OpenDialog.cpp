#include "stdafx.h"
#include "OpenDialog.h"
#include "Map.h"
#include <iostream>
#include <vector>



std::vector<std::string> split(const std::string &str, char delim){
	std::vector<std::string> res;
	size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != std::string::npos){
		res.push_back(std::string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(std::string(str, current, str.size() - current));
	return res;
}

Map* OpenDialog::CreateMap(char *filename,HWND hWnd){
	int width=0,height=0;
	std::vector<int> orignal;
	char source[120];
	int charSize;			// 現在行のサイズ
	FILE *fp;

	fp = fopen(filename,"a+");
	while(fp){
		if(fgets(source,120,fp)==NULL)
			break;
		height++;
		// スプリット
		std::vector<std::string> item = split(source,',');
		width = item.size();
		for(int i=0;i<item.size();i++){
			orignal.push_back(atoi(item[i].c_str()));
		}
	}
	if(fp)
		fclose(fp);
	Map *map = new Map(width,height,orignal);
	map->LoadMap(hWnd);
	return map;
}

OpenDialog::OpenDialog(HWND hWnd)
	:ofn(),szPath()
{
	//this->hWnd = hWnd;
}

TCHAR* OpenDialog::FileOpen(HWND hWnd){
	TCHAR *szFile = new TCHAR[MAX_PATH];		// マップファイル名
    for (int i = 0; i < MAX_PATH; i++){
      szFile[i] = ' ';
    }
	if(szPath[0] == _T('\0')){
		GetCurrentDirectory(MAX_PATH,szPath);
	}
	if(ofn.lStructSize == 0){
		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.hwndOwner  = hWnd;
		ofn.lpstrInitialDir = szPath;
		ofn.lpstrFile = szFile;
		ofn.nMaxFile = MAX_PATH;
		ofn.lpstrFilter = TEXT("すべてのファイル(*.*)\0*.*\0");
		ofn.lpstrTitle = TEXT("ファイルを開く");
		ofn.Flags = OFN_FILEMUSTEXIST;
	}
	if(GetOpenFileName(&ofn)){
		MessageBox(hWnd,szFile,TEXT("ファイルを開く"),MB_OK);
	}
	return szFile;
}