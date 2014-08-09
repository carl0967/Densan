#include "Map.h"
#include <iostream>

Map::Map(int cell_width,int cell_hegiht,int** map_datas){
	this->cell_width = cell_width;
	this->cell_hegiht = cell_hegiht;
	this->map_datas = map_datas;
	offset =0;
}

int Map::GetMapData(double x, double y){
	int index_x=(int)(x+offset)/cell_width;
	int index_y=(int)(y)/cell_hegiht;

	return map_datas[index_y][index_x];
}

Map::~Map(){
	for (int i=0;i<map_height_-1;i++) {
		free(map_datas[i]);
	}
	free(map_datas);
}
void Map::Scroll(int move){
	offset += move;
}

void Map::SetMapHeightAndWidth(int height, int width){
	map_height_ = height;
	map_width_ = width;
}