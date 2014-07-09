
#include "AObject.h"

int AObject::graphic_handle;

AObject::AObject(double x,double y){
	init();
	if(!(graphic_handle>0))  graphic_handle=LoadGraph(file_name);
	pos_.x=x;
	pos_.y=y;
	aerial=false;
	alive=true;
	speed_.x=0;
	speed_.y=0;
	made_time_=10;
}
void AObject::init(){ 
	file_name="–‚—2.png";
	size_.x=32;
	size_.y=32;
	right=false;
}


void AObject::Move(){
	pos_.x+=speed_.x;
	pos_.y+=speed_.y;
}
void AObject::Draw(int offset){
	DrawGraph( (int)pos_.x-offset , (int)pos_.y , graphic_handle ,TRUE ) ;
	/*
	 int Color = GetColor( 255 , 255 , 255 ) ;
    DrawFormatString( 0, 0, Color, "•Ï”  %d ‚Å‚·\n", graphic_handle ) ;
	*/
}

void AObject::TouchedBlockX(double block_x){
	//x²‚Å‚Ì“–‚½‚è”»’è‚Ìê‡
		//‰E‚Æ‚Ì“–‚½‚è”»’è‚Ìê‡
		if(speed_.x>0){
			pos_.x=block_x-size_.x;
		}
		else{
			pos_.x=block_x+32;
		}
		speed_.x=0;

}
void AObject::TouchedBlockY(double block_y){
	//ãŒü‚«
	if(speed_.y<0){
		pos_.y=block_y+32;
	}
	else{
		pos_.y=block_y-size_.y;
	}

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
