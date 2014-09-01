#pragma once
#include "aobject.h"
#include <math.h>

#define PAI 3.14

class Bullet :public AObject
{
public:
	//初期のx座標,y座標,移動速度,画像名,当たり判定の倍率
	Bullet(double x,double y,int damage,double move_power, char* fname);//コンストラクタ
	~Bullet();//デストラクタ
	virtual void Think();
	void Move();
	void DieBullet(); //離れた弾を消滅させる
	virtual void Initialize(double x, double y);//初期化処理(再出現させる際に呼び出す)

	int damage(){return damage_;}


protected:
	double angle_; //発射角度
	int damage_; //弾のダメージ
};

