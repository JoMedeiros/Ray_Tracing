/**
 * @file	primitive.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	25th Apr 2019
 * 	Last Update:	25th Apr 2019
 */

#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "ray.h"
#include "surfaceInteraction.h"
#include "material.h"
#include <memory>

/**
 * @brief Abstract class to derive objects.
 */
class Primitive {
 public:
  virtual ~Primitive(){};
  virtual bool intersect( const Ray& r, SurfaceInteraction *) const = 0;
  // Simpler & faster version of intersection that only return true/false.
  // It does not compute the hit point information.
  virtual bool intersect_p( const Ray& r ) const = 0;
  const shared_ptr<Material> get_material(void) const 
  { return material; }
 private:
  std::shared_ptr<Material> material;
};

#endif // _PRIMITIVE_H_

