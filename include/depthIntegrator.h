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
#include "sampleIntegrator.h"

class DepthIntegrator : public SampleIntegrator {
  private:
    Color min_color;
    Color max_color;
    float max_dist;
    float min_dist;
  public:
    DepthIntegrator( shared_ptr<const Camera> cam, shared_ptr<Sampler> sampler,
        Color near_color = Color(255,255,255), Color far_color = Color(0,0,0),
        float near_value = 0.5, float far_value = 40 ) :
      SampleIntegrator( cam, sampler ) {
        min_color = near_color;
        max_color = far_color;
        max_dist = far_value;
        min_dist = near_value;
      }
    //void render( const Scene& scene );
    Color Li( const Ray& ray, const Scene& scene, Sampler& sampler ) const;
};

#endif // DEPTH_INTEGRATOR_H

