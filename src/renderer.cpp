#include "renderer.h"
#include "ray.h"
#include "sphere.h"
#include <iostream>

using namespace std;

void Renderer::run() {
  int w = buffer->width();
  int h = buffer->height();
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
        if ( p->intersect_p( ray ) )
            color = Color(255, 0, 0);
      }
      buffer->paint( i, j, color );
		}
	}
}
void Renderer::add_primitive(Sphere* sp){
  primitives.push_back(sp);
}

