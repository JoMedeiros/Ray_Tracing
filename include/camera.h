#ifndef _CAMERA_H_
#define _CAMERA_H_

class Camera
{
 private:
  int height;
  int width;
  Point3 origin;
  Point3 lower_left_corner;
  vec3 horizontal, vertical;
  vec3 u, v, w;
 public:
  Camera(int _h, int _w) : height(_h),width(_w){}
}

#endif // _CAMERA_H_
