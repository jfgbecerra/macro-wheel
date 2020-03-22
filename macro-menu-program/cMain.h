#pragma once

#include <vector>
#include <istream>
#include <string>
#include "wx/wx.h"
#include "macro_functions/value_converter.h"
//#include "macro_functions/cribdrag.h"
#include "macro_functions/password_cracker.h"
#include <wx/colour.h>
#include <wx/palette.h>


class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:

	// *** example declarations for application objects ***
	//wxButton* m_btn1 = nullptr;
	//wxTextCtrl* m_txt1 = nullptr;
	//wxListBox* m_list1 = nullptr;

	// Fields for the macro button grid dimensions
	int nFieldWidth = 3;
	int nFieldHeight = 3;

	wxButton** btn;

	void OnButtonClicked(wxCommandEvent& evt);

	void HotKeyDown(wxKeyEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

