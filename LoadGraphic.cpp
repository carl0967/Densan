#include "LoadGraphic.h"
#include <string.h>
LoadGraphic::LoadGraphic(){
	count=0;

}
int LoadGraphic::Load(char* file_name){
	for(int i=0;i<count;i++){
		//一致したとき
		if(!strcmp(file_names[i],file_name)){
		//if(!strcmp("",file_name)){
			return g_handles[i];
		}

	}
	//一致しなかったとき

	g_handles[count]=LoadGraph(file_name);
	file_names[count]=file_name;
	count++;
	return g_handles[count-1];

}