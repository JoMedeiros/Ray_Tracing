#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vec3.h"

class Camera
{
 private:
  int _height;
  int _width;
  Point3 origin;
  Point3 lower_left_corner;
  vec3 horizontal, vertical;
  vec3 u, v, w;
 public:
  Camera(int _h, int _w) : _height(_h),_width(_w){}
  int height() { return _height; }
  int width() { return _width; }
};

#endif // _CAMERA_H_
