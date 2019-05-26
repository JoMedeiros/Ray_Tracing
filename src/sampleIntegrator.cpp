/**
 * @file	sampleIntegrator.cpp
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	17th May 2019
 * 	Last Update:	17th May 2019
 */
#include "sampleIntegrator.h"

void SampleIntegrator::render(const Scene& scene) {
  cout << "Starting rendering...\n";
  //preprocess();

  // TODO This might just be a tile (part) of an image, rendered in parallel.
  int w = scene.buffer->width();
  int h = scene.buffer->height();
//  for ( int y = 0 ; y < h ; y++ ) {
//    for( int x = 0 ; x < w ; x++ ) {
//      Ray ray = cam.generate_ray( screen_coord ); // Generate the ray from (x,y)
//      Color24 L = Li( ray, scene, sampler ); // Determine the color for the ray.
//      camera->film->add_sample( Point2i( x, y ), L ); // Set color of pixel (x,y) to L.
//    }
//  }
//  // Send image color buffer to the output file.
//  camera->film->write_img( image );

	for ( int j = h-1; j >= 0; --j ) {
		for ( int i = 0; i < w; ++i ) {
			float v = float(i) / float(w), 
            u = float(j) / float(h);
      Ray ray = scene.camera->generate_ray(v, u);
      Sampler sampler(1);
      Color L = Li( ray, scene, sampler );
      scene.buffer->paint( i, j, L );
		}
	}
}
