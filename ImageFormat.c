//
//  ImageFormat.c
//  compressJPEG
//
//  Created by syyprime on 2017/6/28.
//  Copyright © 2017年 OpenCV Moments. All rights reserved.
//

#include "ImageFormat.h"


//-------------------------------------------------------------
//-----------------type unsigned char[][]----------------------
//-------------------------------------------------------------

unsigned char ** createSimpleMat(int lig,int col)
{
    unsigned char ** m = (unsigned char **)malloc(lig*sizeof(unsigned char *));
    for (int i = 0; i < lig; i++)
    {
        m[i] = (unsigned char *)malloc(col*sizeof(unsigned char));
    }
    return m;
}


void destroymat(unsigned char ** m)
{
    free(m);
}




//-------------------------------------------------------------
//-----------------------type Matrix---------------------------
//-------------------------------------------------------------


//initialiser une matrice de taille lig*col avec des valeurs zéros
Matrix createMatrix(int lig,int col)
{
    Matrix T = {0,0,NULL};
    
    T.mat = (unsigned char **)malloc(lig*sizeof(unsigned char *));
    for (int i = 0; i < lig; i++)
    {
        T.mat[i] = (unsigned char *)malloc(col*sizeof(unsigned char));
    }
    T.lig = lig;
    T.col = col;
    
    for (int i = 0; i < lig; i++)
    {
        for (int j = 0; j < col; j++)
        {
            T.mat[i][j] = 0;
        }
    }
    
    return T;
}


//liberer la matrice d'entrée
void destroyMatrix(Matrix T)
{
    for (int i = 0; i < T.lig; i++)
    {
        free(T.mat[i]);
        T.mat[i] = NULL;
    }
    free(T.mat);
}


// extraire la matrice simple d'une matrice structurelle
unsigned char ** extraireSimpleMat(Matrix T)
{
    int lig = T.lig;
    int col = T.col;
    
    unsigned char ** m = createSimpleMat(lig, col);
    for (int i = 0; i < lig; i++)
    {
        for (int j = 0; j < col; j++)
        {
            m[i][j] = T.mat[i][j];
        }
    }
    return m;
}





//-------------------------------------------------------------
//-----------------------type Image3---------------------------
//-------------------------------------------------------------


//créer une image du format défini(Image3)
Image3 createImage3(int lig, int col)
{
    
    Image3 img = {0,0,NULL,NULL};
    
    img.lig = lig;
    img.col = col;
    img.data = (RGBQUAD*)malloc(lig*col*sizeof(RGBQUAD));
    
    if (img.data == NULL)
        return img;
    
    img.pixel = (RGBQUAD**)malloc(lig*sizeof(RGBQUAD*));
    if (img.pixel == NULL)
    {
        free(img.data);
        img.data = NULL;
        return img;
    }
    
    for (int i=0;i<lig;i++)
        img.pixel[i] = &(img.data[i*col]);
    
    return img;
}


// liberer image3
void destroyImage3(Image3 m)
{
    if (m.data != NULL) {
        free(m.data);
        m.data = NULL;
    }
    if (m.pixel != NULL) {
        free(m.pixel);
        m.pixel = NULL;
    }
}


//séparer une image(de type imge3) en 3 plans
Matrix * separer(Image3 img)
{
    static Matrix  composant[3];
    int lig = img.lig;
    int col = img.col;
    composant[0].lig = composant[1].lig = composant[2].lig = lig;
    composant[0].col = composant[1].col = composant[2].col = col;
    
    for (int i=0; i<lig ; i++)
    {
        for (int j=0; j<col; j++)
        {
            composant[0].mat[i][j] = img.pixel[i][j].R;
            composant[1].mat[i][j] = img.pixel[i][j].G;
            composant[2].mat[i][j] = img.pixel[i][j].B;
        }
    }
    
    return composant;
}


Matrix extraire1(Image3 img)
{
    int lig = img.lig;
    int col = img.col;
    Matrix m = createMatrix(lig,col);
    
    for (int i=0; i<lig ; i++)
    {
        for (int j=0; j<col; j++)
        {
            m.mat[i][j] = img.pixel[i][j].R;
        }
    }
    
    return m;
}



Matrix extraire2(Image3 img)
{
    int lig = img.lig;
    int col = img.col;
    Matrix m = createMatrix(lig,col);
    
    for (int i=0; i<lig ; i++)
    {
        for (int j=0; j<col; j++)
        {
            m.mat[i][j] = img.pixel[i][j].G;
        }
    }
    
    return m;
}



Matrix extraire3(Image3 img)
{
    int lig = img.lig;
    int col = img.col;
    Matrix m = createMatrix(lig,col);
    
    for (int i=0; i<lig ; i++)
    {
        for (int j=0; j<col; j++)
        {
            m.mat[i][j] = img.pixel[i][j].B;
        }
    }
    
    return m;
}




//intégrer 3 composantes des couleurs plans
Image3 combinerImage3(Matrix T1,Matrix T2,Matrix T3)
{
    
    int lig = T1.lig;
    int col = T1.col;
    
    Image3 img = createImage3(lig,col);
    
    for (int i=0; i<lig ; i++)
    {
        for (int j=0; j<col; j++)
        {
            img.pixel[i][j].R = T1.mat[i][j];
            img.pixel[i][j].G = T2.mat[i][j];
            img.pixel[i][j].B = T3.mat[i][j];
        }
    }
    
    return img;
}




//-------------------------------------------------------------
//--------------------lecture des images-----------------------
//-------------------------------------------------------------


//lecture de l'images de type Image3
Image3 lectureImageRGB(const char *in,int lig,int col)
{
    //char buf;
    FILE *F = NULL;
    Image3 img = {lig,col,NULL,NULL};
    
    if ( (F = fopen(in,"rb+")) == NULL)
    {
        printf("Pb image inexistante");
    }
    
    img = createImage3(lig,col);
    fread(img.data,sizeof(RGBQUAD),col*lig,F);
    fclose(F);
    
    return img;
    
}


//lecture de l'images de type Matrix
Matrix lectureMatrix(const char *in,int lig,int col)
{
    //char buf;
    FILE *F = NULL;
    Matrix mat = {lig,col,NULL};
    
    if ( (F = fopen(in,"rb+")) == NULL)
    {
        printf("Pb composante de l'image inexistante");
    }
    
    mat = createMatrix(lig, col);
    fread(mat.mat,sizeof(unsigned char),col*lig,F);
    fclose(F);
    
    return mat;
    
}

//lecture de l'images de type simpleMat
unsigned char ** lectureSimpleMat(const char *in,int lig,int col)
{
    //char buf;
    FILE *F = NULL;
    unsigned char ** mat = NULL;
    
    if ( (F = fopen(in,"rb+")) == NULL)
    {
        printf("Pb composante de l'image inexistante");
    }
    
    mat = createSimpleMat(lig, col);
    for(int i = 0;i<lig;i++)
    {
        unsigned char * lig = (unsigned char*)mat[i];
        fread(lig,sizeof(unsigned char),col,F);
    }
    
    fclose(F);
    
    return mat;
    
}




// les matrices de Matlab

Matrix lectureMatlabMatrix(const char *in)
{
    FILE *F = NULL;
    
    int lig = 0;
    int col = 0;
    char comma = ',';
    char shift = '\n';
    char *buf = (char *)malloc(sizeof(unsigned char));
    
    if ( (F = fopen(in,"rb+")) == NULL)
    {
        printf("Pb composante de l'image inexistante");
    }
    
    
    // obtenir le nb de col en lisant la 1ere ligne
    while(!feof(F))
    {
        fread(buf,1,1,F);
        if(*buf == comma)
        {
            col++;
        }
        if( *buf == shift)
            break;
    }
    col++;
    
    //obtenir le nb de ligne en comptant des shift
    while(!feof(F))
    {
        fread(buf,1,1,F);
        if(*buf == shift)
        {
            lig++;
        }
    }
    
    //allocation de la matrice avec des tailles obtenues
    
    Matrix T = createMatrix(lig, col);
    
    int i = 0;
    int j = 0;
    int pr = 0;
    F = fopen(in,"rb+");
    while(!feof(F))
    {
        fread(buf,1,1,F);
        //printf("%c ",*buf);
        
        if(*buf != comma && *buf != shift)
            pr = pr *10 +(int)(*buf - '0');
        
        if(*buf == comma)
        {
            T.mat[i][j] = (pr);
            j++;
            pr =0;
            
        }
        if(*buf == shift)
        {
            if(i == lig)
                break;
            
            
            T.mat[i][j] = (pr);
            i++;
            j=0;
            pr = 0;
        }
    }
    
    fclose(F);
    return T;
}


Image3 lectureMatlabRGB(const char *in1,const char *in2,const char *in3)
{
    Matrix T1 = lectureMatlabMatrix(in1);
    Matrix T2 = lectureMatlabMatrix(in2);
    Matrix T3 = lectureMatlabMatrix(in3);
    Image3 img = combinerImage3(T1,T2,T3);
    
    return img;
    
}


//-------------------------------------------------------------
//--------------------Ecriture des images----------------------
//-------------------------------------------------------------


//ecrire la matrice (un pixel chaque ligne)
void ecrireMatrix(Matrix T,char const *out)
{
    FILE *F=fopen(out,"w");
    for(int i=0;i<T.lig;i++)
    {
        for(int j=0;j<T.col;j++)
        {
            fprintf(F,"%d\n",T.mat[i][j]);
        }
    }
    
    fclose(F);
}


