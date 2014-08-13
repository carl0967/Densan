#include "Map.h"
#include <iostream>
#include "DxLib.h"

#define MAP_WIDTH 640	// •\Ž¦ƒ}ƒbƒv‚Ì‰¡•

Map::Map(int cell_width,int cell_hegiht,int** map_datas){
	this->cell_width = cell_width;
	this->cell_hegiht = cell_hegiht;
	this->map_datas = map_datas;
	offset_ =0;

	wallGraph_ = LoadGraph("‰æ‘œ/ƒŒƒ“ƒK‚P.png",FALSE);
}

int Map::GetMapData(double x, double y){
	int index_x=(int)(x)/cell_width;
	int index_y=(int)(y)/cell_hegiht;

	return map_datas[index_y][index_x];
}
int Map::GetMapDataFromCell(int x,int y){
	if(x>=0 && x<map_width_ && y>=0 && y<map_height_) return map_datas[y][x];
	else return -1;
	
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
	if( offset<0)
		offset=0; 
	else if(offset+MAP_WIDTH>map_width_*cell_width)
		offset=map_width_*cell_width - MAP_WIDTH;

	DrawGraph(0,0,background_,FALSE);
	for(int i=0;i<map_height_;i++){
		for(int j=0;j<map_width_;j++){
			switch(GetMapData(j*cell_width,i*cell_hegiht)){
			case EMPTY:
				break;
			case WALL:
					DrawGraph(j*cell_width+offset,i*cell_hegiht,wallGraph_,FALSE);
				break;
			}
		}
	}
}

void Map::SetMapHeightAndWidth(int height, int width){
	map_height_ = height;
	map_width_ = width;
}