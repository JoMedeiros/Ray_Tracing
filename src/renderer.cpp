/**
 * @file	renderer.cpp
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	12th May 2019
 * 	Last Update:	17th May 2019
 */
#include "renderer.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <algorithm>
#include <memory>
#include "flatMaterial.h"
#include <map>

using namespace std;

Renderer::Renderer() {
  // Initialize an empty scene
  this->scene = new Scene();
}

void Renderer::run() {
  integrator->render(*scene);
}
void Renderer::add_primitive(Sphere* & sp){
  scene->primitives.push_back(sp);
}

Vec3 Renderer::load_vec(const YAML::Node & node) {
  Vec3 v;
  if (node.Type() == YAML::NodeType::Scalar)// In this case it is a color
    v = color_table[node.as<string>()];
  else if (node.Type() == YAML::NodeType::Sequence) {
    v = Vec3(node[0].as<float>(), node[1].as<float>(),
        node[2].as<float>());
  }
  return v;
}
Color Renderer::load_color(const YAML::Node & color_node) {
  return load_vec(color_node);
}
/**
 * @brief Parses background node in .yml file to set Background 
 * object
 */
void Renderer::setup_bg(const YAML::Node & bg){
  try
  {
    if (YAML::Node color = bg["color"]) {
      scene->bg = new Background(load_color(color));
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
      scene->bg = new Background(colors_arr[0], colors_arr[1], colors_arr[2], 
          colors_arr[3]);
    }
    else {
      scene->bg = new Background(Color(255,255,255));
    }
  }
  catch (exception & e)
  {
    cerr << "Error parsing Background\n";
    cerr << e.what();
  }
}
/**
 * @brief Sets the camera
 */
void Renderer::setup_camera(const YAML::Node & camera) {
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
      float left, right, bottom, top;
      auto dims = camera["vpdim"];
      left = dims[0].as<float>();
      right = dims[1].as<float>();
      bottom = dims[2].as<float>();
      top = dims[3].as<float>();
      scene->camera = new OrthoCamera( origin, lookat, vup, left, right, 
          bottom, top);
    } 
    else if (type.compare("perspective") == 0) {
      float fd = camera["fdistance"].as<float>();
      float fovy = camera["fovy"].as<float>();
      float aspect_ratio = camera["aspect"].as<float>();
      scene->camera = new PerspectiveCamera( origin, lookat, vup,  
          fovy, aspect_ratio, fd);
    }
    cout << "Initializing buffer..\n";
    this->scene->buffer = new Buffer(height, width);
    auto img_file = camera["img_file"];
    if (img_file["name"].Type() == YAML::NodeType::Scalar)
      this->filename = img_file["name"].as<string>();
    if (img_file["type"].Type() == YAML::NodeType::Scalar)
      this->filetype = img_file["type"].as<string>();
  }
  catch (exception & e)
  {
    cerr << "Error parsing Camera:\n";
    cerr << e.what();
  }
}
/**
 * @brief Sets the scene
 */
void Renderer::setup_scene(const YAML::Node & scene) {
  auto materials = scene["materials"];
  map<string, shared_ptr<Material>> mat_lib;
  for (auto obj=materials.begin();obj!=materials.end();++obj) {
    string type = (*obj)["type"].as<string>();
    if (type.compare("flat") == 0) {
      Color color = load_vec((*obj)["diffuse"]);
      string mat_name = (*obj)["name"].as<string>();
      FlatMaterial mat(color);
      mat_lib[mat_name] = make_shared<FlatMaterial>(mat);
    }
  }

  auto objects = scene["objects"];
  for (auto obj = objects.begin(); obj != objects.end(); ++obj) {
    string type = (*obj)["type"].as<string>();
    if (type.compare("sphere") == 0) {
      string name = (*obj)["name"].as<string>();
      string mat = (*obj)["material"].as<string>();
      float radius = (*obj)["radius"].as<float>();
      Vec3 center = load_vec((*obj)["center"]);
      Sphere* sp = new Sphere(center, radius);
      sp->set_material(mat_lib[mat]);
      this->add_primitive(sp);
    }
  }
}
/**
 * @brief Initialize the running settings like the integrator
 */
void Renderer::setup_running(const YAML::Node & run){
  auto integrator = run["integrator"];
  string type = integrator["type"].as<string>();
  //size_t samples = integrator["spp value"].as<size_t>();
  if (type.compare("flat") == 0) {
    this->integrator=unique_ptr<FlatIntegrator>(
        new FlatIntegrator());
  }
  else if (type.compare("normal") == 0) {
    this->integrator=unique_ptr<NormalMapIntegrator>(
        new NormalMapIntegrator());
  }
  else if (type.compare("depth map") == 0) {
    this->integrator=unique_ptr<DepthIntegrator>(
        new DepthIntegrator());
  }
  
}
/**
 * @brief Sets the renderer parsing a scene.yml file
 * @param r     The Renderer object
 * @param file  The file name to be parsed
 */
void Renderer::setup( string file ) {
  Color c00, c01, c10, c11;
  YAML::Node config, bg, camera, scene, running;
  try {
    config = YAML::LoadFile(file);
    bg = config["background"];
    camera = config["camera"];
    scene = config["scene"];
    running = config["running"];
    cout << "Initializing background...\n";
    setup_bg(bg);
    cout << "Initializing camera...\n";
    setup_camera(camera);
    cout << "Buffer complete...\n";
    setup_scene(scene);
    cout << "Running setup...\n";
    setup_running(running);
  }
  catch (std::exception & e) {
    cout << "Error loading config file:\n";
    cout << e.what() << "\n";
    throw e;
  }
  cout <<
    ">>> The Camera frame is:\n" <<
    "    u" << this->scene->camera->get_u() << "\n" <<
    "    v" << this->scene->camera->get_v() << "\n" <<
    "    w" << this->scene->camera->get_w() << "\n\n" <<
    "    >>> Parsing scene successfuly done! <<<\n\n";
}
/**
 * @brief Saves image as fileformat
 */
void Renderer::save_img() {
  transform(this->filetype.begin(), this->filetype.end(), 
      this->filetype.begin(), ::tolower);

  // OBS: PNG is the default format so you dont need to specify
  if (this->filetype.compare("bmp") == 0)
     stbi_write_bmp((this->filename+".bmp").c_str(), 
     this->scene->buffer->width(),this->scene->buffer->height(), 
        3, this->scene->buffer->data());

  else if (this->filetype.compare("tga") == 0)
     stbi_write_tga((this->filename+".tga").c_str(), 
     this->scene->buffer->width(),this->scene->buffer->height(), 
        3, this->scene->buffer->data());

  else if (this->filetype.compare("jpg") == 0)
     stbi_write_jpg((this->filename+".jpg").c_str(), 
     this->scene->buffer->width(),this->scene->buffer->height(), 
        3, this->scene->buffer->data(), 95);

  // You need to convert the data to float to use hdr
  //else if (this->filetype.compare("hdr") == 0)
  //   stbi_write_hdr((this->filename+".hdr").c_str(), 
  //   this->scene->buffer->width(),this->scene->buffer->height(), 
  //      3, this->scene->buffer->data());
  else
    stbi_write_png((this->filename+".png").c_str(), 
        this->scene->buffer->width(), this->scene->buffer->height(), 
        3, this->scene->buffer->data(), 
        3*this->scene->buffer->width());
}

