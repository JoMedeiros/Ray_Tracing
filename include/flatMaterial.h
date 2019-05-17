/**
 * @file	flatMaterial.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	17th May 2019
 * 	Last Update:	17th May 2019
 */
#ifndef FLAT_MATERIAL_H
#define FLAT_MATERIAL_H

#include "material.h"

class FlatMaterial : public Material {
  public:
    Color color;
    FlatMaterial() { /* Empty */ }
};

#endif // FLAT_MATERIAL_H
