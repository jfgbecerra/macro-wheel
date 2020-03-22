#pragma once

struct crib_drag_data
{
	std::string cipher_1;
	std::string cipher_2;
	std::string crib;
	std::string key;
	std::string results[10];
};

crib_drag_data cribdrag(crib_drag_data crib_data);
string strXOR(string str_1, string str_2);