#include "Kame.h"
#include "WalkStraight.h"

Kame::Kame(double x,double y,Field* field):Enemy(x,y,2,"�摜/����4.png",1,1,new WalkStraight(this,field), new NoAttack(this)){
	//move_ghandle_=loadg.Load("�摜/����2.png");
}