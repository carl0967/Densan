#pragma once

#include "DxLib.h"

/*
攻撃に使用する「弾がない」ことを表す具象クラス
Bulletの実装例
*/

abstract class EmptyBullet extends Bullet{
public:
	//コンストラクタ
	EmptyBullet(double ax,double ay,char* fname,int size_x,int size_y,bool right,int damageValue);
	//関数
	/*
	何もしないで消滅させる
	*/
	void Think();
	
protected:

	//フィールド
	
private:
	
};