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
  //====================
  // Methods
  //====================
  /**
   * @brief Returns a color of background corresponding to coordinate (u, v)
   */
  Color sample( float u, float v ) {
    Color cy1 = tlc + v*(blc-tlc);
    Color cy2 = trc + v*(brc-trc);
    Color c = cy1 + u*(cy2-cy1);
    return c;
  }
};

#endif // _BACKGROUND_H_
