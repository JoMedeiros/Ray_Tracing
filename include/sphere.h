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

class Sphere : public Primitive {
 private:
  Vec3 center;
  float radius;
 public:
  /**
   * @brief Sphere constructor
   */
  Sphere(Vec3 _center, float _radius): center(_center), radius(_radius) {}
  /**
   * @brief Returns the t param, the distance from ray's origin and 
   * intersection point
   */
  float hit(const Ray& r) {
    Vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = 2.0 * dot(oc, r.direction());
    float c = dot(oc, oc) - radius*radius;
    float D = b*b - 4*a*c;
    if (D < 0)
      return -1.0;
    else
      return (-b - sqrt(D)) / (2.0*a);
  }
};

#endif// SPHERE_H

