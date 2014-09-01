#include "Item.h"

Item::Item(double ax,double ay,char* fname,bool right):AObject(ax,ay,0,fname,right){
	object_type_ = O_ITEM;
	alive=true;
	item_sound_ = 0;
}

Item::Item(double ax,double ay,char* fname, char* sound_name,bool right):AObject(ax,ay,0,fname,right){
	object_type_ = O_ITEM;
	alive=true;
	item_sound_ = LoadSoundMem(sound_name);
}

void Item::PlaySound(){
	if(item_sound_ != 0)
	PlaySoundMem(item_sound_,DX_PLAYTYPE_BACK);
}