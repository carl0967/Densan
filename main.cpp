
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

	//�Q�[�����C������
	GameMain fps;

	//���C�����[�v�J�n
	fps.GameStart();
	

	DxLib_End();



		
		
}