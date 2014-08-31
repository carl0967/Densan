/*
敵キャラクターの
カメクラス
*/
#pragma once
#include "NoAttack.h"

#include "Enemy.h"

class Kame:public Enemy{
public:
	Kame(double x,double y,Field* field);
};
