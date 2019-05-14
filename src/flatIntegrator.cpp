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
  float a = 0.25;
  Color mat = Color(0,175, 125);
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
      for ( auto p = scene.primitives.begin();
          p != scene.primitives.end(); ++p) {
        SurfaceInteraction* s = new SurfaceInteraction();
        bool hit = (*p)->intersect( ray, s );
        if ( hit ){
          color = 0.5*255.0*(Vec3(1,1,1) + s->n);
          float m = dot(s->n, scene.camera->get_w());
          color = (m+a)*mat;
            //cout << "Normal: " << s->n.x();
        }
      }
      scene.buffer->paint( i, j, color );
		}
	}
}
/**
 * @brief 
 */
void FlatIntegrator::Li( const Ray& ray, const Scene& scene ) {
  FlatIntegrator f;
}

