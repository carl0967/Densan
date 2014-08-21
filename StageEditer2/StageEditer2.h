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
	int HPos;										// スクロールバーのスクロール位置
	TCHAR *szFile;
	// HINSTANCE hInst;								// 現在のインターフェイス
	//TCHAR szTitle[MAX_LOADSTRING];					// タイトル バーのテキスト
	//TCHAR szWindowClass[MAX_LOADSTRING];			// メイン ウィンドウ クラス名
	// WinMainの引数
	HINSTANCE hInstance;							// インスタンスハンドル
	HINSTANCE hPrevInstance;						// 前のインスタンスハンドル(Win16時代の名残)
	LPTSTR lpCmdLine;								// コマンドライン引数
	int nCmdShow;									// アプリケーション表示方法
public:
	// コンストラクタ
	StageEditer2(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
		LPTSTR lpCmdLine,int nCmdShow);
	// デストラクタ
	~StageEditer2();
	// メインメッセージループ
	int MainLoop();


	// 水平スクロールバーの処理
	void OnHScroll(HWND hWnd, int mes);

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
	ATOM				MyRegisterClass(HINSTANCE hInstance);
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
	BOOL				InitInstance(HINSTANCE hInstance, int nCmdShow);
	
	//
	//  関数: WndProcOfInstance(HWND, UINT, WPARAM, LPARAM)
	//
	//  目的:  メイン ウィンドウのメッセージをインスタンス側で処理します。
	//
	//  WM_COMMAND	- アプリケーション メニューの処理
	//  WM_PAINT	- メイン ウィンドウの描画
	//  WM_DESTROY	- 中止メッセージを表示して戻る
	//
	//
	LRESULT CALLBACK	WndProcOfInstance(HWND, UINT, WPARAM, LPARAM);

	//
	//  関数: WndProc(HWND, UINT, WPARAM, LPARAM)
	//
	//  目的:  メイン ウィンドウのメッセージを処理します。
	//		   この関数は処理をインスタンスに委譲します。
	//
	//  WM_COMMAND	- アプリケーション メニューの処理
	//  WM_PAINT	- メイン ウィンドウの描画
	//  WM_DESTROY	- 中止メッセージを表示して戻る
	//
	//
	static LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

	// バージョン情報ボックスのメッセージ ハンドラーです。
	static INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
};