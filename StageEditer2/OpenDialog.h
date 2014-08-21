#pragma once
#include "resource.h"
#include "stdafx.h"
#include <commdlg.h>
class Map;

class OpenDialog{
private:
	// �e�̃E�B���h�E
	HWND			hWnd;
	// �t�@�C�����̍\����
	OPENFILENAME	ofn;
	// �t�@�C���p�X
	TCHAR			szPath[MAX_PATH];
public:
	// �R���X�g���N�^
	OpenDialog(HWND hWnd);
	// �t�@�C�����J��
	TCHAR* FileOpen(HWND hWnd);
	// �}�b�v�𐶐�����
	Map* CreateMap(char *filename);
};