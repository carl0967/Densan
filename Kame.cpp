#include "Kame.h"
#include "WalkStraight.h"

Kame::Kame(double x,double y,Field* field):Enemy(x,y,"�摜/���߂P.png",32,32,false){
	controller_=new WalkStraight(this,field);
	move_ghandle_=loadg.Load("�摜/���߂Q.png");
}