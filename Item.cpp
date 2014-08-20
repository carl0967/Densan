#include "Item.h"

Item::Item(double ax,double ay,char* fname,int size_x,int size_y,bool right):AObject(ax,ay,fname,size_x,size_y,right){
	object_type_ = O_ITEM;
	alive=true;
}
