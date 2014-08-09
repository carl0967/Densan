
#include "Field.h"


Field::Field(Map map){
	map_ = map;
	gravity_ = 1;
}
//���C�����[�v
bool Field::MainLoop(){
	FallObjects();
	MoveObjects();
	ThinkObjects();
	Scroll();
	CheckOutOfArea();
	TouchPlayer2Objects();
	TouchObjects2Wall();
	DeleteObjects();
	DrawObjects();

	return true;
}

void Field::Scroll(){
	int width = 480;  //��ʂ̉���
	offset_ = width/2-(int)objects_.at(0)->pos().x;
	offset_ = min(offset_,0);
	offset_ = max(offset_,width-100);
}

//����
void Field::FallObjects(){
	for(int i=0; i<objects_.size(); i++)
		objects_.at(i)->Fall(gravity_);
}

//����
void Field::MoveObjects(){
	for(int i=0; i<objects_.size(); i++)
		objects_.at(i)->Move();
}

//������(�}�b�v�S�̂̒������킩��Ȃ�)
void Field::DrawObjects(){
	//�`��
	for(int i=0; i<objects_.size(); i++)
		objects_.at(i)->Draw(offset_);
}

//����
void Field::ThinkObjects(){
	for(int i=0; i<objects_.size(); i++)
		objects_.at(i)->Think();
}

//�������i�����蔻��͉~�ōs��,�L�����̑傫����32�œ��ꂵ�čs���Ă���j
void Field::TouchPlayer2Objects(){
		int px = (int)objects_.at(0)->pos().x;
		int py = (int)objects_.at(0)->pos().y;
	//objects_�̗v�f�O�̓v���C���[�Ȃ̂�i=1����͂��߂�
	for(int i=1; i<objects_.size(); i++){
		//�v���C���[�ƓG�Ƃ̐ڐG����
		if(JudgeCircle(px, py, 16, (int)objects_.at(i)->pos().x, (int)objects_.at(i)->pos().y, 16)){

		}
		//�v���C���[�̒e�ƓG�Ƃ̂����蔻��

		//�G�̒e�ƃv���C���[�Ƃ̂����蔻��

	}
}

//�����i���j
void Field::TouchObjects2Wall(){
	for(int i=0; i<objects_.size(); i++){
		double objectX = objects_.at(i)->pos().x;
		double objectY = objects_.at(i)->pos().y;
		double newX;
		double newY;
		//x������y�����ɕ����Ĕ�����s���̂�
		//k=0�̎�x����,k=1�̎�y����
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
			int toTileX = PixelToTiles(toX+31);
			int toTileY = PixelToTiles(toY+31);

			//�Փ˂��Ă��邩���ׂ�
			for(int x = fromTileX; x<= toTileX; x++){
				for(int y = fromTileY; y <= toTileY; y++){
					if(map_.GetMapData(x,y) == 1){
						if(k==0){  //x�����ł������Ă����ꍇ
							objects_.at(i)->TouchedBlockX(TilesToPixels(x));	
						} 
						if(k==1){ //y�����ł������Ă����ꍇ
							objects_.at(i)->TouchedBlockY(TilesToPixels(y));
						} 
					}
				}
			}
		}
	}
}

//�����i���j
void Field::DeleteObjects(){
	for(int i=0; i<objects_.size(); i++){
		if(!objects_.at(i)->isAlive()){
			//�I�u�W�F�N�g�폜
			delete objects_.at(i);
			//�I�u�W�F�N�g�̎Q�ƍ폜
			vector<AObject*>::iterator start;
			start = objects_.begin()+i;
			objects_.erase(start);
		}
	}
}

//�����i���j
void Field::CheckOutOfArea(){
	for(int i=0; i<objects_.size(); i++){
		if(objects_.at(i)->pos().x < -offset_ || 
			objects_.at(i)->pos().x > -offset_+480 ){
			//�I�u�W�F�N�g�폜
			delete objects_.at(i);
			//�I�u�W�F�N�g�̎Q�ƍ폜
			vector<AObject*>::iterator start;
			start = objects_.begin()+i;
			objects_.erase(start);
		}
	}
}

//������(�}�b�v����̏��)
void Field::AddObject(AObject *object_num){
	/*
	objects_.push_back(object_num);
	vector<int>::iterator start;
	start = test.begin()+2;
	test.erase(start);
	*/
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


