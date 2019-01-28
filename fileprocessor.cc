#include <dirent.h>
#include <string>
#include <vector>
#include "fileprocessor.h"
#include <iostream>

using namespace std;

string folderPath;

fileprocessor::fileprocessor(string path)
{
   folderPath = path;
}

fileprocessor::~fileprocessor()
{

}

std::vector<std::string> fileprocessor::getFiles(string pattern)
{
    DIR *dir;
    struct dirent *ent;
    std::vector<std::string> list;

    if ((dir = opendir("test")) != NULL) {

        while ((ent = readdir(dir)) != NULL) {
            cout << " files " << ent->d_name;
            list.push_back(ent->d_name);
        }
    }
    return list;       
}

