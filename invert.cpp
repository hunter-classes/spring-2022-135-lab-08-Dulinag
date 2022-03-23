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
  ostr.open("outImage.pgm");
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
  ostr.open("outImage2.pgm");
  if (ostr.fail()) {
    cout << "Unable to write file\n";
    exit(1);
  };

  ostr << "P2" << endl;
  ostr << w << endl;
  ostr << h << endl;
  ostr << 255 << endl;

  int jo = w/2;
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
    if (col >= w/2){
      ostr << 255 - img[row][col]<< ' ';

    }
      else {
      ostr << img[row][col]<< ' ';

      }
      ostr << endl;
    }
  }
  ostr.close();
  return;
  }



void wbox (std::string input){
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);

  ofstream ostr;
  ostr.open("outImage3.pgm");
  if (ostr.fail()) {
    cout << "Unable to write file\n";
    exit(1);
  };

  ostr << "P2" << endl;
  ostr << w << endl;
  ostr << h << endl;
  ostr << 255 << endl;

  int a;
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
    if ((row >= h/4 && row < 3*h/4) && (col >= w/4 && col < 3* w/4)){


   ostr << 255 << ' ';

}

  else {

    ostr << img[row][col]<< ' ';
  }



    }
  }
  ostr.close();
  return;
  }


  void frame (std::string input){
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);

    ofstream ostr;
    ostr.open("outImage4.pgm");
    if (ostr.fail()) {
      cout << "Unable to write file\n";
      exit(1);
    };

    ostr << "P2" << endl;
    ostr << w << endl;
    ostr << h << endl;
    ostr << 255 << endl;

    int a;
    for(int row = 0; row < h; row++) {
      for(int col = 0; col < w; col++) {

        if(row == h/4 || row == (3*h)/4)
               {
              if(col >=w/4 && col <=(3*w)/4)

                ostr << 255 << ' ';

              else
              ostr << img[row][col]<< ' ';
}

        else if(col == w/4 || col == (3*w)/4)
             {
                 if(row >= h/4 && row <= (3*h)/4)

                    ostr << 255 << ' ';

                 else
                       ostr << img[row][col]<< ' ';

             }
             else{
                   ostr << img[row][col]<< ' ';
}




      }
    }
    ostr.close();
    return;
    }
