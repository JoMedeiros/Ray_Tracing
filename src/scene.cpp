/**
 * @file	scene.cpp
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	15th May 2019
 * 	Last Update:	15th May 2019
 */
#include "scene.h"

/**
 * @brief calculate intersection of a ray for every primitive
 * in the scene and initialize `isect` with the nearest hit
 */
bool Scene::intersect( const Ray& r, SurfaceInteraction *isect ) const {
  float nearest = 2<<24;// Should be infinite
  for ( Primitive* const &p : this->primitives ) {
    SurfaceInteraction* s = new SurfaceInteraction();
    bool hit = p->intersect( r, s );
    if ( hit ){
      float dist = (s->p - r.origin()).length();
      if (dist < nearest ) {
        nearest = dist;
        isect = s;
      }
    }
  }
  if (nearest < 2<<24) return true;
  return false;
}
/**
 * @brief A faster version that only determines whether there is 
 * an intersection or not. It doesn't calculate the intersection 
 * info.
 */
bool Scene::intersect_p( const Ray& r ) const {
  for ( Primitive*const &p : this->primitives ) {
    if ( p->intersect_p( r ) ) return true;
  }
  return false;
}

