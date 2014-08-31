/*
敵及び自機の抽象クラス。
新しく敵を作る場合はこのクラスを継承したクラスを作る
*/
#pragma once

#include "DxLib.h"
#include "AObject.h"
#include "Attack.h"
class Field;
class CharacterController;
class Attack;

class Character: public AObject{
public:
	//初期のx座標,y座標,移動速度,ジャンプ力,HP,画像のファイル名,当たり判定の倍率のX方向,Y方向,向き(右がtrue),CharacterController,Attack
	Character(double x,double y,double move_power,double jump_power,int hp ,char* f_name,double size_x,double size_y,bool right,CharacterController* controller,Attack* attack); //コンストラクタ
	virtual ~Character(); //デストラクタ

	void Jump();   //ジャンプする
	void Walk(bool right); //right=true　なら右に、falseなら左に移動する
	void Run(bool right); //Walkより速く移動する


	void NoMove(); //とまる（左右の移動を０にする）

	void Move();
	void DoAttack(); //攻撃をする。未実装
	void Damaged(int damage);  //ダメージを受けるときに呼ばれる。HPが０になるとaliveがfalseに
	void Think(); //次にどのような行動をするかを決める。CharacterControllerに委譲。
	vector<Bullet*> GetBullets(); //弾を返す関数

	//ゲッター
	int hp(){return hp_;} //hpのゲッター
	int maxHp(){return max_hp_;}//maxHpのゲッター
	int GetBulletsSize(){return attack_->GetBulletsSize();} //持っている弾の数を返す
	double jump_power() {return jump_power_;}

	//オーバーライド
	void Reset();
	virtual void Draw(int offset); //プレイヤーで書き換える必要があるので仮想関数に

	void set_jump_power(double y);

protected:
	int hp_;  //体力
	int max_hp_; //体力の最大値
	int status_; //キャラクターの状態を表す
	double jump_power_;//ジャンプのスピード
	CharacterController *controller_; //キャラクターを動かすためのコントローラ
	Attack* attack_; 


private:


};