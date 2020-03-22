#define _CRT_SECURE_NO_WARNINGS
#include "cMain.h"


wxBEGIN_EVENT_TABLE(cMain, wxFrame)

	EVT_HOTKEY(20001, HotKeyDown)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "The Hackro", wxPoint(30, 30) , wxSize(600, 600))
{
	// *** This is example code for making application objects ***
	//m_btn1 = new wxButton(this, 10001, "touch me daddy", wxPoint(10, 10), wxSize(250, 50));;
	//m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	//m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));

	btn = new wxButton * [nFieldWidth * nFieldHeight];

	wxGridSizer* grid = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);
	for (int i = 0; i < nFieldWidth; i++)
	{
		for (int j = 0; j < nFieldHeight; j++)
		{
			btn[j * nFieldWidth + i] = new wxButton(this, 10000 + (j * nFieldWidth + i));
			grid->Add(btn[j * nFieldWidth + i], 1, wxEXPAND | wxALL);

			btn[j * nFieldWidth + i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);
		}
	}

	// *** Button labels are set here ***
	btn[0]->SetLabel("Value Conversion Hacker");
	btn[7]->SetLabel("Distraction Window Hacker");
	btn[8]->SetLabel("Exit Hacker");

	this->SetSizer(grid);
	grid->Layout();
}

cMain::~cMain()
{
	delete[] btn;
}

void cMain::OnButtonClicked(wxCommandEvent& evt)
{	// global handler for button presses in the macro grid.
	wxString wx_inputStr_1;
	wxString wx_inputStr_2;
	wxString wx_inputStr_3;

	std::string inputStr_1;
	std::string inputStr_2;
	std::string inputStr_3;
	std::string outStr;
	
	int i = (evt.GetId() - 10000) % nFieldWidth;
	int j = (evt.GetId() - 10000) / nFieldWidth;

	switch(j * nFieldWidth + i)
	{
		case 0:	// case for the value converter
			
			wx_inputStr_1 = wxGetTextFromUser(_("Enter the input style of the number you want converted in lower case."), _("Value Coverter"), _(""), this, -1, -1, true);
			wx_inputStr_2 = wxGetTextFromUser(_("Enter the output style of the number you want converted in lower case."), _("Value Coverter"), _(""), this, -1, -1, true);
			wx_inputStr_3 = wxGetTextFromUser(_("Enter the value you want converted."), _("Value Coverter"), _(""), this, -1, -1, true);
			
			inputStr_1 = wx_inputStr_1.mb_str();
			inputStr_2 = wx_inputStr_2.mb_str();
			inputStr_3 = wx_inputStr_3.mb_str();

			outStr = value_converter(inputStr_1, inputStr_2, inputStr_3);
			wxMessageBox(outStr);

			break;

		case 7: // case for the distraction window hacker
			system("hack_distract.bat");
			break;

		case 8:	// case for the exit button
			// since the only job of this case is to hide window anyways, nothing is done.
			break;
	}

	this->Hide();
	evt.Skip();
}

void cMain::HotKeyDown(wxKeyEvent& evt)
{
	this->Show();
	evt.Skip();
}