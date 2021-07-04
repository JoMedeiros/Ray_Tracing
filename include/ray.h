#ifndef _RAY_H_
#define _RAY_H_

#include "vec3.h"

class Ray
{
private:
	Vec3 A;
	Vec3 B;
public:
	Ray() {}
	
	Ray(const Point3& a, const Vec3&b)
	{ A = a; B = b; }

	Vec3 origin() const
	{ return A; }
	
	Vec3 direction() const
	{ return B; }

  void set_direction(Vec3 v) { B = v; }

  void set_origin(Vec3 v) { A = v; }
	
	/*Vec3 point_at_parameter(float t) 
	{ return A + t*B; }*/

	Vec3 point_at_parameter(float t) const
	{ Vec3 v1 = A; Vec3 v2 = B;
		return v1 + t*v2; }
};
inline ostream & operator << (ostream & os, const Ray ray) {
  os << "ray: [o=" << ray.origin() << ", d=" << ray.direction() << "]";
  return os;
}

#endif
