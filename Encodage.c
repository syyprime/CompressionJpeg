//
//  Encodage.c
//  compressJPEG
//
//  Created by syyprime on 2017/6/28.
//  Copyright © 2017年 OpenCV Moments. All rights reserved.
//

#include "Encodage.h"


//-------------------------------------------------------------
//-----------------------Encodage DC---------------------------
//-------------------------------------------------------------

DC extraireDC(DCAC tab)
{
    DC tabDC = {0,NULL};
    tabDC.nb = tab.nb;
    tabDC.data = (int *)malloc(tab.nb*sizeof(int));
    
    for(int i = 0; i<tab.lig;i++)
    {
        for(int j=0;j<tab.col;j++)
        {
            tabDC.data[j+i*tab.col] = tab.pos[i][j].DC;
        }
    }
    
    return tabDC;
}



//-----------------------Encodage DPCM---------------------------

int * DPCM(DCAC tab,int *freq)
{
    int * codage = (int *)malloc(tab.nb*sizeof(int));
    int vp;
    
    for(int i = 0; i<tab.lig;i++)
    {
        for(int j=0;j<tab.col;j++)
        {
            if(i==0 && j==0)
                codage[0] = tab.pos[0][0].DC;
            else
            {
                vp = tab.data[j+i*tab.col - 1].DC;
                codage[j+i*tab.col] = tab.pos[i][j].DC - vp;
            }
            
            freq[255+codage[j+i*tab.col]]++;
        }
    }
    
    return  codage;
    
}


//-----------------------DC de Format intermédiaire---------------------------
// retourner un tableau 2D (il y a nb.tab lignes)
// en chaque ligne , il y a 2 variables
// la 1ere variabla est le nb de bits pour stocker le codage du parametre DC
// la 2eme variable est la valeur du codage à stocker
// c'est l'idee de codage VLI(vari)

int ** intermediaDC(DCAC tab)
{
    // Les composantes DC extraites
    printf("Les composantes DC extraites sont: \n");
    for(int n=0;n<tab.nb;n++)
    {
        printf("%d ",tab.data[n].DC);
        
    }
    printf("\n\n");
    //
    
    int * codage = (int *)malloc(tab.nb*sizeof(int));
    
    int vp;
    for(int i = 0; i<tab.lig;i++)
    {
        for(int j=0;j<tab.col;j++)
        {
            if(i==0 && j==0)
                codage[0] = tab.pos[0][0].DC;
            else
            {
                vp = tab.data[j+i*tab.col - 1].DC;
                codage[j+i*tab.col] = tab.pos[i][j].DC - vp;
            }
        }
    }
    
    // après le codage DPCM
    printf("Les composantes DC après le codage DPCM sont: \n");
    for(int n=0;n<tab.nb;n++)
    {
        printf("%d ",codage[n]);
        
    }
    printf("\n\n");
    //
    
    int ** inter = (int **)malloc(tab.nb*sizeof(int*));
    
    for(int i = 0; i<tab.nb;i++)
    {
        inter[i] = (int*)malloc(2 * sizeof(int));
        inter[i][0] = log(abs(codage[i])) / log(2) + 1;
        inter[i][1] = codage[i];
    }
    
    
    
    
    return  inter;
    
}







//-------------------------------------------------------------
//-----------------------Encodage AC---------------------------
//-------------------------------------------------------------


AC extraireAC(DCAC tab)
{
    AC tabAC = {0,NULL};
    tabAC.nb = tab.nb;
    tabAC.data = (int **)malloc(tab.nb*sizeof(int *));
    for(int i=0;i<tab.nb;i++)
        tabAC.data[i] = (int*)malloc(63*sizeof(int));
    
    for(int i = 0; i<tabAC.nb;i++)
    {
        for(int j=0;j<63;j++)
        {
            tabAC.data[i][j] = tab.data[i].AC[j];
        }
    }
    
    return tabAC;
}






//-----------------------------Encodage ZIGZAG--------------------------------


//pour un bloc simple
SingleDCAC zigzagSingle(SingleDCAC tab)
{
    int zigzag[63] = {0};
    
    int pos = 0;
    int add = 0;
    
    
    for (int i=0;i<8; i=i+1)
    {
        
        for (int j=0;j<8;j=j+1)
        {
            //calculer la valeur minimale dans chaque ligne diagonale
            int rang = i+j;
            int minVal = 1;
            while(rang>0)
            {
                if(rang<8)  minVal = minVal + rang  ;
                if(rang>7)  minVal = minVal + (16 -rang) ;
                rang --;
            }
            
            //calculer la difference avec la valeur minimale dans chaque ligne diagonale
            rang = i+j;
            if(rang%2 == 1)
            {
                if(rang<8)  add = i;
                if(rang>7)  add = 7-j;
            }
            if(rang%2 == 0)
            {
                if(rang<8)  add = j;
                if(rang>7)  add = 7-i;
            }
            
            //l'index de la position dans 1D tab
            pos = minVal  + add;
            
            if(pos != 1)
                zigzag[pos-2] = tab.AC[j-1+8*i];
        }
    }
    
    for(int n=0;n<63; n=n+1)
        tab.AC[n] = zigzag[n];
    
    return tab;
}


//pour tous les bloc de cette image
DCAC zigzag(DCAC tab)
{
    for (int i=0;i<tab.lig; i=i+1)
    {
        for (int j=0;j<tab.col;j=j+1)
        {
            tab.pos[i][j] = zigzagSingle(tab.pos[i][j]);
        }
    }
    
    return tab;
}



//------------------------------Encodage RLE--------------------------------


//---------1.les résultas des blocs sont traités respectivement------------

int ** RLE(DCAC tab)
{
    int ** codage = (int **)malloc(tab.nb*sizeof(int *));
    
    for (int i=0;i<tab.lig; i=i+1)
    {
        for (int j=0;j<tab.col;j=j+1)
        {
            
            int * buffer = (int*)malloc(100 * sizeof(int));
            
            int compt = 0;
            int p = -1;
            for(int n = 0; n<63 ; n++)
            {
                
                if (tab.pos[i][j].AC[n] == 0)
                {
                    if(compt == 15)
                    {
                        buffer[p+1] = compt;
                        buffer[p+2] = 0;
                        compt = 0;
                        p = p+2;
                    }
                    compt++;
                    
                }
                else
                {
                    buffer[p+1] = compt;
                    buffer[p+2] = tab.pos[i][j].AC[n];
                    compt = 0;
                    p = p+2;
                }
                if(n==62)
                {
                    buffer[p+1] = compt;
                    buffer[p+2] = tab.pos[i][j].AC[n];
                    p = p+2;
                }
                
            }
            
            codage[j+i*tab.col] = (int*)malloc((p+1)*sizeof(int));
            for(int n = 0; n<p+1 ; n++)
                codage[j+i*tab.col][n] = buffer[n];
            
            
            free(buffer);
            
        }
    }
    
    return  codage;
}




int longueurAC(DCAC tab)
{
    int m = 0;
    
    for (int i=0;i<tab.lig; i=i+1)
    {
        for (int j=0;j<tab.col;j=j+1)
        {
            
            int compt = 0;
            int p = -1;
            for(int n = 0; n<63 ; n++)
            {
                
                if (tab.pos[i][j].AC[n] == 0)
                {
                    if(compt == 15)
                    {
                        compt = 0;
                        p = p+2;
                    }
                    compt++;
                    
                }
                else
                {
                    compt = 0;
                    p = p+2;
                }
                
                if(n==62)
                    p = p+2;
                
            }
            
            for(int n = 0; n<p+1 ; n = n+2)
                m++;
            
        }
    }
    return 2*m;
}




int ** intermediaAC(DCAC tab)
{
    
    int ** codage = (int **)malloc(tab.nb*sizeof(int *));
    
    int l = longueurAC(tab);
    int ** inter = (int **)malloc(l*63*sizeof(int*));
    
    int m =0;
    
    for (int i=0;i<tab.lig; i=i+1)
    {
        for (int j=0;j<tab.col;j=j+1)
        {
            
            //buffer des parametres AC d'un block
            int * buffer = (int*)malloc(100 * sizeof(int));
            
            int compt = 0;
            int p = -1;
            for(int n = 0; n<63 ; n++)
            {
                if (tab.pos[i][j].AC[n] == 0)
                {
                    if(compt == 15)
                    {
                        buffer[p+1] = compt;
                        buffer[p+2] = 0;
                        compt = 0;
                        p = p+2;
                    }
                    compt++;
                    
                }
                else
                {
                    buffer[p+1] = compt;
                    buffer[p+2] = tab.pos[i][j].AC[n];
                    compt = 0;
                    p = p+2;
                }
                if(n==62)
                {
                    buffer[p+1] = compt;
                    buffer[p+2] = tab.pos[i][j].AC[n];
                    p = p+2;
                }
                
            }
            
            
            codage[j+i*tab.col] = (int*)malloc((p+1)*sizeof(int));
            for(int n = 0; n<p+1 ; n = n+2)
            {
                inter[m] = (int*)malloc(3 * sizeof(int));
                
                codage[j+i*tab.col][n] = buffer[n];
                codage[j+i*tab.col][n+1] = buffer[n+1];
                
                inter[m][0] = buffer[n];
                if(buffer[n+1] != 0)    inter[m][1] = log(abs(buffer[n+1])) / log(2) + 1;
                if(buffer[n+1] == 0)    inter[m][1] = 0;
                inter[m][2] = buffer[n+1];
                
                m++;
                
            }
            free(buffer);
            
        }
    }
    
    return  inter;
}





//---------2.les résultas des blocs sont traités successivement------------

int * totalRLE(DCAC tab)
{
    int nb = totalLongueurAC(tab);
    int * codage = (int *)malloc((nb)*sizeof(int));
    int compt = 0;
    int p = -1;
    
    
    for (int i=0;i<tab.lig; i=i+1)
    {
        for (int j=0;j<tab.col;j=j+1)
        {
            
            
            
            for(int n = 0; n<63 ; n++)
            {
                if (tab.pos[i][j].AC[n] == 0)
                {
                    if(compt == 15)
                    {
                        codage[p+1] = compt;
                        codage[p+2] = 0;
                        //freq[codage[p+1] + 255]++;
                        //freq[codage[p+2] + 255]++;
                        
                        compt = 0;
                        p = p+2;
                    }
                    compt++;
                }
                else
                {
                    codage[p+1] = compt;
                    codage[p+2] = tab.pos[i][j].AC[n];
                    //freq[codage[p+1] + 255]++;
                    //freq[codage[p+2] + 255]++;
                    
                    compt = 0;
                    p = p+2;
                }
                
            }
            
            
            
        }
    }
    
    // montrer le RLE
    printf("Les composantes AC après le codage RLE sont:\n");
    for(int n = 0; n<nb ; n++)
        printf("%d ",codage[n]);
    
    printf("\n\n\n\n\n");
    //
    
    
    return  codage;
}


int totalLongueurAC(DCAC tab)
{
    int compt = 0;
    int p = -1;
    int m = 0;
    
    for (int i=0;i<tab.lig; i=i+1)
    {
        for (int j=0;j<tab.col;j=j+1)
        {
            
            
            for(int n = 0; n<63 ; n++)
            {
                if (tab.pos[i][j].AC[n] == 0)
                {
                    if(compt == 15)
                    {
                        compt = 0;
                        p = p+2;
                        m++;
                    }
                    compt++;
                    
                }
                else
                {
                    compt = 0;
                    p = p+2;
                    m++;
                }
            }
            
            
        }
    }
    return 2*m;
}





int ** totalIntermediaAC(DCAC tab)
{
    int nb = totalLongueurAC(tab)/2;
    int * rle = totalRLE(tab);
    int ** codage = (int **)malloc((nb/2+1)*sizeof(int *));
    int m = 0;
    
    for(int n = 0; n<nb ; n = n+2)
    {
        codage[m] = (int*)malloc((3)*sizeof(int));
        
        int runLength = *rle;
        int am =*(rle+1);
        
        codage[m][0] = runLength;
        if(am != 0)    codage[m][1] = log(abs(am)) / log(2) + 1;
        if(am == 0)    codage[m][1] = 0;
        codage[m][2] = am;
        
        
        rle = rle +2;
        m++;
        
    }
    
    return  codage;
}



char * VLI(int am)
{
    if(am==0)
        return NULL;
    
    int longueur = log(abs(am)) / log(2) + 1;
    int * codeVLI = (int*)malloc((longueur)*sizeof(int));
    
    if(am>0)
    {
        codeVLI[0]=1;
        am=abs(am);
        
        int min = pow(2,(longueur-1));
        int max = pow(2,longueur) - 1;
        
        for(int i=1;i<longueur;i++)
        {
            double ave = (min+max)/2.0;
            
            if(am<=ave)
            {
                max = floor(ave);
                codeVLI[i] = 0;
            }
            if(am>ave)
            {
                min = ceil(ave);
                codeVLI[i] = 1;
            }
        }

    }
        
    
    if(am<0)
    {
        codeVLI[0]=0;
        am=abs(am);
        
        int min = pow(2,(longueur-1));
        int max = pow(2,longueur) - 1;
        
        for(int i=1;i<longueur;i++)
        {
            double ave = (min+max)/2.0;
            
            if(am<=ave)
            {
                max = floor(ave);
                codeVLI[i] = 1;
            }
            if(am>ave)
            {
                min = ceil(ave);
                codeVLI[i] = 0;
            }
        }
    }
        
    
    char *charVLI = NULL;
    charVLI = (char*)malloc((longueur)*sizeof(char));
    
    for(int i=0;i<longueur;i++)
    {
        if(codeVLI[i])
            charVLI[i] = '1';
        if(!codeVLI[i])
            charVLI[i] = '0';
    }

  
    return charVLI;
}

