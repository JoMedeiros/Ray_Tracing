#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "buffer.h"
#include "background.h"
#include "orthoCamera.h"
#include "perspectiveCamera.h"
#include "sphere.h"
#include <vector>

class Renderer 
{
public:
  Buffer* buffer;
  Background* bg;
  Camera* camera;
  vector<Primitive*> primitives;
  void run();
  void save_img();
  void add_primitive(Sphere* sp);
};

#endif
