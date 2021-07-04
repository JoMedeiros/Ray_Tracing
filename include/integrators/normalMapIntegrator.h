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
#include "sampleIntegrator.h"

class NormalMapIntegrator : public SampleIntegrator {
  public:
    //NormalMapIntegrator() { /* Empty */ }
		NormalMapIntegrator( shared_ptr<const Camera> cam,
		                  shared_ptr<Sampler> sampler ) :
		 SampleIntegrator( cam, sampler ){ /* Empty */ }
    //void render( const Scene& scene);
    //void Li(const Ray& ray, const Scene& scene);
		Color Li( const Ray& ray, const Scene& scene, Sampler& sampler ) const;
};

#endif // NORMAL_MAP_INTEGRATOR_H 

