#pragma once

//�}�b�v�`�b�v�̃f�[�^������\������
//EMPTY=0 WALL=1 ...
enum MapChip{EMPTY,WALL,PLAYER,KAME };

class Map{
public:

private:
	int cell_width;		// �}�b�v��1�Z���̕�
	int cell_hegiht;	// �}�b�v��1�Z���̍���
	int map_width_;		// �}�b�v�̑S�̂̕�
	int map_height_;		// �}�b�v�̑S�̂̍���
	int** map_datas;	// �}�b�v�`�b�v�f�[�^
	int offset;			// �\����ʗ̈悪�S�̃}�b�v���猩�Ăǂ���������킷���߂̕ϐ�
						// �Z���P�ʂł͂Ȃ��s�N�Z���P��(�E��30�X�N���[������Ȃ�Aoffset=30��
						// ���āA�`�悷��Ƃ�(x-ofset,y)���`��ꏊ�ɂȂ�
public:
	int map_width() {return map_width_;}
	int map_height() {return map_height_;}

	Map();

	Map(int cell_width,int cell_hegiht,int** map_datas);		// �R���X�g���N�^
	int GetMapData(double x,double y);	// �`��̈��x,y���W�������ɂƂ��āA
										// �}�b�v�f�[�^�̔z��̊Y������ꏊ�ɉ������邩��Ԃ�
	void Scroll(int);	// offset�𓮂���
	~Map();				// �f�X�g���N�^

	void SetMapHeightAndWidth(int height,int width);		// �}�b�v�S�̂̍����ƕ���ݒ肷��
};