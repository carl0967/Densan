#include "Kame.h"
#include "WalkStraight.h"

Kame::Kame(double x,double y,Field* field):Enemy(x,y,"‰æ‘œ/‚©‚ß4.png",1,1,false){
	controller_=new WalkStraight(this,field);
	//move_ghandle_=loadg.Load("‰æ‘œ/‚©‚ß2.png");
}