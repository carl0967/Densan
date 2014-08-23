#pragma once

//#include "DxLib.h"
#include "AObject.h"
#include "Character.h"

/*
物体である「アイテム」を表す抽象クラス
*/

class Item :public  AObject{
public:
	//コンストラクタ
	//x座標、ｙ座標、ファイル名（画像/画像ファイル名,オブジェクトの幅,オブジェクトの高さ,向き（右向きならtrue）
	Item(double ax,double ay,char* fname,int size_x,int size_y,bool right);
	//x座標、ｙ座標、ファイル名（画像/画像ファイル名,オブジェクトの幅,オブジェクトの高さ,向き（右向きならtrue,音源ファイルのパス
	Item(double ax,double ay,char* fname, char* sound_name,int size_x,int size_y,bool right);

	//関数
	/*
	引数のcharacterのフィールド変数を変更して、アイテムの効果を与える関数
	サブクラスにて実装すること
	*/
	virtual void Affect(Character* character) = 0;
	//音を出す関数
	void PlaySound();
	/*
	オーバーライドした関数
	そのアイテムがどのような動きをするかを決定する
	基本的には自身のスピードを変更する
	サブクラスにて実装すること
	*/
	 //void Think();
protected:
	int item_sound_;
	
private:


};