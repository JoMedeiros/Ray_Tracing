#ifndef _OBJECTS_HPP_
#define _OBJECTS_HPP_

#include "vec3.h"
#include "ray.h"

class Object {
 private:
  //Bounding Box
 public:
  Object(){}
};

class Sphere : public Object {
 private:
  vec3 center;
  float radius;
  /**
   * @brief Returns the t param, the distance from ray's origin and 
   * intersection point
   */
  float hit(const Ray& r) {
    vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = 2.0 * dot(oc, r.direction());
    float c = dot(oc, oc) - radius*radius;
    float D = b*b - 4*a*c;
    if (D < 0)
      return -1.0;
    else
      return (-b - sqrt(D)) / (2.0*a);
  }

 public:
  /**
   * @brief Sphere constructor
   */
  Sphere(vec3 _center, float _radius): center(_center), radius(_radius) {}
};

// @TODO Put this function inside Sphere object
float hit_sphere(const vec3& center, float radius, const Ray& r) {
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0 * dot(oc, r.direction());
	float c = dot(oc, oc) - radius*radius;
	float D = b*b - 4*a*c;
	if (D < 0)
		return -1.0;
	else
		return (-b - sqrt(D)) / (2.0*a);
}

vec3 color(const Ray& r) {
	float t = hit_sphere(vec3(0,0,-1), 0.5, r);
	if (t > 0.0) {
		vec3 N = unit_vector(
			r.point_at_parameter(t) - 
			vec3(0,0,-1));
		return 0.5*vec3(N.x()+1, 
			N.y()+1,
			N.z()+1);
	}
  else {
    return (Color(-1,-1,-1));
  }
	//if (hit_sphere(vec3(0,0,-1), 0.5, r))
	//	return vec3(1, 0, 0);

	vec3 unit_direction = 
	unit_vector(r.direction());
	
	t = 0.5 *
	(unit_direction.y() + 1.0);
	
	return (1.0-t)*vec3(1.0, 1.0, 1.0)
	+ t*vec3(0.5, 0.7, 1.0);
}

#endif// _OBJECTS_HPP_
