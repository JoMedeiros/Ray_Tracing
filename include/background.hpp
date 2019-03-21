#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include <vector>
#include "utils.hpp"

using namespace std;

class Background
{
private:
	unsigned char*** p; // Pixel matrix
  int height;
  int width;
  //void alocate_matrix() {}
public:
	Background(int height, int width, Color c=Color(0,0,0)) {
    p = new unsigned char**[height];
    for (int i=0; i < height; ++i) {
      p[i] = new unsigned char*[width];
      for (int j=0; j < width; ++j) {
        p[i][j] = new unsigned char[3];
        p[i][j][RED] = c.r;
        p[i][j][GREEN] = c.g;
        p[i][j][BLUE] = c.b;
      }
    }
  }
  // @TODO Constructor with image as param
  // Use a library to open, resize images
  ~Background(){
    for (int i=0; i < height; ++i) {
      for (int j=0; j < width; ++j) {
        delete[] p[i][j];
      }
      delete[] p[i];
    }
  }
	Background(int height, int width, Color c00, Color c01, Color c10, Color c11){
    Background(height, width);
    for (int i=0; i < height; ++i) {
      for (int j=0; j < width; ++j) {
        // @TODO Calculate color
      }
    }
  }

	inline unsigned char** operator[](int i) const 
	{ return p[i]; }
	inline unsigned char**& operator[](int i) 
	{ return p[i]; }

};

#endif // _BACKGROUND_H_
