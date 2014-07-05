
#include "AObject.h"

int AObject::graphic_handle;

AObject::AObject(double x,double y,Field field){
	init();
	if(!(graphic_handle>0))  graphic_handle=LoadGraph(file_name);
	pos.x=x;
	pos.y=y;
	aerial=false;
	alive=true;
	speed.x=0;
	speed.y=0;
	made_time=0;
}
void AObject::init(){ 
	file_name="rock2.png";
	size.x=32;
	size.y=32;
	right=false;
}


void AObject::Move(){
	pos.x+=speed.x;
	pos.y+=speed.y;
}
void AObject::Draw(int offset){
	DrawGraph( (int)pos.x-offset , (int)pos.y , graphic_handle ,TRUE ) ;
	/*
	 int Color = GetColor( 255 , 255 , 255 ) ;
    DrawFormatString( 0, 0, Color, "ïœêî  %d Ç≈Ç∑\n", graphic_handle ) ;
	*/
}

void AObject::TouchedWall(double wall_x){
	speed.x=0;
	pos.x=wall_x;
}
void AObject::TouchedFloor(double floor_y){
	speed.y=0;
	pos.y=floor_y;
}
void AObject::Fall(double gravity){
	speed.y+=gravity;
}
void AObject::Think(){
	speed.x=5;
}


void AObject::Die(){
	alive=false;
}
