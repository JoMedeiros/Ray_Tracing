#include "camera.h"

Camera::Camera( Point3 origin, Point3 lookat, Vec3 vup, int _h, int _w )
: _height(_h), _width(_w), _origin(origin), _lookat(lookat), _vup(vup) {
  Vec3 gaze = lookat - origin;
  w = unit_vector(-gaze);
  u = unit_vector( cross( vup, w ) );
  v = unit_vector( cross( w, u ) );
}

Ray OrthoCamera::generate_ray(int x, int y) {
  Ray r;
  r.set_direction(-w);
  r.set_origin( _origin + x*u + y*v );
  return r;
}

Ray OrthoCamera::generate_ray(float x, float y) {
  Ray r;
  r.set_direction(-w);
  r.set_origin( _origin + x*u + y*v );
  return r;
}

Ray PerspectiveCamera::generate_ray(int x, int y) {
  Ray r;
  r.set_direction( -fdist*w + x*u + y*v );
  r.set_origin( _origin );
  return r;
}

Ray PerspectiveCamera::generate_ray(float x, float y) {
  Ray r;
  r.set_direction( -fdist*w + x*u + y*v );
  r.set_origin( _origin );
  return r;
}

