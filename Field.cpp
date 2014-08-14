#include "Field.h"
#include "DxLib.h"
#include "Kame.h"


Field::Field(Map* map){
	map_ = map;
	gravity_ = 1.1;
			//プレイヤー生成
	Player*  player = new Player(100,200,this);
	AddObject(player);

	//テスト用に敵生成
	Kame* kame=new Kame(500,300,this);
	AddObject(kame);

}

//メインループ
bool Field::MainLoop(){
	FallObjects();
	
	ThinkObjects();
	Scroll();
	
	//CheckOutOfArea();
	TouchPlayer2Objects();
	TouchObjects2Wall();

	MoveObjects();



	DeleteObjects();
	DrawObjects();
	
	
	return true;
}

void Field::Scroll(){
	int width = 640;  //画面の横幅
	offset_ = width/2-(int)objects_.at(0)->pos().x;
	offset_ = min(offset_,0);
	offset_ = max(offset_,width-map_->map_width()*32);
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
		objects_.at(i)->Draw(offset_);
	//テスト用マップ描画
	map_->Draw(offset_);

}

//完成
void Field::ThinkObjects(){
	for(int i=0; i<objects_.size(); i++){
		objects_.at(i)->Think();
	}
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
		double newX = 0;
		double newY = 0;
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

			int fromTileX = PixelToTiles(fromX);
			int fromTileY = PixelToTiles(fromY);
			int toTileX = PixelToTiles(toX+objects_.at(0)->size().x-1);
			int toTileY = PixelToTiles(toY+objects_.at(0)->size().y-1);
			
			//衝突しているか調べる
			for(int x = fromTileX; x<= toTileX; x++){
				for(int y = fromTileY; y <= toTileY; y++){
					if(map_->GetMapDataFromCell(x,y) == WALL){
						if(k==0){  //x方向であたっていた場合
							objects_.at(i)->TouchedBlockX(TilesToPixels(x));	
							DrawString(100,100,"あたっている",GetColor(255,255,255));
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
		if(!objects_.at(i)->isAlive()){
			//オブジェクト削除
			delete objects_.at(i);
			//オブジェクトの参照削除
			vector<AObject*>::iterator start;
			start = objects_.begin()+i;
			objects_.erase(start);
		}
	}
}

//完成（仮）
void Field::CheckOutOfArea(){
	for(int i=0; i<objects_.size(); i++){
		if(objects_.at(i)->pos().x < -offset_ || 
			objects_.at(i)->pos().x > -offset_+480 ){
			//オブジェクト削除
			delete objects_.at(i);
			//オブジェクトの参照削除
			vector<AObject*>::iterator start;
			start = objects_.begin()+i;
			objects_.erase(start);
		}
	}
}

//未完成(マップからの情報)
void Field::AddObject(AObject *object){

	vector<AObject*>::iterator end = objects_.end();
	objects_.insert(end,object);

}

int Field::PixelToTiles(double pixels){
	return floor(pixels/32);
}

int Field::TilesToPixels(int tiles){
	return tiles*32;
}

bool Field::JudgeCircle(int x1, int y1, int r1, int x2, int y2, int r2){
		int x = (x1-x2)*(x1-x2);
		int y = (y1-y2)*(y1-y2);
		int l = x+y;
		int r = (r1+r2)*(r1+r2);
		if(l<r)
			return true;
		return false;
}

int Field::GetMapData(double x, double y){
	return map_->GetMapData(x,y);
}

//プレイヤーの座標を返す関数
TwoDimension Field::GetPlayerPos(){
	return objects_.at(0)->pos();
}

