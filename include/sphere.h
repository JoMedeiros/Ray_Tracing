/**
 * @file	sphere.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	25th Apr 2019
 * 	Last Update:	25th Apr 2019
 */

#ifndef SPHERE_H
#define SPHERE_H

#include <memory>
#include "primitive.h"
#include "vec3.h"
#include "ray.h"
#include "surfaceInteraction.h"

class Sphere : public Shape {
 private:
  Vec3 center;
  float radius;
 public:
  /**
   * @brief Sphere constructor
   */
  Sphere(Vec3 _center, float _radius): center(_center), radius(_radius) {}
  /**
   * @brief Returns true if the ray `r` intersects the sphere and
   * false otherwise. Also initialize the values of SurfaceInteraction
   * pointer `s` for the intersection.
   */
  bool intersect( const Ray& r, SurfaceInteraction *s) const;
  /**
   * @brief Returns true if the ray `r` intersects the sphere and
   * false otherwise
   */
  bool intersect_p( const Ray& r ) const;
};

#endif// SPHERE_H

