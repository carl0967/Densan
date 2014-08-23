#include "JumpKame.h"
#include "NoAttack.h"
#include "Jumping.h"

<<<<<<< HEAD
JumpKame::JumpKame(double x,double y,Field* field):Enemy(x,y,2,"‰æ‘œ/jump_kame1.png",1,1,new JumpEnemy(this,field), new NoAttack(this)){
=======
JumpKame::JumpKame(double x,double y,Field* field):Enemy(x,y,2,"‰æ‘œ/‚Æ‚Ô‚©‚ß4.png",1,1,new Jumping(this,field), new NoAttack(this)){
>>>>>>> FETCH_HEAD
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