#include <iostream>
#include "ray.hpp"
#include "objects.hpp"
#include "setup.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main( int argc, char *argv[] ) {
  string filename = "output.ppm";
  if (argc > 1){
    filename = argv[1];
  }
	int nx = 400;
	int ny = 400;
  Buffer buffer(nx, ny);
  Background bg(Color(0,255,51), Color(255,255,51), Color(255,0,51),
      Color(0,0,51));
	
	std::cout << "P3\n" 
	<< nx << " " << ny 
	<< "\n255\n";

	Point3 lower_left_corner(-1.0, -1.0, -1.0);
	vec3 horizontal(2.0, 0.0, 0.0);
	vec3 vertical(0.0, 2.0, 0.0);
	Point3 origin(0.0, 0.0, 0.0);
	
	for ( int j = ny-1; j >= 0; --j ) {
		for ( int i = 0; i < nx; ++i ) {
			float u = float(i) / float(nx), v = float(j) / float(ny);

      buffer.paint(i, j, bg.sample(u, v));
			ray r(origin, lower_left_corner + u*horizontal + v*vertical);
			vec3 col = color(r);

			int ir = int(255.99*col[0]), ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);

			std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
  stbi_write_bmp("output.ppm", nx, ny, 3, buffer.data());
	return EXIT_SUCCESS;
}
