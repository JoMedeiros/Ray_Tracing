/**
 * @file  blinnPhongMaterial.h
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  27 mai 2019
 *  Last Update: 29 mai 2019 (14:58:36)
 */
#ifndef BLINN_PHONG_MATERIAL_H
#define BLINN_PHONG_MATERIAL_H
#include "material.h"

class BlinnPhongMaterial : public Material {
  private:
    Color kambient;
    Color kdifuse; // diffuse constant
    Color kspecular;
    float _glossiness;
  public:
    BlinnPhongMaterial(Color ka, Color kd, Color ks, 
        float glossiness) : 
      kambient(ka), kdifuse(kd), kspecular(ks), 
      _glossiness(glossiness) { /* Empty */ }
    //Getters
    Color ka(){ return kambient; }
    Color kd(){ return kdifuse; }
    Color ks(){ return kspecular; }
    float glossiness(){ return _glossiness; }
  };

#endif //BLINN_PHONG_MATERIAL_H

