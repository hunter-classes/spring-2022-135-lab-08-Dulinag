#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <string>

#include "imageio.h"
#include "invert.h"
using namespace std;





int main()
{


  invert ("inImage.pgm");
  inverthalf ("inImage.pgm");



  return 0;
}
