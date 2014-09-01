#include "Taihou.h"


Taihou::Taihou(double x,double y,Field* field):Enemy(x,y,0,0,50,"Image/taihou.png",new AttackBullet(this,field), new AimAttack(1,3,100,this,field->player(), "Sound/shot_sound.wav"))
{
}

Taihou::~Taihou(void)
{
}
