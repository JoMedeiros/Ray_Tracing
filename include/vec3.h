#ifndef _VEC3_H_
#define _VEC3_H_

#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

enum {RED, GREEN, BLUE};
//@TODO Implemet Point2f
class Vec2 {
};
typedef Vec2 Point2f;

class Vec3 {
 public:
	float e[3];

	// Vec3() {}
	Vec3(float e0=0, float e1=0, float e2=0) : 
	e{e0,e1,e2} {}
  Vec3(const Vec3& v) {
    e[0] = v[0];
    e[1] = v[1];
    e[2] = v[2];
  }

	inline float x() const { return e[0]; }
	inline float y() const { return e[1]; }
	inline float z() const { return e[2]; }
	
	inline float operator[](int i) const 
	{ return e[i]; }
	inline float& operator[](int i) 
	{ return e[i]; }

	inline float length() const
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

inline Vec3 operator/(const Vec3 &v1, float x)
{ return Vec3(v1[0] / x, v1[1] / x, v1[2] / x); }

inline Vec3 operator*(float x, const Vec3 &v)
{ return Vec3(v.e[0] * x, v.e[1] * x, v.e[2] * x); }

inline bool operator==(const Vec3 &v1, const Vec3 &v2)
{ return (v1[0] == v2[0]) and (v1[1] == v2[1]) and (v1[2] == v2[2]); }

inline ostream & operator << (ostream & os, const Vec3 v) {
  os << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
  return os;
}

//=== Operations
inline float dot(const Vec3 &v1, const Vec3 &v2)
{ return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]; }

inline Vec3 cross(const Vec3 &v1, const Vec3 &v2) { 
  float s1 = (v1[1]*v2[2]) - (v1[2]*v2[1]);
  float s2 = (v1[2]*v2[0]) - (v1[0]*v2[2]);
  float s3 = (v1[0]*v2[1]) - (v1[1]*v2[0]);
  return Vec3( s1, s2, s3); 
}

inline Vec3 unit_vector(Vec3 v)
{ return v / v.length(); }

#endif
