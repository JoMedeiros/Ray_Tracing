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

class Triangle {
  public:
    /**
     * @brief Triangle class constructor
     */
    Triangle(Vec3 p0, Vec3 p1, Vec3 p2){
      v0 = p0;
      v1 = p1;
      v2 = p2;
    }
  private:
    Vec3 v0;
    Vec3 v1;
    Vec3 v2;
};

#endif
