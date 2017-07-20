//
//  DCT.h
//  compressJPEG
//
//  Created by syyprime on 2017/6/28.
//  Copyright © 2017年 OpenCV Moments. All rights reserved.
//

#ifndef DCT_h
#define DCT_h

#define PI 3.1415926
#define rad 1.41421356

#include <stdio.h>
#include <math.h>
#include <string.h>

#include "ColorSpace.h"
#include "ImageFormat.h"


//-------------------------------------------------------------
//-----------------------Image blocks--------------------------
//-------------------------------------------------------------

typedef struct
{
    unsigned char block[8][8];
}SingleBlock;

typedef struct
{
    int lig;
    int col;
    int nb;
    SingleBlock * data;
    SingleBlock ** pos;
}ImageBlock;

//stocker une matrice structurelle de format pertinent en la divisant
ImageBlock diviserMatrix(Matrix T);
void destroyBlocks(ImageBlock blc);

//stocker une image structurelle de format pertinent en la divisant
ImageBlock diviser1erPlan(Image3 img);
ImageBlock diviser2emPlan(Image3 img);
ImageBlock diviser3emPlan(Image3 img);



//-------------------------------------------------------------
//------------------------DCAC blocks--------------------------
//-------------------------------------------------------------


typedef struct
{
    int DC;
    int AC[63];
}SingleDCAC;

SingleDCAC transDCT(SingleBlock blc);


typedef struct
{
    int lig;
    int col;
    int nb;
    SingleDCAC * data;
    SingleDCAC ** pos;
}DCAC;


//le resultat final après la partition de région et zero-padding
DCAC createDCAC(Matrix T);




//-------------------------------------------------------------
//----------------------Quantification-------------------------
//-------------------------------------------------------------


SingleDCAC quantification(SingleDCAC tab , int L1UV2, int longueurGarde);
//int L1UV2 -- valeur 1 pour la Luminance ; valeur 2 pour les chrominances
//int longueurGarde -- la longueur de lig/col gardé variant de 2 à 6

DCAC quantificationY(DCAC tab , int longueurGarde);
DCAC quantificationCbCr(DCAC tab , int longueurGarde);






#endif /* DCT_h */
