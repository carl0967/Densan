// main.cpp : �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂�
#include "stdafx.h"
#include "StageEditer2.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{	
	StageEditer2 stageEditer2(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
	return stageEditer2.MainLoop();
}