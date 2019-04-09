#include "camera.h"

Camera::Camera( Point3 origin, Point3 lookat, vec3 vup, int _h, int _w )
{
  _width = _w;
  _height = _h;
  _origin = origin;
  _lookat = lookat;
  _vup = vup;
}

Ray OrthoCamera::generate_ray(int x, int y) {
  // @TODO
}

Ray OrthoCamera::generate_ray(float x, float y) {
  // @TODO
}

Ray PerspectiveCamera::generate_ray(int x, int y) {
  // @TODO
}

Ray PerspectiveCamera::generate_ray(float x, float y) {
  // @TODO
}

