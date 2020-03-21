#pragma once

#include "wx/wx.h"

class gui_main : public wxApp
{
public:
	gui_main();
	~gui_main();
public:
	virtual bool OnInit();
};

