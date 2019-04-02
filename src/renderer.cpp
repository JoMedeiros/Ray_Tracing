#include "renderer.h"
#include "ray.h"
#include <iostream>

void Renderer::run() {
  int nx = buffer->width();
  int ny = buffer->height();
	for ( int j = ny-1; j >= 0; --j ) {
		for ( int i = 0; i < nx; ++i ) {
			float u = float(i) / float(nx), v = float(j) / float(ny);

      buffer->paint(i, j, bg->sample(u, v));
			//ray r(origin, lower_left_corner + u*horizontal + v*vertical);
			//vec3 col = color(r);
		}
	}
}

