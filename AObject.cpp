#include <string.h>
#include "AObject.h"

//int AObject::graphic_handle;
LoadGraphic AObject::loadg=LoadGraphic();

AObject::AObject(double x,double y,char* f_name,int sizex,int sizey,bool r){
	//if(!(graphic_handle>0)){
		//graphic_handle=LoadGraph(f_name);
		graphic_handle=loadg.Load(f_name);
	//}
	pos_.x=x;
	pos_.y=y;
	aerial=false;
	alive=true;
	speed_.x=0;
	speed_.y=0;
	made_time_=10;
	size_.x=sizex;
	size_.y=sizey;
	right=r;
}



void AObject::Move(){
	pos_.x+=speed_.x;
	pos_.y+=speed_.y;
}
void AObject::Draw(int offset){
	if(speed_.x>0) right=true;
	else if(speed_.x<0) right=false; 

	if(right) DrawGraph( (int)pos_.x-offset , (int)pos_.y , graphic_handle ,TRUE ) ;
	else DrawTurnGraph( (int)pos_.x-offset , (int)pos_.y , graphic_handle ,TRUE ) ;
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
		//¶‚Æ‚Ì“–‚½‚è”»’è
		else{
			pos_.x=block_x+32;
		}
		speed_.x=0;

}
void AObject::TouchedBlockY(double block_y){
	//y²‚Æ‚Ì“–‚½‚è”»’è
	//ã‚ÅÚG

	if(speed_.y<0){
		//pos_.y=block_y+32;
	}
	//‰º‚ÅÚG
	else{
		pos_.y=block_y-size_.y;
		aerial=false;
		speed_.y=0;
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
