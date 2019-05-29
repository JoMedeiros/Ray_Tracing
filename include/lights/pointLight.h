/**
 * @file  pointLight.h
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  27 mai 2019
 *  Last Update: 29 mai 2019 (14:24:03)
 */
#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "light.h"

class PointLight : public Light {
  private:
    Point3 _origin;
  public:
    PointLight(Point3 origin, Color intensity=Color(1,1,1)) : 
      Light(intensity), _origin(origin) {}
    Ray generate_ray(Point3 p) {
      Ray r (p, _origin - p);
      return r;
    }
    Point3 origin(){ return _origin; }
};

#endif // POINT_LIGHT_H

