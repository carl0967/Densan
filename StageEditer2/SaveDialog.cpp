#include "stdafx.h"
#include "SaveDialog.h"
#include <iostream>
#include <sstream>

// コンストラクタ
SaveDialog::SaveDialog(HWND hWnd)
	:ofn(),szPath()
{
	this->hWnd = hWnd;
}

void SaveDialog::Save(char* filename,std::vector<int> orignal,int x,int y){
	FILE *fp;
	fp = fopen(filename,"w+");
	for(int i=0;i<y;i++){
		std::string output;
		std::stringstream ss;
		for(int j=0;j<x-1;j++){
			ss << orignal[i*x+j];
			ss << ',';	
		}
		ss << orignal[i*x+x-1];
		ss << "\n";
		fwrite(ss.str().c_str(),1,x*2,fp);
	}
	fclose(fp);
}

TCHAR* SaveDialog::FileSave(HWND hWnd){
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
		ofn.lpstrTitle = TEXT("ファイルを保存する");
	}
	if(GetSaveFileNameW(&ofn)){
		MessageBox(hWnd,TEXT("保存しました"),TEXT("ファイルを保存する"),MB_OK);
	}
	return ofn.lpstrFile;
}