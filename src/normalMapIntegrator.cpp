/**
 * @file	normalMapIntegrator.cpp
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	16th May 2019
 * 	Last Update:	16th May 2019
 */
#include "normalMapIntegrator.h"

Color NormalMapIntegrator::Li( const Ray& ray, const Scene& scene, Sampler& sampler ) const{
  SurfaceInteraction sinter;
  Color Li;
  if (scene.intersect(ray, &sinter)) {
    Li = 127*( sinter.n + Vec3(1, 1, 1) );
  } 
  else Li = Color(127,127, 255);
  return Li;
}
