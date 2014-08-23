#include "JumpKame.h"
#include "NoAttack.h"
#include "Jumping.h"

JumpKame::JumpKame(double x,double y,Field* field):Enemy(x,y,5.0,5.0,1,"‰æ‘œ/jump_kame1.png",1,1,new Jumping(this,field), new NoAttack(this)){
}
