/**
 * @file	normalMapIntegrator.cpp
 * @author	Josivan Medeiros
 * @version	1
 * @date
 *  Created:  16 may 2019
 *  Last Update: 30 mai 2019 (08:25:07)
 */
#include "normalMapIntegrator.h"

Color NormalMapIntegrator::Li( const Ray& ray, const Scene& scene, Sampler& sampler ) const{
  for (unsigned i = 0; i < sampler.get_samples(); ++i){
  }
  SurfaceInteraction sinter;
  Color Li;
  if (scene.intersect(ray, &sinter)) {
    Li = 127*( sinter.n + Vec3(1, 1, 1) );
  } 
  else Li = Color(127,127, 255);
  return Li;
}
