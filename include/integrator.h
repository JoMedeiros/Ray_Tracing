/**
 * @file	integrator.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	12th May 2019
 * 	Last Update:	12th May 2019
 */
#ifndef INTEGRATOR_H
#define INTEGRATOR_H
#include "scene.h"

class Integrator {
  public:
    virtual ~Integrator() {};
    virtual void render( const Scene& scene) = 0;
    virtual void Li(const Ray& ray, const Scene& scene) = 0;
};

#endif // INTEGRATOR_H

