# Ray Tracing

## How to Compile

To parse files the program needs yaml-cpp library. Currently the library files
are installed locally. If you have yaml-cpp installed, change the makefile to
link with the yaml-cpp directory in your system. To compile:
```
make
```

## Usage

```
./bin/img_gen <yaml_file> > <log_file>
```

## Checklist

- [x] Buffer
- [ ] Scene Parser 
  - [x] Parse camera
  - [x] Parse background
  - [x] Parse spheres
  - [ ] Parse integrator
  - [ ] Parse lights
- [ ] Background
  - [x] 4 points gradient
  - [ ] image as background
- [ ] Camera
  - [x] OrthoCamera
  - [ ] PerspectiveCamera
- [x] Sphere
- [ ] Triangle
- [ ] main loop
- [ ] Sampler

### TODOS

- [ ] set output file name from the yaml file
- [ ] choose file format from yaml file
- [ ] put background in yaml file inside scene tag
- [ ] Implement class as specified in the code examples of 
project 4
- [x] Remove buffer from Renderer to Scene class
- [x] Move loop "intersection with objects" from Renderer to Scene
- [x] Put pixels loop in  Integrator
- [ ] Implement DepthIntegrator
  - [ ] Allow user to set start and end color
  - [ ] Allow user to set min a max distances
- [x] Implement NormalMapIntegrator
- [ ] Implement Material
- [ ] create Triangle class
- [ ] create Triangle Mesh class
- [ ] Implement BVH
- [ ] Parse OBJ
- [ ] Implement save_img function in Renderer class
- [ ] Implement Sampler class
- [ ] Implement BlinnPhongIntegrator
- [ ] Move camera from Scene to Integrator

