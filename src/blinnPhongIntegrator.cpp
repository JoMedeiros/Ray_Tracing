/**
 * @file  blinnPhongIntegrator.cpp
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  27 mai 2019
 *  Last Update: 29 mai 2019 (15:19:44)
 */
#include "blinnPhongIntegrator.h"
#include "blinnPhongMaterial.h"
#include "ambientLight.h"
#include "pointLight.h"

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
    // Loop through lights
    for (auto l = scene.lights.begin(); 
        l != scene.lights.end(); ++l) {
      Light* li = (*l).get();
      if (AmbientLight* light = dynamic_cast<AmbientLight*>(li)){
        L = L + 255 * light->intensity() * bfm->ka();
      }
      if (PointLight* light = dynamic_cast<PointLight*>(li)){
        Vec3 I = unit_vector(light->origin() - si.p);
        Vec3 H = unit_vector(I + -ray.direction());
        float t = max(dot(I, si.n), 0.0f);
        float NH = max(dot(si.n, H), 0.0f);
        Ray shadow_ray(si.p + 0.001*I, I);
        if (scene.intersect_p(shadow_ray)) t = 0;
        L = truncate( L + 255*t*(bfm->kd() * light->intensity())
            + 255*pow(NH, bfm->glossiness())*bfm->ks()*light->intensity());
          //L = L + 255 * light->intensity() * bfm->ka();
      }
    }
    float t = dot(Vec3(0,1,0), si.n);
    if (t < 0) t = 0;
    if (t > 1) t = 255;
    Vec3 light(1,4,0);
    //L = truncate(
    //    L + t*255*bfm->kd());
  }
  return L;
}

