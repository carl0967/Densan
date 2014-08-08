/*
敵及び自機の抽象クラス。
新しく敵を作る場合はこのクラスを継承したクラスを作る
*/
#pragma once

#include "DxLib.h"
#include "AObject.h"
class CharacterController;

class Character: public AObject{
public:
	Character(double x,double y,char* f_name,int size_x,int size_y,bool right); //コンストラクタ

	//下位クラスで挙動を変えたい場合は、これらをオーバーライドする
	virtual void Jump();   //ジャンプする
	virtual void Walk(bool right); //right=true　なら右に、falseなら左に移動する
	virtual void Run(bool right); //Walkより速く移動する

	void NoMove(); //とまる（左右の移動を０にする）

	void DoAttack(); //攻撃をする。未実装
	void Damaged(int damage);  //ダメージを受けるときに呼ばれる。HPが０になるとaliveがfalseに
	void Think(); //次にどのような行動をするかを決める。CharacterControllerに委譲。

protected:
	int hp_;  //体力
	int status_; //キャラクターの状態を表す
	CharacterController *controller_; //キャラクターを動かすためのコントローラ


private:


};