/**
 * @file  blinnPhongMaterial.h
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  27 mai 2019
 *  Last Update: 27 mai 2019 (18:45:11)
 */
#ifndef BLINN_PHONG_MATERIAL_H
#define BLINN_PHONG_MATERIAL_H
#include "material.h"

class BlinnPhongMaterial : public Material {
  private:
    Color kambient;
    Color kdifuse; // diffuse constant
    Color kespecular;
    float _glossiness;
  public:
    BlinnPhongMaterial(Color ka, Color kd, Color ke, 
        float glossiness) : 
      kambient(ka), kdifuse(kd), kespecular(ke), 
      _glossiness(glossiness) { /* Empty */ }
    //Getters
    Color ka(){ return kambient; }
    Color kd(){ return kdifuse; }
    Color ke(){ return kespecular; }
  };

#endif //BLINN_PHONG_MATERIAL_H

