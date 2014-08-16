#include "Field.h"
#include "DxLib.h"
#include "Kame.h"
#include "AObject.h"
#include "Coin.h"


Field::Field(Map* map){
	map_ = map;
	obj_manager_=new ObjectManager(map->map_width(),map->map_height());
	gravity_ = 1.1;
	clear_flag = false;
	end_flag = false;
	menu_flag = false;
	clear_count = 0;
	end_count = 0;
	end_graphic_handle = LoadGraph("画像/game_over.png");
	//clear_graphic_handle = LoadGraph("画像/game_clear.png");

	Initialize();
}

//メインループ
int Field::MainLoop(){
	FallObjects();
	
	ThinkObjects();
	Scroll();
	
	TouchObjects2Wall();
	MoveObjects();
	CheckOutOfArea();
	DownObjectsDie();
	TouchPlayer2Objects();
	Reset();
	GameOver();

	//最初生存フラグをfalseにするので、これがあると消えてしまう
	//DeleteObjects();
	DrawObjects();

	if(menu_flag)
		return -1;
	return 0;
}

//ゲームクリア処理
void Field::GameClear(){
	if(clear_flag){
		clear_flag++;
		DrawGraph(100,100,clear_graphic_handle,true);
		if(clear_count >= 100){
			menu_flag=true;
		}
	}
}

//ゲームオーバー処理
void Field::GameOver(){
	if(end_flag){
		end_count++;
		DrawGraph(100,100,end_graphic_handle,true);
		if(end_count >= 100){
			menu_flag=true;
		}
	}
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
				AddObject(new Kame(i*32,k*32,this),false);
				obj_manager_->FindObject(i,k,KAME); //オブジェクトマネージャーに登録
				break;
			case COIN:
				Coin* coin=new Coin(i*32,k*32);
				coin->Revival();
				AddObject(coin,false);
				obj_manager_->FindObject(i,k,COIN);
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
	if(!end_flag){
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
}

////完成
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
	if(player_->life()<0)
		end_flag = true;
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
			int toTileX = PixelToTiles(toX+objects_.at(i)->size().x-1);
			int toTileY = PixelToTiles(toY+objects_.at(i)->size().y-1);
			
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
		for(int i=0; i<objects_.size(); i++){
			objects_.at(i)->Reset();
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
	for(int i=1; i<objects_.size(); i++){
		if(objects_.at(i)->isAlive()){
			if(objects_.at(i)->pos().x < -offset_-320 || 
			objects_.at(i)->pos().x > -offset_+640+320 ){
				objects_.at(i)->Die();
			}
		}
	}
}

void Field::DownObjectsDie(){
	for(int i=0; i<objects_.size(); i++){
		if(objects_.at(i)->pos().y>=480)
			objects_.at(i)->Die();
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
	double pxSize = p->size().x*p->hit_size().x;
	double pySize = p->size().y*p->hit_size().y;
	double pxCenter = p->pos().x+p->size().x/2;
	double pyCenter = p->pos().y+p->size().y/2;
	double px = pxCenter-pxSize/2;
	double py = pyCenter-pySize/2;
	
	double exSize = e->size().x*e->hit_size().x;
	double eySize = e->size().y*e->hit_size().y;
	double exCenter = e->pos().x+e->size().x/2;
	double eyCenter = e->pos().y+e->size().y/2;
	double ex = exCenter-exSize/2;
	double ey = eyCenter-eySize/2;

	//x軸方向だけで接触しているか判定
	if(px+pxSize >= ex && px <= ex+exSize){
		//y軸方向だけで接触しているか判定
		if(py+pySize >= ey && py <= ey+eySize){
			//両方が成り立つ時、接触しているのでtrueを返す
			return true;
		}
	}
	return false;
}

int Field::GetMapData(double x, double y){
	return map_->GetMapData(x,y);
}
int Field::GetNextMapData(TwoDimension pos,TwoDimension speed,bool right){
	if(right){
		return map_->GetMapData(pos.x+speed.x+32,pos.y);
	}
	else return map_->GetMapData(pos.x+speed.x,pos.y);
}

//プレイヤーの座標を返す関数
TwoDimension Field::GetPlayerPos(){
	return objects_.at(0)->pos();
}