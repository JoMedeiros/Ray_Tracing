#include "renderer.h"
#include "ray.h"
#include "sphere.h"
#include <iostream>

using namespace std;

void Renderer::run() {
  int nx = buffer->width();
  int ny = buffer->height();
	Point3 lower_left_corner(-1.0, -1.0, -1.0);
	//Vec3 horizontal(3.0, 0.0, 0.0);
	//Vec3 vertical(0.0, 2.0, 0.0);
	//Point3 origin(0.0, 0.0, 0.0);
	for ( int j = ny-1; j >= 0; --j ) {
		for ( int i = 0; i < nx; ++i ) {
			float v = float(i+0.5) / float(nx), u = float(j+0.5) / float(ny);

			//Ray r(origin, lower_left_corner + u*horizontal + v*vertical);
      Ray r = camera->generate_ray(v, u);
      //cout << "pixel (" << j << ", " << i << ") " 
        //<< "ray: [o=" << r.origin() << ", d=" << r.direction() << "\n";
      Color col = bg->sample(u, v);
      buffer->paint( i, j, col );
      //buffer->paint(i, j, bg->sample(u, v));

      //render.buffer->paint(i, j, col);
		}
	}
}

