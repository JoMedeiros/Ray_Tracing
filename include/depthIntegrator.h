/**
 * @file	depthIntegrator.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	12th May 2019
 * 	Last Update:	12th May 2019
 */
#ifndef DEPTH_INTEGRATOR_H
#define DEPTH_INTEGRATOR_H

#include "integrator.h"

class DepthIntegrator : public Integrator{
  public:
    DepthIntegrator() { /* Empty */ }
    void render( const Scene& scene);
    void Li(const Ray& ray, const Scene& scene);
};

#endif // DEPTH_INTEGRATOR_H

