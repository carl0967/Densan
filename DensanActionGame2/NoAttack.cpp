#include "NoAttack.h"


NoAttack::NoAttack(Character* chara):Attack(0,0,0,chara)
{
}

void NoAttack::DoAttack(){
	//何もしない
}

void NoAttack::InitializeBullet(int num){
	//何もしない
}

NoAttack::~NoAttack(void)
{
}
