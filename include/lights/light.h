/**
 * @file	light.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	12th May 2019
 * 	Last Update:	12th May 2019
 */
#ifndef LIGHT_H
#define LIGHT_H

#include "ray.h"

class Light {
  private:
    Color _intensity;
  public:
    Light(Color intensity) : _intensity(intensity){}
    virtual ~Light() = default;
    //Ray generate_ray(Point3 p) = 0;
    Color intensity(){return _intensity;}
};
#endif // LIGHT_H

