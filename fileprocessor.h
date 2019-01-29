#include <dirent.h>
#include <string>
#include <vector>

using namespace std;

class fileprocessor
{
private:
    /* data */
    const char* folderPath;
public:
    fileprocessor(const char* path);
    ~fileprocessor();
    std::vector<std::string> getFiles(const char* path);
};

