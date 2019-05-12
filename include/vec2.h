/**
 * @file	vec2.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	25th Apr 2019
 * 	Last Update:	25th Apr 2019
 */

#ifndef VEC2_H
#define VEC2_H

class Vec2 {
public:
  Vec2(float x=0, float y=0){
    e[0] = x;
    e[1] = y;
  };
  float e[2];
  float x() { return e[0]; }
  float y() { return e[1]; }
};
typedef Vec2 Point2f;

#endif // VEC2_H

