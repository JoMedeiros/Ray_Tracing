#ifndef _SETUP_H_
#define _SETUP_H_

#include "renderer.h"
#include "vec3.h" // Color
#include "yaml-cpp/yaml.h"
#include <iostream>

std::map<std::string, Color> color_table;
vec3 load_vec(const YAML::Node & node) {
  vec3 v;
  if (node.Type() == YAML::NodeType::Scalar)// In this case it is a color
    v = color_table[node.as<string>()];
  else if (node.Type() == YAML::NodeType::Sequence)
    v = vec3(node[0].as<int>(), node[1].as<int>(),
        node[2].as<int>());
  return v;
}
Color load_color(const YAML::Node & color_node) {
  return load_vec(color_node);
}
/**
 * @brief Parses background node in .yml file to set Background object
 */
void setup_bg(const YAML::Node & bg, Renderer &r){
  try
  {
    if (YAML::Node color = bg["color"]) {
      r.bg = new Background(load_color(color));
    }
    else if ( YAML::Node colors = bg["colors"] ) {
      Color colors_arr[4];
      int i = 0;
      for (auto it = colors.begin();it != colors.end();++it) {
        colors_arr[i] = load_color(*it);
        ++i;
      }
      for (;i < 4;++i) {
        colors[i] = colors[i-1];
      }
      r.bg = new Background(colors_arr[0], colors_arr[1], colors_arr[2], 
          colors_arr[3]);
    }
    else {
      r.bg = new Background(Color(255,255,255));
    }
  }
  catch (exception & e)
  {
    cerr << "Error parsing Background\n";
    cerr << e.what();
  }
}
void setup_camera(const YAML::Node & camera, Renderer &r) {
  try
  {
    int width=800, height=600;
    width = camera["width"].as<int>();
    height = camera["height"].as<int>();
    Point3 origin = load_vec(camera["position"]);
    Point3 lookat = load_vec(camera["target"]);
    vec3 vup(0,0,1);
    r.camera = new Camera( origin, lookat, vup,  height, width );
  }
  catch (exception & e)
  {
    cerr << "Error parsing Camera:\n";
    cerr << e.what();
  }
}
  /**
   * @brief Sets the renderer parsing a scene.yml file
   */
int setup(Renderer &r, string file="scene.yml") {
  Color c00, c01, c10, c11;
  YAML::Node config, bg, camera;
  try {
    config = YAML::LoadFile(file);
    bg = config["background"];
    camera = config["camera"];
    setup_bg(bg, r);
    setup_camera(camera, r);
    r.buffer = new Buffer(r.camera->height(), r.camera->width());
  }
  catch (std::exception & e) {
    cout << "Error loading config file:\n";
    cout << e.what() << "\n";
    throw e;
    return -1;
  }
  return 0;
}

#endif// _SETUP_H_

