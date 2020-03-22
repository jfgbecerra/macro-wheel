#pragma once
#include "wx/wx.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:
	//wxButton* m_btn1 = nullptr;
	//wxTextCtrl* m_txt1 = nullptr;
	//wxListBox* m_list1 = nullptr;

	// the fields for height and width of button grid
	int nFieldWidth = 3;
	int nFieldHeight = 3;

	wxButton** btn;

	void OnButtonClicked(wxCommandEvent& evt);
	void HotKeyDown(wxKeyEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

