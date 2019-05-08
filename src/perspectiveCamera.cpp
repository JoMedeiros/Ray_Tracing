/**
 * @file	perspectiveCamera.cpp
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	5th May 2019
 * 	Last Update:	5th May 2019
 */
#include "perspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera( Point3 origin, Point3 lookat, 
    Vec3 vup, double fovy, double aspect_ratio, double fd) : 
    Camera( origin, lookat, vup, 400, 600 ), fdist(fd) 
{
  w = unit_vector(origin - lookat);
  u = unit_vector(cross(vup, w));
  v = cross(w, u);

  double theta = fovy * M_PI;
  double mid_height = tan(theta / 2);
  double mid_width = aspect_ratio * mid_height;
  lower_left_corner = origin - (mid_width * fd * u);
}

Ray PerspectiveCamera::generate_ray(int x, int y) {
  Ray r;
  r.set_direction( 
      unit_vector( 
        lower_left_corner + (-fdist*w + x*u + y*v )));
  r.set_origin( _origin );
  return r;
}

Ray PerspectiveCamera::generate_ray(float x, float y) {
  Ray r;
  r.set_direction( 
      unit_vector( 
       lower_left_corner + (-fdist*w + x*u + y*v )));
  r.set_origin( _origin );
  return r;
}

