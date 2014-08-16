#define MAX_SELECTION 3//選択肢の個数
#pragma once
#include <dxlib.h>
#include <string>
using namespace std;

/*メニュー画面のクラス*/

class Menu{
private:
	typedef struct{
        int x, y;       // 座標格納用変数
		char picName[128];// 項目名画像格納用変数
        char fileName[128]; // 項目名格納用変数
	} MenuElement_t ;
	int key[256]; // キーが押されているフレーム数を格納する

public:
	void Start();//タイトル画面の表示
	string Select();//ユーザーの選択
	int gpUpdateKey();//キーの入力情報
};
