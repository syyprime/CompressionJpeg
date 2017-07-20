//
//  ImageFormat.h
//  compressJPEG
//
//  Created by syyprime on 2017/6/28.
//  Copyright © 2017年 OpenCV Moments. All rights reserved.
//

#ifndef ImageFormat_h
#define ImageFormat_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//-------------------------------------------------------------
//-----------------------Format 1------------------------------
//-------------------unsigned char[][]-------------------------
//-------------------------------------------------------------
unsigned char ** createSimpleMat(int lig,int col);
void destroymat(unsigned char ** m);



//-------------------------------------------------------------
//-----------------------Format 2------------------------------
//-----------------------type Matrix---------------------------
//-------------------------------------------------------------
typedef struct
{
    int lig, col;
    unsigned char **mat;
}Matrix;


Matrix createMatrix(int lig,int col);
void destroyMatrix(Matrix T);

unsigned char ** extraireSimpleMat(Matrix T);



//-------------------------------------------------------------
//-----------------------Format 3------------------------------
//-----------------------type Image3---------------------------
//-------------------------------------------------------------
typedef struct
{
    unsigned char R;
    unsigned char G;
    unsigned char B;
} RGBQUAD;


typedef struct
{
    int lig;
    int col;
    RGBQUAD * data;
    RGBQUAD ** pixel;
}Image3;


Image3 createImage3(int nbLig, int nbCol);
void destroyImage3(Image3 m);Matrix * separer(Image3 img);

Matrix * separer(Image3 img);
Matrix extraire1(Image3 img);
Matrix extraire2(Image3 img);
Matrix extraire3(Image3 img);

Image3 combinerImage3(Matrix T1,Matrix T2,Matrix T3);





//-------------------------------------------------------------
//--------------------lecture des images-----------------------
//-------------------------------------------------------------

// la lecture des valeurs(simples et par ordre) des matrices
Image3 lectureImageRGB(const char *in,int lig,int col);
Matrix lectureMatrix(const char *in,int lig,int col);
unsigned char ** lectureSimpleMat(const char *in,int lig,int col);

// la lecture des matrices obtenues par Matblab
Matrix lectureMatlabMatrix(const char *in);
Image3 lectureMatlabRGB(const char *in1,const char *in2,const char *in3);




//-------------------------------------------------------------
//--------------------Ecriture des images----------------------
//-------------------------------------------------------------
void ecrireMatrix(Matrix T,char const *out);








#include <stdio.h>

#endif /* ImageFormat_h */
