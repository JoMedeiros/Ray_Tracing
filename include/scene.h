/**
 * @file	scene.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created:	12th May 2019
 * 	Last Update:	12th May 2019
 */
#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <vector>
#include "light.h"
#include "primitive.h"
#include "buffer.h"
#include "camera.h"
#include "background.h"

class Scene {
  //=== Public data
  public:
    Scene(){};
    Background* bg;
    Buffer* buffer;
    Camera* camera;
    vector<Primitive*> primitives;
    vector<unique_ptr<Light>> lights; // list of lights
    shared_ptr< Background > background; // The background object.
  //private:
    shared_ptr<Primitive> aggregate; // The scene graph of objects, acceleration structure.

    //=== Public interface
  public:
    Scene( shared_ptr<Primitive> ag, const vector<shared_ptr<Light>>& ls )
    //  : lights{ls}
    //, aggregate{ag}
    {/* empty */}
    /// Determines the intersection info; return true if there is an intersection.
    bool intersect( const Ray& r, SurfaceInteraction *isect ) const;
    /*! A faster version that only determines whether there is an intersection or not;
     * it doesn't calculate the intersection info.
     */
    bool intersect_p( const Ray& r ) const;
};

#endif // SCENE_H

