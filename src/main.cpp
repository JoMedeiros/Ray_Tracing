#include <iostream>
#include "renderer.h"
#include "ray.h"
#include "background.h"
#include "buffer.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main( int argc, char *argv[] ) {
  string filename = "scene.yml";
  string outputfile = "output.ppm";
  Renderer render;
  if (argc > 1){
    filename = argv[1];
  }
  else {
    cout << "Missing arguments\nHow to use:\n" << argv[0] 
      << " <filename>.yml\n";
    return EXIT_FAILURE;
  }
  cout <<
" +=========================================+\n" <<
" |  Ray Tracer Teaching Tool -- RT3, v1.0  |\n" <<
" |  copyright DIMAp/UFRN 2017-1019.        |\n" <<
" +=========================================+\n\n" <<
"[1] Scene file parsing initiated...\n";
  try {
    render.setup( filename);
  } 
  catch (exception &e ) {
    cerr << e.what();
    return EXIT_FAILURE;
  }
  cout <<
"[2] Starting ray tracing progress.\n" <<
"    Image dimensions in pixels (W x H): 40 x 30.\n" <<
"    Samples per pixel: 1.\n" <<
"    Max ray recursion depth: 1.\n" <<
"    Ray tracing is usually a slow process, please be patient: \n";

  render.run();
  stbi_write_png("output.png", render.scene->buffer->width(), 
      render.scene->buffer->height(), 3, render.scene->buffer->data(), 3*render.scene->buffer->width());
	return EXIT_SUCCESS;
}
