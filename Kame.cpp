#include "Kame.h"
#include "WalkStraight.h"
#include "NoAttack.h"

Kame::Kame(double x,double y,Field* field):Enemy(x,y,2.0,0,2,"�摜/kame1.png",1,1,new WalkStraight(this,field), new NoAttack(this)){
	move_ghandle_=loadg.Load("�摜/kame2.png");
}