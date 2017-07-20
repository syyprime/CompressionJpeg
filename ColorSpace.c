//
//  ColorSpace.c
//  compressJPEG
//
//  Created by syyprime on 2017/6/28.
//  Copyright © 2017年 OpenCV Moments. All rights reserved.
//

#include "ColorSpace.h"


Image3 rgb2ycbcr(Image3 img)
{
    int lig = img.lig;
    int col = img.col;
    Image3 img2 = createImage3(lig, col);
    
    
    // la matrice de transformation
    double m_2ycbcr[3][3]={{0}} ;
    m_2ycbcr[0][0] = 0.299;
    m_2ycbcr[0][1] = 0.587;
    m_2ycbcr[0][2] = 0.114;
    m_2ycbcr[1][0] = -0.1687;
    m_2ycbcr[1][1] = -0.3313;
    m_2ycbcr[1][2] = 0.5;
    m_2ycbcr[2][0] = 0.5;
    m_2ycbcr[2][1] = -0.4187;
    m_2ycbcr[2][2] = -0.0813;
    
    int vect[3]= {0};
    vect[1] = 128;
    vect[2] = 128;
    
    //un pixel dans l'espace RGB
    double pixRGB[3]= {0};

    
    for (int i=0; i<(lig); i++){
        
        for (int j=0; j<(col); j++){
            
            pixRGB[0] = img.pixel[i][j].R;
            pixRGB[1] = img.pixel[i][j].G ;
            pixRGB[2] = img.pixel[i][j].B;
            
            //un pixel dans l'espace YCbCr
            double pixYCrCb[3]= {0};
            
            for (int u=0; u<3; u++){
                for (int w=0; w<3; w++){
                    
                    pixYCrCb[u] = pixYCrCb[u] + m_2ycbcr[u][w]*pixRGB[w];
                    
                }
                pixYCrCb[u] = pixYCrCb[u] + vect[u];
                
            }
            
            img2.pixel[i][j].R = round(pixYCrCb[0]);
            img2.pixel[i][j].G = round(pixYCrCb[1]);
            img2.pixel[i][j].B = round(pixYCrCb[2]);
            
            
        }
    }
    
    return img2;
    
    
    //    // la matrice de transformation
    //    double m_2RGB[3][3]={{0}} ;
    //    m_2RGB[0][0] = 1.0000;
    //    m_2RGB[0][1] = 0.0000;
    //    m_2RGB[0][2] = 1.4020;
    //    m_2RGB[1][0] = 1.0000;
    //    m_2RGB[1][1] = -0.3441;
    //    m_2RGB[1][2] = -0.7141;
    //    m_2RGB[2][0] = 1.0000;
    //    m_2RGB[2][1] = 1.7720;
    //    m_2RGB[2][2] = 0.0000;
    //
    //    //un pixel dans l'espace RGB et YCbCr
    //    double pixRGB[3]= {0};
    //    double pixYCrCb[3]= {0};
    //
    //    int vect[3]= {0};
    //    vect[0] = -128*1.402;
    //    vect[1] = 128*(0.3341+0.7141);
    //    vect[2] = -128*1.772;
    
}


Matrix getY(Image3 img)
{
    
    Matrix m = extraire1(img);
    
    return m;
}


Matrix getCb(Image3 img)
{
    
    Matrix m = extraire2(img);
    
    return m;
}


Matrix getCr(Image3 img)
{
    
    Matrix m = extraire2(img);
    
    return m;
}



Image3 ycbcr2rgb(Image3 img)
{
    int lig = img.lig;
    int col = img.col;
    Image3 img2 = createImage3(lig, col);
    
    
    // la matrice de transformation
    double m_2RGB[3][3]={{0}} ;
    m_2RGB[0][0] = 1.0000;
    m_2RGB[0][1] = 0.0000;
    m_2RGB[0][2] = 1.4020;
    m_2RGB[1][0] = 1.0000;
    m_2RGB[1][1] = -0.3441;
    m_2RGB[1][2] = -0.7141;
    m_2RGB[2][0] = 1.0000;
    m_2RGB[2][1] = 1.7720;
    m_2RGB[2][2] = 0.0000;
    
    int vect[3]= {0};
    vect[0] = -128*1.402;
    vect[1] = 128*(0.3341+0.7141);
    vect[2] = -128*1.772;
    
    //un pixel dans l'espace RGB
    double pixYCrCb[3]= {0};
    
    
    for (int i=0; i<(lig); i++){
        
        for (int j=0; j<(col); j++){
            
            pixYCrCb[0] = img.pixel[i][j].R;
            pixYCrCb[1] = img.pixel[i][j].G ;
            pixYCrCb[2] = img.pixel[i][j].B;
            
            //un pixel dans l'espace YCbCr
            double pixRGB[3]= {0};
            
            for (int u=0; u<3; u++){
                for (int w=0; w<3; w++){
                    
                    pixRGB[u] = pixRGB[u] + m_2RGB[u][w]*pixYCrCb[w];
                    
                }
                pixRGB[u] = pixRGB[u] + vect[u];
                
            }
            
            img2.pixel[i][j].R = round(pixRGB[0]);
            img2.pixel[i][j].G = round(pixRGB[1]);
            img2.pixel[i][j].B = round(pixRGB[2]);
            
            
        }
    }
    
    return img2;
    
}
