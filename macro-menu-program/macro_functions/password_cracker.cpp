#include "password_cracker.h"

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
    string password;
    string set[] = {"kill", "end", "sad", "live", "shoot", "me", "help", "die"};

    ZipArchive::Ptr archive = ZipFile::Open(file_path);

    printAllKLengthRec(set, "", 8, 2, archive, password);
    
    return password;
}
