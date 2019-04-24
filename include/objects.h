#ifndef _OBJECTS_HPP_
#define _OBJECTS_HPP_

#include <memory>
#include "vec3.h"
#include "ray.h"

class SurfaceInteraction;
class Material {};

/**
 * @brief Abstract class to derive objects.
 */
class Primitive {
 public:
  virtual ~Primitive();
  virtual bool intersect( const Ray& r, SurfaceInteraction *) const = 0;
  // Simpler & faster version of intersection that only return true/false.
  // It does not compute the hit point information.
  virtual bool intersect_p( const Ray& r ) const = 0;
  virtual const shared_ptr<Material> get_material(void) const { return material; }
 private:
  std::shared_ptr<Material> material;
};

/**
 * @brief Class to store infromations about a intersection of an object with a ray
 */
class SurfaceInteraction {
public:
    SurfaceInteraction(const Point3&p,const Vec3&n, const Vec3&wo, float time, const Point2f& uv, const Primitive *pri )
        : p{p}, n{n}, wo{wo}, time{time}, uv{uv}, primitive{pri}{};

    Point3 p; // Contact point.
    Vec3 n; // The surface normal.
    Vec3 wo; // Outgoing direction of light, which is -ray.
    float time; // Time of contact.
    Point2f uv; // Parametric coordinate (u,v) of the hit surface.
    const Primitive *primitive=nullptr; // Point3er to the primitive.
};


class Sphere : public Primitive {
 private:
  Vec3 center;
  float radius;
  /**
   * @brief Returns the t param, the distance from ray's origin and 
   * intersection point
   */
 public:
  /**
   * @brief Sphere constructor
   */
  Sphere(Vec3 _center, float _radius): center(_center), radius(_radius) {}
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


#endif// _OBJECTS_HPP_
