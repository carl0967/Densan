#include "AimAttack.h"

AimAttack::AimAttack(int damage, int speed, int interval, Character* chara):Attack(damage, speed, interval ,chara)
{
}

void AimAttack::DoAttack(){
	Attack::DoAttack(new AimBullet(chara_->GetCenterPosX(), chara_->GetCenterPosY(), damage_, speed_, 1, 1,100,100));
}

void AimAttack::InitializeBullet(int num){
	dynamic_cast<AimBullet*>(bullets_.at(num))->Initialize(chara_->GetCenterPosX(), chara_->GetCenterPosY(), 100.0, 100.0);
}
