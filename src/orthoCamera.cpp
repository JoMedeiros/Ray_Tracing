/**
 * @file	orthoCamera.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	5th May 2019
 * 	Last Update:	5th May 2019
 */
#include "orthoCamera.h"

/**
 * @brief Class constructor
 */
OrthoCamera::OrthoCamera( Point3 origin, Point3 lookat, Vec3 vup, double left, 
  double right, double bottom, double top ) : 
  Camera( origin, lookat, vup, right - left, top - bottom ), _left(left), _right(right), 
  _bottom(bottom), _top(top) 
{ /* Empty */ }

/**
 * @brief Generates rays to ray tracing.
 */
Ray OrthoCamera::generate_ray(float x, float y) {
  x = _left + (_right - _left) * x;
  y = _bottom + (_top - _bottom) * (1- y);
  Vec3 o = _origin + x * this->u + y * this->v;
  Ray r;
  r.set_direction( unit_vector( -w ) );
  r.set_origin( o );
  return r;
}

/**
 * @brief Generates rays to ray tracing.
 */
Ray OrthoCamera::generate_ray(int x, int y) {
  Ray r;
  r.set_direction( unit_vector( -w));
  r.set_origin( _origin + x*u + y*v );
  return r;
}

