
#include "GoalFlag.h"
#include "Player.h"

//コンストラクタ
GoalFlag::GoalFlag(double ax,double ay):Item(ax,ay,"Image/flag1.png",1,1,false){
}
//関数
void GoalFlag::Affect(Character* character){
	dynamic_cast<Player*>(character)->SetGameStatus(CLEAR);

}
void GoalFlag::Think(){
	speed_.x = 0;
	speed_.y = 0;
}

