#pragma once

#include "DxLib.h"

/*
「火炎弾で攻撃する」ことを表す具象クラス
Attackの実装例
*/

class FireBallAttack extends Attack{
public:
	//コンストラクタ
	FireBallAttack();
	
protected:
	//関数
	CreateBullet();
	
private:
	

};