#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vec3.h"
#include "ray.h"

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
  virtual Ray generate_ray(int x, int y) = 0;
  virtual Ray generate_ray(float x, float y) = 0;
};

class PerspectiveCamera : public Camera {
 public:
  PerspectiveCamera( Point3 origin, Point3 lookat, vec3 vup, int _h, int _w ) :
    Camera( origin, lookat, vup, _h, _w ) {}

  Ray generate_ray(int x, int y);
  Ray generate_ray(float x, float y);
};

class OrthoCamera : public Camera {
 public:
  OrthoCamera( Point3 origin, Point3 lookat, vec3 vup, int _h, int _w ) :
    Camera( origin, lookat, vup, _h, _w ) {}
  Ray generate_ray(int x, int y);
  Ray generate_ray(float x, float y);
};


#endif // _CAMERA_H_
