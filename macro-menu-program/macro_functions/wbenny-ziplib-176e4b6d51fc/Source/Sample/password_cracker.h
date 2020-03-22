#pragma once
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <string>
#endif

#include "../ZipLib/ZipFile.h"
#include "../ZipLib/streams/memstream.h"

#include "../ZipLib/methods/Bzip2Method.h"

#include <fstream>

std::string password_cracker(std::string file_path);
void printAllKLengthRec(std::string set[], std::string prefix, int n, int k, ZipArchive::Ptr archive, std::string& out);