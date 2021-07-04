/**
 * @file	flatIntegrator.cpp
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created: 14 may 2019
 *  Last Update: 30 mai 2019 (08:24:01)
 */
#include "flatIntegrator.h"
#include "flatMaterial.h"

/**
 * @brief Light integrator.
 *
 * @param ray
 * @param scene
 * @param sampler
 *
 * @return 
 */
Color FlatIntegrator::Li( const Ray& ray, const Scene& scene, Sampler& sampler ) const {
  for (unsigned i = 0; i < sampler.get_samples(); ++i){
  }
  //SurfaceInteraction si;
  Color L(0,0,0); // The radiance
  // Find closest ray intersection or return background radiance.
  SurfaceInteraction si;  
  if (!scene.intersect(ray, &si)) {
    // This might be just:
    L = scene.bg->sample(1,1); //TODO implement bg sample with ray
  }
  else {
    Material * m = si.primitive->get_material().get();
    FlatMaterial *fm = dynamic_cast< FlatMaterial *>(m);
    // Assign diffuse color to L.
    L = fm->kd(); // Call a method present only in FlatMaterial.
  }
  return L;
}


