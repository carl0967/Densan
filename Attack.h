#pragma once

#include "DxLib.h"

/*
「攻撃する」ことを表す抽象クラスのヘッダーファイル
担当:中井
*/
/*
更新:2014/07/21
更新内容:未作成状態から形を与えただけ
*/

abstract class Attack{
public:
	//関数
	/*
	CreateBulletでbulletを生成し、bulletsへ追加
	*/
	void DoAttack(){
		CreateBullet();
	}
	/*
	bulletsに対して描画
	*/
	void DrawBullets(){

	}
	/*

	*/
	void MoveBullets(){

	}

	
protected:
	//フィールド
	ArrayList<Bullet> bullet;
	//関数
	abstract CreateBullet();
	
private:
	

};