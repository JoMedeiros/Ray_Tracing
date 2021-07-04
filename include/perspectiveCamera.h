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
  Point3 lower_left_corner;
  Vec3 horizontal;
  Vec3 vertical;
 public:
  PerspectiveCamera( Point3 origin, Point3 lookat, 
  Vec3 vup, float fovy, float aspect_ratio, float fd);

  Ray generate_ray(int x, int y);
  Ray generate_ray(float x, float y);
};


#endif //PERSPECTIVE_CAMERA_H

