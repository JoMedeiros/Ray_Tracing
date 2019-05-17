/**
 * @file	normalMapIntegrator.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	12th May 2019
 * 	Last Update:	12th May 2019
 */
#ifndef NORMAL_MAP_INTEGRATOR_H
#define NORMAL_MAP_INTEGRATOR_H

#include "integrator.h"

class NormalMapIntegrator : public Integrator {
  public:
    void render( const Scene& scene);
    void Li(const Ray& ray, const Scene& scene);
};

#endif // NORMAL_MAP_INTEGRATOR_H 

