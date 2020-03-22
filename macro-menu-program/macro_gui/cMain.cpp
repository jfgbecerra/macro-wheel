#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10001, OnButtonClicked)
	EVT_HOTKEY(20001, HotKeyDown)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "MacroPenis")
{
	//m_btn1 = new wxButton(this, 10001, "touch me daddy", wxPoint(10, 10), wxSize(250, 50));;
	//m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	//m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
}

cMain::~cMain()
{

}

void cMain::OnButtonClicked(wxCommandEvent& evt)
{
	m_list1->AppendString(m_txt1->GetValue());
	this->Hide();
	evt.Skip();
}

void cMain::HotKeyDown(wxKeyEvent& evt)
{
	this->Show();
	evt.Skip();
}