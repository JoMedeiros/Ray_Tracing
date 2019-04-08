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
  catch (exception &e ) {
    cerr << e.what();
    return -1;
  }
  string filename = "output.ppm";
  if (argc > 1){
    filename = argv[1];
  }
	
  render.run();
  stbi_write_bmp("output.bmp", render.buffer->width(),
  render.buffer->height(),  
      3, render.buffer->data());
	return EXIT_SUCCESS;
}
