#include "Menu.h"
#include <string>

/*タイトル画面の表示を行う。Enterキーが入力されたら選択画面に移る。*/
void Menu::Start(){
	// while(裏画面を表画面に反映, メッセージ処理, 画面クリア, キー更新)
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && gpUpdateKey()==0 ){

		//計算フェーズ

		if( key[ KEY_INPUT_RETURN ] == 1){
			break;
		}

		// 描画フェーズ

		// メニュー項目を描画
		LoadGraphScreen(0,20,"画像/title.png",TRUE);

		DrawFormatString( 320, 300, GetColor(255,255,255), "Press the Enter Key!");

	}
}

/*選択肢の文字列を画面に表示して、ユーザーの選択待ち(ここでループをまわす)。
選択した場合はその選択肢の番号を返す。*/

int Menu::Select(){
	// メニュー項目要素を作る

	//画像を描画する
    MenuElement_t MenuElement[MAX_SELECTION]={
            {  80,100, "画像/stage1.png" }, // タグの中身の順番で格納される。xに80が、yに100が、nameに選択肢のファイル名
			{  50,150, "画像/stage2.png" },
			{  50,200, "画像/stage3.png" }
    };

    int SelectNum = 0; // 現在の選択番号

	// while(裏画面を表画面に反映, メッセージ処理, 画面クリア, キー更新)
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && gpUpdateKey()==0 ){

		// 計算フェーズ 
			
		if( key[ KEY_INPUT_DOWN ] == 1 ){ // 下キーが押された瞬間だけ処理
						
			SelectNum = ( SelectNum + 1 ) % MAX_SELECTION; // 現在の選択項目を一つ下にずらす(ループする)
		}

		if(key[ KEY_INPUT_UP ] == 1 ){ // 上キーが押された瞬間だけ処理

			SelectNum = ( SelectNum + (MAX_SELECTION - 1) ) % MAX_SELECTION; // 現在の選択項目を一つ上にずらす(逆ループする)
		}

		if( key[ KEY_INPUT_DOWN ] == 1 || key[ KEY_INPUT_UP ] == 1 ){ // 下キーか、上キーが押された瞬間
			for( int i=0; i<MAX_SELECTION; i++ ){              // メニュー項目数である個数分ループ処理
				if( i == SelectNum ){          // 今処理しているのが、選択番号と同じ要素なら
					MenuElement[i].x = 80; // 座標を80にする
				} else {                       // 今処理しているのが、選択番号以外なら
					MenuElement[i].x = 50;// 座標を50にする
				}
			}
		}

		if( key[ KEY_INPUT_RETURN ] == 1){
			return SelectNum;
		}

		// 描画フェーズ
		LoadGraphScreen(20,10,"画像/select_title.png",TRUE);

		for( int i=0; i<MAX_SELECTION; i++ ){ // メニュー項目を描画
			LoadGraphScreen(MenuElement[i].x,MenuElement[i].y,MenuElement[i].name,TRUE);
			if(i==SelectNum){
				LoadGraphScreen(MenuElement[i].x-30,MenuElement[i].y+10,"画像/selection_key.png",TRUE);
			}
		}

	}
}

// キーの入力状態を更新する
int Menu::gpUpdateKey(){
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll( tmpKey ); // 全てのキーの入力状態を得る
	for( int i=0; i<256; i++ ){ 
		if( tmpKey[i] != 0 ){ // i番のキーコードに対応するキーが押されていたら
			key[i]++;     // 加算
		} else {              // 押されていなければ
			key[i] = 0;   // 0にする
		}
	}
	return 0;
}