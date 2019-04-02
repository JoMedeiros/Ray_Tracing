#ifndef _SETUP_H_
#define _SETUP_H_

//#include "yaml-cpp/yaml.h"
#include "background.h"
#include "buffer.h"
#include <iostream>

int setup(Background & bg, Buffer & buffer) {
/*  int width, height;
  Color c00, c01, c10, c11;
  YAML::Node img, colors, objects;
  try {
    img = YAML::LoadFile("config.yml");
    width = img["width"].as<int>();
    height = img["height"].as<int>();
    colors = img["colors"].as<YAML::Node>();
    objects = img["objects"].as<YAML::Node>();
  }
  catch (std::exception & e) {
    cout << "Error loading config file:\n";
    cout << e.what() << "\n";
    return -1;
  }
  bg = Background(c00, c01, c10,c11);
  buffer = Buffer(width, height);*/
  return 0;
}

#endif// _SETUP_H_

