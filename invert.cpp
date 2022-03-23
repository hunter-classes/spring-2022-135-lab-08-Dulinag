#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
#include "imageio.h"
#include "invert.h"



  void invert (std::string input){
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);

  ofstream ostr;
  ostr.open("inImage.pgm");
  if (ostr.fail()) {
    cout << "Unable to write file\n";
    exit(1);
  };

  ostr << "P2" << endl;
  ostr << w << endl;
  ostr << h << endl;
  ostr << 255 << endl;

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      assert(img[row][col] < 256);
      assert(img[row][col] >= 0);
      ostr << 255 - img[row][col]<< ' ';
      ostr << endl;
    }
  }
  ostr.close();
  return;
}

void inverthalf (std::string input){
int img[MAX_H][MAX_W];
int h, w;
readImage(input, img, h, w);

ofstream ostr;
ostr.open("inImage.pgm");
if (ostr.fail()) {
  cout << "Unable to write file\n";
  exit(1);
};

ostr << "P2" << endl;
ostr << w << endl;
ostr << h << endl;
ostr << 128 << endl;

for(int row = 0; row < h; row++) {
  for(int col = 0; col < w; col++) {
    assert(img[row][col] < 128);
    assert(img[row][col] >= 0);
    ostr << 127 - img[row][col]<< ' ';
    ostr << endl;
  }
}
ostr.close();
return;
}
