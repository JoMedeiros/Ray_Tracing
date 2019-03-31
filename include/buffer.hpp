#ifndef _BUFFER_H_
#define _BUFFER_H_

#include <vector>
#include "vec3.hpp"

using namespace std;
typedef unsigned char pixel_type;

class Buffer
{
private:
	pixel_type* p; // Pixel matrix
  int _height;
  int _width;
public:
  // Setters & getters
  int height() const { return _height; }
  int width() const { return _width; }
  pixel_type* data() { return p; }
  // Constructors
	Buffer(int height, int width) {
    this->_height = height;
    this->_width = width;
    p = new pixel_type[height*height*3];
    for (int i=0; i < height; ++i) {
      for (int j=0; j < width; ++j) {
        p[3*(i*width + j) + RED] = 55;
        p[3*(i*width + j) + GREEN] = 155;
        p[3*(i*width + j) + BLUE] = 255;
      }
    }
  }
  // @TODO Constructor with image as param
  // Use a library to open, resize images
	inline pixel_type operator[](int i) const 
	{ return p[i*_height]; }
	inline pixel_type& operator[](int i) 
	{ return p[i*_height]; }
};

#endif // _BUFFER_H_
