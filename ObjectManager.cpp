#include "ObjectManager.h"

ObjectManager::ObjectManager(int map_width,int map_height){
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

int ObjectManager::FindObject(int cell_x,int cell_y){
	if(ids[cell_y][cell_x]==-1){
		ids[cell_y][cell_x]=id_counter;
		id_counter++;
	}
	return ids[cell_y][cell_x];
}

int ObjectManager::GetId(int cell_x,int cell_y){
	if(cell_x <0 || cell_y<0 )return -1;
	else return ids[cell_y][cell_x];
}