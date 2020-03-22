#include "password_cracker.h"
#include <fstream>
#include <iostream>

using namespace std;

void printAllKLengthRec(string set[], string prefix, int n, int k, ZipArchive::Ptr archive, string& out) {
    bool found = false;
    // Base case: k is 0, 
    // print prefix 
    if (k == 0)
    {
        ZipArchiveEntry::Ptr entry = archive->GetEntry("file.txt");

        // if the entry is password protected, it is necessary
        // to set the password before getting a decompression stream
        if (entry->IsPasswordProtected())
        {
            // when decompressing an encrypted entry
            // there is no need to specify the use of data descriptor
            // (ZibLib will deduce if the data descriptor was used)
            entry->SetPassword(prefix);
        }

        // if the entry is password protected and the provided password is wrong
        // (or none is provided) the return value will be nullptr
        std::istream* decompressStream = entry->GetDecompressionStream();
        cout << prefix;

        if (decompressStream != nullptr) {
            out = prefix;
        }
        return;
    }
    // One by one add all characters  
    // from set and recursively  
    // call for k equals to k-1 
    for (int i = 0; i < n; i++)
    {
        string newPrefix;

        // Next character of input added 
        newPrefix = prefix + set[i];

        // k is decreased, because  
        // we have added a new character 
        printAllKLengthRec(set, newPrefix, n, k - 1, archive, out);
    }
}


std::string password_cracker(std::string file_path)
{
    using namespace std;

    string password;
    string set[500];

    ifstream inFile;
    inFile.open("C:\\Users\\Coleman Cook\\Documents\\macro-wheel\\macro-menu-program\\macro_functions\\10-million-password-list-top-1000000.txt");
   

    for (long int j = 0; j < 500; j++)
    {
        inFile>>set[j];
    }

    ZipArchive::Ptr archive = ZipFile::Open(file_path);

    printAllKLengthRec(set, "", 500, 1, archive, password);
    
    return password;
}
