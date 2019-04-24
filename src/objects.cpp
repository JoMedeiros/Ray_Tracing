#include "objects.h"


Vec3 color(const Ray& r) {
  Sphere s( Vec3(0,0,-1), 5 );
	float t = s.hit( r );
	//float t = hit_sphere(Vec3(0,0,-1), 5, r);
	if (t > 0.0) {
		Vec3 N = unit_vector( r.point_at_parameter(t) - Vec3(0,0,-1));
		return 0.5*Vec3(N.x()+1, N.y()+1,	N.z()+1);
	}
  else {
    return (Color(-1,-1,-1));
  }
	//if (hit_sphere(Vec3(0,0,-1), 0.5, r))
	//	return Vec3(1, 0, 0);

	Vec3 unit_direction = 
	unit_vector(r.direction());
	
	t = 0.5 *
	(unit_direction.y() + 1.0);
	
	return (1.0-t)*Vec3(1.0, 1.0, 1.0)
	+ t*Vec3(0.5, 0.7, 1.0);
}

