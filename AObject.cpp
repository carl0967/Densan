#include <string.h>
#include "AObject.h"

//int AObject::graphic_handle;
LoadGraphic AObject::loadg=LoadGraphic();

AObject::AObject(double x,double y,char* f_name,int hit_size_x,int hit_size_y,bool right){
	//初期化処理
	graphic_handle_=loadg.Load(f_name);
	GetObjectSize();
	move_ghandle_=0;
	pos_.x=x;
	pos_.y=y;
	first_pos_.x=pos_.x;
	first_pos_.y=pos_.y;
	aerial=false;
	alive=false;
	speed_.x=0;
	speed_.y=0;
	live_count_=0;
	hit_size_.x=hit_size_x;
	hit_size_.y=hit_size_y;
	this->right=right;
	first_right=right;
	move_power=5.0;
}

AObject::~AObject(){
}

void AObject::Reset(){
	pos_.x = first_pos_.x;
	pos_.y = first_pos_.y;
	alive = true;
	aerial = false;
	speed_.x=0;
	speed_.y=0;
	live_count_=0;
	right = first_right;
}

void AObject::Move(){
	pos_.x+=speed_.x;
	pos_.y+=speed_.y;
}
void AObject::Draw(int offset){
	if(alive){
		live_count_++; //１周期のカウンタを進める

		//右向き左向き変更処理
		if(speed_.x>0) right=true;
		else if(speed_.x<0) right=false; 
		if(speed_.y<0) aerial=true;
		
		//描画（アニメーション画像がある場合はアニメーション）
		if(right){
			if(speed_.x>0 && move_ghandle_!=0 &&live_count_%2==0)   DrawGraph( (int)pos_.x+offset , (int)pos_.y , move_ghandle_ ,TRUE );
			else DrawGraph( (int)pos_.x+offset , (int)pos_.y , graphic_handle_ ,TRUE ) ;
		}
		else{
			if(speed_.x<0 && move_ghandle_!=0  &&live_count_%2==0)   DrawTurnGraph( (int)pos_.x+offset , (int)pos_.y , move_ghandle_ ,TRUE );
			else DrawTurnGraph( (int)pos_.x+offset , (int)pos_.y , graphic_handle_ ,TRUE ) ;
		}
	}
}

void AObject::TouchedBlockX(double block_x){
	//x軸での当たり判定の場合
		//右との当たり判定の場合
		if(speed_.x>0){
			pos_.x=block_x-size_.x;
		}
		//左との当たり判定
		else if(speed_.x<0){
			pos_.x=block_x+32;
		}
		speed_.x=0;

}
void AObject::TouchedBlockY(double block_y){
	//y軸との当たり判定

	//上で接触
	if(speed_.y<0){
		pos_.y=block_y+32;
	}
	//下で接触
	else if(speed_.y>0){
		pos_.y=block_y-size_.y;
		aerial=false;
	}
	speed_.y=0;
}

void AObject::Fall(double gravity){
	speed_.y+=gravity;
}
void AObject::Think(){
	speed_.x=2;
}

void AObject::Die(){
	alive=false;
}

void AObject::Set_Speed(double speed_x,double speed_y){
	speed_.x=speed_x;
	speed_.y=speed_y;
}

void AObject::GetObjectSize(){
	int sizeX=0,sizeY=0;
	int* p_sizeX = &sizeX;
	int* p_sizeY = &sizeY;
	GetGraphSize(graphic_handle_,p_sizeX,p_sizeY);
	size_.x = *p_sizeX;
	size_.y = *p_sizeY;
}

double AObject::GetCenterPosX(){
	return pos_.x+size_.x/2;
}

double AObject::GetCenterPosY(){
	return pos_.y+size_.y/2;
}

void AObject::Set_move_power(double x){
	move_power=x;
}