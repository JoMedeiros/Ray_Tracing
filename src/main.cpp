#include <iostream>
#include "renderer.h"
#include "ray.h"
#include "objects.h"
#include "common.h"
#include "background.h"
#include "buffer.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main( int argc, char *argv[] ) {
  Renderer render;
  try {
    setup(render);
  } 
  catch (exception &e )
  {
    cerr << e.what();
    return -1;
  }
  
  // cout << "Bufferender.height: " << render.buffer->height() << "Buuferender.widht: " << render.buffer->width() << "\n";
  string filename = "output.ppm";
  if (argc > 1){
    filename = argv[1];
  }
	int nx = 600;
	int ny = 400;
  // render.buffer = new Buffer(nx, ny);
  // render.bg = new Background(Color(0,255,51), Color(255,255,51), Color(255,0,51),
     //  Color(0,0,51));
  Buffer buffer(nx, ny);
  Background bg(Color(0,255,51), Color(255,255,51), Color(255,0,51),
      Color(0,0,51));
	
	Point3 lower_left_corner(-1.0, -1.0, -1.0);
	vec3 horizontal(3.0, 0.0, 0.0);
	vec3 vertical(0.0, 2.0, 0.0);
	Point3 origin(0.0, 0.0, 0.0);
	
  render.run();
	/*for ( int j = render.buffer->height()-1; j >= 0; --j ) {
		for ( int i = 0; i < render.buffer->width(); ++i ) {
			float u = float(i) / float(nx), v = float(j) / float(ny);

			ray r(origin, lower_left_corner + u*horizontal + v*vertical);
			vec3 col = color(r);
      if (col == Color(-1,-1,-1)){
        col = bg.sample(u, v);
      }
      else {
        int ir = int(255.99*col[0]), ig = int(255.99*col[1]);
        int ib = int(255.99*col[2]);
        col = Color(ir,ig,ib);
      }

      render.buffer->paint(i, j, col);
		}
	}*/
  stbi_write_bmp("output.bmp", render.buffer->width(),
  render.buffer->height(),  
      3, render.buffer->data());
	return EXIT_SUCCESS;
}
