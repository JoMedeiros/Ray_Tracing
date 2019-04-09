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
  string filename = "scene.yml";
  string outputfile = "output.ppm";
  Renderer render;
  if (argc > 1){
    filename = argv[1];
  }
  try {
    setup(render, filename);
  } 
  catch (exception &e ) {
    cerr << e.what();
    return -1;
  }
  render.run();
  stbi_write_bmp("output.bmp", render.buffer->width(), 
      render.buffer->height(), 3, render.buffer->data());
	return EXIT_SUCCESS;
}
