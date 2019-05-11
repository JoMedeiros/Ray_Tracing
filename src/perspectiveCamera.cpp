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
    Vec3 vup, float fovy, float aspect_ratio, float fd) : 
    Camera( origin, lookat, vup, 400, 600 ), fdist(fd) {
  _origin = origin;
  _lookat = lookat;
  w = unit_vector( origin - lookat );
  u = unit_vector( cross( vup, w ) );
  v = unit_vector( cross( w, u ) );

  float theta = fovy * M_PI / 180;
  float hh = tan(theta / 2) * fd; // half hight of the screen
  cout << "Half Height: " << hh << "\n";
  float hw = aspect_ratio * hh; // half width of the screen
  cout << "Half Width: " << hw << "\n";
  lower_left_corner = origin  - fd*w  - hw*u - hh*v;

  cout << "LLC: " << lower_left_corner << "\n";
  // llc + horizontal = lower right corner
  horizontal = 2*hw*u; // Total horizontal vector
  // llc + vertical = top left corner
  vertical = 2*hh*v; // Total vertical vector
}

Ray PerspectiveCamera::generate_ray(int x, int y) {
  Ray r;
  r.set_direction( 
      // unit_vector( -(fdist)*w+ x*u+y*v));
      unit_vector( lower_left_corner + x*u + y*v ));
  r.set_origin( _origin );
  return r;
}

Ray PerspectiveCamera::generate_ray(float x, float y) {
  Ray r;
  r.set_direction( 
      // unit_vector( (lower_left_corner + x*horizontal - y*vertical) - _origin));
      unit_vector( -(fdist)*w+ (x-0.5)*horizontal-(y-0.5)*vertical));
  r.set_origin( _origin );
  return r;
}

