#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include <vector>
#include "vec3.hpp"
//#include "utils.hpp"

using namespace std;

class Background
{
private:
	unsigned char*** p; // Pixel matrix
  int height;
  int width;
  //void alocate_matrix() {}
public:
  // Setters & getters
  int get_height() const {return height;}
  int get_width() const {return width;}
	Background(int height, int width, Color c=Color(0,0,0)) {
    this->height = height;
    this->width = width;
    p = new unsigned char**[height];
    for (int i=0; i < height; ++i) {
      p[i] = new unsigned char*[width];
      for (int j=0; j < width; ++j) {
        p[i][j] = new unsigned char[3];
        p[i][j][RED] = c[RED];
        p[i][j][GREEN] = c[GREEN];
        p[i][j][BLUE] = c[BLUE];
      }
    }
  }
	Background(int height, int width, Color c00, Color c01, Color c10, Color c11) :
    Background(height, width) {
    Color dy1 = (c10 - c00) / (float) height;
    Color dy2 = (c11 - c01) / (float) height;
    for (int i=0; i < height; ++i) {
      Color cy1 = c00 + i * dy1;
      Color cy2 = c01 + i * dy2;
      Color dx = (cy2 - cy1) / width;
      for (int j=0; j < width; ++j) {
        // @TODO Calculate color
        Color c = cy1 + j * dx;
        p[i][j][RED] = c[RED];
        p[i][j][GREEN] = c[GREEN];
        p[i][j][BLUE] = c[BLUE];
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

	inline unsigned char** operator[](int i) const 
	{ return p[i]; }
	inline unsigned char**& operator[](int i) 
	{ return p[i]; }

};

#endif // _BACKGROUND_H_
