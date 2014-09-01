#include "Warp.h"
#include "Player.h"


Warp::Warp(double ax,double ay):Item(ax,ay,"Image/warp.png", "Sound/coin_sound.wav",false)
{
}

void Warp::Affect(Character* chara){
	dynamic_cast<Player*>(chara)->NextMap();
}

void Warp::Think(){
	speed_.x = 0;
	speed_.y = 0;
}

Warp::~Warp(void)
{
}
