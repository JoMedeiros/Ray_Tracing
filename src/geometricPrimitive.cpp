/**
 * @file  geometricPrimitive.cpp
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  30 mai 2019
 *  Last Update: 05 jun 2019 (10:49:56)
 */
#include "geometricPrimitive.h"

/**
 * @brief Verify if a ray intersects the primitive and fill
 * a pointer to a SurfaceInteraction with informations about
 * the first hit.
 *
 * @param r
 * @param s
 *
 * @return True if the ray intersects the primitive, false otherwise
 */
bool GeometricPrimitive::intersect( const Ray& r, SurfaceInteraction *s) const {
  bool hit = this->_shape->intersect(r, s);
  if (hit) s->primitive = this;
  return hit;
}
/**
 * @brief Simpler & faster version of intersection that only 
 * returns true/false. It does not compute the hit point 
 * information.
 *
 * @param r
 *
 * @return True if the ray intersects the primitive, false otherwise
 */
bool GeometricPrimitive::intersect_p( const Ray& r ) const {
  return this->_shape->intersect_p(r);
}

