
#include "GoalFlag.h"
#include "Player.h"

//�R���X�g���N�^
GoalFlag::GoalFlag(double ax,double ay):Item(ax,ay,"Image/flag1.png",false){
}
//�֐�
void GoalFlag::Affect(Character* character){
	dynamic_cast<Player*>(character)->SetGameStatus(CLEAR);

}
void GoalFlag::Think(){
	speed_.x = 0;
	speed_.y = 0;
}

