#include <string.h>
#include "AObject.h"

//int AObject::graphic_handle;
LoadGraphic AObject::loadg=LoadGraphic();

AObject::AObject(double x,double y,char* f_name,int sizex,int sizey,bool r){
	//����������
	graphic_handle_=loadg.Load(f_name);
	move_ghandle_=0;
	pos_.x=x;
	pos_.y=y;
	aerial=false;
	alive=true;
	speed_.x=0;
	speed_.y=0;
	made_time_=0; //������
	live_count_=0;
	size_.x=sizex;
	size_.y=sizey;
	right=r;
}



void AObject::Move(){
	pos_.x+=speed_.x;
	pos_.y+=speed_.y;
}
void AObject::Draw(int offset){
	live_count_++; //�P�����̃J�E���^��i�߂�

	//�E�����������ύX����
	if(speed_.x>0) right=true;
	else if(speed_.x<0) right=false; 

	//�`��i�A�j���[�V�����摜������ꍇ�̓A�j���[�V�����j
	if(right){
		if(speed_.x>0 && move_ghandle_!=0 &&live_count_%2==0)   DrawGraph( (int)pos_.x+offset , (int)pos_.y , move_ghandle_ ,TRUE );
		else DrawGraph( (int)pos_.x+offset , (int)pos_.y , graphic_handle_ ,TRUE ) ;
	}
	else{
		if(speed_.x<0 && move_ghandle_!=0  &&live_count_%2==0)   DrawTurnGraph( (int)pos_.x+offset , (int)pos_.y , move_ghandle_ ,TRUE );
		else DrawTurnGraph( (int)pos_.x+offset , (int)pos_.y , graphic_handle_ ,TRUE ) ;
	}

}

void AObject::TouchedBlockX(double block_x){
	//x���ł̓����蔻��̏ꍇ
		//�E�Ƃ̓����蔻��̏ꍇ
		if(speed_.x>0){
			pos_.x=block_x-size_.x;
		}
		//���Ƃ̓����蔻��
		else{
			pos_.x=block_x+32;
		}
		speed_.x=0;

}
void AObject::TouchedBlockY(double block_y){
	//y���Ƃ̓����蔻��
	//��ŐڐG

	if(speed_.y<0){
		pos_.y=block_y+32;
	}
	//���ŐڐG
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

void AObject::Set_Speed(double speed_x,double speed_y){
	speed_.x=speed_x;
	speed_.y=speed_y;
}





















































