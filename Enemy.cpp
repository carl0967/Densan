#include "Enemy.h"

Enemy::Enemy(double x,double y,int hp ,char* file_name,int sizex,int sizey,bool r, Atack* atack):Character(x,y,hp, file_name,sizex,sizey,r,atack){
	object_type_ = O_ENEMY;
}