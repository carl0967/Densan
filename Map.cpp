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
	background_ = -1;
}

int Map::SetBackground(std::string filename){
	background_ = LoadGraph(filename.c_str());
	return background_==-1 ? -1 : 0;
}

int Map::GetMapData(double x, double y){
	int index_x=(int)(x)/cell_width;
	int index_y=(int)(y)/cell_hegiht;

	if(index_x>=0 && index_x<map_width_ && index_y>=0 && index_y<map_height_)
		return map_datas[index_y][index_x];
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
	Draw(-this->offset_);
}

void Map::Draw(int offset){
	if( -offset<0)
		offset=0; 
	else if(-offset+MAP_WIDTH>map_width_*cell_width)
		offset= -(map_width_*cell_width - MAP_WIDTH);

	//---------------”wŒi‚Ì•`‰æ---------------
	if(background_ !=-1){
		int width = 0,height = 0;
		GetGraphSize(background_,&width,&height);

		for(int i=0;width*i+offset%width<MAP_WIDTH;i++){
			DrawGraph(width*i+offset%width,0,background_,FALSE);
		}
	}
	
	

	//---------------ƒZƒ‹‚Ì•`‰æ---------------
	for(int i=0;i<map_height_;i++){
		for(int j=0;j<MAP_WIDTH/cell_width+1;j++){
			switch(GetMapData((j+(int)(-offset/cell_width))*cell_width,i*cell_hegiht)){
			case EMPTY:
				break;
			case WALL:
					DrawGraph(j*cell_width-(-offset%cell_width),i*cell_hegiht,wallGraph_,FALSE);
				break;
			}
		}
	}
}

void Map::SetMapHeightAndWidth(int height, int width){
	map_height_ = height;
	map_width_ = width;
}

int Map::GetMapDataFromCell(int x,int y){
	return (x>=0 && x<map_width_ && y>=0 && y<map_height_) ? map_datas[y][x] : -1;
}