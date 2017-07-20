//
//  Encodage.h
//  compressJPEG
//
//  Created by syyprime on 2017/6/28.
//  Copyright © 2017年 OpenCV Moments. All rights reserved.
//

#ifndef Encodage_h
#define Encodage_h

#include <stdio.h>
#include <math.h>
#include <string.h>


#include "ImageFormat.h"
#include "ColorSpace.h"
#include "DCT.h"


//-------------------------------------------------------------
//------------------------Encodage DC--------------------------
//-------------------------------------------------------------

typedef struct
{
    int nb;
    int * data;
}DC;

DC extraireDC(DCAC tab);


int * DPCM(DCAC tab,int *freq);
//ecrire les frequences de chaque chiffre(-255~255) dans le tableau d'entré.
int ** intermediaDC(DCAC tab);
//DC de Format intermédiaire



//-------------------------------------------------------------
//------------------------Encodage AC--------------------------
//-------------------------------------------------------------


typedef struct
{
    int nb;
    int ** data;
}AC;

AC extraireAC(DCAC tab);


//zigzag
SingleDCAC zigzagSingle(SingleDCAC tab);
DCAC zigzag(DCAC tab);



//RLE

//---1. les résultas des blocs sont traités respectivement

int ** RLE(DCAC tab);
//retourner un pointeur qui a M lignes(m -- nb de blocs divisés de cette image)
//chaque ligne stocke du codage RLE correspondant à son bloc.

int longueurAC(DCAC tab);
//retourner le nombre des codages après RLE

int ** intermediaAC(DCAC tab);
//AC de Format intermédiaire


//---2. les résultas des blocs sont traités successivement

int * totalRLE(DCAC tab);
//retourner un pointeur qui stocke du codage RLE bloc par bloc.
//ecrire les frequences de chaque chiffre(-255~255) dans le tableau d'entré.

int totalLongueurAC(DCAC tab);
//retourner le nombre des codages après RLE

int ** totalIntermediaAC(DCAC tab);
//AC de Format intermédiaire






//Variable length 
char * VLI(int in);


#endif /* Encodage_h */
