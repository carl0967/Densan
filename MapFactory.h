#pragma once
#include <vector>
#include <string>
#include "Map.h"

class MapFactory{
public:
	// �����̃t�@�C������Map�C���X�^���X�𐶐����ĕԂ�
	Map* CreateMap(std::string fileName);
	Map* CreateMap(std::string fileName,std::string backgroundName);
};