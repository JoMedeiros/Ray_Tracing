#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include <vector>
#include "vec3.hpp"
//#include "utils.hpp"

// @TODO Constructor with image as param
// Use a library to open, resize images: STD_IMAGE
using namespace std;

class Background
{
private:
  Color c00;
  Color c01;
  Color c10;
  Color c11;
public:
	Background( Color c ) : c00(c), c01(c), c10(c), c11(c) { }
	Background( Color c00, Color c01, Color c10, Color c11 ) {
    this->c00 = c00;
    this->c01 = c01;
    this->c10 = c10;
    this->c11 = c11;
  }
  Color sample( float u, float v ) {
    Color cy1 = c00 + v*(c10-c00);
    Color cy2 = c01 + v*(c11-c01);
    Color c = cy1 + u*(cy2-cy1);
    return c;
  }
};

#endif // _BACKGROUND_H_
