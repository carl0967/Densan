#pragma once

#include "resource.h"
#include "stdafx.h"
#include <commdlg.h>
#include <iostream>
#include <sstream>
#include "Map.h"



#define MAX_LOADSTRING 100

class StageEditer2{
private:
	Map *map;
	//MSG msg;
	//HACCEL hAccelTable;
	int HPos;										// �X�N���[���o�[�̃X�N���[���ʒu
	TCHAR *szFile;
	// HINSTANCE hInst;								// ���݂̃C���^�[�t�F�C�X
	//TCHAR szTitle[MAX_LOADSTRING];					// �^�C�g�� �o�[�̃e�L�X�g
	//TCHAR szWindowClass[MAX_LOADSTRING];			// ���C�� �E�B���h�E �N���X��
	// WinMain�̈���
	HINSTANCE hInstance;							// �C���X�^���X�n���h��
	HINSTANCE hPrevInstance;						// �O�̃C���X�^���X�n���h��(Win16����̖��c)
	LPTSTR lpCmdLine;								// �R�}���h���C������
	int nCmdShow;									// �A�v���P�[�V�����\�����@
public:
	// �R���X�g���N�^
	StageEditer2(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
		LPTSTR lpCmdLine,int nCmdShow);
	// �f�X�g���N�^
	~StageEditer2();
	// ���C�����b�Z�[�W���[�v
	int MainLoop();


	// �����X�N���[���o�[�̏���
	void OnHScroll(HWND hWnd, int mes);

	//
	//  �֐�: MyRegisterClass()
	//
	//  �ړI: �E�B���h�E �N���X��o�^���܂��B
	//
	//  �R�����g:
	//
	//    ���̊֐�����юg�����́A'RegisterClassEx' �֐����ǉ����ꂽ
	//    Windows 95 ���O�� Win32 �V�X�e���ƌ݊�������ꍇ�ɂ̂ݕK�v�ł��B
	//    �A�v���P�[�V�������A�֘A�t����ꂽ
	//    �������`���̏������A�C�R�����擾�ł���悤�ɂ���ɂ́A
	//    ���̊֐����Ăяo���Ă��������B
	//
	ATOM				MyRegisterClass(HINSTANCE hInstance);
	//
	//   �֐�: InitInstance(HINSTANCE, int)
	//
	//   �ړI: �C���X�^���X �n���h����ۑ����āA���C�� �E�B���h�E���쐬���܂��B
	//
	//   �R�����g:
	//
	//        ���̊֐��ŁA�O���[�o���ϐ��ŃC���X�^���X �n���h����ۑ����A
	//        ���C�� �v���O���� �E�B���h�E���쐬����ѕ\�����܂��B
	//
	BOOL				InitInstance(HINSTANCE hInstance, int nCmdShow);
	
	//
	//  �֐�: WndProcOfInstance(HWND, UINT, WPARAM, LPARAM)
	//
	//  �ړI:  ���C�� �E�B���h�E�̃��b�Z�[�W���C���X�^���X���ŏ������܂��B
	//
	//  WM_COMMAND	- �A�v���P�[�V���� ���j���[�̏���
	//  WM_PAINT	- ���C�� �E�B���h�E�̕`��
	//  WM_DESTROY	- ���~���b�Z�[�W��\�����Ė߂�
	//
	//
	LRESULT CALLBACK	WndProcOfInstance(HWND, UINT, WPARAM, LPARAM);

	//
	//  �֐�: WndProc(HWND, UINT, WPARAM, LPARAM)
	//
	//  �ړI:  ���C�� �E�B���h�E�̃��b�Z�[�W���������܂��B
	//		   ���̊֐��͏������C���X�^���X�ɈϏ����܂��B
	//
	//  WM_COMMAND	- �A�v���P�[�V���� ���j���[�̏���
	//  WM_PAINT	- ���C�� �E�B���h�E�̕`��
	//  WM_DESTROY	- ���~���b�Z�[�W��\�����Ė߂�
	//
	//
	static LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

	// �o�[�W�������{�b�N�X�̃��b�Z�[�W �n���h���[�ł��B
	static INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
};