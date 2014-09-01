#include "JumpKame.h"
#include "NoAttack.h"
#include "Jumping.h"

JumpKame::JumpKame(double x,double y,Field* field):Enemy(x,y,1.0,5.0,1,"Image/jump_kame1.png",new Jumping(this,field), new NoAttack(this)){
}
