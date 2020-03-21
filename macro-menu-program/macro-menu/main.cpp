// macro-menu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <cstdio>
#include <tchar.h>
#include <windows.h>

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

	return 0;
}

