#pragma once
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <string>
#endif

#include "wbenny-ziplib-176e4b6d51fc/Source/ZipLib/ZipFile.h"

#include "wbenny-ziplib-176e4b6d51fc/Source/ZipLib/streams/memstream.h"

#include "wbenny-ziplib-176e4b6d51fc//Source/ZipLib/methods/Bzip2Method.h"

#include <fstream>

std::string password_cracker(std::string file_path);
void printAllKLengthRec(std::string set[], std::string prefix, int n, int k, ZipArchive::Ptr archive, std::string& out);