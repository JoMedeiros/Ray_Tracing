/**
 * @file  blinnPhongIntegrator.cpp
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  27 mai 2019
 *  Last Update: 28 mai 2019 (15:44:38)
 */
#include "blinnPhongIntegrator.h"
#include "blinnPhongMaterial.h"

Color BlinnPhongIntegrator::Li( const Ray& ray, const Scene& scene,
    Sampler& sampler ) const {
  Color L(0,0,0); // The radiance
  // Find closest ray intersection or return background radiance.
  SurfaceInteraction si;  
  if (!scene.intersect(ray, &si)) {
    // This might be just:
    L = scene.bg->sample(1,1); //TODO implement bg sample with ray
  }
  else {
    Material * m = si.primitive->get_material().get();
    BlinnPhongMaterial *bfm = 
      dynamic_cast< BlinnPhongMaterial *>(m);
    // Simulating light with direction (0,-1,0)
    float t = dot(Vec3(0,1,0), si.n);
    if (t < 0) t = 0;
    if (t > 1) t = 255;
    Ray shadow_ray(si.p, Vec3(0,20,0));
    if (scene.intersect_p(shadow_ray)) t = 0;
    L = t*255*bfm->kd() + 255*bfm->ka(); // Call a method present only in FlatMaterial.
  }
  return L;
}

