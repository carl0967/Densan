/*
�摜�̃t�@�C�����ƃO���t�B�b�N�n���h���̊֘A�t�����Ǘ�����N���X
�܂��ǂݍ��񂾂��Ƃ̂Ȃ��t�@�C�����̂ݓǂݍ���
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