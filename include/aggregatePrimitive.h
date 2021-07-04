/**
 * @file  aggregatePrimitive.h
 * @author  Josivan Medeiros
 * @version
 * @brief
 * @date
 *  Created:  30 mai 2019
 *  Last Update: 30 mai 2019 (15:17:02)
 */
#ifndef AGGREGATE_PRIMITIVE_H
#define AGGREGATE_PRIMITIVE_H

#include "primitive.h"
#include <vector>

class AggregatePrimitive : public Primitive {
  public:
    AggregatePrimitive();
    vector<Primitive> primitives;
};

#endif //AGGREGATE_PRIMITIVE_H

