#include "Field.h"
#include "Map.h"
#include "AObject.h"
#include <vector>



Field::Field(void)
{
}

//ÉÅÉCÉìÉãÅ[Év
bool Field::MainLoop(){
	FallObjects();
	MoveObjects();
	ThinkObjects();
	CheckOutOfArea();
	TouchPlayer2Objects();
	TouchObjects2Wall();
	DeleteObjects();
	DrawObjects();

}

void Field::Scroll(){

}

void Field::FallObjects(){
	for(int i=0; i<objects.size;i++)
		objects.size;
}

void Field::MoveObjects(){
}

void Field::DrawObjects(){
}

void Field::ThinkObjects(){
}

void Field::TouchPlayer2Objects(){
}

void Field::TouchObjects2Wall(){
}

void Field::DeleteObjects(){
}

void Field::CheckOutOfArea(){
}

void Field::AddObject(int object_num){
}





