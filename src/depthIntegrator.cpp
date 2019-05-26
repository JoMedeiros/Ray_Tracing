#include "depthIntegrator.h"
#include <limits>

/*void DepthIntegrator::render( const Scene& scene) {
  int w = scene.buffer->width();
  int h = scene.buffer->height();
  // TODO use min and max set by user
  float min = 2.6;
  float max = 10;
  float range = min - max;
	for ( int j = h-1; j >= 0; --j ) {
		for ( int i = 0; i < w; ++i ) {
			float v = float(i+0.5) / float(w), 
            u = float(j+0.5) / float(h);
      Ray ray = scene.camera->generate_ray(v, u);
      SurfaceInteraction surf;
      Color color = Color(255, 255, 255);
      if (scene.intersect(ray, &surf)) {
        float dist = (surf.p - scene.camera->get_origin()).length();
        if ( dist > min and dist < max) {
          float t = (dist - min)/range;
          color = (1-t)*(Color(255,255,255));
        }
      }
      scene.buffer->paint( i, j, color );
    }
  }
}*/
/**
 * @brief 
 */
Color DepthIntegrator::Li( const Ray& ray, const Scene& scene, Sampler& sampler ) const {
  Color L(0,0,0); 
  SurfaceInteraction si;
  if (!scene.intersect(ray, &si)) {
    // This might be just:
    L = max_color; //TODO implement bg sample with ray
  }
  else {
    float dist = (scene.camera->get_origin() - si.p).length();
    float t = dist > max_dist ? 1 : dist < min_dist ? 0 : 
      (dist - min_dist) / (max_dist - min_dist);
    L = t * max_color + (1-t)*min_color;
  }
  return L;
}
