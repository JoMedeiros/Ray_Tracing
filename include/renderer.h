#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <vector>
#include <map>
#include <iostream>

//#ifndef STB_IMAGE_WRITE_IMPLEMENTATION
//#define STB_IMAGE_WRITE_IMPLEMENTATION
//#include "stb_image_write.h"
//#endif
#include "yaml-cpp/yaml.h"

#include "scene.h"
//#include "buffer.h"
//#include "background.h"
//#include "ray.h"
#include "orthoCamera.h"
#include "perspectiveCamera.h"
#include "sphere.h"
#include "flatIntegrator.h"
#include "depthIntegrator.h"
#include "normalMapIntegrator.h"

class Renderer 
{
  private:
    string filename;
    string filetype;
  public:
    Renderer();
    Scene* scene;
    map<string, Color> color_table;
    void run();
    void setup( string file );
    Vec3 load_vec(const YAML::Node & node);
    Color load_color(const YAML::Node & color_node);
    void setup_bg(const YAML::Node & bg);
    void setup_camera(const YAML::Node & camera);
    void setup_scene(const YAML::Node & scene);
    void save_img();
    void add_primitive(Sphere* &sp);
};

#endif
