#include "cribdrag.h"
#include <string>
#include <iostream>


using namespace std;

crib_drag_data cribdrag(crib_drag_data crib_data)
{	// TODO execute the cribdrag method with the input string and the crib string

	string cipher_xor_str;
	string cipher_xor_substr;

	fill_n(crib_data.results, crib_data.results->length, 0);				// empty result array
	cipher_xor_str = strXOR(crib_data.cipher_1, crib_data.cipher_2);		// XOR the 2 cipher strings 

	int crib_runs = crib_data.cipher_1.length - crib_data.crib.length;		// determine number of times to run crib XOR
	
	for (int i = 0; i < crib_runs; i++)
	{
		cipher_xor_substr = cipher_xor_str.substr(i, crib_data.crib.length - 1);
		crib_data.results->append(strXOR(cipher_xor_substr, crib_data.crib));
	}
}

string strXOR(string str_1, string str_2)
{	// TODO create XOR'd string output for input strings str_1 and str_2 by converting each char to its corresponding hex value and comparing it
	
	int str_len;
	int str1_len = str_1.length();
	int str2_len = str_2.length();

	char temp_char_1;
	char temp_char_2;

	string str_out;


	// Handling in case the strings are of different lengths
	if (str1_len < str2_len)
		str_len = str1_len;
	else
		str_len = str2_len;


	// Loop through each array, creating a new XOR'd string from each char
	for (int i = 0; i < str_len; i++)
	{
		temp_char_1 = str_1[i];
		temp_char_2 = str_2[i];

		str_out[i] = temp_char_1 ^ temp_char_2;
	}

	return str_out;
}