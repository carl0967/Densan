#include "JumpKame.h"
#include "NoAttack.h"
#include "Jumping.h"

JumpKame::JumpKame(double x,double y,Field* field):Enemy(x,y,2,"�摜/�ƂԂ���4.png",1,1,new Jumping(this,field), new NoAttack(this)){
}
