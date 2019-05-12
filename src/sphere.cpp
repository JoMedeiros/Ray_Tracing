#include "sphere.h"

bool Sphere::intersect( const Ray& r, SurfaceInteraction *s) const {
  Vec3 oc = r.origin() - center;
  float a = dot(r.direction(), r.direction());
  float b = 2*dot(oc, r.direction());
  float c = dot(oc, oc) - radius*radius;
  float D = b*b - 4*a*c;
  if (D < 0)
    return false;
  float t = (-b - sqrt(D)) / (2.0*a);
  Point3 p = r.origin() + t*r.direction();
  Point3 n = unit_vector(p - center);
  // *s = SurfaceInteraction(p, n, -(r.direction()), 0.0, Point2f(0,0), pt);
  s->n = n;
  s->p = p;
  s->wo = -r.direction();
  s->primitive = this;
  // cout << "Normal: " << s->n << "\n";
  return (t >= 0);
}
/**
 * @breif
 * Simpler & faster version of intersection that only return true/false.
 * It does not compute the hit point information.
 */
bool Sphere::intersect_p( const Ray& r ) const {
  Vec3 oc = r.origin() - center;
  float a = dot(r.direction(), r.direction());
  float b = dot(oc, r.direction());
  float c = dot(oc, oc) - radius*radius;
  float D = b*b - a*c;
  if (D < 0)
    return false;
  float t = (-b - sqrt(D)) / (2.0*a);
  return (t >= 0);
}

Vec3 color(const Ray& r) {
  Sphere s( Vec3(0,0,-1), 5 );
	// float t = s.hit( r );
	//float t = hit_sphere(Vec3(0,0,-1), 5, r);
	// if (t > 0.0) {
	// 	Vec3 N = unit_vector( r.point_at_parameter(t) - Vec3(0,0,-1));
	// 	return 0.5*Vec3(N.x()+1, N.y()+1,	N.z()+1);
	// }
  //else {
  //  return (Color(-1,-1,-1));
  //}
	//if (hit_sphere(Vec3(0,0,-1), 0.5, r))
	//	return Vec3(1, 0, 0);

	Vec3 unit_direction = 
	unit_vector(r.direction());
	
	double t = 0.5 *
	(unit_direction.y() + 1.0);
	
	return (1.0-t)*Vec3(1.0, 1.0, 1.0)
	+ t*Vec3(0.5, 0.7, 1.0);
}

