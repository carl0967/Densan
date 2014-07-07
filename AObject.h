#pragma once

#include "DxLib.h"


/*
「物体」の抽象クラス
*/
/*
変更部分メモ
座標やスピード,サイズのx,yを構造体でまとめた
*/

//２次元をあらわす構造体。x軸とy軸をまとめている。
typedef struct{
	double x;
	double y;
}TwoDimension;

class AObject{
public:
	AObject(double ax,double ay);
	void Move();                  //自身のスピード分移動する
	void Draw(int offset);   //offsetを使って自身の描画位置を算出して描画する
	void Think();  //自身のスピードを操作して行動を決める
	void Fall(double gravity);  // 引数の重力分落ちる
	void Die(); //生存フラグをfalseにする

	void TouchedBlockX(double set_x);
	void TouchedBlockY(double set_y);

	//ゲッター
	TwoDimension pos() {return pos_;}
	TwoDimension speed() {return speed_; }
	bool isAerial() {return aerial;}
	bool isRight() {return right;}
	bool isAlive() {return alive;}

	//未完成。設定するにはFieldから現在の時間もらってこないとなんで、コンストラクタの引数でFieldがいる
	int  made_time() {return made_time_;}

protected:

	int made_time_;   //生成された時間（Fieldからみた）
	static int graphic_handle;  //どのメモリに画像が読み込まれているか
	TwoDimension pos_; //x,y座標
	TwoDimension speed_; //x,y軸のスピード
	TwoDimension size_; //オブジェクトのｘ方向の幅と、y方向の高さ
	bool alive; //生存していればtrue
	bool right; //向きを表す。右向きならtrue。左向きならfalse
	bool aerial; //空中にいるならtrue。地面に接しているならfalse
	char* file_name; //画像ファイル名

	 //ファイル名、サイズ、rightを初期化するメソッド。
	//下位クラスではこれをオーバーライドすればいいかと思い作成してみた。
	//コンストラクタで呼ばれる
	void init(); 


};