#ifndef _SETUP_H_
#define _SETUP_H_

#include "renderer.h"
#include "vec3.h" // Color
#include "yaml-cpp/yaml.h"
#include <iostream>

/**
 * @brief Sets the renderer parsing a config.yml file
 */
int setup(Renderer &r) {
  int width=800, height=600;
  Color c00, c01, c10, c11;
  YAML::Node config, bg, camera;
  try {
    config = YAML::LoadFile("config.yml");
    bg = config["background"];
    camera = config["camera"];
    width = camera["width"].as<int>();
    height = camera["height"].as<int>();
    //colors = config["colors"].as<YAML::Node>();
    //scene = config["objects"].as<YAML::Node>();
    r.buffer = new Buffer(width, height);
  }
  catch (std::exception & e) {
    cout << "Error loading config file:\n";
    cout << e.what() << "\n";
    return -1;
  }
  /* bg = Background(c00, c01, c10,c11);
  */
  r.buffer = new Buffer(width, height);
  return 0;
}

#endif// _SETUP_H_

