#include "AimAttack.h"

AimAttack::AimAttack(int damage, int speed, int interval, Character* chara,Character* aim_chara):Attack(damage, speed, interval ,chara)
{
	aim_chara_ = aim_chara;

}
AimAttack::AimAttack(int damage, int speed, int interval, Character* chara, Character* aim_chara, char* sound_name):Attack(damage, speed, interval, chara, sound_name)
{
	aim_chara_ = aim_chara;
}

void AimAttack::DoAttack(){
	Attack::DoAttack( new AimBullet(chara_->GetCenterPosX(), chara_->GetCenterPosY(), damage_, speed_, 1, 1,aim_chara_->GetCenterPosX(), aim_chara_->GetCenterPosY()));
}

void AimAttack::InitializeBullet(int num){
	dynamic_cast<AimBullet*>(bullets_.at(num))->Initialize(chara_->GetCenterPosX(), chara_->GetCenterPosY(),aim_chara_->GetCenterPosX(),aim_chara_->GetCenterPosY());
}
