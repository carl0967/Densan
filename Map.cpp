#include "Map.h"
#include <iostream>

Map::Map(int cell_width,int cell_hegiht,int** map_datas){
	this->cell_width = cell_width;
	this->cell_hegiht = cell_hegiht;
	this->map_datas = map_datas;
	offset =0;
}

int Map::GetMapData(double x, double y){
	return map_datas[(int)(x+offset)/cell_hegiht][(int)(y+offset)/cell_width];
}

Map::~Map(){
	for (int i=0;i<map_hegiht-1;i++) {
		free(map_datas[i]);
	}
	free(map_datas);
}
void Map::Scroll(int move){
	offset += move;
}

void Map::SetMapHeightAndWidth(int height, int width){
	map_hegiht = height;
	map_width = width;
}