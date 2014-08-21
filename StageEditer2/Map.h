#pragma once
#include "stdafx.h"
#include "resource.h"
#include <commdlg.h>
#include <vector>

class Map{
private:
	int width;				// �}�b�v�̕�
	int height;				// �}�b�v�̍���
	int offset;				// �}�b�v�`��I�t�Z�b�g�l

	std::vector<int> orignal;		// �}�b�v�f�[�^
	TCHAR *szFile;					// �}�b�v�t�@�C����

	BITMAP renga;		// �����K
	HDC rengaMem;		//
	BITMAP player;		// �v���C���[
	HDC playerMem;		//
	BITMAP kame;		// ���߂���
	HDC kameMem;		//
	BITMAP coin;		// �R�C��
	HDC coinMem;		//	
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