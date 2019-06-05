/**
 * @file	primitive.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created: 25 apr 2019
 *  Last Update: 30 mai 2019 (08:38:32)
 */

#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "ray.h"
#include "surfaceInteraction.h"
#include "material.h"
#include "shape.h"
#include <memory>

/**
 * @brief Abstract class to derive objects.
 */
class Primitive {
  public:
    virtual ~Primitive(){};
    /**
     * @brief Verify if a ray intersects the primitive and fill
     * a pointer to a SurfaceInteraction with informations about
     * the first hit.
     *
     * @param r
     * @param s
     *
     * @return 
     */
    virtual bool intersect( const Ray& r, SurfaceInteraction *s) 
      const = 0;
    /**
     * @brief Simpler & faster version of intersection that only 
     * returns true/false. It does not compute the hit point 
     * information.
     *
     * @param r
     *
     * @return 
     */
    virtual bool intersect_p( const Ray& r ) const = 0;
    /**
     * @brief Sets the primitive material.
     *
     * @param mat
     */
    void set_material(shared_ptr<Material> mat) {
      material = mat;
    }
    const shared_ptr<Material> get_material() const 
    { return material; }
  private:
    shared_ptr<Material> material;
};

#endif //PRIMITIVE_H

