#include "Kame.h"
#include "WalkStraight.h"
#include "AimAttack.h"

Kame::Kame(double x,double y,Field* field):Enemy(x,y,2,"画像/かめ4.png",1,1,new WalkStraight(this,field),  new NormalAttack(1,7,10,this)){
	//move_ghandle_=loadg.Load("画像/かめ2.png");
}