
#include "GoalFlag.h"
#include "Player.h"

//�R���X�g���N�^
GoalFlag::GoalFlag(double ax,double ay):Item(ax,ay,"�摜/flag1.png",1,1,false){
}
//�֐�
void GoalFlag::Affect(Character* character){
	dynamic_cast<Player*>(character)->ChangeClear();

}
void GoalFlag::Think(){
	speed_.x = 0;
	speed_.y = 0;
}

