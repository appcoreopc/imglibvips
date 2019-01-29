
#include <iostream>
#include <string>
#include <vips/vips8>
#include "imageprocessor.h"
#include <experimental/filesystem>

using namespace std;
using namespace vips;
namespace fs = std::experimental::filesystem;

std::vector<std::string> images;

imageprocessor::imageprocessor(std::vector<std::string> imageList)
{
    images = imageList;
}

imageprocessor::~imageprocessor()
{
}

void imageprocessor::execute() {

  for (auto i : images) {
       cout << "file " << i.c_str() << endl;

       auto filename = "/home/jeremy/tmp/" + imageprocessor::basename(i);
            
       VImage source = VImage::new_from_file(filename.c_str(), 
       VImage::option ()->set ("access", VIPS_ACCESS_SEQUENTIAL));

       // applies resize //

       VImage target =  source.resize(200);

       char* fname = const_cast<char *>(string("tstttt").c_str());

       cout << "output filename " << fname;
       target.jpegsave(fname);
   }
}

std::string imageprocessor::basename(std::string &filename)
{
    if (filename.empty()) {
        return {};
    }

    auto len = filename.length();
    auto index = filename.find_last_of("/\\");

    if (index == std::string::npos) {
        return filename;
    }

    if (index + 1 >= len) {

        len--;
        index = filename.substr(0, len).find_last_of("/\\");

        if (len == 0) {
            return filename;
        }

        if (index == 0) {
            return filename.substr(1, len - 1);
        }

        if (index == std::string::npos) {
            return filename.substr(0, len);
        }

        return filename.substr(index + 1, len - index - 1);
    }

    return filename.substr(index + 1, len - index);
}

