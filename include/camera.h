/**
 * @file	camera.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	5th May 2019
 * 	Last Update:	5th May 2019
 */
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vec3.h"
#include "ray.h"

/**
 * @brief Definition of abstract class Camera.
 */
class Camera
{
 protected:
  int _height;
  int _width;
  Point3 _origin;
  Point3 _lookat;
  Vec3 _vup;
  Vec3 u, v, w;
 public:
  Camera( Point3 origin, Point3 lookat, Vec3 vup, int _h, int _w );
  //virtual ~Camera(){};
  // Getters
  int height() { return _height; }
  int width() { return _width; }
  // Setters
  void set_height(int h) { _height = h; }
  void set_width(int w) { _width = w; }
  Vec3 get_u() { return u; }
  Vec3 get_v() { return v; }
  Vec3 get_w() { return w; }
  virtual Ray generate_ray(int x, int y) = 0;
  virtual Ray generate_ray(float x, float y) = 0;
};

#endif // _CAMERA_H_

