/**
 * @file	common.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	25th Apr 2019
 * 	Last Update:	5th May 2019
 */
#ifndef _SETUP_H_
#define _SETUP_H_

#include "renderer.h"
#include "vec3.h" // Color
#include "yaml-cpp/yaml.h"
#include <iostream>

std::map<std::string, Color> color_table;
Vec3 load_vec(const YAML::Node & node) {
  Vec3 v;
  if (node.Type() == YAML::NodeType::Scalar)// In this case it is a color
    v = color_table[node.as<string>()];
  else if (node.Type() == YAML::NodeType::Sequence)
    v = Vec3(node[0].as<int>(), node[1].as<int>(),
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
    Point3 vup = load_vec(camera["up"]);
    string type = camera["type"].as<string>();
    if (type.compare("orthographic") == 0) {
      double left, right, bottom, top;
      auto dims = camera["vpdim"];
      left = dims[0].as<double>();
      right = dims[1].as<double>();
      bottom = dims[2].as<double>();
      top = dims[3].as<double>();
      r.camera = new OrthoCamera( origin, lookat, vup, left, right, 
          bottom, top);
    } 
    else if (type.compare("orthographic") == 0) {
      float fd = camera["fdistance"].as<int>();
      r.camera = new PerspectiveCamera( origin, lookat, vup,
          height, width, fd);
    }
    else {
      r.camera = new PerspectiveCamera( origin, lookat, vup,  
          height, width, 1);
    }
    cout << "Initializing buffer...\n";
    r.buffer = new Buffer(height, width);
  }
  catch (exception & e)
  {
    cerr << "Error parsing Camera:\n";
    cerr << e.what();
  }
}

/**
 * @brief Sets the renderer parsing a scene.yml file
 * @param r     The Renderer object
 * @param file  The file name to be parsed
 */
int setup(Renderer &r, string file="scene.yml") {
  Color c00, c01, c10, c11;
  YAML::Node config, bg, camera;
  try {
    config = YAML::LoadFile(file);
    bg = config["background"];
    camera = config["camera"];
    cout << "Initializing background...\n";
    setup_bg(bg, r);
    cout << "Initializing camera...\n";
    setup_camera(camera, r);
    cout << "Buffer complete...\n";
  }
  catch (std::exception & e) {
    cout << "Error loading config file:\n";
    cout << e.what() << "\n";
    throw e;
    return -1;
  }
  cout <<
">>> The Camera frame is:\n" <<
"    u" << r.camera->get_u() << "\n" <<
"    v" << r.camera->get_v() << "\n" <<
"    w" << r.camera->get_w() << "\n\n" <<
"    >>> Parsing scene successfuly done! <<<\n\n";
  return 0;
}

#endif// _SETUP_H_

