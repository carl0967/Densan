#include "LoadGraphic.h"
#include <string.h>
LoadGraphic::LoadGraphic(){
	count=0;

}
int LoadGraphic::Load(char* file_name){
	for(int i=0;i<count;i++){
		//��v�����Ƃ�
		if(!strcmp(file_names[i],file_name)){
		//if(!strcmp("",file_name)){
			return g_handles[i];
		}

	}
	//��v���Ȃ������Ƃ�

	g_handles[count]=LoadGraph(file_name);
	file_names[count]=file_name;
	count++;
	return g_handles[count-1];

}