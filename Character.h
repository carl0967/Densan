/*
敵及び自機の抽象クラス。
新しく敵を作る場合はこのクラスを継承したクラスを作る
*/
#pragma once

#include "DxLib.h"
#include "AObject.h"
#include "Atack.h"
class Field;
class CharacterController;
class Atack;

class Character: public AObject{
public:
	Character(double x,double y,int hp ,char* f_name,int size_x,int size_y,bool right,Atack* atack); //コンストラクタ

	//下位クラスで挙動を変えたい場合は、これらをオーバーライドする
	virtual void Jump();   //ジャンプする
	virtual void Walk(bool right); //right=true　なら右に、falseなら左に移動する
	virtual void Run(bool right); //Walkより速く移動する

	void NoMove(); //とまる（左右の移動を０にする）

	void DoAttack(); //攻撃をする。未実装
	void Damaged(int damage);  //ダメージを受けるときに呼ばれる。HPが０になるとaliveがfalseに
	void Think(); //次にどのような行動をするかを決める。CharacterControllerに委譲。
	vector<Bullet*> GetBullets(); //弾を返す関数

	//ゲッター
	int hp(){return hp_;} //hpのゲッター
	int maxHp(){return max_hp_;}//maxHpのゲッター
	int GetBulletsSize(){return atack_->GetBulletsSize();} //持っている弾の数を返す

	//オーバーライド
	void Reset();
	virtual void Draw(int offset); //プレイヤーで書き換える必要があるので仮想関数に

protected:
	int hp_;  //体力
	int max_hp_; //体力の最大値
	int status_; //キャラクターの状態を表す
	CharacterController *controller_; //キャラクターを動かすためのコントローラ
	Atack* atack_;


private:


};