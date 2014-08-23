#include "stdafx.h"
#include "StageEditer2.h"
#include "OpenDialog.h"
#include "SaveDialog.h"
#include "CreateDialog.h"
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
	szFile = nullptr;
	HPos= 0;

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
	if(szFile)
		delete[] szFile;
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
			if(map){
				map->setOffset(info.nPos);
			}
		}
	}
}

LRESULT CALLBACK StageEditer2::WndProcOfInstance(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	static HWND empty,wall,player,kame,coin,flag,flykame,taiho;
	static int blockType = 0;
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	SCROLLINFO scr;

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
			MessageBox(hWnd,L"Hello World",L"Hello World",MB_OK |MB_TOPMOST) ;
			break;
		case IDM_CREATEMAP:
		{
			if(map){
				MessageBox(hWnd,L"���݂̃}�b�v�������܂�",L"�x��",MB_OK |MB_TOPMOST);
				delete map;
			}
			DialogBox(hInstance, L"CREATE_DIALOG", NULL, &CreateDialog::DialogProc);
			map = CreateDialog::CreateMap();
			InvalidateRect(hWnd , NULL , TRUE);	// �ĕ`��v��
			break;
		}
		case IDM_OPEN:
			if(szFile)delete szFile;
			szFile = nullptr;
			szFile = open.FileOpen(hWnd);
			if(szFile){
				//TCHAR�^��char�^�ɕϊ�
				WideCharToMultiByte(CP_ACP,0,szFile,-1,c,sizeof(c),NULL,NULL);
				map = open.CreateMap(c,hWnd);
				// map->LoadMap(hWnd);
				// �X�N���[���o�[
				scr.cbSize = sizeof(SCROLLINFO);
				scr.fMask = SIF_PAGE | SIF_RANGE;
				scr.nMin = 0;
				scr.nMax = map->getWidth();
				scr.nPage = 1;
				SetScrollInfo(hWnd , SB_HORZ , &scr , TRUE);
				InvalidateRect(hWnd , NULL , TRUE);	// �ĕ`��v��
			}
			break;
		case IDM_SAVE:
			if(szFile)delete szFile;
			szFile = nullptr;
			szFile = save.FileSave(hWnd);
			if(!map){
				MessageBox(hWnd,L"�ۑ�����Map������܂���",L"�G���[",MB_OK |MB_TOPMOST) ;
				break;
			}
			if(szFile){
				//TCHAR�^��char�^�ɕϊ�
				WideCharToMultiByte(CP_ACP,0,szFile,-1,c,sizeof(c),NULL,NULL);
				save.Save(c,map->getMapdata(),map->getWidth(),map->getHeight());
			}
			break;
		case IDM_ABOUT:
			DialogBox(hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, &StageEditer2::About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case BID_EMPTY:
			blockType = 0;
			break;
		case BID_WALL:
			blockType = 1;
			break;
		case BID_PLAYER:
			blockType = 2;
			break;
		case BID_KAME:
			blockType = 3;
			break;
		case BID_COIN:
			blockType = 4;
			break;
		case BID_FLAG:
			blockType = 5;
			break;
		case BID_FLYKAME:
			blockType = 6;
			break;
		case BID_TAIHO:
			blockType = 7;
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			// TODO: �`��R�[�h�������ɒǉ����Ă�������...
			if(map){
				map->DrawMap(hWnd,&ps,hdc);
			}
			EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
		if(map){
			map->SetMapData(lParam & 0xFFFF,(lParam >> 16) & 0xFFFF,hWnd , blockType);
		}
		break;
	case WM_CREATE:
	{
		empty = CreateWindow(
			TEXT("BUTTON") , TEXT("Empty") , 
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON , 
			0 , 480 , 100 , 50 , hWnd , (HMENU)BID_EMPTY ,
			((LPCREATESTRUCT)(lParam))->hInstance , NULL
		);
		wall = CreateWindow(
			TEXT("BUTTON") , TEXT("Wall") , 
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON , 
			100 , 480 , 100 , 50 , hWnd , (HMENU)BID_WALL ,
			((LPCREATESTRUCT)(lParam))->hInstance , NULL
		);
		player = CreateWindow(
			TEXT("BUTTON") , TEXT("Player") , 
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON , 
			200 , 480 , 100 , 50 , hWnd , (HMENU)BID_PLAYER ,
			((LPCREATESTRUCT)(lParam))->hInstance , NULL
		);
		kame = CreateWindow(
			TEXT("BUTTON") , TEXT("Kame") , 
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON , 
			300 , 480 , 100 , 50 , hWnd , (HMENU)BID_KAME ,
			((LPCREATESTRUCT)(lParam))->hInstance , NULL
		);
		coin = CreateWindow(
			TEXT("BUTTON") , TEXT("Coin") , 
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON , 
			400 , 480 , 100 , 50 , hWnd , (HMENU)BID_COIN ,
			((LPCREATESTRUCT)(lParam))->hInstance , NULL
		);
		flag = CreateWindow(
			TEXT("BUTTON") , TEXT("Flag") , 
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON , 
			500 , 480 , 100 , 50 , hWnd , (HMENU)BID_FLAG ,
			((LPCREATESTRUCT)(lParam))->hInstance , NULL
		);
		flag = CreateWindow(
			TEXT("BUTTON") , TEXT("�ƂԂ���") , 
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON , 
			600 , 480 , 100 , 50 , hWnd , (HMENU)BID_FLYKAME,
			((LPCREATESTRUCT)(lParam))->hInstance , NULL
		);
		flag = CreateWindow(
			TEXT("BUTTON") , TEXT("�����ف[") , 
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON , 
			700 , 480 , 100 , 50 , hWnd , (HMENU)BID_TAIHO ,
			((LPCREATESTRUCT)(lParam))->hInstance , NULL
		);
		break;
	}
	case WM_HSCROLL:
		OnHScroll(hWnd,LOWORD(wParam));
		if(map){
			map->setOffset(HPos);
		}
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