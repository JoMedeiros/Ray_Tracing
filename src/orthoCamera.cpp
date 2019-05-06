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
 * @brief Generates rays to ray tracing.
 */
Ray OrthoCamera::generate_ray(float x, float y) {
  Ray r;
  r.set_direction( unit_vector( -w));
  r.set_origin( _origin + x*u + y*v );
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

