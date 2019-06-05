/**
 * @file	sampleIntegrator.cpp
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	17th May 2019
 * 	Last Update:	17th May 2019
 */
#include "sampleIntegrator.h"

void SampleIntegrator::render(const Scene& scene) {
  //preprocess();

  // TODO This might just be a tile (part) of an image, rendered in parallel.
  int w = scene.buffer->width();
  int h = scene.buffer->height();

	for ( int j = h-1; j >= 0; --j ) {
		for ( int i = 0; i < w; ++i ) {
			float v = float(i) / float(w), 
            u = float(j) / float(h);
      Ray ray = scene.camera->generate_ray(v, u);
      Sampler sampler(1);
      Color L = Li( ray, scene, sampler );
      scene.buffer->paint( i, j, L );
    }
	}
}
