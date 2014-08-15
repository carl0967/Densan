#include "Field.h"
#include "DxLib.h"
#include "Kame.h"
#include "AObject.h"


Field::Field(Map* map){
	map_ = map;
	obj_manager_=new ObjectManager(map->map_width(),map->map_height());
	gravity_ = 1.1;

	/*
	//プレイヤー生成
	Player*  player = new Player(100,200,this);
	AddObject(player,true);
	player_ = player;

	//テスト用に敵生成
	Kame* kame=new Kame(500,300,this);
	AddObject(kame,false);
	*/
	Initialize();
}

//メインループ
bool Field::MainLoop(){
	FallObjects();
	
	ThinkObjects();
	Scroll();
	
	//CheckOutOfArea();
	TouchObjects2Wall();
	MoveObjects();
	TouchPlayer2Objects();
	Reset();

	//最初生存フラグをfalseにするので、これがあると消えてしまう
	//DeleteObjects();
	DrawObjects();
	
	
	return true;
}

void Field::Scroll(){
	int width = 640;  //画面の横幅
	int old_offset=offset_;
	offset_ = width/2-(int)objects_.at(0)->pos().x;
	offset_ = min(offset_,0);
	offset_ = max(offset_,width-map_->map_width()*32);

	//新しく現れたマップを読み込む
	if(PixelToTiles(old_offset)!=PixelToTiles(offset_)){
		//右端を読み込む場合
		if(player_->isRight()){
			for(int i=0;i<15;i++){
			int x=PixelToTiles(-offset_+width); //offset+widthで読み込むx座標になる
			int id=obj_manager_->GetId(x,i);
			if(id!=-1){
				if(objects_.at(id)->isAlive()==false) objects_.at(id)->Reset();
			}
			}
		}
	}
}

void Field::Initialize(){
	//オブジェクト生成
	for(int i=0; i<map_->map_width(); i++){
		for(int k=0; k<map_->map_height(); k++){
			int map_chip=map_->GetMapDataFromCell(i,k);
			switch(map_chip){
			case EMPTY:
				break;

			case PLAYER:
				player_  = new Player(i*32,k*32,this);
				player_->Revival(); //Objectは最初は死んでるので起こす
				AddObject(player_,true);
				obj_manager_->FindObject(i,k,PLAYER); //オブジェクトマネージャーに登録
				break;
			case KAME:
				AddEnemy(new Kame(i*32,k*32,this));
				AddObject(enemys_.at(enemys_.size()-1),false);
				obj_manager_->FindObject(i,k,KAME); //オブジェクトマネージャーに登録
				break;
			}
		}
	}
	
	//最初の描画領域の敵のみ動かす(Reset関数を呼び出して生存フラグをtrueにしてる)
	for(int i=0;i<15;i++){
		for(int j=0;j<20;j++){
			int id=obj_manager_->GetId(j,i);
			if(id!=-1) objects_.at(id)->Reset();
		}
	}
	

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

//完成
void Field::DrawObjects(){
	//プレイヤー描画
	if(player_->isAlive()){
		if(player_->superCount()%2==0)
			player_->Draw(offset_);
	}
	//敵描画
	for(int i=1; i<objects_.size(); i++){
		if(objects_.at(i)->isAlive())
			objects_.at(i)->Draw(offset_);
	}
	//テスト用マップ描画
	map_->Draw(offset_);
	//HPバー描画
	int percentHp = (player_->hp()*100)/player_->maxHp();
	DrawString(30,10,"HP",GetColor(255,255,255),true);
	DrawBox(20,30,120,50,GetColor(0,0,0),true);
	DrawBox(20,30,20+percentHp,50,GetColor(255,0,0),true);
	DrawBox(20,30,120,50,GetColor(255,255,255),false);
	//残機描画
	DrawFormatString(600,0,GetColor(255,255,255),"%s %d","X",player_->life());

}

//完成
void Field::ThinkObjects(){
	for(int i=0; i<objects_.size(); i++){
		objects_.at(i)->Think();
	}
}

//未完成(プレイヤーの無敵時間管理も行う)
void Field::TouchPlayer2Objects(){
		int px = (int)objects_.at(0)->pos().x;
		int py = (int)objects_.at(0)->pos().y;
	//objects_の要素０はプレイヤーなのでi=1からはじめる
	for(int i=1; i<objects_.size(); i++){
		//プレイヤーと敵との接触判定
		if(objects_.at(i)->isAlive()){
			if(JudgeHitCharacters(player_,objects_.at(i)) && !player_->super()){
				player_->Damaged(1);
			}
		}
		//プレイヤーの弾と敵とのあたり判定

		//敵の弾とプレイヤーとのあたり判定

	}
	player_->superTime();
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

void Field::Reset(){
	if(!player_->isAlive()){
		player_->Reset();
		for(int i=0; i<enemys_.size(); i++){
			enemys_.at(i)->Reset();
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
void Field::AddObject(AObject *object, bool isBegin){
		vector<AObject*>::iterator place;
	if(isBegin)
		place= objects_.begin();
	else
		place = objects_.end();
	objects_.insert(place,object);

}

void Field::AddEnemy(Enemy* enemy){
	vector<Enemy*>::iterator end;
	end = enemys_.end();
	enemys_.insert(end,enemy);
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

//キャラクター同士の当たり判定
bool Field::JudgeHitCharacters(AObject* p, AObject* e){
	//x軸方向だけで接触しているか判定
	if(p->pos().x+p->size().x >= e->pos().x && p->pos().x <= e->pos().x+e->size().x){
		//y軸方向だけで接触しているか判定
		if(p->pos().y+p->size().y >= e->pos().y && p->pos().y <= e->pos().y+e->size().y){
			//両方が成り立つ時、接触しているのでtrueを返す
			return true;
		}
	}
	return false;

}

int Field::GetMapData(double x, double y){
	return map_->GetMapData(x,y);
}

//プレイヤーの座標を返す関数
TwoDimension Field::GetPlayerPos(){
	return objects_.at(0)->pos();
}

