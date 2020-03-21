#pragma once

#include "wx/wx.h"

class cApp : public wxApp
{
public:
	cApp();
	~cApp();
public:
	virtual bool OnInit();
};

