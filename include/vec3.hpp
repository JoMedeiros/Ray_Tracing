#ifndef _VEC3_H_
#define _VEC3_H_

#include <math.h>
#include <stdlib.h>

enum {RED, GREEN, BLUE};

class vec3 {
 public:
	float e[3];

	vec3() {}
	vec3(float e0, float e1, float e2) : 
	e{e0,e1,e2} {}

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
typedef vec3 Point3;
typedef vec3 Color;

//=== Operators
inline vec3 operator+
(const vec3 &v1, const vec3 &v2)
{ return vec3(v1.e[0] + v2.e[0], 
	v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]); }

inline vec3 operator-
(const vec3 &v1, const vec3 &v2)
{ return vec3(v1.e[0] - v2.e[0], 
	v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]); }

inline vec3 operator/(const vec3 &v1, float x)
{ return vec3(v1.e[0] / x, 
	v1.e[1] / x, v1.e[2] / x); }

inline vec3 operator*(float x, const vec3 &v1)
{ return vec3(v1.e[0] * x, 
	v1.e[1] * x, v1.e[2] * x); }

//=== Operations
inline float dot(const vec3 &v1, const vec3 &v2)
{ return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1]
	 + v1.e[2] * v2.e[2]; }

inline vec3 unit_vector(vec3 v)
{ return v / v.length(); }

#endif
