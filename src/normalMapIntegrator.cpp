/**
 * @file	normalMapIntegrator.cpp
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	16th May 2019
 * 	Last Update:	16th May 2019
 */
#include "normalMapIntegrator.h"

void NormalMapIntegrator::render( const Scene& scene) {
  int w = scene.buffer->width();
  int h = scene.buffer->height();
  vector<SurfaceInteraction> inters;
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
      SurfaceInteraction sinter;
      if (scene.intersect(ray, &sinter)) {
        color = 127*( sinter.n + Vec3(1, 1, 1) );
        sinter.uv = Vec2(i,j);
      }
      inters.push_back(sinter);
      scene.buffer->paint( i, j, color );
		}
	}
}
void NormalMapIntegrator::Li(const Ray& ray, const Scene& scene) {
}

