#pragma once

#include "DxLib.h"

/*
「攻撃しない」ことを表す具象クラス
Attackの実装例
*/

class NoAttack extends Attack{
public:
	//コンストラクタ
	NoAttack();
	//関数
	
protected:
	//フィールド
	//ArrayList<Bullet> bullet;
	//関数
	CreateBullet();
	
private:
	

};