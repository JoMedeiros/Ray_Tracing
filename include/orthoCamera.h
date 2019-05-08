/**
 * @file	orthoCamera.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	5th May 2019
 * 	Last Update:	5th May 2019
 */
#ifndef ORTHO_CAMERA_H
#define ORTHO_CAMERA_H

#include "camera.h"

class OrthoCamera : public Camera {
 private:
   double _left;
   double _right;
   double _bottom;
   double _top;
 public:
  OrthoCamera( Point3 origin, Point3 lookat, Vec3 vup, double left, double right, 
      double bottom, double top );
  Ray generate_ray(int x, int y);
  Ray generate_ray(float x, float y);
};

#endif //ORTHO_CAMERA_H

