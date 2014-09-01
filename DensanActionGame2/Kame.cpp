#include "Kame.h"
#include "WalkStraight.h"
#include "NoAttack.h"

Kame::Kame(double x,double y,Field* field):Enemy(x,y,2.0,0,2,"Image/kame1.png",new WalkStraight(this,field), new NoAttack(this)){
	move_ghandle_=loadg.Load("Image/kame2.png");
}