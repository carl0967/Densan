#pragma once

#include "AObject.h"
#include "Bullet.h"

/*
「攻撃する」ことを表す抽象クラス
*/

/*
更新における注意点
DrawBulletsに引数を追加
offsetをもたせるようにする
*/

abstract class Attack{
public:
	//コンストラクタ
	Attack();
	//関数
	/*
	CreateBulletでbulletを生成し、bulletsへ追加
	DrawBulletsで弾を描画
	MoveBulletsで動かす
	*/
	void DoAttack();
	/*
	bulletsに対して描画
	*/
	void DrawBullets(int offset);
	/*
	bulletsを動かす
	*/
	void MoveBullets();

	
protected:
	//フィールド
	//生成した弾の保管場所
	ArrayList<Bullet> bullets;
	//関数
	//弾を生成する
	abstract CreateBullet();
	
private:
	

};