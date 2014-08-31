#pragma once
#include <vector>
#include <string>
#include "Map.h"

class MapFactory{
public:
	// 引数のファイル名でMapインスタンスを生成して返す
	Map* CreateMap(std::string fileName);
	Map* CreateMap(std::string fileName,std::string backgroundName);
};