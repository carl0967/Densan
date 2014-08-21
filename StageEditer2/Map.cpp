#include "stdafx.h"
#include "Map.h"
#define CELL_WIDTH 32
#define CELL_HEIGHT 32

Map::Map(int width,int height,std::vector<int> orignal)
	:width(width),height(height),orignal(orignal)
{
}

void Map::AddMapData(int xPos,int yPos,HWND hWnd){
	int index_x=(int)(xPos)/CELL_WIDTH;
	int index_y=(int)(yPos)/CELL_HEIGHT;

	if(orignal[index_y*width+index_x]<3){
		orignal[index_y*width+index_x]++;
		InvalidateRect(hWnd , NULL , FALSE);	// 再描画要求
	}else{
		orignal[index_y*width+index_x] = 0;
		InvalidateRect(hWnd , NULL , TRUE);		// 再描画要求
	}
}
void Map::LoadMap(HWND hWnd){
	static HBITMAP hBitmap;		// ビットマップハンドル

	rengaMem = CreateCompatibleDC(NULL);	
	hBitmap = (HBITMAP)LoadImage(
		(HINSTANCE)GetWindowLong(hWnd,GWL_HINSTANCE),
		TEXT(".\\graph\\renga.bmp"),IMAGE_BITMAP,
		0,0,LR_LOADFROMFILE);
	SelectObject(rengaMem,hBitmap);
	GetObject(hBitmap,sizeof(BITMAP),&renga);
	
	playerMem = CreateCompatibleDC(NULL);
	hBitmap = (HBITMAP)LoadImage(
		(HINSTANCE)GetWindowLong(hWnd,GWL_HINSTANCE),
		TEXT(".\\graph\\player.bmp"),IMAGE_BITMAP,
		0,0,LR_LOADFROMFILE);
	SelectObject(playerMem,hBitmap);
	GetObject(hBitmap,sizeof(BITMAP),&player);

	kameMem = CreateCompatibleDC(NULL);
	hBitmap = (HBITMAP)LoadImage(
		(HINSTANCE)GetWindowLong(hWnd,GWL_HINSTANCE),
		TEXT(".\\graph\\kame.bmp"),IMAGE_BITMAP,
		0,0,LR_LOADFROMFILE);
	SelectObject(kameMem,hBitmap);
	GetObject(hBitmap,sizeof(BITMAP),&kame);

	coinMem = CreateCompatibleDC(NULL);
	hBitmap = (HBITMAP)LoadImage(
		(HINSTANCE)GetWindowLong(hWnd,GWL_HINSTANCE),
		TEXT(".\\graph\\coin.bmp"),IMAGE_BITMAP,
		0,0,LR_LOADFROMFILE);
	SelectObject(coinMem,hBitmap);
	GetObject(hBitmap,sizeof(BITMAP),&coin);
}



VOID Map::DrawMap(HWND hWnd,PAINTSTRUCT *ps,HDC hdc){
	hdc = BeginPaint(hWnd, ps);
	// TODO: 描画コードをここに追加してください...
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			switch(orignal[i*width+j]){
			case 0:	// empty
				//　何も表示しない
				break;
			case 1:	// wall
				BitBlt(hdc,(j-offset)*CELL_WIDTH,i*CELL_HEIGHT,renga.bmWidth,renga.bmHeight,rengaMem,0,0,SRCCOPY);
				break;
			case 2:	// player
				BitBlt(hdc,(j-offset)*CELL_WIDTH,i*CELL_HEIGHT,player.bmWidth,player.bmHeight,playerMem,0,0,SRCCOPY);
				break;
			case 3:	// kame
				BitBlt(hdc,(j-offset)*CELL_WIDTH,i*CELL_HEIGHT,renga.bmWidth,renga.bmHeight,kameMem,0,0,SRCCOPY);
				break;
			case 4:	// coin
				BitBlt(hdc,(j-offset)*CELL_WIDTH,i*CELL_HEIGHT,renga.bmWidth,renga.bmHeight,coinMem,0,0,SRCCOPY);
				break;
			}
		}
	}
	EndPaint(hWnd, ps);
}