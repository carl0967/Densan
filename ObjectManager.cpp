#include "ObjectManager.h"

ObjectManager::ObjectManager(int map_width,int map_height){
	width=map_width;
	height=map_height;
	//2ŸŒ³”z—ñ‚Ì“®“I¶¬
	ids=new int*[map_height];
	for(int i=0;i<map_height;i++){
		ids[i]=new int[map_width];
	}
	//‰Šú‰»
	id_counter=1;
	for(int i=0;i<map_height;i++){
		for(int j=0;j<map_width;j++){
			ids[i][j]=-1;
		}
	}
}

int ObjectManager::FindObject(int cell_x,int cell_y,MapChip map_chip){
	if(ids[cell_y][cell_x]==-1){
		if(map_chip==PLAYER) ids[cell_y][cell_x]=0;
		else{
		ids[cell_y][cell_x]=id_counter;
		id_counter++;
		}
	}
	
	return ids[cell_y][cell_x];
	
}

int ObjectManager::GetId(int cell_x,int cell_y){
	if(cell_x <0 || cell_y<0 )return -1;
	else return ids[cell_y][cell_x];
}

TwoDimension ObjectManager::GetCellPosFromId(int id){
	TwoDimension td;
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			if(ids[i][j]==id){
				td.x=j;
				td.y=i;
				return td;
			}
		}
	}
	//Œ©‚Â‚©‚ç‚È‚©‚Á‚½ê‡
	td.x=0;
	td.y=0;
	return td;

}

ObjectManager::~ObjectManager(){
	for(int i=0;i<height;i++){
		delete ids[i];
	}
	delete ids;
}