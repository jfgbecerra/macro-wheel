#define _CRT_SECURE_NO_WARNINGS
#include "cMain.h"
#ifdef _MSC_VER
#include <windows.h>
#endif
#include "dependencies/TinyEXIF-master/TinyEXIF.h"
#include <iostream> // std::cout
#include <fstream>  // std::ifstream
#include <vector>   // std::vector
#include <iomanip>  // std::setprecision




using namespace std;

wxBEGIN_EVENT_TABLE(cMain, wxFrame)

	EVT_HOTKEY(20001, HotKeyDown)
wxEND_EVENT_TABLE()

class EXIFStreamFile : public TinyEXIF::EXIFStream {
public:
	explicit EXIFStreamFile(const char* fileName)
		: file(fileName, std::ifstream::in | std::ifstream::binary) {}
	bool IsValid() const override {
		return file.is_open();
	}
	const uint8_t* GetBuffer(unsigned desiredLength) override {
		buffer.resize(desiredLength);
		if (!file.read((char*)buffer.data(), desiredLength))
			return NULL;
		return buffer.data();
	}
	bool SkipBuffer(unsigned desiredLength) override {
		return (bool)file.seekg(desiredLength, std::ios::cur);
	}
private:
	std::ifstream file;
	std::vector<uint8_t> buffer;
};


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
			grid->Add(btn[j * nFieldWidth + i], 1, wxEXPAND | wxALL);

			btn[j * nFieldWidth + i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);
		}
	}


	// *** Button labels are set here ***
	btn[0]->SetLabel("Value Conversion Hacker");
	btn[0]->SetBackgroundColour(wxColour(0, 204, 204, 256));
	btn[1]->SetLabel("Image Metadata Hacker");
	btn[1]->SetBackgroundColour(wxColour(0, 255, 255, 256));
	btn[2]->SetLabel("Hack me to Tonga Time");
	btn[2]->SetBackgroundColour(wxColour(51, 255, 255, 256));
	btn[3]->SetLabel("Hack me to Alabama");
	btn[3]->SetBackgroundColour(wxColour(0, 102, 204, 256));
	btn[4]->SetLabel("Hack me a zip file");
	btn[4]->SetBackgroundColour(wxColour(0, 128, 255, 256));
	btn[5]->SetLabel("Multi-Pad Encryption Hacking");
	btn[5]->SetBackgroundColour(wxColour(51, 123, 255, 256));

	btn[6]->SetBackgroundColour(wxColour(0, 0, 204, 256));
	btn[7]->SetLabel("Distraction Window Hacker");
	btn[7]->SetBackgroundColour(wxColour(0, 0, 255, 256));
	btn[8]->SetLabel("Exit Hackro");
	btn[8]->SetBackgroundColour(wxColour(51, 51, 255, 256));

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

	EXIFStreamFile stream();

	//crib_drag_data my_crib_data;
	
	int i = (evt.GetId() - 10000) % nFieldWidth;
	int j = (evt.GetId() - 10000) / nFieldWidth;

	switch(j * nFieldWidth + i)
	{
		case 0:	
			// case for the value converter
			
			// *** get data values and pass to wxstring ***
			wx_inputStr_1 = wxGetTextFromUser(_("Enter the input style of the number you want converted in lower case."), _("Value Coverter"), _(""), this, -1, -1, true);
			wx_inputStr_2 = wxGetTextFromUser(_("Enter the output style of the number you want converted in lower case."), _("Value Coverter"), _(""), this, -1, -1, true);
			wx_inputStr_3 = wxGetTextFromUser(_("Enter the value you want converted."), _("Value Coverter"), _(""), this, -1, -1, true);
			
			// *** pass data to a REAL string ***
			inputStr_1 = wx_inputStr_1.mb_str();
			inputStr_2 = wx_inputStr_2.mb_str();
			inputStr_3 = wx_inputStr_3.mb_str();


			// *** pass strings into value converter function ***
			outStr = value_converter(inputStr_1, inputStr_2, inputStr_3);
			wxMessageBox(outStr);

			break;

		case 2:
			// case for hacking to hawaii
			system("tzutil /s \"Tonga Standard Time\"");
			wxMessageBox("It's Tonga Time");
			break;

		case 3:
			system("tzutil /s \"Central Standard Time\"");
			wxMessageBox("Yee Haw Time");
			break;

		//case 5:

		//	wxMessageBox("Crib dragging process activated. To end the process, enter 'end'.");
		//	my_crib_data.cipher_1 = wxGetTextFromUser(_("Enter the first cipher you wish to compare"), _("Crib Drag Hacker"), _(""), this, -1, -1, true);
		//	my_crib_data.cipher_2 = wxGetTextFromUser(_("Enter the second cipher you wish to compare"), _("Crib Drag Hacker"), _(""), this, -1, -1, true);
		//	my_crib_data.crib = wxGetTextFromUser(_("Enter the value you wish to use as a crib"), _("Crib Drag Hacker"), _(""), this, -1, -1, true);

		//	while (strcmp(wx_inputStr_1.c_str(), "end") != 0)
		//	{
		//		my_crib_data = cribdrag(my_crib_data);
		//		wx_inputStr_2 << my_crib_data.results[0];

		//		wxMessageBox("Your current crib results are: \n" + wx_inputStr_2);
		//		
		//		wx_inputStr_1 = wxGetTextFromUser(_("Enter a new crib value or enter 'end'"), _("Crib Drag Hacker"), _(""), this, -1, -1, true);
		//		my_crib_data.crib = wx_inputStr_1;
		//	}

		//	wxMessageBox("Crib dragging process ended.");
		//	break;

		case 7: // case for the distraction window hacker
			system("hack_distract.bat");
			break;

		case 8:	// case for the exit button
			// since the only job of this case is to hide window anyways, nothing is done.
			break;
	}

	if ((j * nFieldWidth + i) == 1)
	{	// *** This is the image metadata selection set for the hacker because the switch case won't allow me to create objects. Fuck you c++
		wx_inputStr_1 = wxGetTextFromUser(_("Enter the file path of the image you want hacked."), _("Value Coverter"), _(""), this, -1, -1, true);

		EXIFStreamFile stream(wx_inputStr_1);

		if (!stream.IsValid())
		{
			wxMessageBox("No data was found to be hacked");
		}
		else
		{
			wxMessageBox("Image metadata found.");
			TinyEXIF::EXIFInfo imageEXIF(stream);
			if (!imageEXIF.Fields)
			{
				wxMessageBox("No EXIF or XMP metadata");
			}
			else
			{
				if (imageEXIF.ImageWidth || imageEXIF.ImageHeight)
					wx_inputStr_2 << "Image Resolution: " << imageEXIF.ImageWidth << "x" << imageEXIF.ImageHeight << " pixels" << "\n";

				if (imageEXIF.RelatedImageWidth || imageEXIF.RelatedImageHeight)
					wx_inputStr_2 << "Related Image Resolution: " << imageEXIF.RelatedImageWidth << "x" << imageEXIF.RelatedImageHeight << " pixels" << "\n";
				
				if (!imageEXIF.ImageDescription.empty())
					wx_inputStr_2 << "Description: " << imageEXIF.ImageDescription << "\n";

				if (!imageEXIF.Make.empty() || !imageEXIF.Model.empty())
					wx_inputStr_2 << "CameraModel: " << imageEXIF.Make << " - " << imageEXIF.Model << "\n";

				if (!imageEXIF.SerialNumber.empty())
					wx_inputStr_2 << "SerialNumber: " << imageEXIF.SerialNumber << "\n";

				if (imageEXIF.XResolution || imageEXIF.YResolution || imageEXIF.ResolutionUnit)
					wx_inputStr_2 << "Resolution: " << imageEXIF.XResolution << "x" << imageEXIF.YResolution << " (" << imageEXIF.ResolutionUnit << ")\n";

				if (imageEXIF.BitsPerSample)
					wx_inputStr_2 << "BitsPerSample: " << imageEXIF.BitsPerSample << "\n";

				if (!imageEXIF.Software.empty())
					wx_inputStr_2 << "Software: " << imageEXIF.Software << "\n";

				if (!imageEXIF.DateTime.empty())
					wx_inputStr_2 << "DateTime: " << imageEXIF.DateTime << "\n";

				if (!imageEXIF.DateTimeOriginal.empty())
					wx_inputStr_2 << "DateTimeOriginal: " << imageEXIF.DateTimeOriginal << "\n";

				if (!imageEXIF.DateTimeDigitized.empty())
					wx_inputStr_2 << "DateTimeDigitized: " << imageEXIF.DateTimeDigitized << "\n";

				if (!imageEXIF.SubSecTimeOriginal.empty())
					wx_inputStr_2 << "SubSecTimeOriginal: " << imageEXIF.SubSecTimeOriginal << "\n";

				if (!imageEXIF.Copyright.empty())
					wx_inputStr_2 << "Copyright: " << imageEXIF.Copyright << "\n";

				if (imageEXIF.GeoLocation.hasLatLon()) 
				{
					wx_inputStr_2 << "GeoLocation.Latitude: " << imageEXIF.GeoLocation.Latitude << "\n";
					wx_inputStr_2 << "GeoLocation.Longitude: " << imageEXIF.GeoLocation.Longitude << "\n";
				}
				if (imageEXIF.GeoLocation.hasAltitude())
				{
					wx_inputStr_2 << "GeoLocation.Altitude: " << imageEXIF.GeoLocation.Altitude << " m" << "\n";
					wx_inputStr_2 << "GeoLocation.AltitudeRef: " << (int)imageEXIF.GeoLocation.AltitudeRef << "\n";
				}
				wxMessageBox(wx_inputStr_2);
			}
		}
	}else if((j * nFieldWidth + i) == 4)
	{
		wx_inputStr_1 = wxGetTextFromUser(_("Enter the file path of archive you would like to dictionary attack."), _("Dictionary Attack Hacker"), _(""), this, -1, -1, true);
		inputStr_1 = wx_inputStr_1.mb_str();
		inputStr_2 = password_cracker(inputStr_1);
		wx_inputStr_3 << "Your Password is: " << inputStr_2;
		wxMessageBox(wx_inputStr_3);
	}

	this->Hide();
	evt.Skip();
}

void cMain::HotKeyDown(wxKeyEvent& evt)
{
	this->Show();
	evt.Skip();
}