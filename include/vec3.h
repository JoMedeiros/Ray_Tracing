/**
 * @file	vec3.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	25th Apr 2019
 * 	Last Update:	25th Apr 2019
 */

#ifndef VEC3_H
#define VEC3_H

#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

enum {RED, GREEN, BLUE};

class Vec3 {
 public:
	double e[3];

	// Vec3() {}
	Vec3(double e0=0, double e1=0, double e2=0) : 
	e{e0,e1,e2} {}
  Vec3(const Vec3& v) {
    e[0] = v[0];
    e[1] = v[1];
    e[2] = v[2];
  }

	inline double x() const { return e[0]; }
	inline double y() const { return e[1]; }
	inline double z() const { return e[2]; }
	
	inline double operator[](int i) const 
	{ return e[i]; }
	inline double& operator[](int i) 
	{ return e[i]; }

	inline double length() const
	{ return sqrt(e[0]*e[0] + e[1]*e[1]
		+ e[2]*e[2]); }
};
typedef Vec3 Point3;
typedef Vec3 Color;

//=== Operators
inline Vec3 operator-(const Vec3 &v)
{ return Vec3(-v[0], -v[1], -v[2]); }

inline Vec3 operator+(const Vec3 &v1, const Vec3 &v2)
{ return Vec3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]); }

inline Vec3 operator-(const Vec3 &v1, const Vec3 &v2)
{ return Vec3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]); }

inline Vec3 operator/(const Vec3 &v1, double x)
{ return Vec3(v1[0] / x, v1[1] / x, v1[2] / x); }

inline Vec3 operator*(double x, const Vec3 &v)
{ return Vec3(v.e[0] * x, v.e[1] * x, v.e[2] * x); }

inline bool operator==(const Vec3 &v1, const Vec3 &v2)
{ return (v1[0] == v2[0]) and (v1[1] == v2[1]) and (v1[2] == v2[2]); }

inline ostream & operator << (ostream & os, const Vec3 v) {
  os << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
  return os;
}

//=== Operations
inline double dot(const Vec3 &v1, const Vec3 &v2)
{ return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]; }

inline Vec3 cross(const Vec3 &v1, const Vec3 &v2) { 
  double s1 = (v1[1]*v2[2]) - (v1[2]*v2[1]);
  double s2 = (v1[2]*v2[0]) - (v1[0]*v2[2]);
  double s3 = (v1[0]*v2[1]) - (v1[1]*v2[0]);
  return Vec3( s1, s2, s3); 
}

inline Vec3 unit_vector(Vec3 v)
{ return v / v.length(); }

#endif // VEC3_H

