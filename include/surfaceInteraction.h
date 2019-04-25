/**@file	include/surfaceInteraction.h
 * @author	josivanmedeiros
 * @version	1
 * @date
 * 	Created:	25th Apr 2019
 * 	Last Update:	25th Apr 2019
 */

#ifndef _SURFACE_INTERACTION_H_
#define _SURFACE_INTERACTION_H_

#include "vec3.h"

class Primitive;

/**
 * @brief Class to store infromations about a intersection of an object with
 * a ray
 */
class SurfaceInteraction {
public:
  SurfaceInteraction(const Point3&p,const Vec3&n, const Vec3&wo, float time, 
      const Point2f& uv, const Primitive *pri );

  Point3 p; // Contact point.
  Vec3 n; // The surface normal.
  Vec3 wo; // Outgoing direction of light, which is -ray.
  float time; // Time of contact.
  Point2f uv; // Parametric coordinate (u,v) of the hit surface.
  const Primitive *primitive=nullptr; // Pointer to the primitive.
};

#endif // _SURFACE_INTERACTION_H_
