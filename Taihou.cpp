#include "Taihou.h"


Taihou::Taihou(double x,double y,Field* field):Enemy(x,y,2,"�摜/��C�i�����j.png",1,1,new AttackBullet(this,field), new AimAttack(1,3,50,this,field->player()))
{
}


Taihou::~Taihou(void)
{
}