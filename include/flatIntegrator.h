/**
 * @file	flatIntegrator.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	12th May 2019
 * 	Last Update:	12th May 2019
 */
#ifndef FLAT_INTEGRATOR_H
#define FLAT_INTEGRATOR_H

#include "integrator.h"

class FlatIntegrator : public Integrator{
  public:
    FlatIntegrator(){/* Empty */}
    void render( const Scene& scene );
		Color Li( const Ray& ray, const Scene& scene, Sampler& sampler ) const;
};

#endif // FLAT_INTEGRATOR_H

