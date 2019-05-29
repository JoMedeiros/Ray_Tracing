/**
 * @file  directionalLight.h
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  27 mai 2019
 *  Last Update: 29 mai 2019 (09:52:56)
 */
#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H

#include "light.h"

class DirectionalLight : public Light {
  private:
    Vec3 _direction;
  public:
    DirectionalLight(Vec3 direction) : _direction(direction) {}
    Ray generate_ray(Point3 p){
      Ray r (p , _direction);
      return r;
    }
};

#endif // DIRECTIONAL_LIGHT_H

