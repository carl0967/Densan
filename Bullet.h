#pragma once
#include "aobject.h"
#include <math.h>

#define PAI 3.14

class Bullet :public AObject
{
public:
	Bullet(double x,double y,int damage,double move_power, char* fname, double hit_size_x, double hit_size_y);//コンストラクタ
	~Bullet();
	virtual void Think();
	void Move();
	void DieBullet(); //離れた弾を消滅させる
	virtual void Initialize(double x, double y);//初期化処理(再出現させる際に呼び出す)


	//ゲッター
	int damage(){return damage_;}

protected:
	int damage_;
	double angle_; //発射角度
};

