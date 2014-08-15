#define MAX_SELECTION 3//選択肢の個数
#pragma once
#include <dxlib.h>
#include <string>
using namespace std;

/*メニュー画面のクラス*/

class Menu{
private:
	string selection_array;//選択肢の文字列の配列
	typedef struct{
        int x, y;       // 座標格納用変数
        char name[128]; // 項目名格納用変数
	} MenuElement_t ;
	int key[256]; // キーが押されているフレーム数を格納する

public:
	void Start();//タイトル画面の表示
	int Select();//ユーザーの選択
	int gpUpdateKey();//キーの入力情報
};
