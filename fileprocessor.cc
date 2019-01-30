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

std::vector<std::string> fileprocessor::getFiles(const char* path)
{
    DIR *dir;
    struct dirent *ent;
    std::vector<std::string> list;

    if ((dir = opendir(folderPath.c_str())) != NULL) {

        while ((ent = readdir(dir)) != NULL) {
                        
            string s = ent->d_name;
            if ((s.find("png") != std::string::npos))
            {
                 list.push_back(ent->d_name);
            }
        }
    }

    return list;       
}

