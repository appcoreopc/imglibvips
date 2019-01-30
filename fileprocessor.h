#include <dirent.h>
#include <string>
#include <vector>

using namespace std;

class fileprocessor
{
private:
    string folderPath;
public:
    fileprocessor(string path);
    ~fileprocessor();
    std::vector<std::string> getFiles(const char* path);
};

