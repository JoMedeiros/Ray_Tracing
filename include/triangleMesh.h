/**
 * @file  triangleMesh.h
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  11 jun 2019
 *  Last Update: 13 jun 2019 (18:51:01)
 */
#ifndef TRIANGLE_MESH_H
#define TRIANGLE_MESH_H

#include <vector>
#include <memory>
#include "vec3.h"
#include "vec2.h"

using namespace std;

struct TriangleMesh {
    int nTriangles; //!< # of triangles in the mesh.
    vector<int> vertexIndices; //!< The list of indices that make up each individual triangle.

    // Here comes the data associated with each vertex.
    unique_ptr< Point3[] > points;   //!< The 3D geometric coordinates
    unique_ptr< Vec3[] > normals; //!< The 3D normals.
    unique_ptr< Point2f[] > uv;       //!< The 2D texture coordinages (might be 3D, if necessary).

    // Regular constructor
    TriangleMesh( int nTri, const int *indices,	int nVertices, 
        const Point3 *p, const Vec3 *n, const Point2f *uv ) {
      this->nTriangles = nTri;
      this->points = std::unique_ptr<Point3[]>(new Point3[nVertices]());
      this->normals = std::unique_ptr<Vec3[]>(new Point3[nTri]());
      this->uv = std::unique_ptr<Point2f[]>(new Point2f[nTri]());
      for (int i=0; i < nVertices; ++i){
        this->points[i] = p[i];
      }
      for (int i=0; i < 3*nVertices; ++i)
        this->vertexIndices.push_back(indices[i]);
      for (int i=0; i < nTri; ++i){
        this->normals[i] = n[i];
        this->uv[i] = uv[i];
      }
    }
};

#endif //TRIANGLE_MESH_H

