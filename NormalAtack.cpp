#include "NormalAtack.h"


NormalAtack::NormalAtack(int damage, int speed, int interval, Character* chara):Atack(damage, speed, interval ,chara)
{
}

void NormalAtack::DoAtack(){
	Atack::DoAtack(new NormalBullet(chara_->GetCenterPosX(), chara_->GetCenterPosY(), damage_, speed_, 1, 1,chara_->isRight()));
}

NormalAtack::~NormalAtack(void)
{
}
