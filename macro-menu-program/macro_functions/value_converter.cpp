// Driver script to call your functions that you want to run for macros this is a call for a python script 
// You can make calls for other languages like this. 

#pragma once
#include <iostream>
#include <cstdlib>
#include "value_converter.h" 

using namespace std;

void value_converter() 
{

    system("python py_scripts/val_converter.py");
    system("pause");
}