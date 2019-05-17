/**
 * @file	flatIntegrator.cpp
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	14th May 2019
 * 	Last Update:	14th May 2019
 */
#include "flatIntegrator.h"

void FlatIntegrator::render( const Scene& scene ) {
  int w = scene.buffer->width();
  int h = scene.buffer->height();
	for ( int j = h-1; j >= 0; --j ) {
		for ( int i = 0; i < w; ++i ) {
			float v = float(i+0.5) / float(w), 
            u = float(j+0.5) / float(h);
      Ray ray = scene.camera->generate_ray(v, u);
      //Ray ray = camera->generate_ray( float(i)/float(w), 
          //float(j)/ float(h));
      cout << "pixel (" << j << ", " << i << ") " 
        << "ray: " << ray << "\n";
      Color color = scene.bg->sample(u, v);
      if (scene.intersect_p(ray)) color = Color (255,0,0);
      scene.buffer->paint( i, j, color );
		}
	}
}
/**
 * @brief 
 */
Color FlatIntegrator::Li( const Ray& ray, const Scene& scene, Sampler& sampler ) const {
}

