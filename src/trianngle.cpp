/**
 * @file  trianngle.cpp
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  03 jun 2019
 *  Last Update: 04 jun 2019 (07:49:06)
 */
#include "triangle.h"

/**
 * @brief Calls the intersection function of the shape.
 *
 * @param r The ray to intersect the shape.
 * @param s A class to store informations about the intersection
 * if it exists.
 *
 * @return True if the ray intersects the object, false 
 * otherwise.
 */
bool Triangle::intersect( const Ray& r, SurfaceInteraction *s) 
  const{
    Vec3 v = v1 - v0;
    Vec3 u = v2 - v1;
    Vec3 n = cross(v, u);
    float Area = n.length();
    float t;// the t parameter for the ray
    Point3 p0 = v0;
    Point3 l0 = r.origin();
    Point3 l = r.direction();
    t = dot((p0 - l0), n) / dot(l, n);
    Point3 P = r.origin() + t*r.direction();
    float x = cross((P-v0),(P-v1)).length() / Area;
    if (x < 0.0f ) return false;
    float y = cross((P-v1),(P-v2)).length() / Area;
    if (y < 0.0f ) return false;
    float z = cross((P-v2),(P-v0)).length() / Area;
    if (z < 0.0f ) return false;
    
    s->p = P;
    s->n = unit_vector(n);
    return true;
}
/**
 * @brief Simpler & faster version of intersection that only 
 * return true/false. It does not compute the hit point 
 * information
 *
 * @param r The ray to intersect the shape.
 *
 * @return True if the ray intersects the object, false 
 * otherwise.
 */
bool Triangle::intersect_p( const Ray& r ) const {
    Vec3 v = v1 - v0;
    Vec3 u = v2 - v1;
    Vec3 n = cross(v, u);
    float Area = n.length();
    float t;// the t parameter for the ray
    Point3 p0 = v0;
    Point3 l0 = r.origin();
    Point3 l = r.direction();
    t = dot((p0 - l0), n) / dot(l, n);
    Point3 P = r.origin() + t*r.direction();
    float x = cross((P-v0),(P-v1)).length() / Area;
    if (x < 0.0f ) return false;
    float y = cross((P-v1),(P-v2)).length() / Area;
    if (y < 0.0f ) return false;
    float z = cross((P-v2),(P-v0)).length() / Area;
    if (z < 0.0f ) return false;
    
    return true;
}

