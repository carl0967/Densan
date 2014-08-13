#pragma once

#include "DxLib.h"

/*
攻撃である「火炎弾」を表す具象クラス
Bulletの実装例
*/

abstract class FireBall extends Bullet{
public:
	//コンストラクタ
	//x座標、ｙ座標、ファイル名（画像/画像ファイル名,オブジェクトの幅,オブジェクトの高さ,向き（右向きならtrue）,ダメージ量
	FireBall(double ax,double ay,char* fname,int size_x,int size_y,bool right,int damageValue);
	//関数
	/*
	やや高速に設定する
	*/
	abstract void Think();
	
protected:

private:
	
};