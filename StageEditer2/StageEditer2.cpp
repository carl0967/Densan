#include "stdafx.h"
#include "StageEditer2.h"
#include "OpenDialog.h"
#include "SaveDialog.h"
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
	//delete[] szFile;
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
		// 選択されたメニューの解析:
		switch (wmId)
		{
		case IDM_HELLO:
			//LPVOID lpMsgBuf;
			//SetLastError(NO_ERROR);		//エラー情報をクリアする
			//ここにチェックしたい処理を書く
			MessageBox(hWnd,L"Hello World",L"Hello World",MB_OK |MB_TOPMOST) ;

			/*
			FormatMessage(				//エラー表示文字列作成
				FORMAT_MESSAGE_ALLOCATE_BUFFER | 
				FORMAT_MESSAGE_FROM_SYSTEM | 
				FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL, GetLastError(),
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
				(LPTSTR) &lpMsgBuf, 0, NULL);
			*/
			//MessageBox(NULL, (LPCWSTR)lpMsgBuf, NULL, MB_OK);	//メッセージ表示
			//LocalFree(lpMsgBuf);
			break;
		case IDM_OPEN:
			szFile = open.FileOpen(hWnd);
			//TCHAR型をchar型に変換
			WideCharToMultiByte(CP_ACP,0,szFile,-1,c,sizeof(c),NULL,NULL);
			map = open.CreateMap(c);
			// map->LoadMap(hWnd);
			// スクロールバー
			scr.cbSize = sizeof(SCROLLINFO);
			scr.fMask = SIF_PAGE | SIF_RANGE;
			scr.nMin = 0;
			scr.nMax = map->getWidth();
			scr.nPage = 1;
			SetScrollInfo(hWnd , SB_HORZ , &scr , TRUE);
			InvalidateRect(hWnd , NULL , TRUE);	// 再描画要求
			break;
		case IDM_SAVE:
			szFile = save.FileSave(hWnd);
			//TCHAR型をchar型に変換
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
			// TODO: 描画コードをここに追加してください...
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