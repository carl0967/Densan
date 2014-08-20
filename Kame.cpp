#include "Kame.h"
#include "WalkStraight.h"

Kame::Kame(double x,double y,Field* field):Enemy(x,y,2,"‰æ‘œ/‚©‚ß4.png",1,1,new WalkStraight(this,field), new NoAttack(this)){
	//move_ghandle_=loadg.Load("‰æ‘œ/‚©‚ß2.png");
}