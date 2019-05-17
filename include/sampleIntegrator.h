/**
 * @file	sampleIntegrator.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	12th May 2019
 * 	Last Update:	17th May 2019
 */
#ifndef SAMPLE_INTEGRATOR_H
#define SAMPLE_INTEGRATOR_H

#include "integrator.h"
#include "sampler.h"
#include "camera.h"
#include <memory>

class SampleIntegrator : public Integrator {
  //=== Public interface
	public:
		virtual ~SampleIntegrator();
		SampleIntegrator( shared_ptr<const Camera> cam,
		                  shared_ptr<Sampler> sampler )
		    : camera{cam}, sampler{sampler}{};

		virtual Color Li( const Ray& ray, const Scene& scene,
				Sampler& sampler ) const = 0;
		virtual void render( const Scene& scene );
		virtual void preprocess( const Scene& scene );
	protected:
		std::shared_ptr<const Camera> camera;
	private:
		std::shared_ptr<Sampler> sampler;
};

#endif // SAMPLE_INTEGRATOR_H

