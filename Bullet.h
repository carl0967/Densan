#pragma once
#include "aobject.h"

enum Direction{
	RIGHT = 1, LEFT = -1
};

class Bullet :public AObject
{
public:
	Bullet(double x,double y,int damage,int speed, char* fname, int hit_size_x, int hit_size_y,bool right);//コンストラクタ
	virtual void Think() = 0;
	void DieBullet(); //離れた弾を消滅させる
	void Initialize(double x, double y,int direction);//初期化処理(再出現させる際に呼び出す)
	~Bullet(void);


	//ゲッター
	int damage(){return damage_;}

protected:
	int damage_;
	int bullet_speed_; //弾の速度
	int direction_;   //1のとき右方向,-1の時左方向
};

