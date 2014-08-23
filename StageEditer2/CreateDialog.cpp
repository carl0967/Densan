#include "stdafx.h"
#include "CreateDialog.h"


BOOL CreateDialog:: DialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
	case WM_CREATE:
		break;
	case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case IDCANCEL:
                    EndDialog(hWnd, IDCANCEL);
                    return TRUE;
                case IDOK:
                    GetDlgItemText(hWnd, IDC_EDIT1, (LPWSTR)width, (int)sizeof(width));
                    GetDlgItemText(hWnd, IDC_EDIT2, (LPWSTR)height, (int)sizeof(height));
					EndDialog(hWnd, IDOK);
                    return TRUE;
            }
            return FALSE;
    }
    return FALSE;
}

// ŽÀ‘ÔŠm•Û
TCHAR CreateDialog::width[64];
TCHAR CreateDialog::height[64];


Map* CreateDialog::CreateMap(){
	Map *map = nullptr;
	std::vector<int> orignal;
	for(int i=0;i<GetHeight();i++){
		for(int j=0;j<GetWidth();j++){
			if(i==GetHeight()-1 || j==0 || j==GetWidth()-1)
				orignal.push_back(1);
			else
				orignal.push_back(0);
		}
	}
	map = new Map(GetWidth(),GetHeight(),orignal);
	if(map)
		map->LoadMap(NULL);
	return map;
}

int CreateDialog::GetHeight(){
	char temp[64];
	//TCHARŒ^‚ðcharŒ^‚É•ÏŠ·
    WideCharToMultiByte(CP_ACP,0,height,-1,temp,sizeof(temp),NULL,NULL);
	return atoi(temp);
}

int CreateDialog::GetWidth(){
	char temp[64];
	//TCHARŒ^‚ðcharŒ^‚É•ÏŠ·
    WideCharToMultiByte(CP_ACP,0,width,-1,temp,sizeof(temp),NULL,NULL);
	return atoi(temp);
}
