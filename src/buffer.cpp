/**
 * @file  buffer.cpp
 * @brief Implementation of Buffer class methods.
 *
 * @author  Josivan Medeiros da Silva Gois
 * @date  31/03/2019
 */
#include "buffer.h"
#include "cstdlib"

Buffer::Buffer(int height, int width) {
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

Buffer::Buffer(Buffer & other) {
  this->_height = other._height;
  this->_width = other._width;
  p = (pixel_type*) realloc(p, (_height*_width*3)*sizeof(pixel_type));
  for (int i=0; i < _height; ++i) {
    for (int j=0; j < _width; ++j) {
      p[3*(i*_width + j) + RED] = 55;
      p[3*(i*_width + j) + GREEN] = 155;
      p[3*(i*_width + j) + BLUE] = 255;
    }
  }
}

void Buffer::paint(int x, int y, Color color) {
  p[3*(x*_width +y) + RED] = color[RED];
  p[3*(x*_width +y) + GREEN] = color[GREEN];
  p[3*(x*_width +y) + BLUE] = color[BLUE];
}

Color Buffer::get_color(int x, int y) {
  Color color;
  color[RED] = p[3*(x*_width + y) + RED];
  color[GREEN] = p[3*(x*_width + y) + GREEN];
  color[BLUE] = p[3*(x*_width + y) + BLUE];
  return color;
}

