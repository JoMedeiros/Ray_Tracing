/**
 * @file  blinnPhongIntegrator.h
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  27 mai 2019
 *  Last Update: 27 mai 2019 (18:56:53)
 */
#ifndef BLINN_PHONG_INTEGRATOR
#define BLINN_PHONG_INTEGRATOR

#include "sampleIntegrator.h"

class BlinnPhongIntegrator : public SampleIntegrator {
  public:
    /**
     * @brief Class constructor
     *
     * @param cam   A shared pointer to a camera.
     * @param sampler A shared pointer to a sampler.
     */
    BlinnPhongIntegrator( shared_ptr<const Camera> cam,
      shared_ptr<Sampler> sampler ) : 
      SampleIntegrator( cam, sampler ){};

    /**
     * @brief Linght integrator.
     *
     * @param ray   A ray from the camera generate in render 
     * function.
     * @param scene A Scene composed by objects, camera, background
     * and lights.
     * @param sampler A sampler object.
     *
     * @return 
     */
		virtual Color Li( const Ray& ray, const Scene& scene,
				Sampler& sampler ) const;
};

#endif // BLINN_PHONG_INTEGRATOR

