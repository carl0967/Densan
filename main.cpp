
#include "DxLib.h"
#include<iostream>
#include "GameMain.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){

	ChangeWindowMode(true); //�E�C���h�E���[�h�̐ݒ�
	if( DxLib_Init() == -1 ) return -1;		// �c�w���C�u�������������� �G���[���N������I��
	 SetDrawScreen( DX_SCREEN_BACK ); 

	//�Q�[�����C������
	GameMain fps;

	//���C�����[�v�J�n
	fps.GameStart();
	

	DxLib_End();

	return 0;



		
		
}