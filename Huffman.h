//
//  Huffman.h
//  compressJPEG
//
//  Created by syyprime on 2017/6/29.
//  Copyright © 2017年 OpenCV Moments. All rights reserved.
//

#ifndef Huffman_h
#define Huffman_h

#include <stdio.h>
#include <math.h>
#include <string.h>


#include "ImageFormat.h"
#include "ColorSpace.h"
#include "DCT.h"
#include "Encodage.h"


//-------------------------------------------------------------
//--------------------------Huffman----------------------------
//-----------------------arbre à créer-------------------------
//-------------------------------------------------------------




//-------------------------------------------------------------
//--------------------------Huffman----------------------------
//---------------------arbre prédéfini-------------------------
//-------------------------------------------------------------

void HuffmanLumAC(int ** data,int longueur,char const *out);
void HuffmanChrAC(int ** data,int longueur,char const *out);
void HuffmanLumDC(int ** data,int ligneGarde,char const *out);
void HuffmanChrDC(int ** data,int ligneGarde,char const *out);



//-------------------------------------------------------------
//-------------------------Ecriture----------------------------
//-------------------------------------------------------------

void ecrireLuminanceAC(Matrix T,int ligneGarde,char const *out);
void ecrireChrominanceAC(Matrix T,int ligneGarde,char const *out);
void ecrireLuminanceDC(Matrix T,int ligneGarde,char const *out);
void ecrireChrominanceDC(Matrix T,int ligneGarde,char const *out);

void ecritureBinaire(const char *in,const char *out);


#endif /* Huffman_h */
