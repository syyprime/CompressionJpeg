//
//  Traitement.c
//  compressJPEG
//
// parametres en entrée: in1,in2,in3 --> chemins des matrices R,G,B obtenues par Matlab
//                       out1~6 --> chemins des fichiers Y,Cb,CR(DC AC à l'ordre)
//                       outBin1~6 --> chemins des fichiers Binaires (Resultats finals)
//
//  Created by syyprime on 2017/6/28.
//  Copyright © 2017年 OpenCV Moments. All rights reserved.
//

#include "Traitement.h"


void imageCompress(char const *in1,char const *in2,char const *in3,int ligneGarde,char const *out1,char const *out2,char const *out3,char const *out4,char const *out5,char const *out6,char const *outBin1,char const *outBin2,char const *outBin3,char const *outBin4,char const *outBin5,char const *outBin6)
{
    

    Image3 img = lectureMatlabRGB(in1,in2,in3);
    
    Image3 img2 = rgb2ycbcr(img);
    
    
    
    Matrix Y  =extraire1(img2);
    Matrix Cb  =extraire2(img2);
    Matrix Cr  =extraire3(img2);
    
    
    
    
    ecrireLuminanceDC(Y,ligneGarde,out1);
    ecrireLuminanceAC(Y,ligneGarde,out2);
    ecrireChrominanceDC(Cb,ligneGarde,out3);
    ecrireChrominanceAC(Cb,ligneGarde,out4);
    ecrireChrominanceDC(Cr,ligneGarde,out5);
    ecrireChrominanceAC(Cr,ligneGarde,out6);
    
    
    ecritureBinaire(out1,outBin1);
    ecritureBinaire(out2,outBin2);
    ecritureBinaire(out3,outBin3);
    ecritureBinaire(out4,outBin4);
    ecritureBinaire(out5,outBin5);
    ecritureBinaire(out6,outBin6);



    
    
    
//    ecrireMatrix(Y,"/Users/pc/Documents/CURRENT/documents/compressJPEG/Y.txt");
//    ecrireMatrix(Cb,"/Users/pc/Documents/CURRENT/documents/compressJPEG/Cb.txt");
//    ecrireMatrix(Cr,"/Users/pc/Documents/CURRENT/documents/compressJPEG/Cr.txt");
    
    
//    DCAC dcac = createDCAC(Y);
//    dcac = quantificationY(dcac , 5);
//    dcac = zigzag(dcac);
    
    
//    
//    int freqLumDC[511] = {0};
//    int * dc =  DPCM(dcac,freqLumDC);
//    int ** interDC = intermediaDC(dcac);
//
//    int freqLumAC[511] = {0};
//    int * ac = totalRLE(dcac,freqLumAC);
//    int ** interAC = intermediaDC(dcac);
//    
//    
//    
//    
//    HuffmanLumDC(interDC,dcac.nb,"/Users/pc/Documents/CURRENT/documents/compressJPEG/LumDC.txt");
//    HuffmanChrDC(interDC,dcac.nb,"/Users/pc/Documents/CURRENT/documents/compressJPEG/ChrDC.txt");
//    HuffmanLumAC(interAC,totalLongueurAC(dcac),"/Users/pc/Documents/CURRENT/documents/compressJPEG/LumAC.txt");
//    HuffmanChrAC(interAC,totalLongueurAC(dcac),"/Users/pc/Documents/CURRENT/documents/compressJPEG/ChrAC.txt");



}


//
//clock_t start, finish;
//double  duration;
//double  durationF;
//
//FILE *F=fopen("/Users/pc/Documents/CURRENT/documents/compressJPEG/TempsDeCalcul.txt","w");
//
//
//
//
////lectureMatlabRGB
//start = clock();
//Image3 img = lectureMatlabRGB("/Users/pc/Documents/CURRENT/documents/compressJPEG/1.txt","/Users/pc/Documents/CURRENT/documents/compressJPEG/2.txt","/Users/pc/Documents/CURRENT/documents/compressJPEG/3.txt");
//finish = clock();
//
//
//fprintf(F, "Taille de l'image : %d lignes x %d colonnes. \n\n", img.lig,img.col);
//
//
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : lectureMatlabRGB \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n\n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
////RGB2YCbCr
//start = clock();
//img = rgb2ycbcr(img);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : rgb2ycbcr \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n\n", duration*CLOCKS_PER_SEC);
//
//
//
////extraire
//start = clock();
//Matrix Y  =extraire1(img);
//Matrix Cb  =extraire2(img);
//Matrix Cr  =extraire3(img);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : extraire \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
////----------------------------------Y------------------------------------
//
//fprintf(F, "Y\n\n\n\n");
//
//// DCAC Blocks
//start = clock();
//DCAC daTab = createDCAC(Y);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : createDCAC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// quantification
//start = clock();
//daTab = quantificationY(daTab , 5);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : quantificationY \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// intermediaire(DPCM inclu)
//start = clock();
//int ** tDC = intermediaDC(daTab);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : intermediaDC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// HuffmanDC
//start = clock();
//HuffmanLumDC(tDC,daTab.nb,"/Users/pc/Documents/CURRENT/documents/compressJPEG/YDC.txt");
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : HuffmanLumDC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// ecritureBinaire
//start = clock();
//ecritureBinaire("/Users/pc/Documents/CURRENT/documents/compressJPEG/YDC.txt","/Users/pc/Documents/CURRENT/documents/compressJPEG/BinYDC.txt");
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : ecritureBinaire \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//
//
//
//// ZIGZAG
//start = clock();
//daTab =  zigzag(daTab);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : zigzag \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// totalLongueurAC
//start = clock();
//int l = totalLongueurAC(daTab);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : totalLongueurAC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// totalIntermediaAC
//start = clock();
//int ** tAC = totalIntermediaAC(daTab);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : totalIntermediaAC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// HuffmanAC
//start = clock();
//HuffmanLumAC(tAC,l,"/Users/pc/Documents/CURRENT/documents/compressJPEG/YAC.txt");
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : HuffmanLumAC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// ecritureBinaire
//start = clock();
//ecritureBinaire("/Users/pc/Documents/CURRENT/documents/compressJPEG/YAC.txt","/Users/pc/Documents/CURRENT/documents/compressJPEG/BinYAC.txt");
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : ecritureBinaire \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//
//
//
////----------------------------------Cb------------------------------------
//fprintf(F, "Cb\n\n\n\n");
//// DCAC Blocks
//start = clock();
//DCAC daTabCb = createDCAC(Cb);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : createDCAC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// quantification
//start = clock();
//daTabCb = quantificationCbCr(daTabCb , 5);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : quantificationCbCr \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// intermediaire(DPCM inclu)
//start = clock();
//int ** tDCcb = intermediaDC(daTabCb);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : intermediaDC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// HuffmanDC
//start = clock();
//HuffmanChrDC(tDCcb,daTabCb.nb,"/Users/pc/Documents/CURRENT/documents/compressJPEG/CbDC.txt");
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : HuffmanLChrDC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// ecritureBinaire
//start = clock();
//ecritureBinaire("/Users/pc/Documents/CURRENT/documents/compressJPEG/CbDC.txt","/Users/pc/Documents/CURRENT/documents/compressJPEG/BinCbDC.txt");
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : ecritureBinaire \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//// ZIGZAG
//start = clock();
//daTabCb =  zigzag(daTabCb);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : zigzag \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// totalLongueurAC
//start = clock();
//int lcb = totalLongueurAC(daTabCb);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : totalLongueurAC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// totalIntermediaAC
//start = clock();
//int ** tACcb = totalIntermediaAC(daTabCb);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : totalIntermediaAC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// HuffmanAC
//start = clock();
//HuffmanChrAC(tACcb,lcb,"/Users/pc/Documents/CURRENT/documents/compressJPEG/CbAC.txt");
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : HuffmanChrAC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//
//// ecritureBinaire
//start = clock();
//ecritureBinaire("/Users/pc/Documents/CURRENT/documents/compressJPEG/CbAC.txt","/Users/pc/Documents/CURRENT/documents/compressJPEG/BinCbAC.txt");
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : ecritureBinaire \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
////----------------------------------Cr------------------------------------
//
//fprintf(F, "Cr\n\n\n\n");
//
//// DCAC Blocks
//start = clock();
//DCAC daTabCr = createDCAC(Cr);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : createDCAC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// quantification
//start = clock();
//daTabCr = quantificationY(daTabCr , 5);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : quantificationY \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// intermediaire(DPCM inclu)
//start = clock();
//int ** tDCcr = intermediaDC(daTabCr);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : intermediaDC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// HuffmanDC
//start = clock();
//HuffmanChrDC(tDC,daTabCr.nb,"/Users/pc/Documents/CURRENT/documents/compressJPEG/CrDC.txt");
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : HuffmanLChrDC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//// ecritureBinaire
//start = clock();
//ecritureBinaire("/Users/pc/Documents/CURRENT/documents/compressJPEG/CrDC.txt","/Users/pc/Documents/CURRENT/documents/compressJPEG/BinCrDC.txt");
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : ecritureBinaire \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//// ZIGZAG
//start = clock();
//daTab =  zigzag(daTabCr);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : zigzag \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// totalLongueurAC
//start = clock();
//int lcr = totalLongueurAC(daTabCr);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : totalLongueurAC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// totalIntermediaAC
//start = clock();
//int ** tACcr = totalIntermediaAC(daTabCr);
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : totalIntermediaAC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//// HuffmanAC
//start = clock();
//HuffmanChrAC(tACcr,lcr,"/Users/pc/Documents/CURRENT/documents/compressJPEG/CrAC.txt");
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : HuffmanLumAC \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//// ecritureBinaire
//start = clock();
//ecritureBinaire("/Users/pc/Documents/CURRENT/documents/compressJPEG/CrAC.txt","/Users/pc/Documents/CURRENT/documents/compressJPEG/BinCrAC.txt");
//finish = clock();
//
//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//fprintf(F,"function  : ecritureBinaire \n");
//fprintf(F, "Time  :  %f seconds   \n", duration);
//fprintf(F, "Clock cycles  :  %f  times \n", duration*CLOCKS_PER_SEC);
//fprintf(F, "\n");
//
//
//
//
//fclose(F);
//

