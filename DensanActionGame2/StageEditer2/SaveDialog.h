#pragma once
#include "resource.h"
#include "stdafx.h"
#include <commdlg.h>
#include <vector>

class SaveDialog{
private:
	// �e�̃E�B���h�E
	//HWND			hWnd;
	// �t�@�C�����̍\����
	OPENFILENAME	ofn;
	// �t�@�C���p�X
	TCHAR			szPath[MAX_PATH];
public:
	SaveDialog(HWND hWnd);
	// �t�@�C����ۑ�����
	void Save(char* filename,std::vector<int> orignal,int x,int y);
	// �t�@�C����ۑ�����
	TCHAR* FileSave(HWND hWnd);
};