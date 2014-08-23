#include "stdafx.h"
#include "StageEditer2.h"
#include "OpenDialog.h"
#include "SaveDialog.h"
#include "CreateDialog.h"
#include <commdlg.h>
#include <iostream>
#include <sstream>
#include <vector>

HINSTANCE hInst;								// 現在のインターフェイス
TCHAR szTitle[MAX_LOADSTRING];					// タイトル バーのテキスト
TCHAR szWindowClass[MAX_LOADSTRING];			// メイン ウィンドウ クラス名
MSG msg;
HACCEL hAccelTable;


// -----------ウィンドウプロシージャ-----------
// 静的なメンバ関数としておくことで、
// 外部からコールバックとして呼び出すことができる。
LRESULT CALLBACK StageEditer2::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// 元のインスタンスを登録されたユーザーデータから取得
	StageEditer2* stageEditer2 = (StageEditer2*)GetWindowLongPtr(hWnd,GWL_USERDATA);
	// インスタンス側の処理へ委譲
	return stageEditer2->WndProcOfInstance(hWnd,message,wParam,lParam);
}

// コンストラクタ
StageEditer2::StageEditer2(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine, int nCmdShow)
{
	// WinMainの引数を保管しておく
	this->hInstance = hInstance;
	this->hPrevInstance = hPrevInstance;
	this->lpCmdLine = lpCmdLine;
	this->nCmdShow = nCmdShow;

	//初期化
	map = nullptr;
	szFile = nullptr;
	HPos= 0;

	//WIN API関係
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_STAGEEDITER2, szWindowClass, MAX_LOADSTRING);

	// ウィンドウクラスの登録
	if (!MyRegisterClass(hInstance)){
		exit(0);		// アプリケーションを終了させる
	}

	// アプリケーションの初期化を実行します:
	if (!InitInstance (hInstance, nCmdShow)){
		exit(0);		// アプリケーションを終了させる
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_STAGEEDITER2));
}

// デストラクタ
StageEditer2::~StageEditer2(){
	if(szFile)
		delete[] szFile;
}

// メインメッセージループ
// ここで処理が繰り返される。
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
//  関数: MyRegisterClass()
//
//  目的: ウィンドウ クラスを登録します。
//
//  コメント:
//
//    この関数および使い方は、'RegisterClassEx' 関数が追加された
//    Windows 95 より前の Win32 システムと互換させる場合にのみ必要です。
//    アプリケーションが、関連付けられた
//    正しい形式の小さいアイコンを取得できるようにするには、
//    この関数を呼び出してください。
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
//   関数: InitInstance(HINSTANCE, int)
//
//   目的: インスタンス ハンドルを保存して、メイン ウィンドウを作成します。
//
//   コメント:
//
//        この関数で、グローバル変数でインスタンス ハンドルを保存し、
//        メイン プログラム ウィンドウを作成および表示します。
//
BOOL StageEditer2::InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance;	// グローバル変数にインスタンス処理を格納します。

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
	// オブジェクトのポインタをユーザーデータに登録
	// これはコールバックから自オブジェクトを呼び出すために
	// 必要である。
	SetWindowLongPtr(hWnd,GWL_USERDATA,(LONG)this);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}


// 水平スクロールバーの処理
void StageEditer2::OnHScroll(HWND hWnd, int mes)
{
	// 現在のスクロールバーの状況を取得する
	SCROLLINFO info;
	info.cbSize = sizeof(info);
	info.fMask = SIF_ALL;
	GetScrollInfo(hWnd, SB_HORZ, &info);
	int xmax = info.nMax - info.nPage+1;            // Posの最大値
	int xpos = info.nPos;                           // 変化前のPos位置
	int dx = 0;                                     // 変化量
	int tPos = info.nTrackPos;
	int pitch = 1;

	switch (mes)
	{
	case SB_LINEUP:								// サイズは縦方向と同じにした
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

	// 変化させる必要があると思われるとき
	if (dx != 0)
	{
		xpos += dx;                                   // コピーを変化させる
		if (xpos < 0)
			xpos = 0;                                   // 下のリミット
		if (xpos > xmax)
			xpos = xmax;                                // 上のリミット

		// 実際に変化させる必要があるとき
		if (xpos != info.nPos)
		{
			dx = xpos - info.nPos;                      // 実際の変化量を保存する
			info.nPos = xpos;                           // スクロールバーに設定する
			SetScrollInfo(hWnd, SB_HORZ, &info, TRUE);
			HPos = xpos;                                // 表示用のコピーを変更する
			// 画面をスクロールさせる
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
		// 選択されたメニューの解析:
		switch (wmId)
		{
		case IDM_HELLO:
			MessageBox(hWnd,L"Hello World",L"Hello World",MB_OK |MB_TOPMOST) ;
			break;
		case IDM_CREATEMAP:
		{
			if(map){
				MessageBox(hWnd,L"現在のマップを消します",L"警告",MB_OK |MB_TOPMOST);
				delete map;
			}
			DialogBox(hInstance, L"CREATE_DIALOG", NULL, &CreateDialog::DialogProc);
			map = CreateDialog::CreateMap();
			InvalidateRect(hWnd , NULL , TRUE);	// 再描画要求
			break;
		}
		case IDM_OPEN:
			if(szFile)delete szFile;
			szFile = nullptr;
			szFile = open.FileOpen(hWnd);
			if(szFile){
				//TCHAR型をchar型に変換
				WideCharToMultiByte(CP_ACP,0,szFile,-1,c,sizeof(c),NULL,NULL);
				map = open.CreateMap(c,hWnd);
				// map->LoadMap(hWnd);
				// スクロールバー
				scr.cbSize = sizeof(SCROLLINFO);
				scr.fMask = SIF_PAGE | SIF_RANGE;
				scr.nMin = 0;
				scr.nMax = map->getWidth();
				scr.nPage = 1;
				SetScrollInfo(hWnd , SB_HORZ , &scr , TRUE);
				InvalidateRect(hWnd , NULL , TRUE);	// 再描画要求
			}
			break;
		case IDM_SAVE:
			if(szFile)delete szFile;
			szFile = nullptr;
			szFile = save.FileSave(hWnd);
			if(!map){
				MessageBox(hWnd,L"保存するMapがありません",L"エラー",MB_OK |MB_TOPMOST) ;
				break;
			}
			if(szFile){
				//TCHAR型をchar型に変換
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
			// TODO: 描画コードをここに追加してください...
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
			TEXT("BUTTON") , TEXT("とぶかめ") , 
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON , 
			600 , 480 , 100 , 50 , hWnd , (HMENU)BID_FLYKAME,
			((LPCREATESTRUCT)(lParam))->hInstance , NULL
		);
		flag = CreateWindow(
			TEXT("BUTTON") , TEXT("たいほー") , 
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
		InvalidateRect(hWnd , NULL , TRUE);	// 再描画要求
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// バージョン情報ボックスのメッセージ ハンドラーです。
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