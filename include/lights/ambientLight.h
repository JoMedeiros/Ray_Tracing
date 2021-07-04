/**
 * @file  ambientLight.h
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  29 mai 2019
 *  Last Update: 29 mai 2019 (10:03:20)
 */
#ifndef AMBIENT_LIGHT_H
#define AMBIENT_LIGHT_H

#include "light.h"

class AmbientLight : public Light {
  public:
    AmbientLight(Color intensity) : Light (intensity) {}
};

#endif // AMBIENT_LIGHT_H

