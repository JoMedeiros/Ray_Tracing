/**
 * @file  blinnPhongIntegrator.cpp
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  27 mai 2019
 *  Last Update: 07 jun 2019 (16:19:05)
 */
#include "blinnPhongIntegrator.h"
#include "blinnPhongMaterial.h"
#include "ambientLight.h"
#include "pointLight.h"
#include "directionalLight.h"

Color BlinnPhongIntegrator::Li( const Ray& ray, const Scene& scene,
    Sampler& sampler ) const {
  for (unsigned i = 0; i < sampler.get_samples(); ++i){
  }
  Color L(0,0,0); // The radiance
  // Find closest ray intersection or return background radiance.
  SurfaceInteraction si;  
  if (!scene.intersect(ray, &si)) {
    L = scene.bg->sample(1,1); //TODO implement bg sample with ray
  }
  else {
    BlinnPhongMaterial *bfm=dynamic_cast<BlinnPhongMaterial*>(
        si.primitive->get_material().get());
    float a = bfm->glossiness();
    // Loop through lights
    for (auto & li : scene.lights) {
      if (auto light = dynamic_cast<AmbientLight*>(li.get())){
        L = truncate(L + 255 * light->intensity() * bfm->ka());
      }
      //=== Point Light
      else if (PointLight*light =
          dynamic_cast<PointLight*>(li.get())) {
        Vec3 I = unit_vector(light->origin() - si.p);
        Vec3 H = unit_vector(I + -ray.direction());
        float t = max(dot(I, si.n), 0.0f);
        float NH = max(dot(si.n, H), 0.0f);
        SurfaceInteraction shadow_si;
        Ray shadow_ray(si.p + 0.00001*I, I);
        // If the distance to object hit is greater than the 
        // distance to the light point, the object does not oclude
        if (scene.intersect(shadow_ray, &shadow_si) and
            (light->origin() - si.p).length() > 
            (shadow_si.p - si.p).length()) t = 0;
        L = truncate( L + 255*t*(bfm->kd() * light->intensity())
            + 255*pow(NH, a)*bfm->ks()*light->intensity());
      }
      //=== Directional Light
      else if (DirectionalLight* light = 
          dynamic_cast<DirectionalLight*>(li.get())) {
        Vec3 I = unit_vector(-light->direction());
        Vec3 H = unit_vector(I + -ray.direction());
        float a = bfm->glossiness();
        float t = max(dot(I, si.n), 0.0f);
        float NH = max(dot(si.n, H), 0.0f);
        // TODO Verify min and max t
        Ray shadow_ray(si.p + 0.00001*I, I);
        if (scene.intersect_p(shadow_ray)) t = 0;
        L = truncate( L + 255*t*(bfm->kd() * light->intensity())
            + 255*pow(NH, a)*bfm->ks()*light->intensity());
      }
    }
  }
  return L;
}

