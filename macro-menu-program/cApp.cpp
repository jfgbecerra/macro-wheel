
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <tchar.h>
#include <windows.h>
#include "cApp.h"

wxIMPLEMENT_APP(cApp);


cApp::cApp()
{

}

cApp::~cApp()
{

}

bool cApp::OnInit()
{
	m_frame1 = new cMain();
	m_frame1->Show();
	m_frame1->RegisterHotKey(20001, MOD_ALT, 0x31);

	return true;
}

