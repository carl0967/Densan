#include "NoAtack.h"


NoAtack::NoAtack(Character* chara):Atack(0,0,0,chara)
{
}


void NoAtack::DoAtack(){
	//何もしない
}

NoAtack::~NoAtack(void)
{
}
