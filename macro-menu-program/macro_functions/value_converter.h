#pragma once
#include <iostream>
#include <cstdlib>
#include <unordered_map> 
#include <string>

using namespace std;

string value_converter(string input, string output, string value);
string HexToBin(string hexdec);
void createMap(unordered_map<string, char>* um);
