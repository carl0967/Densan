#include "Kame.h"
#include "WalkStraight.h"
#include "NoAttack.h"

Kame::Kame(double x,double y,Field* field):Enemy(x,y,2,"�摜/kame1.png",1,1,new WalkStraight(this,field), new NoAttack(this)){
}