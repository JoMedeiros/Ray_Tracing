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
  : p{p}, n{n}, wo{wo}, time{time}, uv{uv}, primitive{pri}{};

/*===========================================================================*/
/*================================[ Methods ]================================*/
/*===========================================================================*/



