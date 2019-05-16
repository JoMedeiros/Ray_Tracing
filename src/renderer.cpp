#include "renderer.h"
#include "ray.h"
#include "sphere.h"
#include <iostream>

using namespace std;

Renderer::Renderer() {
  // Initialize an empty scene
  this->scene = new Scene();
}

void Renderer::run() {
  int w = scene->buffer->width();
  int h = scene->buffer->height();
  float a = 0.25;
  Color mat = Color(0,175, 125);
	for ( int j = h-1; j >= 0; --j ) {
		for ( int i = 0; i < w; ++i ) {
			float v = float(i+0.5) / float(w), 
            u = float(j+0.5) / float(h);
      Ray ray = scene->camera->generate_ray(v, u);
      //Ray ray = camera->generate_ray( float(i)/float(w), 
          //float(j)/ float(h));
      cout << "pixel (" << j << ", " << i << ") " 
        << "ray: " << ray << "\n";
      Color color = scene->bg->sample(u, v);
      if (scene->intersect_p(ray)) color = Color (255,0,0);
      //for ( Primitive*& p : scene->primitives ) {
      //  SurfaceInteraction* s = new SurfaceInteraction();
      //  bool hit = p->intersect( ray, s );
      //  if ( hit ){
      //    color = 0.5*255.0*(Vec3(1,1,1) + s->n);
      //    float m = dot(s->n, scene->camera->get_w());
      //    color = (m+a)*mat;
      //      //cout << "Normal: " << s->n.x();
      //  }
      //}
      scene->buffer->paint( i, j, color );
		}
	}
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
  for (auto obj = scene.begin(); obj != scene.end(); ++obj) {
    string type = (*obj)["type"].as<string>();
    if (type.compare("sphere") == 0) {
      string name = (*obj)["name"].as<string>();
      float radius = (*obj)["radius"].as<float>();
      Vec3 center = load_vec((*obj)["center"]);
      Sphere* sp = new Sphere(center, radius);
      this->add_primitive(sp);
    }
  }
}
/**
 * @brief Initialize the Renderer settings loading file
 */
/**
 * @brief Sets the renderer parsing a scene.yml file
 * @param r     The Renderer object
 * @param file  The file name to be parsed
 */
void Renderer::setup( string file ) {
  Color c00, c01, c10, c11;
  YAML::Node config, bg, camera, scene;
  try {
    config = YAML::LoadFile(file);
    bg = config["background"];
    camera = config["camera"];
    scene = config["scene"];
    cout << "Initializing background...\n";
    setup_bg(bg);
    cout << "Initializing camera...\n";
    setup_camera(camera);
    cout << "Buffer complete...\n";
    setup_scene(scene);
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

