#include "renderer.h"
#include "ray.h"
#include "sphere.h"
#include <iostream>

using namespace std;

void Renderer::run() {
  int w = buffer->width();
  int h = buffer->height();
  float a = 0.25;
  Color mat = Color(0,175, 125);
	for ( int j = h-1; j >= 0; --j ) {
		for ( int i = 0; i < w; ++i ) {
			float v = float(i+0.5) / float(w), u = float(j+0.5) / float(h);
      Ray ray = camera->generate_ray(v, u);
      //Ray ray = camera->generate_ray( float(i)/float(w), 
          //float(j)/ float(h));
      cout << "pixel (" << j << ", " << i << ") " 
        << "ray: " << ray << "\n";
      Color color = bg->sample(u, v);
      for ( Primitive*& p : primitives ) {
        SurfaceInteraction* s = new SurfaceInteraction();
        bool hit = p->intersect( ray, s );
        if ( hit ){
          color = 0.5*255.0*(Vec3(1,1,1) + s->n);
          float m = dot(s->n, camera->get_w());
          color = (m+a)*mat;
            //cout << "Normal: " << s->n.x();
        }
      }
      buffer->paint( i, j, color );
		}
	}
}
void Renderer::add_primitive(Sphere* sp){
  primitives.push_back(sp);
}

