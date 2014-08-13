#include "Map.h"
#include <iostream>
#include "DxLib.h"

#define MAP_WIDTH 640	// 表示マップの横幅

Map::Map(int cell_width,int cell_hegiht,int** map_datas){
	this->cell_width = cell_width;
	this->cell_hegiht = cell_hegiht;
	this->map_datas = map_datas;
	offset_ =0;

	wallGraph_ = LoadGraph("画像/レンガ１.png",FALSE);
}

int Map::GetMapData(double x, double y){
	int index_x=(int)(x)/cell_width;
	int index_y=(int)(y)/cell_hegiht;

	return map_datas[index_y][index_x];
}

Map::~Map(){
	for (int i=0;i<map_height_-1;i++) {
		delete[] map_datas[i];
	}
	delete[] map_datas;
}
void Map::Scroll(int move){
	if( (offset_>0||move>0 ) 
		&& (offset_+MAP_WIDTH<map_width_*cell_width || move < 0))
		offset_ += move;
}

void Map::Draw(){
	Draw(this->offset_);
}

void Map::Draw(int offset){
	DrawGraph(0,0,background_,FALSE);
	for(int i=0;i<map_height_;i++){
		for(int j=0;j<MAP_WIDTH/cell_width+1;j++){
			switch(GetMapData((j+(int)(offset/cell_width))*cell_width,i*cell_hegiht)){
			case EMPTY:
				break;
			case WALL:
					DrawGraph(j*cell_width-(offset%cell_width),i*cell_hegiht,wallGraph_,FALSE);
				break;
			}
		}
	}
}

void Map::SetMapHeightAndWidth(int height, int width){
	map_height_ = height;
	map_width_ = width;
}