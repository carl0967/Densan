#include "Taihou.h"


Taihou::Taihou(double x,double y,Field* field):Enemy(x,y,1000,"�摜/taihou.png",1,1,new AttackBullet(this,field), new AimAttack(1,3,50,this,field->player(), "����/shot_sound.wav"))
{
}


Taihou::~Taihou(void)
{
}
