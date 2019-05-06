/**
 * @file	perspectiveCamera.cpp
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	5th May 2019
 * 	Last Update:	5th May 2019
 */
#include "perspectiveCamera.h"

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

