#include <iostream>
#include <string>
#include <vips/vips8>

using namespace std;

class imageprocessor
{
private:
    /* data */
    std::vector<std::string> images;
    string getFilenameWithoutExtension(string fullname);
    bool validateSize(int &height, int &width);
public:
    imageprocessor(std::vector<std::string> imageList, string path);
    ~imageprocessor();

    void execute(int &height, int &width);
};

