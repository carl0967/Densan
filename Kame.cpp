#include "Kame.h"
#include "WalkStraight.h"

Kame::Kame(double x,double y):Enemy(x,y,"�摜/���߂P.png",32,32,false){
	controller_=new WalkStraight(this);
	move_ghandle_=loadg.Load("�摜/���߂Q.png");
}