/*
敵キャラクターの
カメクラス
*/
#pragma once
#include "Enemy.h"

class JumpKame:public Enemy{
public:
	JumpKame(double x,double y,Field* field);
	void Jump();//オーバーライド
private:
	int sanpo;//ジャンプした回数
};
