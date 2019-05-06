#include "camera.h"

Camera::Camera( Point3 origin, Point3 lookat, Vec3 vup, int _h, int _w )
: _height(_h), _width(_w), _origin(origin), _lookat(lookat), _vup(vup) {
  Vec3 gaze = lookat - origin;
  w = unit_vector(-gaze);
  u = unit_vector( cross( vup, w ) );
  v = unit_vector( cross( w, u ) );
  // @TODO Set lower_left_corner
  lower_left_corner = (_lookat - (_width/2.0)*u) - (_height/2.0)*v;
}

// @TODO sum lower_left_corner to origin in ortho camera


