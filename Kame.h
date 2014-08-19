/*
敵キャラクターの
カメクラス
*/
#pragma once
#include "NoAtack.h"

#include "Enemy.h"

class Kame:public Enemy{
public:
	Kame(double x,double y,Field* field);
};
