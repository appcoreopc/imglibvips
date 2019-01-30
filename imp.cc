#include <vips/vips8>
#include <dirent.h>
#include <iostream>
#include <string>
#include "fileprocessor.h"
#include "imageprocessor.h"

using namespace vips;
using namespace std;

int main (int argc, char **argv)
{   
   string targetFolder("/home/jeremy/tmp");

   fileprocessor f(targetFolder);

   auto path = f.getFiles("");

  
 if (VIPS_INIT (argv[0])) 
    vips_error_exit (NULL);
   
   imageprocessor imp(path, targetFolder); 
   imp.execute();
   
  vips_shutdown ();
  
  return (0);
}
