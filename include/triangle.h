/**
 * @file	include/triangle.h
 * @author	josivanmedeiros
 * @version	1
 * @date
 *  Created: 12 may 2019
 *  Last Update: 13 jun 2019 (19:56:58)
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "vec3.h"
#include "shape.h"
#include "triangleMesh.h"
#include "Bound3f.h"

/*class Triangle : public Shape {
  private:
    int *v; // Pointer to an index array
    shared_ptr<TriangleMesh> mesh;
    Vec3 v0;
    Vec3 v1;
    Vec3 v2;
    bool culling;
  public:*/
    /**
     * @brief Triangle class constructor
     */
    /*Triangle(Vec3 p0, Vec3 p1, Vec3 p2){
      v0 = p0;
      v1 = p1;
      v2 = p2;
      culling = false;
    }*/
    /**
     * @brief Calls the intersection function of the shape.
     *
     * @param r The ray to intersect the shape.
     * @param s A class to store informations about the intersection
     * if it exists.
     *
     * @return True if the ray intersects the object, false 
     * otherwise.
     */
    //virtual bool intersect( const Ray& r, SurfaceInteraction *s) const;
    /**
     * @brief Simpler & faster version of intersection that only 
     * return true/false. It does not compute the hit point 
     * information
     *
     * @param r The ray to intersect the shape.
     *
     * @return True if the ray intersects the object, false 
     * otherwise.
     */
    //virtual bool intersect_p( const Ray& r ) const;
//};
class Triangle : public Shape {
	private:
		int *v; // Pointer to an index array stored elsewhere (triangle mesh) in memory.
		// After the proper triangle initialization, we may access v[0], v[1], and v[2]
		shared_ptr<TriangleMesh> mesh;
		bool backface_cull; // Set it `true` to turn backface culling.
    int id;

	public:
		Triangle( shared_ptr<TriangleMesh> _mesh, int tri_id, 
      bool bfc=true ) : Shape(), mesh{_mesh}, backface_cull{bfc}, 
      id{tri_id}{ 
        this->v = &(_mesh->vertexIndices[ 3 * tri_id ]); 
      }
		// Return the triangle's bounding box.
		Bounds3f object_bound() const;
		bool intersect(const Ray &ray, SurfaceInteraction *isect ) const;
		bool intersect_p( const Ray &ray ) const;
};


#endif
