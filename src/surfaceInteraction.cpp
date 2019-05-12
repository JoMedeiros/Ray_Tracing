/**@file	surfaceInteraction.cpp
 * @author	josivanmedeiros
 * @version	704
 * @date
 * 	Created:	25th Apr 2019
 * 	Last Update:	25th Apr 2019
 */

/*===========================================================================*/
/*=============================[ Constructors ]==============================*/
/*===========================================================================*/
#include "surfaceInteraction.h"
#include "primitive.h"

SurfaceInteraction::SurfaceInteraction(const Point3&p,const Vec3&n, 
    const Vec3&wo, float time, const Point2f& uv, const Primitive *pri )
{
  this->p = p;
  this->n = n;
  this->wo = wo;
  this->time = time;
  this->uv = uv;
  this->primitive = pri;
};

/*===========================================================================*/
/*================================[ Methods ]================================*/
/*===========================================================================*/



