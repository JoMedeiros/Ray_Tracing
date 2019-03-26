#ifndef _BUFFER_H_
#define _BUFFER_H_

#include <vector>
#include "vec3.hpp"

using namespace std;

class Buffer
{
private:
	unsigned char*** p; // Pixel matrix
  int height;
  int width;
  //void alocate_matrix() {}
public:
  // Setters & getters
  int height() const {return height;}
  int width() const {return width;}
  // Constructors
	Buffer(int height, int width) {
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
  // @TODO Constructor with image as param
  // Use a library to open, resize images
	inline unsigned char** operator[](int i) const 
	{ return p[i]; }
	inline unsigned char**& operator[](int i) 
	{ return p[i]; }
};

#endif // _BUFFER_H_
