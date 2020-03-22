#pragma once

struct crib_drag_data
{
	string cipher_1;
	string cipher_2;
	string key;
	string message;
	string crib;
	string results[10];
};

crib_drag_data cribdrag(crib_drag_data crib_data);
std::string strXOR(std::string str_1, std::string str_2);
