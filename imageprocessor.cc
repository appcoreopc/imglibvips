
#include <iostream>
#include <string>
#include <vips/vips8>
#include "imageprocessor.h"
#include <experimental/filesystem>

using namespace std;
using namespace vips;

std::vector<std::string> images;
string location;

imageprocessor::imageprocessor(std::vector<std::string> imageList, string path)
{
    images = imageList;
    location = path;
}

imageprocessor::~imageprocessor()
{    
}

void imageprocessor::execute(int &height, int &width) {

   if (!validateSize(height, width))
      return;


  for (auto imgElement : images) {
            
       cout << "Processing file " << imgElement.c_str() << endl;

        auto rawFileName = getFilenameWithoutExtension(imgElement);

        auto filename = location + "/" + imgElement;
            
       VImage source = VImage::new_from_file(filename.c_str(), 
       VImage::option ()->set ("access", VIPS_ACCESS_SEQUENTIAL));

       // applies resize //
       VImage target =  source.shrink(height, width);

       auto finalOutputfile = rawFileName + ".webp";
       char* fname = const_cast<char *>(finalOutputfile.c_str());

       cout << "output filename " << fname;
       target.webpsave(fname);       
   }
}

string imageprocessor::getFilenameWithoutExtension(string fullname) {
    size_t lastindex = fullname.find_last_of("."); 
    string rawname = fullname.substr(0, lastindex); 
    return rawname;
}

bool imageprocessor::validateSize(int &height, int &width) {    
    return (height > 20 && height <= 2000 && width > 20 && width <= 2000);
}
