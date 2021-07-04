/**
 * @file	background.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	12th May 2019
 * 	Last Update:	12th May 2019
 */
#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

//#ifndef STB_IMAGE_IMPLEMENTATION
//#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
//#endif

#include <vector>
#include "vec3.h"

// @TODO Constructor with image as param
// Use a library to open, resize images: STD_IMAGE
using namespace std;

class Background
{
private:
  //====================
  // Attributes
  //====================
  Color blc; //< bottom left corner
  Color tlc; //< top left corner
  Color trc; //< top right corner
  Color brc; //< bottom right corner
  bool hasImg = false;
  int width, height, channels;
  unsigned char *image;
public:
  //====================
  // Constructors
  //====================
	Background( Color c= Color(0,0,0) ) : blc(c), tlc(c), trc(c), brc(c) { }
	Background( Color trc, Color tlc, Color blc, Color brc ) {
    this->blc = blc;
    this->tlc = tlc;
    this->trc = trc;
    this->brc = brc;
  }
  /**
   * @brief Copy constructor
   */
	Background( Background & other) {
    blc = other.blc;
    tlc = other.tlc;
    trc = other.trc;
    brc = other.brc;
  }
  Background( string filename) {
    stbi_set_flip_vertically_on_load(true);
    this->image = stbi_load(filename.c_str(),
        &width,
        &height,
        &channels,
        STBI_rgb);
    // ... do something with the image
    this->hasImg = true;
  }
  ~Background() {
    stbi_image_free(this->image);
  }
  //====================
  // Methods
  //====================
  /**
   * @brief Returns a color of background corresponding to coordinate (u, v)
   */
  Color sample( float u, float v ) {
    Color c;
    if (this->hasImg ){
      int x1 = floor(v*this->width);
      int x2 = ceil(v*this->width);
      int y1 = floor(u*this->height);
      int y2 = ceil(u*this->height);
      unsigned char *r1 = this->image + (y1*this->width*this->channels  + x1*this->channels);
      unsigned char *r2 = this->image + (y1*this->width*this->channels  + x2*this->channels);
      unsigned char *r3 = this->image + (y2*this->width*this->channels  + x1*this->channels);
      unsigned char *r4 = this->image + (y2*this->width*this->channels  + x2*this->channels);
      return 0.25 * (Color(*r1,*(r1+1),*(r1+2)) + Color(*r2,*(r2+1),*(r2+2)) +
          Color(*r3,*(r3+1),*(r3+2)) + Color(*r4,*(r4+1),*(r4+2)));
    } 
    else {
     Color cy1 = tlc + v*(blc-tlc);
     Color cy2 = trc + v*(brc-trc);
     c = cy1 + u*(cy2-cy1);
    }
    return c;
  }
};

#endif // _BACKGROUND_H_
