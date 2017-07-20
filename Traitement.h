//
//  Traitement.h
//  compressJPEG
//
//  Created by syyprime on 2017/6/28.
//  Copyright © 2017年 OpenCV Moments. All rights reserved.
//

#ifndef Traitement_h
#define Traitement_h

#include <stdio.h>
#include <time.h>


#include "ImageFormat.h"
#include "ColorSpace.h"
#include "DCT.h"
#include "Encodage.h"
#include "Huffman.h"


void imageCompress(char const *in1,char const *in2,char const *in3,int ligneGarde,char const *out1,char const *out2,char const *out3,char const *out4,char const *out5,char const *out6,char const *outBin1,char const *outBin2,char const *outBin3,char const *outBin4,char const *outBin5,char const *outBin6);


#endif /* Traitement_h */
