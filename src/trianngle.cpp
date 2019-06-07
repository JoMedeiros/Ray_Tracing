/**
 * @file  trianngle.cpp
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  03 jun 2019
 *  Last Update: 07 jun 2019 (16:11:18)
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
bool Triangle::intersect( const Ray& r, SurfaceInteraction *s) const 
{
  float epsilon = 0.000001, det, inv_det;
  float u, v, t;
  Vec3 edge1 = v1 - v0;
  Vec3 edge2 = v2 - v0;
  Vec3 N = unit_vector( cross(edge1, edge2));
  s->n = N;
  //cout << N << "\n";
  Vec3 pvec = cross(r.direction(), edge2);

  det = dot(edge1, pvec);
  if (culling) {
    cout << "culling on\n";
    if (det < epsilon)
      return false;
    Vec3 tvec = r.origin() - v0;
    u = dot(tvec, pvec);
    if (u < 0.0 or u > det )
      return false;
    Vec3 qvec = cross(tvec, edge1);
    v = dot(r.direction(), qvec);
    if (v < 0.0 or u + v > det)
      return false;
    t = dot(edge2, qvec);
    inv_det = 1.0 / det;
    t *= inv_det;
    u *= inv_det;
    v *= inv_det;
  }
  else {
    if (det > -epsilon and det < epsilon)
      return false;
    inv_det = 1.0 / det;
    Vec3 tvec = r.origin() - v0;
    u = dot(tvec, pvec) * inv_det;
    if (u < 0.0 or u > 1.0)
      return false;
    Vec3 qvec = cross(tvec, edge1);
    v = dot(r.direction(), qvec) * inv_det;
    if (v < 0.0 or u + v > 1.0)
      return false;
    t  = dot(edge2, qvec) * inv_det;
    if (t < 0) return false;
  }
  Vec3 P = (1.0 - u - v)*v0 + u*v1 + v*v2;
  s->p = P;
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
bool Triangle::intersect_p( const Ray& r ) const 
{
  float epsilon = 0.000001, det, inv_det;
  float u, v, t;
  Vec3 edge1 = v1 - v0;
  Vec3 edge2 = v2 - v0;
  Vec3 pvec = cross(r.direction(), edge2);

  det = dot(edge1, pvec);
  if (culling) {
    if (det < epsilon)
      return false;
    Vec3 tvec = r.origin() - v0;
    u = dot(tvec, pvec);
    if (u < 0.0 or u > det )
      return false;
    Vec3 qvec = cross(tvec, edge1);
    v = dot(r.direction(), qvec);
    if (v < 0.0 or u + v > det)
      return false;
    t = dot(edge2, qvec);
    inv_det = 1.0 / det;
    t *= inv_det;
    u *= inv_det;
    v *= inv_det;
  }
  else {
    if (det > -epsilon and det < epsilon)
      return false;
    inv_det = 1.0 / det;
    Vec3 tvec = r.origin() - v0;
    u = dot(tvec, pvec) * inv_det;
    if (u < 0.0 or u > 1.0)
      return false;
    Vec3 qvec = cross(tvec, edge1);
    v = dot(r.direction(), qvec) * inv_det;
    if (v < 0.0 or u + v > 1.0)
      return false;
    t  = dot(edge2, qvec) * inv_det;
    if (t < 0) return false;
  }
  return true;
}

