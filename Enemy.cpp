#include "Enemy.h"

Enemy::Enemy(double x,double y,int hp ,char* file_name,int sizex,int sizey,bool r, Attack* attack):Character(x,y,hp, file_name,sizex,sizey,r,attack){
	object_type_ = O_ENEMY;
}