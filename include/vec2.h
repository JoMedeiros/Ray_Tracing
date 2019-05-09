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
  double e[2];
  double x() { return e[0]; }
  double y() { return e[1]; }
};
typedef Vec2 Point2f;

#endif // VEC2_H

