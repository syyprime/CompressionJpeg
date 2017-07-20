//
//  ColorSpace.h
//  compressJPEG
//
//  Created by syyprime on 2017/6/28.
//  Copyright © 2017年 OpenCV Moments. All rights reserved.
//

#ifndef ColorSpace_h
#define ColorSpace_h

#include <stdio.h>
#include <math.h>

#include "ImageFormat.h"


Image3 rgb2ycbcr(Image3 img);

Matrix getY(Image3 img);
Matrix getCb(Image3 img);
Matrix geCr(Image3 img);


Image3 ycbcr2rgb(Image3 img);

#endif /* ColorSpace_h */
