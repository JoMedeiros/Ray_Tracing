/**
 * @file	renderer.cpp
 * @author	Josivan Medeiros
 * @version	1
 * @date
 *  Created:  12 may 2019
 *  Last Update: 13 jun 2019 (20:08:45)
 */
#include "renderer.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <algorithm>
#include <memory>
#include "flatMaterial.h"
#include "blinnPhongMaterial.h"
#include <map>
#include "ambientLight.h"
#include "pointLight.h"
#include "directionalLight.h"

using namespace std;

/**
 * @brief Sets the scene
 */
void Renderer::setup_scene(const YAML::Node & scene) {
  map<string, shared_ptr<Material>> mat_lib;
  auto materials = scene["materials"];
  try {
    for (auto obj=materials.begin();obj!=materials.end();++obj) {
      string type = (*obj)["type"].as<string>();
      if (type.compare("flat") == 0) {
        Color color = load_vec((*obj)["diffuse"]);
        string mat_name = (*obj)["name"].as<string>();
        mat_lib[mat_name] = shared_ptr<FlatMaterial>(
            new FlatMaterial(color));
      }
      else if (type.compare("blinn") == 0) {
        string mat_name = (*obj)["name"].as<string>();
        Color ka = load_vec((*obj)["ambient"]);
        Color kd = load_vec((*obj)["diffuse"]);
        Color ks = load_vec((*obj)["specular"]);
        float glossiness = (*obj)["glossiness"].as<float>();
        mat_lib[mat_name] = shared_ptr<BlinnPhongMaterial>(
          new BlinnPhongMaterial( ka, kd, ks, glossiness ));
      }
    }
  }
  catch (exception & e) {
    cerr << "Error loading materials\n";
    cerr << e.what();
  }
  try {
    auto objects = scene["objects"];
    for (auto obj = objects.begin(); obj != objects.end(); ++obj) {
      string type = (*obj)["type"].as<string>();
      if (type.compare("sphere") == 0) {
        string name = (*obj)["name"].as<string>();
        string mat = (*obj)["material"].as<string>();
        float radius = (*obj)["radius"].as<float>();
        Vec3 center = load_vec((*obj)["center"]);
        Sphere* sp = new Sphere(center, radius);
        GeometricPrimitive * gp = new GeometricPrimitive(sp);
        if (auto mate = mat_lib[mat])
          gp->set_material(mat_lib[mat]);
        else throw invalid_argument("material not in library\n");
        this->add_primitive(gp);
      }
      /*else if (type.compare("triangle") == 0) {
        string name = (*obj)["name"].as<string>();
        string mat = (*obj)["material"].as<string>();
        Vec3 p0 = load_vec((*obj)["v0"]);
        Vec3 p1 = load_vec((*obj)["v1"]);
        Vec3 p2 = load_vec((*obj)["v2"]);
        Triangle* t = new Triangle(p0, p1, p2);
        GeometricPrimitive * gp = new GeometricPrimitive(t);
        if (auto mate = mat_lib[mat]) 
          gp->set_material(mat_lib[mat]);
        else throw invalid_argument("Integrator is not valid. The"
            " valid integrators are:\nflat\nnormal\ndepth_map\n");
        this->add_primitive(gp);
      }*/
      else if (type.compare("trianglemesh") == 0) {
        string name = (*obj)["name"].as<string>();
        string mat = (*obj)["material"].as<string>();
        int nTri = (*obj)["ntriangles"].as<int>();
        auto is = (*obj)["indices"];
        auto vs = (*obj)["vertices"];
        auto ns = (*obj)["normals"];
        auto uvs = (*obj)["uv"];
        int indices[is.size()];
        Vec3 vertices[vs.size()];
        Vec3 normals[nTri];
        Vec2 uv_s[uvs.size()];
        for (size_t i=0; i < is.size();i++){
          indices[i] = is[i].as<int>();
        }
        int i = 0;
        for (size_t i=0; i < ns.size();i++) {
          normals[i] = load_vec(ns[i]);
        }
        for (auto v = vs.begin(); v != vs.end(); ++v) {
          vertices[i] = load_vec(*v);
          cout << "vertice " << i << ": " << vertices[i] << "\n";
          ++i;
        }
        cout << "vertices in renderer.cpp:\n";
        for (int i=0;i < 4; ++i)
          cout << vertices[i] << "\n";

        i = 0;
        for (auto uv = uvs.begin(); uv != uvs.end(); ++uv) {
          uv_s[i] = load_vec2(*uv);
          ++i;
        }
        //TriangleMesh tm( nTri, indices, vs.size(), vertices, 
            //normals, uv_s );
        shared_ptr<TriangleMesh> tm_ptr(
              new TriangleMesh( nTri, indices, vs.size(), 
                vertices, normals, uv_s ) );
        for (int i=0; i < nTri; i++) {
          Triangle* t = new Triangle( tm_ptr, i );
          GeometricPrimitive * gp = new GeometricPrimitive(t);
          if (auto mate = mat_lib[mat])
            gp->set_material(mat_lib[mat]);
          else throw invalid_argument("material not in library\n");
          this->add_primitive(gp);
          cout << "triangle added in renderer.cpp\n";
        }
      }
    }
  }
  catch (exception & e) {
    cerr << "Error loading objects\n";
    cerr << e.what();
  }
  setup_lights(scene["lights"]);
}
/**
 * @brief Default Constructor
 */
Renderer::Renderer() {
  // Initialize an empty scene
  this->scene = new Scene();
}
/**
 * @brief Render image
 */
void Renderer::run() {
  cout << "Calling integrator render...\n";
  integrator->render(*scene);
}
/**
 * @brief Inserts a Primitive object in the scene
 *
 * @param sp  A Sphere object.
 */
void Renderer::add_primitive(Primitive* sp){
  scene->primitives.push_back(sp);
}

/**
 * @brief Loads a Vec3 described in a yaml node
 *
 * @param node  The node reference in the format:
 *
 * [ x, y, z ]
 * or:
 * - x
 * - y
 * - z
 *
 * @return  A Vec3 object initialized with {x, y, z}
 */
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
/**
 * @brief Loads a Vec2 described in a yaml node
 *
 * @param node  The node reference in the format:
 *
 * [ x, y ]
 * or:
 * - x
 * - y
 *
 * @return  A Vec2 object initialized with {x, y}
 */
Vec2 Renderer::load_vec2(const YAML::Node & node) {
  Vec2 v;
  if (node.Type() == YAML::NodeType::Sequence) {
    v = Vec2(node[0].as<float>(), node[1].as<float>());
  }
  return v;
}
/**
 * @brief Loads a color from a yaml node
 *
 * @param color_node The node in this format in .yml file:
 * [ x, y, z ] 
 * or:
 * - x
 * - y
 * - z
 *
 * @return 
 */
Color Renderer::load_color(const YAML::Node & color_node) {
  return load_vec(color_node);
}
/**
 * @brief Parses background node in .yml file to set Background 
 * object
 *
 * @param bg The background node. It should contain 4 colors as
 * described in `load_vec` function.
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
 * @brief Parses the lights node in yml file and sets the lights.
 *
 * @param lights The yaml Node.
 */
void Renderer::setup_lights(const YAML::Node & lights) {
  try {
    for (auto l = lights.begin(); l != lights.end(); ++l) {
      string type = (*l)["type"].as<string>();
      if (type.compare("ambient") == 0) {
        Color intensity = load_vec((*l)["intensity"]);
        this->scene->lights.push_back(unique_ptr<AmbientLight>(
              new AmbientLight(intensity)));
      }
      else if (type.compare("point") == 0) {
        Color intensity = load_vec((*l)["intensity"]);
        Color position = load_vec((*l)["position"]);
        this->scene->lights.push_back(unique_ptr<PointLight>(
              new PointLight(position, intensity)));
      }
      else if (type.compare("directional") == 0) {
        Color intensity = load_vec((*l)["intensity"]);
        Color direction = load_vec((*l)["direction"]);
        this->scene->lights.push_back(unique_ptr<DirectionalLight>(
              new DirectionalLight(direction, intensity)));
      }
    }
  }
  catch (exception & e) {
    cerr << "Error loading file\n";
  }
}
/**
 * @brief Initialize the running settings like the integrator
 */
void Renderer::setup_running(const YAML::Node & run){
  auto integrator = run["integrator"];
  string type = integrator["type"].as<string>();
  size_t samples = integrator["spp value"].as<size_t>();
  shared_ptr<Sampler> sampler(new Sampler(samples));
  shared_ptr<Camera> cam(scene->camera);
  if (type.compare("flat") == 0) {
    this->integrator=unique_ptr<FlatIntegrator>(
        new FlatIntegrator(cam, sampler));
  }
  else if (type.compare("normal") == 0) {
    this->integrator=unique_ptr<NormalMapIntegrator>(
        new NormalMapIntegrator(cam, sampler));
  }
  else if (type.compare("depth_map") == 0) {
    try {
      Color near_color = load_color(integrator["near_color"]);
      Color far_color = load_color(integrator["far_color"]);
      float near_value = integrator["near_value"].as<float>();
      float far_value = integrator["far_value"].as<float>();
      this->integrator= unique_ptr<DepthIntegrator>(
          new DepthIntegrator(cam, sampler, near_color, far_color, near_value, 
            far_value));
    }
    catch (exception & e) {
      this->integrator= unique_ptr<DepthIntegrator>(
          new DepthIntegrator(cam, sampler));
    }
  }
  else if (type.compare("blinn_phong") == 0) {
    this->integrator=unique_ptr<BlinnPhongIntegrator>(
        new BlinnPhongIntegrator( cam, sampler ));
  }
  else {
    throw invalid_argument("Integrator is not valid. The valid"
        "integrators are:\nflat\nnormal\ndepth_map\n");
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

