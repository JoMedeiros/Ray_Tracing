/**
 * @file  pointLight.h
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  27 mai 2019
 *  Last Update: 27 mai 2019 (16:21:38)
 */
#include "light.h"

class PointLight : public Light {
  private:
    Point3 _origin;
  public:
    PointLight(Point3 origin): _origin(origin){}
    virtual Ray generate_ray(Point3 p){
      Ray r (_origin, p - _origin);
      return r;
    }
};

