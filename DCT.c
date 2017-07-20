//
//  DCT.c
//  compressJPEG
//
//  Created by syyprime on 2017/6/28.
//  Copyright © 2017年 OpenCV Moments. All rights reserved.
//

#include "DCT.h"




//-------------------------------------------------------------
//------------------------Image Blocks-------------------------
//-------------------------------------------------------------


//stocker une matrice structurelle de format pertinent en la divisant
ImageBlock diviserMatrix(Matrix T)
{
    ImageBlock blc = {0,0,0,NULL,NULL};
    blc.lig = ceil(T.lig/8.00);
    blc.col = ceil(T.col/8.00);
    blc.nb = blc.lig * blc.col;
    
    
    blc.data = (SingleBlock*)malloc(blc.nb*sizeof(SingleBlock)); //allocation
    if (blc.data == NULL)
        return(blc);
    
    blc.pos = (SingleBlock**)malloc(blc.lig*sizeof(SingleBlock *));
    for (int i=0;i<blc.lig;i++)
        blc.pos[i] = &(blc.data[i*blc.col]);
    
    
    //position des blocks
    for(int m = 0; m<blc.lig ;m++)
    {
        for(int n = 0; n<blc.col ;n++)
        {
            //position dedans chaque block
            for(int i = 0; i<8 ;i++)
            {
                for(int j = 0; j<8 ;j++)
                {
                    if(8*m+i>T.lig || 8*n+j>T.col)
                        blc.pos[m][n].block[i][j] =0;
                    else if(8*m+i<T.lig && 8*n+j<T.col)
                        blc.pos[m][n].block[i][j] = T.mat[8*m+i][8*n+j];
                }
            }
        }
    }
    
    
    return blc;
}


// liberer blocks
void destroyBlocks(ImageBlock blc)
{
    if (blc.data != NULL) {
        free(blc.data);
        blc.data = NULL;
    }
    if (blc.pos != NULL) {
        free(blc.pos);
        blc.pos = NULL;
    }
}





//stocker une image structurelle de format pertinent en la divisant
ImageBlock diviser1erPlan(Image3 img)
{
    Matrix T;
    T = extraire1(img);
    ImageBlock blc = diviserMatrix(T);
    
    return blc;
}

ImageBlock diviser2emPlan(Image3 img)
{
    Matrix T;
    T = extraire2(img);
    ImageBlock blc = diviserMatrix(T);
    
    return blc;
}

ImageBlock diviser3emPlan(Image3 img)
{
    Matrix T;
    T = extraire3(img);
    ImageBlock blc = diviserMatrix(T);
    
    return blc;
}





//-------------------------------------------------------------
//------------------------DCAC blocks--------------------------
//-------------------------------------------------------------

SingleDCAC transDCT(SingleBlock blc)
{
    double Cu,Cv;
    double f[8][8] = {0};
    
    
    //u,v --- positions
    for (int u=0;u<8; u=u+1)
    {
        for (int v=0;v<8;v=v+1)
        {
            // initialisation de Ci,Cj
            if(u==0)    Cu=1/sqrt(2.0);
            else    Cu=1;
            
            if(v==0)     Cv=1/sqrt(2.0);
            else    Cv=1;
            
            
            //i,j --boucle
            for (int i=0;i<8; i=i+1)
            {
                for (int j=0;j<8;j=j+1)
                {
                    //double test = cos((2*i+1)*u*PI/16)*cos((2*j+1)*v*PI/16) * (blc.block[i][j]);
                    f[u][v] = f[u][v] + 0.25*Cu*Cv*cos((2*i+1)*u*PI/16)*cos((2*j+1)*v*PI/16) * (blc.block[i][j]);
                }
            }
        }
    }
    
    SingleDCAC parameter = {0,0};
    int m = 0;
    for (int u=0;u<8; u=u+1)
    {
        for (int v=0;v<8;v=v+1)
        {
            if(u==0 && v==0)
                parameter.DC = f[u][v];
            else
            {
                parameter.AC[m] = round(f[u][v]);
                m++;
            }
            
        }
    }
    
    return parameter;
}




//le resultat final après la partition de région et zero-padding
DCAC createDCAC(Matrix T)
{
    ImageBlock blc = diviserMatrix(T);
    DCAC tab;
    
    tab.lig = blc.lig;
    tab.col = blc.col;
    tab.nb = blc.nb;
    tab.data = (SingleDCAC*)malloc(tab.nb*sizeof(SingleDCAC));
    tab.pos = (SingleDCAC**)malloc(tab.lig*sizeof(SingleDCAC *));
    for (int i=0;i<tab.lig;i++)
        tab.pos[i] = &(tab.data[i*tab.col]);
    
    
    for (int i=0;i<tab.lig; i=i+1)
    {
        for (int j=0;j<tab.col;j=j+1)
        {
            tab.pos[i][j] = transDCT(blc.pos[i][j]);
        }
    }
    
    
    return tab;
}



//-------------------------------------------------------------
//----------------------Quantification-------------------------
//-------------------------------------------------------------


SingleDCAC quantification(SingleDCAC tab , int L1UV2 , int longueurGarde)
{
    
    // le tableau de quantification pour la luminance ou la chrominance
    int q[64];
    
    if(L1UV2 == 1) //luminance
    {
        int q1[16] = {16,11,10,16,24,40,51,61,12,12,14,19,26,58,60,55};
        int q2[16] = {14,13,16,24,40,57,69,56,14,17,22,29,51,87,80,62};
        int q3[16] = {18,22,37,56,68,109,103,77,24,35,55,64,81,104,113,92};
        int q4[16] = {49,64,78,87,103,121,120,101,72,92,95,98,112,100,103,99};
        memcpy(q, q1, sizeof(q1));
        memcpy(q+16, q2, sizeof(q2));
        memcpy(q+32, q3, sizeof(q3));
        memcpy(q+48, q4, sizeof(q4));
        
    }
    
    if(L1UV2 == 2) //chrominance
    {
        int q1[16] = {17,18,24,47,99,99,99,99,18,21,26,66,99,99,99,99};
        int q2[16] = {24,26,56,99,99,99,99,99,47,66,99,99,99,99,99,99};
        int q3[16] = {99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99};
        int q4[16] = {99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99};
        memcpy(q, q1, sizeof(q1));
        memcpy(q+16, q2, sizeof(q2));
        memcpy(q+32, q3, sizeof(q3));
        memcpy(q+48, q4, sizeof(q4));
    }
    
        if(L1UV2 != 1 && L1UV2 !=2)
            printf("le nb indiquant le tableau de quantification n'est pas correct.\n 1 pour la luminance.\n 2 pour la chrominance.\n");
    
    
    
    
    // le tableau de masque avec des differents taux de compression
    int masque[64];
    
    if(longueurGarde == 6)
    {
        int q1[16] = {1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0};
        int q2[16] = {1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0};
        int q3[16] = {1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0};
        int q4[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        memcpy(masque, q1, sizeof(q1));
        memcpy(masque+16, q2, sizeof(q2));
        memcpy(masque+32, q3, sizeof(q3));
        memcpy(masque+48, q4, sizeof(q4));
    }
    
    if(longueurGarde == 5)
    {
        int q1[16] = {1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0};
        int q2[16] = {1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0};
        int q3[16] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int q4[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        memcpy(masque, q1, sizeof(q1));
        memcpy(masque+16, q2, sizeof(q2));
        memcpy(masque+32, q3, sizeof(q3));
        memcpy(masque+48, q4, sizeof(q4));
    }
    
    if(longueurGarde == 4)
    {
        int q1[16] = {1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0};
        int q2[16] = {1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0};
        int q3[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int q4[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        memcpy(masque, q1, sizeof(q1));
        memcpy(masque+16, q2, sizeof(q2));
        memcpy(masque+32, q3, sizeof(q3));
        memcpy(masque+48, q4, sizeof(q4));
    }
    
    if(longueurGarde == 3)
    {
        int q1[16] = {1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0};
        int q2[16] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int q3[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int q4[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        memcpy(masque, q1, sizeof(q1));
        memcpy(masque+16, q2, sizeof(q2));
        memcpy(masque+32, q3, sizeof(q3));
        memcpy(masque+48, q4, sizeof(q4));
    }
    
    if(longueurGarde == 2)
    {
        int q1[16] = {1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0};
        int q2[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int q3[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int q4[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        memcpy(masque, q1, sizeof(q1));
        memcpy(masque+16, q2, sizeof(q2));
        memcpy(masque+32, q3, sizeof(q3));
        memcpy(masque+48, q4, sizeof(q4));
    }
    
    if(longueurGarde ==8 || longueurGarde ==7 || longueurGarde ==1)
        printf("la longueur de la ligne gardé doit etre entre 2--6.\n");
    
    
    // quantifier et puis multiplier avec un masque choisi
    tab.DC = tab.DC / q[0];
    
    for (int i=0;i<63; i=i+1)
    {
        tab.AC[i] = tab.AC[i] / q[i+1];
        tab.AC[i] = tab.AC[i] * masque[i+1];
    }
    
    return tab;
}


DCAC quantificationY(DCAC tab , int longueurGarde)
{
    
    for (int i=0;i<tab.lig; i=i+1)
    {
        for (int j=0;j<tab.col;j=j+1)
        {
            tab.pos[i][j] = quantification(tab.pos[i][j] , 1 , longueurGarde);
            //printf("%d ",tab.pos[i][j].DC);
        }
    }
    
    
    return tab;
}

DCAC quantificationCbCr(DCAC tab , int longueurGarde)
{
    
    for (int i=0;i<tab.lig; i=i+1)
    {
        for (int j=0;j<tab.col;j=j+1)
        {
            tab.pos[i][j] = quantification(tab.pos[i][j] , 2 , longueurGarde);
        }
    }
    
    
    return tab;
}





