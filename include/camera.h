#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vec3.h"

enum CamType {ORTHO, PERSP};
class Camera
{
 private:
  int _height;
  int _width;
  CamType type;
  Point3 _origin;
  Point3 _lookat;
  Point3 lower_left_corner;
  vec3 horizontal, vertical, _vup;
  vec3 u, v, w;
 public:
  Camera( Point3 origin, Point3 lookat, vec3 vup, int _h, int _w );
  int height() { return _height; }
  int width() { return _width; }
};

#endif // _CAMERA_H_
