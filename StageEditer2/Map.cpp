#include "stdafx.h"
#include "Map.h"
#define CELL_WIDTH 32
#define CELL_HEIGHT 32

Map::Map(int width,int height,std::vector<int> orignal)
	:width(width),height(height),orignal(orignal),offset()
{
}

void Map::AddMapData(int xPos,int yPos,HWND hWnd){
	int index_x=(int)(xPos)/CELL_WIDTH;
	int index_y=(int)(yPos)/CELL_HEIGHT;
	index_x += offset;
	if(index_x <= width && index_y <= height){
		if(orignal[index_y*width+index_x]<GRAPHIC_NUM-1){
			orignal[index_y*width+index_x]++;
		}else{
			orignal[index_y*width+index_x] = 0;
		}
	}
	InvalidateRect(hWnd , NULL , TRUE);	// �ĕ`��v��
}

void Map::SetMapData(int xPos,int yPos,HWND hWnd,int type){
	int index_x=(int)(xPos)/CELL_WIDTH;
	int index_y=(int)(yPos)/CELL_HEIGHT;
	index_x += offset;
	if(index_x <= width && index_y <= height){
		orignal[index_y*width+index_x] = type;
	}
	InvalidateRect(hWnd , NULL , TRUE);	// �ĕ`��v��
}
void Map::LoadMap(HWND hWnd){
	static HBITMAP hBitmap;		// �r�b�g�}�b�v�n���h��
	wchar_t* source[GRAPHIC_NUM] ={		// �摜�̃\�[�X��
	L".\\graph\\empty.bmp",
	L".\\graph\\renga.bmp",
	L".\\graph\\player.bmp",
	L".\\graph\\kame.bmp",
	L".\\graph\\coin.bmp",
	L".\\graph\\flag.bmp",
	L".\\graph\\flyKame.bmp",
	L".\\graph\\taiho.bmp"};

	for(int i=0;i<GRAPHIC_NUM;i++){
		graphicMem[i] = CreateCompatibleDC(NULL);	
		hBitmap = (HBITMAP)LoadImage(
			(HINSTANCE)GetWindowLong(hWnd,GWL_HINSTANCE),
			source[i],IMAGE_BITMAP,
			0,0,LR_LOADFROMFILE);
		SelectObject(graphicMem[i],hBitmap);
		GetObject(hBitmap,sizeof(BITMAP),&graphics[i]);
	}
}
/*
void Map::ToolDraw(){

}*/



VOID Map::DrawMap(HWND hWnd,PAINTSTRUCT *ps,HDC hdc){
	// TODO: �`��
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			int index = orignal[i*width+j];
			// index��0�ȏ�ł���GRAPHIC_NUM�����̏ꍇ�̂ݕ`��(�G���[��h��)
			if(index<GRAPHIC_NUM && index >= 0)
				BitBlt(hdc,(j-offset)*CELL_WIDTH,i*CELL_HEIGHT,graphics[index].bmWidth,graphics[index].bmHeight,graphicMem[index],0,0,SRCCOPY);
		}
	}
}