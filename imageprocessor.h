#include <iostream>
#include <string>
#include <vips/vips8>

using namespace std;

class imageprocessor
{
private:
    /* data */
    std::vector<std::string> images;
    std::string basename(std::string &filename);
public:
    imageprocessor(std::vector<std::string> imageList, string path);
    ~imageprocessor();

    void execute();
};

