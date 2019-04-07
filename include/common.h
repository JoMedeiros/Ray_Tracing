#ifndef _SETUP_H_
#define _SETUP_H_

#include "renderer.h"
#include "vec3.h" // Color
#include "yaml-cpp/yaml.h"
#include <iostream>

std::map<std::string, Color> color_table;
Color load_color(const YAML::Node & color_node) {
  Color color;
  if (color_node.Type() == YAML::NodeType::Scalar)
    color = color_table[color_node.as<string>()];
  else if (color_node.Type() == YAML::NodeType::Sequence)
    color = Color(color_node[0].as<int>(), color_node[1].as<int>(),
        color_node[2].as<int>());
  return color;
}
/**
 * @brief Parses background node in .yml file to set Background object
 */
void setup_bg(const YAML::Node & bg, Renderer &r){
  try
  {
    string type = bg["type"].as<string>();
    if (type.compare("solid") == 0) {
      auto color = bg["color"];
      r.bg = new Background(load_color(color));
    }
    else if (type.compare("interpolation") == 0) {
      auto colors = bg["colors"];
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
    r.camera = new Camera(height, width);
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

