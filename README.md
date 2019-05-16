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

### TODOS

- [x] Remove buffer from Renderer to Scene class
- [x] Move loop "intersection with objects" from Renderer to Scene
- [ ] Put pixels loop in  Integrator
- [ ] Implement save_img function in Renderer class

