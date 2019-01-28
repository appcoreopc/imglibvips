#include <dirent.h>
#include <string>
#include <vector>

using namespace std;

class fileprocessor
{
private:
    /* data */
    string folderPath;
public:
    fileprocessor(string path);
    ~fileprocessor();
    std::vector<std::string> getFiles(string pattern);
};

