#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include <array>
#include "utils.hpp"

using namespace std;

class background
{
private:
	array<array<unsigned char>> p; // Pixel matrix
  array<Color> corners;
public:
	background(int height, int width, Color c) {
    //@TODO
  }
	background(int height, int width, Color c00, Color c01, Color c10, Color c11){
    //@TODO
  }
	vec3(float e0, float e1, float e2) : 
	e{e0,e1,e2} {}

	inline float operator[](int i) const 
	{ return p[i]; }
	inline float& operator[](int i) 
	{ return p[i]; }

};

#endif // _BACKGROUND_H_
