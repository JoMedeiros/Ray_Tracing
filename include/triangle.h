/**@file	include/triangle.h
 * @author	josivanmedeiros
 * @version	1
 * @date
 * 	Created:	12th May 2019
 * 	Last Update:	12th May 2019
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "vec3.h"
#include "shape.h"

class Triangle : public Shape {
  public:
    /**
     * @brief Triangle class constructor
     */
    Triangle(Vec3 p0, Vec3 p1, Vec3 p2){
      v0 = p0;
      v1 = p1;
      v2 = p2;
    }
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
    virtual bool intersect( const Ray& r, SurfaceInteraction *s) 
      const;
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
    virtual bool intersect_p( const Ray& r ) const;
  private:
    Vec3 v0;
    Vec3 v1;
    Vec3 v2;
};

#endif
