/**
 * @file	perspectiveCamera.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	5th May 2019
 * 	Last Update:	5th May 2019
 */
#ifndef PERSPECTIVE_CAMERA_H
#define PERSPECTIVE_CAMERA_H

#include "camera.h"
#include <cmath>

/**
 * @brief Definition of perspective camera class.
 */
class PerspectiveCamera : public Camera {
 private:
  float fdist;
  Point3 _lower_left_corner;
 public:
  PerspectiveCamera( Point3 origin, Point3 lookat, 
    Vec3 vup, double fovy, double aspect_ratio, double fd);
  PerspectiveCamera( Point3 origin, Point3 lookat, Vec3 vup, int _h, int _w, 
      float fd) : Camera( origin, lookat, vup, _h, _w ), fdist(fd) { }

  Ray generate_ray(int x, int y);
  Ray generate_ray(float x, float y);
};


#endif //PERSPECTIVE_CAMERA_H

