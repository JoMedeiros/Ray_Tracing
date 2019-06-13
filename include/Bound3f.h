/**
 * @file  Bound3f.h
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  13 jun 2019
 *  Last Update: 13 jun 2019 (14:19:02)
 */
#ifndef BOUND3F_H
#define BOUND3F_H

#include "vec3.h"

struct Bounds3f {
  Bounds3f (Point3 lb, Point3 ub) : lower_bound(lb), upper_bound(ub)
  {/* Empty */}
  Point3 lower_bound;
  Point3 upper_bound;
};

#endif //BOUND3F_H

