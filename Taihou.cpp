#include "Taihou.h"


Taihou::Taihou(double x,double y,Field* field):Enemy(x,y,1000,"‰æ‘œ/taihou.png",1,1,new AttackBullet(this,field), new AimAttack(1,3,50,this,field->player(), "‰¹Œ¹/shot_sound.wav"))
{
}


Taihou::~Taihou(void)
{
}
