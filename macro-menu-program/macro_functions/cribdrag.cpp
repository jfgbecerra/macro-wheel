
#include <string>
#include <iostream>
#include <stdio.h>


using namespace std;

#include "cribdrag.h"


crib_drag_data cribdrag(crib_drag_data crib_data)
{	// TODO execute the cribdrag method with the input string and the crib string

	string cipher_xor_str;
	string cipher_xor_substr;


	// Empty results array
	for (int j = 0; j < 10; j++)
	{
		crib_data.results[j] = "";
	}

	cipher_xor_str = strXOR(crib_data.cipher_1, crib_data.cipher_2);		// XOR the 2 cipher strings 

	int crib_runs = crib_data.cipher_1.size() - crib_data.crib.size();		// determine number of times to run crib XOR
	
	for (int i = 0; i < crib_runs; i++)
	{
		cipher_xor_substr = cipher_xor_str.substr(i, crib_data.crib.size() - 1);
		crib_data.results->append(strXOR(cipher_xor_substr, crib_data.crib));
	}

	return crib_data;
}

string strXOR(std::string str_1, std::string str_2)
{	// TODO create XOR'd string output for input strings str_1 and str_2 by converting each char to its corresponding hex value and comparing it
	
	
	int str1_len = str_1.length();
	int str2_len = str_2.length();
	

	int temp_char_1;
	int temp_char_2;
	char temp_char_3;

	int str_len;

	

	// Handling in case the strings are of different lengths
	if (str1_len < str2_len)
		str_len = str1_len;
	else
		str_len = str2_len;

	string str_out;

	int test_arr[50];

	// Loop through each array, creating a new XOR'd string from each char
	for (int i = 0; i < str_len; i++)
	{
		temp_char_3 = 0;
		temp_char_1 = (int)str_1[i];
		temp_char_2 = (int)str_2[i];

		temp_char_3 += (temp_char_1 ^ temp_char_2);

		test_arr[i] = temp_char_3;
	}

	for (int j = 0; j < str_len; j++)
	{
		str_out[j] = test_arr[j];
	}

	return str_out;
}