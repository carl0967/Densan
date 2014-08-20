#include "Enemy.h"

Enemy::Enemy(double x,double y,int hp ,char* file_name,int sizex,int sizey,CharacterController* controller, Attack* attack)
	:Character(x,y,hp, file_name,sizex,sizey,false,controller,attack){
	object_type_ = O_ENEMY;
}