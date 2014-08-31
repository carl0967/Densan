#include "Taihou.h"


Taihou::Taihou(double x,double y,Field* field):Enemy(x,y,0,0,50,"Image/taihou.png",1,1,new AttackBullet(this,field), new AimAttack(1,3,50,this,field->player(), "Sound/shot_sound.wav"))
{
}

Taihou::~Taihou(void)
{
}
