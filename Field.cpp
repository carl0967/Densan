/*
#include "Field.h"


Field::Field(Map map){
	map_ = map;
	gravity_ = 1;
}
//メインループ
bool Field::MainLoop(){
	FallObjects();
	MoveObjects();
	ThinkObjects();
	CheckOutOfArea();
	TouchPlayer2Objects();
	TouchObjects2Wall();
	DeleteObjects();
	CalcOffset();
	DrawObjects();

}

void Field::Scroll(){
}

//完成
void Field::FallObjects(){
	for(int i=0; i<objects_.size(); i++)
		objects_.at(i)->Fall(gravity_);
}

//完成
void Field::MoveObjects(){
	for(int i=0; i<objects_.size(); i++)
		objects_.at(i)->Move();
}

//未完成(マップ全体の長さがわからない)
void Field::DrawObjects(){
	//描画
	for(int i=0; i<objects_.size(); i++)
		objects_.at(i)->Draw(offset);
}

//完成
void Field::ThinkObjects(){
	for(int i=0; i<objects_.size(); i++)
		objects_.at(i)->Think();
}

//未完成（当たり判定は円で行う,キャラの大きさは32で統一して行っている）
void Field::TouchPlayer2Objects(){
		int px = (int)objects_.at(0)->pos().x;
		int py = (int)objects_.at(0)->pos().y;
	//objects_の要素０はプレイヤーなのでi=1からはじめる
	for(int i=1; i<objects_.size(); i++){
		//プレイヤーと敵との接触判定
		if(JudgeCircle(px, py, 16, (int)objects_.at(i)->pos().x, (int)objects_.at(i)->pos().y, 16)){

		}
		//プレイヤーの弾と敵とのあたり判定

		//敵の弾とプレイヤーとのあたり判定

	}
}

//完成（仮）
void Field::TouchObjects2Wall(){
	for(int i=0; i<objects_.size(); i++){
		double objectX = objects_.at(i)->pos().x;
		double objectY = objects_.at(i)->pos().y;
		double newX;
		double newY;
		//x方向とy方向に分けて判定を行うので
		//k=0の時x方向,k=1の時y方向
		for(int k=0; k<2; k++){
			if(k==0){
				newX = objectX+objects_.at(i)->speed().x;
				newY = objectY;
			}
			else{
				newX = objectX;
				newY = objectY+objects_.at(i)->speed().y;
			}
			newX = floor(newX);
			newY = floor(newY);
	
			double fromX = min(objectX,newX);
			double fromY = min(objectY,newY);
			double toX = max(objectX,newX);
			double toY = max(objectY,newY);

			int fromTileX = pixelsToTiles(fromX);
			int fromTileY = pixelsToTiles(fromY);
			int toTileX = pixelsToTiles(toX+31);
			int toTileY = pixelsToTiles(toY+31);

			//衝突しているか調べる
			for(int x = fromTileX; x<= toTileX; x++){
				for(int y = fromTileY; y <= toTileY; y++){
					if(map_.GetMapData(x,y) == 1){
						if(k==0){  //x方向であたっていた場合
							objects_.at(i)->TouchedBlockX(TilesToPixels(x));	
						} 
						if(k==1){ //y方向であたっていた場合
							objects_.at(i)->TouchedBlockY(TilesToPixels(y));
						} 
					}
				}
			}
		}
	}
}

//完成（仮）
void Field::DeleteObjects(){
	for(int i=0; i<objects_.size(); i++){
		if(!objects_.at(i)->alive()){
			//オブジェクト削除
			delete objects_.at(i);
			//オブジェクトの参照削除
			vector<Chara*>::iterator start;
			start = v.begin()+i;
			v.erase(start);
		}
	}
}

//完成（仮）
void Field::CheckOutOfArea(){
	for(int i=0; i<objects_.size(); i++){
		if(objects_.at(i)->pos().x < offset || 
			objects_.at(i)->pos().x > offset+480 ){
			//オブジェクト削除
			delete objects_.at(i);
			//オブジェクトの参照削除
			vector<Chara*>::iterator start;
			start = v.begin()+i;
			v.erase(start);
		}
	}
}

//未完成(マップからの情報)
void Field::AddObject(AObject *object_num){
	objects_.push_back(object_num);
	vector<int>::iterator start;
	start = test.begin()+2;
	test.erase(start);
}

void Field::CalcOffset(){
	int width = 480;  //画面の横幅
	offset = width/2-(int)objects_.at(0)->pos().x;
	offset = min(offsetX,0);
	offset = max(offsetX,width-100);
}

int pixelsToTiles(double pixels){
	return floor(pixels/32);
}

int tilesToPixels(int tiles){
	return tiles*32;
}

bool JudgeCircle(int x1, int y1, int r1, int x2, int y2, int r2){
		int x = (x1-x2)*(x1-x2);
		int y = (y1-y2)*(y1-y2);
		int l = x+y;
		int r = (r1+r2)*(r1+r2);
		if(l<r)
			return true;
		return false;
}


*/