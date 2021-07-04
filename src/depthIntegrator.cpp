/**
 * @file  depthIntegrator.cpp
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  27 mai 2019
 *  Last Update: 30 mai 2019 (08:22:41)
 */
#include "depthIntegrator.h"
#include <limits>

/**
 * @brief Integrates the light corresponding to a ray.
 *
 * @param ray
 * @param scene
 * @param sampler
 *
 * @return 
 */
Color DepthIntegrator::Li( const Ray& ray, const Scene& scene, Sampler& sampler ) const {
  for (unsigned i = 0; i < sampler.get_samples(); ++i){
  }
  Color L(0,0,0); 
  SurfaceInteraction si;
  if (!scene.intersect(ray, &si)) {
    L = max_color; 
  }
  else {
    float dist = (scene.camera->get_origin() - si.p).length();
    float t = dist > max_dist ? 1 : dist < min_dist ? 0 : 
      (dist - min_dist) / (max_dist - min_dist);
    L = t * max_color + (1-t)*min_color;
  }
  return L;
}
