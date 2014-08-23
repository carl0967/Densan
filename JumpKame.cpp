#include "JumpKame.h"
#include "NoAttack.h"
#include "Jumping.h"

JumpKame::JumpKame(double x,double y,Field* field):Enemy(x,y,2,"‰æ‘œ/‚Æ‚Ô‚©‚ß4.png",1,1,new Jumping(this,field), new NoAttack(this)){
	sanpo=0;
}

void JumpKame::Jump(){
	if(sanpo%3==0){
		speed_.y=-15;
	}
	else{
		speed_.y=-7;
	}
	aerial=true;
	sanpo++;
}