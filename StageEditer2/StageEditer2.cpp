#include "stdafx.h"
#include "StageEditer2.h"
#include "OpenDialog.h"
#include "SaveDialog.h"
#include <commdlg.h>
#include <iostream>
#include <sstream>
#include <vector>

HINSTANCE hInst;								// ���݂̃C���^�[�t�F�C�X
TCHAR szTitle[MAX_LOADSTRING];					// �^�C�g�� �o�[�̃e�L�X�g
TCHAR szWindowClass[MAX_LOADSTRING];			// ���C�� �E�B���h�E �N���X��
MSG msg;
HACCEL hAccelTable;


// -----------�E�B���h�E�v���V�[�W��-----------
// �ÓI�ȃ����o�֐��Ƃ��Ă������ƂŁA
// �O������R�[���o�b�N�Ƃ��ČĂяo�����Ƃ��ł���B
LRESULT CALLBACK StageEditer2::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// ���̃C���X�^���X��o�^���ꂽ���[�U�[�f�[�^����擾
	StageEditer2* stageEditer2 = (StageEditer2*)GetWindowLongPtr(hWnd,GWL_USERDATA);
	// �C���X�^���X���̏����ֈϏ�
	return stageEditer2->WndProcOfInstance(hWnd,message,wParam,lParam);
}

// �R���X�g���N�^
StageEditer2::StageEditer2(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine, int nCmdShow)
{
	// WinMain�̈�����ۊǂ��Ă���
	this->hInstance = hInstance;
	this->hPrevInstance = hPrevInstance;
	this->lpCmdLine = lpCmdLine;
	this->nCmdShow = nCmdShow;

	//������
	map = nullptr;

	//WIN API�֌W
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_STAGEEDITER2, szWindowClass, MAX_LOADSTRING);

	// �E�B���h�E�N���X�̓o�^
	if (!MyRegisterClass(hInstance)){
		exit(0);		// �A�v���P�[�V�������I��������
	}

	// �A�v���P�[�V�����̏����������s���܂�:
	if (!InitInstance (hInstance, nCmdShow)){
		exit(0);		// �A�v���P�[�V�������I��������
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_STAGEEDITER2));
}

// �f�X�g���N�^
StageEditer2::~StageEditer2(){
	//delete[] szFile;
}

// ���C�����b�Z�[�W���[�v
// �����ŏ������J��Ԃ����B
int StageEditer2::MainLoop(){


	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}

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

ATOM StageEditer2::MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex = {};

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;	
	wcex.lpfnWndProc	= &StageEditer2::WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_STAGEEDITER2));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_STAGEEDITER2);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

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
BOOL StageEditer2::InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance;	// �O���[�o���ϐ��ɃC���X�^���X�������i�[���܂��B

	hWnd = CreateWindow(
		szWindowClass, szTitle,
		WS_OVERLAPPEDWINDOW | WS_HSCROLL,
		CW_USEDEFAULT, CW_USEDEFAULT , 
		CW_USEDEFAULT, CW_USEDEFAULT , 
		NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}
	// �I�u�W�F�N�g�̃|�C���^�����[�U�[�f�[�^�ɓo�^
	// ����̓R�[���o�b�N���玩�I�u�W�F�N�g���Ăяo�����߂�
	// �K�v�ł���B
	SetWindowLongPtr(hWnd,GWL_USERDATA,(LONG)this);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}


// �����X�N���[���o�[�̏���
void StageEditer2::OnHScroll(HWND hWnd, int mes)
{
	// ���݂̃X�N���[���o�[�̏󋵂��擾����
	SCROLLINFO info;
	info.cbSize = sizeof(info);
	info.fMask = SIF_ALL;
	GetScrollInfo(hWnd, SB_HORZ, &info);
	int xmax = info.nMax - info.nPage+1;            // Pos�̍ő�l
	int xpos = info.nPos;                           // �ω��O��Pos�ʒu
	int dx = 0;                                     // �ω���
	int tPos = info.nTrackPos;
	int pitch = 1;

	switch (mes)
	{
	case SB_LINEUP:								// �T�C�Y�͏c�����Ɠ����ɂ���
		dx = -pitch;
		break;
	case SB_LINEDOWN:
		dx = pitch;
		break;
	case SB_PAGEUP:
		dx = -pitch;
		break;
	case SB_PAGEDOWN:
		dx = pitch;
		break;
	case SB_THUMBTRACK:
		dx = tPos - xpos;
		break;
	}

	// �ω�������K�v������Ǝv����Ƃ�
	if (dx != 0)
	{
		xpos += dx;                                   // �R�s�[��ω�������
		if (xpos < 0)
			xpos = 0;                                   // ���̃��~�b�g
		if (xpos > xmax)
			xpos = xmax;                                // ��̃��~�b�g

		// ���ۂɕω�������K�v������Ƃ�
		if (xpos != info.nPos)
		{
			dx = xpos - info.nPos;                      // ���ۂ̕ω��ʂ�ۑ�����
			info.nPos = xpos;                           // �X�N���[���o�[�ɐݒ肷��
			SetScrollInfo(hWnd, SB_HORZ, &info, TRUE);
			HPos = xpos;                                // �\���p�̃R�s�[��ύX����

			// ��ʂ��X�N���[��������
			map->setOffset(info.nPos);
		}
	}
}



LRESULT CALLBACK StageEditer2::WndProcOfInstance(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	int wmId, wmEvent;
	static PAINTSTRUCT ps;
	static HDC hdc;
	static SCROLLINFO scr;

	OpenDialog open(hWnd);
	SaveDialog save(hWnd);

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		char c[MAX_PATH];
		// �I�����ꂽ���j���[�̉��:
		switch (wmId)
		{
		case IDM_HELLO:
			//LPVOID lpMsgBuf;
			//SetLastError(NO_ERROR);		//�G���[�����N���A����
			//�����Ƀ`�F�b�N����������������
			MessageBox(hWnd,L"Hello World",L"Hello World",MB_OK |MB_TOPMOST) ;

			/*
			FormatMessage(				//�G���[�\��������쐬
				FORMAT_MESSAGE_ALLOCATE_BUFFER | 
				FORMAT_MESSAGE_FROM_SYSTEM | 
				FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL, GetLastError(),
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
				(LPTSTR) &lpMsgBuf, 0, NULL);
			*/
			//MessageBox(NULL, (LPCWSTR)lpMsgBuf, NULL, MB_OK);	//���b�Z�[�W�\��
			//LocalFree(lpMsgBuf);
			break;
		case IDM_OPEN:
			szFile = open.FileOpen(hWnd);
			//TCHAR�^��char�^�ɕϊ�
			WideCharToMultiByte(CP_ACP,0,szFile,-1,c,sizeof(c),NULL,NULL);
			map = open.CreateMap(c);
			// map->LoadMap(hWnd);
			// �X�N���[���o�[
			scr.cbSize = sizeof(SCROLLINFO);
			scr.fMask = SIF_PAGE | SIF_RANGE;
			scr.nMin = 0;
			scr.nMax = map->getWidth();
			scr.nPage = 1;
			SetScrollInfo(hWnd , SB_HORZ , &scr , TRUE);
			InvalidateRect(hWnd , NULL , TRUE);	// �ĕ`��v��
			break;
		case IDM_SAVE:
			szFile = save.FileSave(hWnd);
			//TCHAR�^��char�^�ɕϊ�
			WideCharToMultiByte(CP_ACP,0,szFile,-1,c,sizeof(c),NULL,NULL);
			save.Save(c,map->getMapdata(),map->getWidth(),map->getHeight());
			break;
		case IDM_ABOUT:
			DialogBox(hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, &StageEditer2::About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		if(map){
			//hdc = BeginPaint(hWnd, &ps);
			map->DrawMap(hWnd,&ps,hdc);
			// TODO: �`��R�[�h�������ɒǉ����Ă�������...
			//EndPaint(hWnd, &ps);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
		map->AddMapData(lParam & 0xFFFF,(lParam >> 16) & 0xFFFF,hWnd);
		break;
	case WM_CREATE:
		break;
	case WM_HSCROLL:
		OnHScroll(hWnd,LOWORD(wParam));
		InvalidateRect(hWnd , NULL , TRUE);	// �ĕ`��v��
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// �o�[�W�������{�b�N�X�̃��b�Z�[�W �n���h���[�ł��B
INT_PTR CALLBACK StageEditer2::About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}