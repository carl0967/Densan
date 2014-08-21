
#include "Field.h"
#include "DxLib.h"
#include "Kame.h"
#include "AObject.h"
#include "Coin.h"
#include "GoalFlag.h"
#include "JumpKame.h"
#include "Taihou.h"

Field::Field(Map* map){
	map_ = map;
	obj_manager_=new ObjectManager(map->map_width(),map->map_height());
	gravity_ = 1.1;
	menu_flag = false;
	wait_count_=0;
	end_graphic_handle = LoadGraph("画像/game_over.png");
	clear_graphic_handle = LoadGraph("画像/game_clear.png");

	Initialize();
}

//メインループ
int Field::MainLoop(){
	FallObjects();
	
	ThinkObjects();
	Scroll();
	
	TouchObjectsToWall();
	MoveObjects();
	CheckOutOfArea();
	DownObjectsDie();
	TouchPlayerToObjects();
	BulletTouchWall();

	Reset();
	if(player_->game_status()==OVER) GameOver();
	if(player_->game_status()==CLEAR) GameClear();

	//最初生存フラグをfalseにするので、これがあると消えてしまう
	//DeleteObjects();
	DrawObjects();

	if(menu_flag) return -1;
	return 0;
}

//ゲームクリア処理
void Field::GameClear(){
	wait_count_++;
	DrawGraph(100,100,clear_graphic_handle,true);
	if(wait_count_>= 100){
		menu_flag=true;
	}
}

//ゲームオーバー処理
void Field::GameOver(){
	wait_count_++;
	DrawGraph(100,100,end_graphic_handle,true);
	if(wait_count_ >= 100){
		menu_flag=true;
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
			int x=PixelToTiles(-offset_+width); //offset+widthで読み込むx座標になる。offsetは-のため反転
			FindObject(0,map_->map_height(),x,x+1);
		}
	}
}

void Field::Initialize(){
	//オブジェクト生成
	//新しくオブジェクトを生成するときは、ここのcaseを追加する
	for(int i=0; i<map_->map_width(); i++){
		for(int k=0; k<map_->map_height(); k++){
			int map_chip=map_->GetMapDataFromCell(i,k);
			switch(map_chip){
			case PLAYER:
				player_  = new Player(i*32,k*32,this);
				AddObject(player_,true);
				obj_manager_->RegisterObject(i,k,PLAYER); //オブジェクトマネージャーに登録
				break;
			case KAME:
				AddObject(new Kame(i*32,k*32,this),false);
				obj_manager_->RegisterObject(i,k,KAME); //オブジェクトマネージャーに登録
				break;
				
			case COIN:
				{
				Coin* coin=new Coin(i*32,k*32);
				AddObject(coin,false);
				obj_manager_->RegisterObject(i,k,COIN);
				break;
				}
			case G_FLAG:
				{
				GoalFlag* g_flag=new GoalFlag(i*32,k*32);
				AddObject(g_flag,false);
				obj_manager_->RegisterObject(i,k,G_FLAG);
				break;
				}
							case JUMPKAME:
				{
				AddObject(new JumpKame(i*32,k*32,this),false);
				obj_manager_->RegisterObject(i,k,JUMPKAME);
				break;
				}
			case TAIHOU:
				{
					AddObject(new Taihou(i*32,k*32,this),false);
					obj_manager_->RegisterObject(i,k,TAIHOU);
					break;
				}
				
			}
		}
	}
	
	//最初の描画領域の敵のみ動かす
	FindObject(0,map_->map_height(),0,20);

}
void Field::FindObject(int from_y,int to_y,int from_x,int to_x){
	for(int i=from_y;i<to_y;i++){
		for(int j=from_x;j<to_x;j++){
			int id=obj_manager_->GetId(j,i);
			if(id!=-1){
				if(objects_.at(id)->object_type()==O_ENEMY && objects_.at(id)->isAlive()==false) objects_.at(id)->Reset();
			}
		}
	}
}

//完成
void Field::FallObjects(){
	for(int i=0; i<(int)objects_.size(); i++)
		objects_.at(i)->Fall(gravity_);
}

//完成
void Field::MoveObjects(){
	for(int i=0; i<(int)objects_.size(); i++)
		objects_.at(i)->Move();
}

//完成
void Field::DrawObjects(){
	if(player_->game_status()==NOTHING){
		//オブジェクト描画
		for(int i=0; i<(int)objects_.size(); i++){
			if(objects_.at(i)->isAlive()){
				objects_.at(i)->Draw(offset_);
			}
		}
		//マップ描画
		map_->Draw(offset_);
		//HPバー描画
		int percentHp = (player_->hp()*100)/player_->maxHp();
		DrawString(30,10,"HP",GetColor(255,255,255),true);
		DrawBox(20,30,120,50,GetColor(0,0,0),true);
		DrawBox(20,30,20+percentHp,50,GetColor(255,0,0),true);
		DrawBox(20,30,120,50,GetColor(255,255,255),false);
		//スコア表示
		DrawString(350,0,"スコア",GetColor(255,255,255),true);
		DrawFormatString(410,0,GetColor(255,255,255),"%d",player_->score(),true);
		//残機描画
		DrawString(550,0,"残機",GetColor(255,255,255),true);
		DrawFormatString(600,0,GetColor(255,255,255),"%s %d","X",player_->life());
	}
}

////完成
void Field::ThinkObjects(){
	for(int i=0; i<(int)objects_.size(); i++){
		objects_.at(i)->Think();
	}
}

//未完成(プレイヤーの無敵時間管理も行う)
void Field::TouchPlayerToObjects(){
		int px = (int)objects_.at(0)->pos().x;
		int py = (int)objects_.at(0)->pos().y;
	//objects_の要素０はプレイヤーなのでi=1からはじめる
	for(int i=1; i<(int)objects_.size(); i++){
		//プレイヤーと敵との接触判定
		if(objects_.at(i)->object_type()==O_ENEMY && objects_.at(i)->isAlive()){
			if(JudgeHitCharacters(player_,objects_.at(i)) && !player_->super()){
				player_->Damaged(1); //プレイヤーに１ダメージ
			}
		}
		//プレイヤーとアイテムとの接触判定
		if(objects_.at(i)->object_type() == O_ITEM && objects_.at(i)->isAlive()){
			if(JudgeHitCharacters(player_,objects_.at(i))){
				dynamic_cast<Item*>(objects_.at(i))->Affect(dynamic_cast<Character*>(objects_.at(0)));
				objects_.at(i)->Die();
			}
		}
	}
	//弾の当たり判定
	if(player_->isAlive()){
		for(int i=0 ; i<(int)objects_.size(); i++){
			if(objects_.at(i)->object_type()==O_ENEMY && objects_.at(i)->isAlive()){
			//プレイヤーの弾と敵とのあたり判定
				for(int k=0; k<player_->GetBulletsSize(); k++){
					if(player_->GetBullets().at(k)->isAlive()){
						if(this->JudgeHitCharacters (player_->GetBullets().at(k), objects_.at(i)) ){
							dynamic_cast<Character*>(objects_.at(i))->Damaged(player_->GetBullets().at(k)->damage());
							player_->GetBullets().at(k)->Die();
						}
					}
				}
		
				//敵の弾とプレイヤーとのあたり判定)
				for(int k=0; k < dynamic_cast<Character*>(objects_.at(i))->GetBulletsSize(); k++){
					if(dynamic_cast<Character*>(objects_.at(i))->GetBullets().at(k)->isAlive()){
						if(this->JudgeHitCharacters(dynamic_cast<Character*>(objects_.at(i))->GetBullets().at(k), player_)){
							player_->Damaged(dynamic_cast<Character*>(objects_.at(i))->GetBullets().at(k)->damage());
							dynamic_cast<Character*>(objects_.at(i))->GetBullets().at(k)->Die();
						}
					}
				}
			}
		}

	}
	player_->superTime();
	if(player_->life()<0) player_->SetGameStatus(OVER);
}

//完成（仮）
void Field::TouchObjectsToWall(){
	for(int i=0; i<(int)objects_.size(); i++){
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

void Field::BulletTouchWall(){
	for(int i=0; i < (int)objects_.size() ;i++){
		if(objects_.at(i)->object_type() != O_ITEM){
			for(int k=0; k < dynamic_cast<Character*>(objects_.at(i))->GetBulletsSize(); k++){
				double bulletX = dynamic_cast<Character*>(objects_.at(i))->GetBullets().at(k)->pos().x;
				double bulletY = dynamic_cast<Character*>(objects_.at(i))->GetBullets().at(k)->pos().y;
				double bulletSizeX = dynamic_cast<Character*>(objects_.at(i))->GetBullets().at(k)->size().x;
				double bulletSizeY = dynamic_cast<Character*>(objects_.at(i))->GetBullets().at(k)->size().y;
				if(map_->GetMapData(bulletX, bulletY) == WALL || map_->GetMapData(bulletX+bulletSizeX, bulletY) == WALL ||
					map_->GetMapData(bulletX, bulletY+bulletSizeY) == WALL || map_->GetMapData(bulletX+bulletSizeX, bulletY+bulletSizeY) == WALL){
					dynamic_cast<Character*>(objects_.at(i))->GetBullets().at(k)->Die();
				}
			}
		}
	}
}

void Field::Reset(){
	if(!player_->isAlive()){
		for(int i=0; i<(int)objects_.size(); i++){
			objects_.at(i)->Reset();
		}
	}
}

//完成（仮）
/*
void Field::DeleteObjects(){
	for(int i=0; i<(int)objects_.size(); i++){
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
*/

//完成（仮）
void Field::CheckOutOfArea(){
	for(int i=1; i<(int)objects_.size(); i++){
		if(objects_.at(i)->isAlive()){
			if(objects_.at(i)->pos().x < -offset_-320 || 
			objects_.at(i)->pos().x > -offset_+640+320 ){
				if(objects_.at(i)->object_type()==O_ENEMY)objects_.at(i)->Die();
			}
		}
	}
}

void Field::DownObjectsDie(){
	for(int i=0; i<(int)objects_.size(); i++){
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
	return (int)floor(pixels/32);
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
/*
int Field::GetMapData(double x, double y){
	return map_->GetMapData(x,y);
}
*/
bool Field::IsNextMapDataAWall(TwoDimension pos,TwoDimension speed,bool right){
	if(right){
		if( map_->GetMapData(pos.x+speed.x+32,pos.y)==WALL) return  true;
		else return false;
	}
	else{
		if(map_->GetMapData(pos.x+speed.x,pos.y)==WALL) return true;
		else return false;
	}
}

//プレイヤーの座標を返す関数
TwoDimension Field::GetPlayerPos(){
	return objects_.at(0)->pos();
}

Field::~Field(){
	
	for(int i=objects_.size()-1;i>=0;i--){
		delete objects_.at(i);
	}
	delete obj_manager_;
}