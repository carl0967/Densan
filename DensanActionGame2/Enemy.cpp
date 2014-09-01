#include "Enemy.h"

Enemy::Enemy(double x,double y,double move_power,double jump_power,int hp ,char* file_name,CharacterController* controller, Attack* attack)
	:Character(x,y,move_power,jump_power,hp, file_name,false,controller,attack){
	object_type_ = O_ENEMY;
}