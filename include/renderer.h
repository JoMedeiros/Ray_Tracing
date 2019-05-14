#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "buffer.h"
#include "background.h"
#include "orthoCamera.h"
#include "perspectiveCamera.h"
#include "sphere.h"
#include "scene.h"
#include "yaml-cpp/yaml.h"
#include <vector>
#include <map>

class Renderer 
{
  public:
    Buffer* buffer;
    Background* bg;
    Scene* scene;
    Camera* camera;
    vector<Primitive*> primitives;
    map<string, Color> color_table;
    void run();
    void setup( string file="scene.yml" );
    Vec3 load_vec(const YAML::Node & node);
    Color load_color(const YAML::Node & color_node);
    void setup_bg(const YAML::Node & bg);
    void setup_camera(const YAML::Node & camera);
    void setup_scene(const YAML::Node & scene);
    void save_img();
    void add_primitive(Sphere* sp);
};

#endif
