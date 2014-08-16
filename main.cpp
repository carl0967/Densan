
#include "DxLib.h"
#include<iostream>
#include "GameMain.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
	 ChangeWindowMode( TRUE ),DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK ); // �E�B���h�E���[�h�ɐݒ�etc

	ChangeWindowMode(true);
	if( DxLib_Init() == -1 )		// �c�w���C�u��������������
	{
		return -1 ;			// �G���[���N�����璼���ɏI��
	}

	/*

	MapFactory* mapf=new MapFactory();
	Map* map;
	map=mapf->CreateMap("map.txt");
	



	Field* field=new Field(map);




	AObject* character= new Player(1,0,field);
	*/

	//�Q�[�����C������
	GameMain fps;

	//���C�����[�v�J�n
	fps.GameStart();
	

	DxLib_End();



		
		
}