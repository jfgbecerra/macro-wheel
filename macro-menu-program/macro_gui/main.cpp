// macro-menu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <tchar.h>
#include <windows.h>
#include "cApp.h"


int main()
{       
	enum{one_keyid = 1};
	RegisterHotKey(nullptr, one_keyid, MOD_ALT, 0x31); // register 1 key as hot key
	MSG msg;

	while(GetMessage(&msg, nullptr, 0, 0))
	{
		PeekMessage(&msg, nullptr, 0, 0, 0x0001);
		switch(msg.message)
		{
		case WM_HOTKEY:
			if(msg.wParam == one_keyid)
			{
				// Add Change here to call display the script guid
				printf("1 Pressed");
			}
			default: ;
		}
		
	}
	system("pause");
	return 0;
}

