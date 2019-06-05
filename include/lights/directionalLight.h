/**
 * @file  directionalLight.h
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  27 mai 2019
 *  Last Update: 04 jun 2019 (08:22:18)
 */
#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H

#include "light.h"

class DirectionalLight : public Light {
  private:
    Vec3 _direction;
  public:
    DirectionalLight(Point3 direction, Color intensity=Color(1,1,1)) : 
      Light(intensity), _direction(direction) {}
    Ray generate_ray(Point3 p){
      Ray r (p , _direction);
      return r;
    }
    // Getters
    Vec3 direction() { return _direction; }
};

#endif // DIRECTIONAL_LIGHT_H

