/**
 * @file  shape.h
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  28 mai 2019
 *  Last Update: 03 jun 2019 (17:26:39)
 */
#ifndef SHAPE_H
#define SHAPE_H

#include "ray.h"
#include "surfaceInteraction.h"

class Shape {
  public:
    virtual ~Shape() = default;
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
    virtual bool intersect( const Ray& r, SurfaceInteraction *s) const = 0;
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
    virtual bool intersect_p( const Ray& r ) const = 0;
};

#endif // SHAPE_H

