/**
 * @file  geometricPrimitive.h
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  30 mai 2019
 *  Last Update: 30 mai 2019 (14:30:31)
 */
#ifndef GEOMETRIC_PRIMITIVE_H
#define GEOMETRIC_PRIMITIVE_H

#include "primitive.h"
#include "shape.h"

class GeometricPrimitive : public Primitive {
  private:
    unique_ptr<Shape> shape;
    /**
     * @brief Verify if a ray intersects the primitive and fill
     * a pointer to a SurfaceInteraction with informations about
     * the first hit.
     *
     * @param r
     * @param s
     *
     * @return True if the ray intersects the primitive, false 
     * otherwise
     */
    virtual bool intersect( const Ray& r, SurfaceInteraction *s) 
      const;
    /**
     * @brief Simpler & faster version of intersection that only 
     * returns true/false. It does not compute the hit point 
     * information.
     *
     * @param r
     *
     * @return True if the ray intersects the primitive, false 
     * otherwise
     */
    virtual bool intersect_p( const Ray& r ) const;
};

#endif //GEOMETRIC_PRIMITIVE_H

