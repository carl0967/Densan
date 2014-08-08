#include "Kame.h"
#include "WalkStraight.h"

Kame::Kame(double x,double y):Enemy(x,y,"‰æ‘œ/‚©‚ß‚P.png",32,32,false){
	controller_=new WalkStraight(this);
	move_ghandle_=loadg.Load("‰æ‘œ/‚©‚ß‚Q.png");
}