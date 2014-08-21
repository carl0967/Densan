#pragma once
#include "stdafx.h"
#include "resource.h"
#include <commdlg.h>
#include <vector>
#define GRAPHIC_NUM 8

class Map{
	enum MapChip{EMPTY,WALL,PLAYER,KAME,COIN,G_FLAG,FLYKAME,TAIHO};
private:
	int width;				// �}�b�v�̕�
	int height;				// �}�b�v�̍���
	int offset;				// �}�b�v�`��I�t�Z�b�g�l

	std::vector<int> orignal;		// �}�b�v�f�[�^
	TCHAR *szFile;					// �}�b�v�t�@�C����

	BITMAP graphics[GRAPHIC_NUM];	// �摜�f�[�^�̃r�b�g�}�b�v
	HDC	graphicMem[GRAPHIC_NUM];	// �摜�f�[�^�̃�����
public:
	Map(int,int,std::vector<int>);
	// �}�b�v��ǂݍ���
	VOID LoadMap(HWND hWnd);
	// �`�悷��
	VOID DrawMap(HWND hWnd,PAINTSTRUCT *ps,HDC hdc);
	// �}�b�v�f�[�^���z������
	void AddMapData(int xPos,int yPos,HWND hWnd);
	// �Z�b�^�[
	void setOffset(int offset){this->offset=offset;}
	// �Q�b�^�[
	int getOffset(){return offset;}
	int getWidth(){return width;}
	int getHeight(){return height;}
	std::vector<int> getMapdata(){return orignal;}

};