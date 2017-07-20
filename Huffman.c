//
//  Huffman.c
//  compressJPEG
//
//  Created by syyprime on 2017/6/29.
//  Copyright © 2017年 OpenCV Moments. All rights reserved.
//

#include "Huffman.h"



//-------------------------------------------------------------
//--------------------------Huffman----------------------------
//-------------------------------------------------------------

void HuffmanLumAC(int ** data,int longueur,char const *out)
{
    FILE *F=fopen(out,"wb");
    
    
    
    for(int n = 0; n<(longueur/4); n++)
    {
        int run = data[n][0];
        int cat = data[n][1];
        char * huffCode = NULL;
        
        if(run==0 && cat==0)
            huffCode="1010";
        if(run==0 && cat==1)
            huffCode="00";
        if(run==0 && cat==2)
            huffCode="01";
        if(run==0 && cat==3)
            huffCode="100";
        if(run==0 && cat==4)
            huffCode="1011";
        if(run==0 && cat==5)
            huffCode="11010";
        if(run==0 && cat==6)
            huffCode="1111000";
        if(run==0 && cat==7)
            huffCode="11111000";
        if(run==0 && cat==8)
            huffCode="1111110110";
        if(run==0 && cat==9)
            huffCode="1111111110000010";
        if(run==0 && cat==10)
            huffCode="1111111110000011";
        
        
        if(run==1 && cat==1)
            huffCode="1100";
        if(run==1 && cat==2)
            huffCode="11011";
        if(run==1 && cat==3)
            huffCode="1111001";
        if(run==1 && cat==4)
            huffCode="111110110";
        if(run==1 && cat==5)
            huffCode="11111110110";
        if(run==1 && cat==6)
            huffCode="1111111110000100";
        if(run==1 && cat==7)
            huffCode="1111111110000101";
        if(run==1 && cat==8)
            huffCode="1111111110000110";
        if(run==1 && cat==9)
            huffCode="1111111110000111";
        if(run==1 && cat==10)
            huffCode="1111111110001000";
        
        
        if(run==2 && cat==1)
            huffCode="11100";
        if(run==2 && cat==2)
            huffCode="11111001";
        if(run==2 && cat==3)
            huffCode="1111110111";
        if(run==2 && cat==4)
            huffCode="111111110100";
        if(run==2 && cat==5)
            huffCode="1111111110001001";
        if(run==2 && cat==6)
            huffCode="1111111110001010";
        if(run==2 && cat==7)
            huffCode="1111111110001011";
        if(run==2 && cat==8)
            huffCode="1111111110001100";
        if(run==2 && cat==9)
            huffCode="1111111110001101";
        if(run==2 && cat==10)
            huffCode="1111111110001110";
        
        if(run==3 && cat==1)
            huffCode="111010";
        if(run==3 && cat==2)
            huffCode="111110111";
        if(run==3 && cat==3)
            huffCode="111111110101";
        if(run==3 && cat==4)
            huffCode="1111111110001111";
        if(run==3 && cat==5)
            huffCode="1111111110010000";
        if(run==3 && cat==6)
            huffCode="1111111110010001";
        if(run==3 && cat==7)
            huffCode="1111111110010010";
        if(run==3 && cat==8)
            huffCode="1111111110010011";
        if(run==3 && cat==9)
            huffCode="1111111110010100";
        if(run==3 && cat==10)
            huffCode="1111111110010101";
        
        if(run==4 && cat==1)
            huffCode="11100";
        if(run==4 && cat==2)
            huffCode="1111111000";
        if(run==4 && cat==3)
            huffCode="1111110111";
        if(run==4 && cat==4)
            huffCode="1111111110010111";
        if(run==4 && cat==5)
            huffCode="1111111110011000";
        if(run==4 && cat==6)
            huffCode="1111111110011000";
        if(run==4 && cat==7)
            huffCode="1111111110011010";
        if(run==4 && cat==8)
            huffCode="1111111110011011";
        if(run==4 && cat==9)
            huffCode="1111111110011100";
        if(run==4 && cat==10)
            huffCode="1111111110011101";
        
        if(run==5 && cat==1)
            huffCode="1111010";
        if(run==5 && cat==2)
            huffCode="11111110111";
        if(run==5 && cat==3)
            huffCode="1111111110011110";
        if(run==5 && cat==4)
            huffCode="1111111110011111";
        if(run==5 && cat==5)
            huffCode="1111111110100000";
        if(run==5 && cat==6)
            huffCode="1111111110100001";
        if(run==5 && cat==7)
            huffCode="1111111110100010";
        if(run==5 && cat==8)
            huffCode="1111111110100011";
        if(run==5 && cat==9)
            huffCode="1111111110100011";
        if(run==5 && cat==10)
            huffCode="1111111110100101";
        
        if(run==6 && cat==1)
            huffCode="1111011";
        if(run==6 && cat==2)
            huffCode="111111110110";
        if(run==6 && cat==3)
            huffCode="1111111110100110";
        if(run==6 && cat==4)
            huffCode="1111111110100111";
        if(run==6 && cat==5)
            huffCode="1111111110101000";
        if(run==6 && cat==6)
            huffCode="1111111110101001";
        if(run==6 && cat==7)
            huffCode="1111111110101010";
        if(run==6 && cat==8)
            huffCode="1111111110101011";
        if(run==6 && cat==9)
            huffCode="1111111110101100";
        if(run==6 && cat==10)
            huffCode="1111111110101101";
        
        if(run==7 && cat==1)
            huffCode="11111010";
        if(run==7 && cat==2)
            huffCode="111111110111";
        if(run==7 && cat==3)
            huffCode="1111111110101110";
        if(run==7 && cat==4)
            huffCode="1111111110101111";
        if(run==7 && cat==5)
            huffCode="1111111110110000";
        if(run==7 && cat==6)
            huffCode="1111111110110001";
        if(run==7 && cat==7)
            huffCode="1111111110110010";
        if(run==7 && cat==8)
            huffCode="1111111110110011";
        if(run==7 && cat==9)
            huffCode="1111111110110100";
        if(run==7 && cat==10)
            huffCode="1111111110110101";
        
        if(run==8 && cat==1)
            huffCode="111111000";
        if(run==8 && cat==2)
            huffCode="111111000";
        if(run==8 && cat==3)
            huffCode="1111111110110110";
        if(run==8 && cat==4)
            huffCode="1111111110110111";
        if(run==8 && cat==5)
            huffCode="1111111110111000";
        if(run==8 && cat==6)
            huffCode="1111111110111001";
        if(run==8 && cat==7)
            huffCode="1111111110111010";
        if(run==8 && cat==8)
            huffCode="1111111110111011";
        if(run==8 && cat==9)
            huffCode="1111111110111100";
        if(run==8 && cat==10)
            huffCode="1111111110111101";
        
        if(run==9 && cat==1)
            huffCode="111111001";
        if(run==9 && cat==2)
            huffCode="1111111110111110";
        if(run==9 && cat==3)
            huffCode="1111111110111111";
        if(run==9 && cat==4)
            huffCode="1111111111000000";
        if(run==9 && cat==5)
            huffCode="1111111111000001";
        if(run==9 && cat==6)
            huffCode="1111111111000010";
        if(run==9 && cat==7)
            huffCode="1111111111000011";
        if(run==9 && cat==8)
            huffCode="1111111111000100";
        if(run==9 && cat==9)
            huffCode="1111111111000101";
        if(run==9 && cat==10)
            huffCode="1111111111000110";
        

        if(run==10 && cat==1)
            huffCode="111111001";
        if(run==10 && cat==2)
            huffCode="1111111111001000";
        if(run==10 && cat==3)
            huffCode="1111111111001001";
        if(run==10 && cat==4)
            huffCode="1111111111001010";
        if(run==10 && cat==5)
            huffCode="1111111111001011";
        if(run==10 && cat==6)
            huffCode="1111111111001100";
        if(run==10 && cat==7)
            huffCode="1111111111001101";
        if(run==10 && cat==8)
            huffCode="1111111111001110";
        if(run==10 && cat==9)
            huffCode="1111111111001111";
        if(run==10 && cat==10)
            huffCode="1111111111010000";
        
        
        if(run==11 && cat==1)
            huffCode="1111111001";
        if(run==11 && cat==2)
            huffCode="1111111111010000";
        if(run==11 && cat==3)
            huffCode="1111111111010001";
        if(run==11 && cat==4)
            huffCode="1111111111010010";
        if(run==11 && cat==5)
            huffCode="1111111111010010";
        if(run==11 && cat==6)
            huffCode="1111111111010100";
        if(run==11 && cat==7)
            huffCode="1111111111010101";
        if(run==11 && cat==8)
            huffCode="1111111111010110";
        if(run==11 && cat==9)
            huffCode="1111111111010111";
        if(run==11 && cat==10)
            huffCode="1111111111011000";
        
        
        
        if(run==12 && cat==1)
            huffCode="1111111010";
        if(run==12 && cat==2)
            huffCode="1111111111011001";
        if(run==12 && cat==3)
            huffCode="1111111111011010";
        if(run==12 && cat==4)
            huffCode="1111111111011011";
        if(run==12 && cat==5)
            huffCode="1111111111011100";
        if(run==12 && cat==6)
            huffCode="1111111111011101";
        if(run==12 && cat==7)
            huffCode="1111111111011110";
        if(run==12 && cat==8)
            huffCode="1111111111011111";
        if(run==12 && cat==9)
            huffCode="1111111111100000";
        if(run==12 && cat==10)
            huffCode="1111111111100001";
        
        
        if(run==13 && cat==1)
            huffCode="11111111000";
        if(run==13 && cat==2)
            huffCode="1111111111100010";
        if(run==13 && cat==3)
            huffCode="1111111111100011";
        if(run==13 && cat==4)
            huffCode="1111111111100100";
        if(run==13 && cat==5)
            huffCode="1111111111100101";
        if(run==13 && cat==6)
            huffCode="1111111111100110";
        if(run==13 && cat==7)
            huffCode="1111111111100111";
        if(run==13 && cat==8)
            huffCode="1111111111101000";
        if(run==13 && cat==9)
            huffCode="1111111111101001";
        if(run==13 && cat==10)
            huffCode="1111111111101010";
        
        
        if(run==14 && cat==1)
            huffCode="1111111111101011";
        if(run==14 && cat==2)
            huffCode="1111111111101100";
        if(run==14 && cat==3)
            huffCode="1111111111101101";
        if(run==14 && cat==4)
            huffCode="1111111111101110";
        if(run==14 && cat==5)
            huffCode="1111111111101111";
        if(run==14 && cat==6)
            huffCode="1111111111110000";
        if(run==14 && cat==7)
            huffCode="1111111111110001";
        if(run==14 && cat==8)
            huffCode="1111111111110010";
        if(run==14 && cat==9)
            huffCode="1111111111110011";
        if(run==14 && cat==10)
            huffCode="1111111111110100";
        
        
        if(run==15 && cat==1)
            huffCode="1111111111110101";
        if(run==15 && cat==2)
            huffCode="1111111111110110";
        if(run==15 && cat==3)
            huffCode="1111111111110110";
        if(run==15 && cat==4)
            huffCode="1111111111111000";
        if(run==15 && cat==5)
            huffCode="1111111111111001";
        if(run==15 && cat==6)
            huffCode="1111111111111010";
        if(run==15 && cat==7)
            huffCode="1111111111111011";
        if(run==15 && cat==8)
            huffCode="1111111111111100";
        if(run==15 && cat==9)
            huffCode="1111111111111101";
        if(run==15 && cat==10)
            huffCode="1111111111111110";
        if(run==15 && cat==0)
            huffCode="11111111001";
        
        
        fprintf(F,"%s",huffCode);
        
        
        int am = data[n][2];
        char * amVLI = VLI(am);
        
        fprintf(F,"%s",amVLI);

    }
    fclose(F);
}



void HuffmanChrAC(int ** data,int longueur,char const *out)
{
    FILE *F=fopen(out,"wb");
    
    
    
    for(int n = 0; n<(longueur/4); n++)
    {
        int run = data[n][0];
        int cat = data[n][1];
        char * huffCode = NULL;
        
        if(run==0 && cat==0)
            huffCode="00";
        if(run==0 && cat==1)
            huffCode="01";
        if(run==0 && cat==2)
            huffCode="100";
        if(run==0 && cat==3)
            huffCode="1010";
        if(run==0 && cat==4)
            huffCode="11000";
        if(run==0 && cat==5)
            huffCode="11001";
        if(run==0 && cat==6)
            huffCode="111000";
        if(run==0 && cat==7)
            huffCode="1111000";
        if(run==0 && cat==8)
            huffCode="111110100";
        if(run==0 && cat==9)
            huffCode="1111110110";
        if(run==0 && cat==10)
            huffCode="111111110100";
        
        
        if(run==1 && cat==1)
            huffCode="1011";
        if(run==1 && cat==2)
            huffCode="111001";
        if(run==1 && cat==3)
            huffCode="11110110";
        if(run==1 && cat==4)
            huffCode="111110101";
        if(run==1 && cat==5)
            huffCode="11111110110";
        if(run==1 && cat==6)
            huffCode="11111110110";
        if(run==1 && cat==7)
            huffCode="1111111110001000";
        if(run==1 && cat==8)
            huffCode="1111111110001001";
        if(run==1 && cat==9)
            huffCode="1111111110001010";
        if(run==1 && cat==10)
            huffCode="1111111110001011";
        
        
        if(run==2 && cat==1)
            huffCode="11010";
        if(run==2 && cat==2)
            huffCode="11110111";
        if(run==2 && cat==3)
            huffCode="1111110111";
        if(run==2 && cat==4)
            huffCode="111111110110";
        if(run==2 && cat==5)
            huffCode="111111111000010";
        if(run==2 && cat==6)
            huffCode="1111111110001100";
        if(run==2 && cat==7)
            huffCode="1111111110001101";
        if(run==2 && cat==8)
            huffCode="1111111110001110";
        if(run==2 && cat==9)
            huffCode="1111111110001111";
        if(run==2 && cat==10)
            huffCode="1111111110010000";
        
        if(run==3 && cat==1)
            huffCode="11011";
        if(run==3 && cat==2)
            huffCode="11111000";
        if(run==3 && cat==3)
            huffCode="1111111000";
        if(run==3 && cat==4)
            huffCode="111111110111";
        if(run==3 && cat==5)
            huffCode="1111111110010001";
        if(run==3 && cat==6)
            huffCode="1111111110010010";
        if(run==3 && cat==7)
            huffCode="1111111110010011";
        if(run==3 && cat==8)
            huffCode="1111111110010100";
        if(run==3 && cat==9)
            huffCode="1111111110010101";
        if(run==3 && cat==10)
            huffCode="1111111110010110";
        
        if(run==4 && cat==1)
            huffCode="111010";
        if(run==4 && cat==2)
            huffCode="111110110";
        if(run==4 && cat==3)
            huffCode="1111111110010111";
        if(run==4 && cat==4)
            huffCode="1111111110011000";
        if(run==4 && cat==5)
            huffCode="1111111110011001";
        if(run==4 && cat==6)
            huffCode="1111111110011010";
        if(run==4 && cat==7)
            huffCode="1111111110011011";
        if(run==4 && cat==8)
            huffCode="1111111110011100";
        if(run==4 && cat==9)
            huffCode="1111111110011101";
        if(run==4 && cat==10)
            huffCode="1111111110011110";
        
        if(run==5 && cat==1)
            huffCode="111011";
        if(run==5 && cat==2)
            huffCode="1111111001";
        if(run==5 && cat==3)
            huffCode="1111111110011111";
        if(run==5 && cat==4)
            huffCode="1111111110100000";
        if(run==5 && cat==5)
            huffCode="1111111110100001";
        if(run==5 && cat==6)
            huffCode="1111111110100010";
        if(run==5 && cat==7)
            huffCode="1111111110100011";
        if(run==5 && cat==8)
            huffCode="1111111110100100";
        if(run==5 && cat==9)
            huffCode="1111111110100101";
        if(run==5 && cat==10)
            huffCode="1111111110100110";
        
        if(run==6 && cat==1)
            huffCode="1111001";
        if(run==6 && cat==2)
            huffCode="11111110111";
        if(run==6 && cat==3)
            huffCode="1111111110100111";
        if(run==6 && cat==4)
            huffCode="1111111110101000";
        if(run==6 && cat==5)
            huffCode="1111111110101001";
        if(run==6 && cat==6)
            huffCode="1111111110101010";
        if(run==6 && cat==7)
            huffCode="1111111110101011";
        if(run==6 && cat==8)
            huffCode="1111111110101100";
        if(run==6 && cat==9)
            huffCode="1111111110101101";
        if(run==6 && cat==10)
            huffCode="1111111110101110";
        
        if(run==7 && cat==1)
            huffCode="1111010";
        if(run==7 && cat==2)
            huffCode="11111111000";
        if(run==7 && cat==3)
            huffCode="1111111110101111";
        if(run==7 && cat==4)
            huffCode="1111111110110000";
        if(run==7 && cat==5)
            huffCode="1111111110110001";
        if(run==7 && cat==6)
            huffCode="1111111110110010";
        if(run==7 && cat==7)
            huffCode="1111111110110011";
        if(run==7 && cat==8)
            huffCode="1111111110110100";
        if(run==7 && cat==9)
            huffCode="1111111110110101";
        if(run==7 && cat==10)
            huffCode="1111111110110110";
        
        if(run==8 && cat==1)
            huffCode="11111001";
        if(run==8 && cat==2)
            huffCode="1111111110110111";
        if(run==8 && cat==3)
            huffCode="1111111110111000";
        if(run==8 && cat==4)
            huffCode="1111111110111001";
        if(run==8 && cat==5)
            huffCode="1111111110111010";
        if(run==8 && cat==6)
            huffCode="1111111110111011";
        if(run==8 && cat==7)
            huffCode="1111111110111100";
        if(run==8 && cat==8)
            huffCode="1111111110111101";
        if(run==8 && cat==9)
            huffCode="1111111110111110";
        if(run==8 && cat==10)
            huffCode="1111111110111111";
        
        if(run==9 && cat==1)
            huffCode="111110111";
        if(run==9 && cat==2)
            huffCode="1111111111000000";
        if(run==9 && cat==3)
            huffCode="1111111111000001";
        if(run==9 && cat==4)
            huffCode="1111111111000010";
        if(run==9 && cat==5)
            huffCode="1111111111000011";
        if(run==9 && cat==6)
            huffCode="1111111111000100";
        if(run==9 && cat==7)
            huffCode="1111111111000101";
        if(run==9 && cat==8)
            huffCode="1111111111000110";
        if(run==9 && cat==9)
            huffCode="1111111111000111";
        if(run==9 && cat==10)
            huffCode="1111111111001000";
        
  
        if(run==10 && cat==1)
            huffCode="111111000";
        if(run==10 && cat==2)
            huffCode="1111111111001001";
        if(run==10 && cat==3)
            huffCode="1111111111001010";
        if(run==10 && cat==4)
            huffCode="1111111111001011";
        if(run==10 && cat==5)
            huffCode="1111111111001100";
        if(run==10 && cat==6)
            huffCode="1111111111001101";
        if(run==10 && cat==7)
            huffCode="1111111111001110";
        if(run==10 && cat==8)
            huffCode="1111111111001111";
        if(run==10 && cat==9)
            huffCode="1111111111010000";
        if(run==10 && cat==10)
            huffCode="1111111111010001";
        
        
        if(run==11 && cat==1)
            huffCode="111111001";
        if(run==11 && cat==2)
            huffCode="1111111111010010";
        if(run==11 && cat==3)
            huffCode="1111111111010011";
        if(run==11 && cat==4)
            huffCode="1111111111010100";
        if(run==11 && cat==5)
            huffCode="1111111111010101";
        if(run==11 && cat==6)
            huffCode="1111111111010110";
        if(run==11 && cat==7)
            huffCode="1111111111010111";
        if(run==11 && cat==8)
            huffCode="1111111111011000";
        if(run==11 && cat==9)
            huffCode="1111111111011001";
        if(run==11 && cat==10)
            huffCode="1111111111011010";
        
        
        
        if(run==12 && cat==1)
            huffCode="111111010";
        if(run==12 && cat==2)
            huffCode="1111111111011011";
        if(run==12 && cat==3)
            huffCode="1111111111011100";
        if(run==12 && cat==4)
            huffCode="1111111111011101";
        if(run==12 && cat==5)
            huffCode="1111111111011110";
        if(run==12 && cat==6)
            huffCode="1111111111011111";
        if(run==12 && cat==7)
            huffCode="1111111111100000";
        if(run==12 && cat==8)
            huffCode="1111111111100001";
        if(run==12 && cat==9)
            huffCode="1111111111100010";
        if(run==12 && cat==10)
            huffCode="1111111111100011";
        
        
        if(run==13 && cat==1)
            huffCode="11111111001";
        if(run==13 && cat==2)
            huffCode="1111111111100100";
        if(run==13 && cat==3)
            huffCode="1111111111100101";
        if(run==13 && cat==4)
            huffCode="1111111111100110";
        if(run==13 && cat==5)
            huffCode="1111111111100111";
        if(run==13 && cat==6)
            huffCode="1111111111101000";
        if(run==13 && cat==7)
            huffCode="1111111111101001";
        if(run==13 && cat==8)
            huffCode="1111111111101010";
        if(run==13 && cat==9)
            huffCode="1111111111101011";
        if(run==13 && cat==10)
            huffCode="1111111111101100";
        
        
        if(run==14 && cat==1)
            huffCode="11111111100000";
        if(run==14 && cat==2)
            huffCode="1111111111101101";
        if(run==14 && cat==3)
            huffCode="1111111111101110";
        if(run==14 && cat==4)
            huffCode="1111111111101111";
        if(run==14 && cat==5)
            huffCode="1111111111110000";
        if(run==14 && cat==6)
            huffCode="1111111111110001";
        if(run==14 && cat==7)
            huffCode="1111111111110010";
        if(run==14 && cat==8)
            huffCode="1111111111110011";
        if(run==14 && cat==9)
            huffCode="1111111111110100";
        if(run==14 && cat==10)
            huffCode="1111111111110101";
        
        
        if(run==15 && cat==1)
            huffCode="111111111000011";
        if(run==15 && cat==2)
            huffCode="1111111111110110";
        if(run==15 && cat==3)
            huffCode="1111111111110111";
        if(run==15 && cat==4)
            huffCode="1111111111111000";
        if(run==15 && cat==5)
            huffCode="1111111111111001";
        if(run==15 && cat==6)
            huffCode="1111111111111010";
        if(run==15 && cat==7)
            huffCode="1111111111111011";
        if(run==15 && cat==8)
            huffCode="1111111111111100";
        if(run==15 && cat==9)
            huffCode="1111111111111101";
        if(run==15 && cat==10)
            huffCode="1111111111111110";
        if(run==15 && cat==0)
            huffCode="1111111010";
        
        
        fprintf(F,"%s",huffCode);
        
        
        int am = data[n][2];
        char * amVLI = VLI(am);
        
        fprintf(F,"%s",amVLI);
        
    }

    fclose(F);
}


void HuffmanLumDC(int ** data,int longueur,char const *out)
{
    FILE *F=fopen(out,"wb");
    
    
    
    for(int n = 0; n<(longueur); n++)
    {
        int cat = data[n][0];
        char * huffCode = NULL;
        
        if(cat==0)
            huffCode="00";
        if(cat==1)
            huffCode="010";
        if(cat==2)
            huffCode="011";
        if(cat==3)
            huffCode="100";
        if(cat==4)
            huffCode="101";
        if(cat==5)
            huffCode="110";
        if(cat==6)
            huffCode="1110";
        if(cat==7)
            huffCode="11110";
        if(cat==8)
            huffCode="111110";
        if(cat==9)
            huffCode="1111110";
        if(cat==10)
            huffCode="11111110";
        if(cat==11)
            huffCode="111111110";

        
        
        fprintf(F,"%s",huffCode);
        
        
        int am = data[n][1];
        char * amVLI = VLI(am);
        
        fprintf(F,"%s",amVLI);
        
    }
    
    fclose(F);
    
}

void HuffmanChrDC(int ** data,int longueur,char const *out)
{
    FILE *F=fopen(out,"wb");
    
    
    
    for(int n = 0; n<(longueur); n++)
    {
        int cat = data[n][0];
        char * huffCode = NULL;
        
        if(cat==0)
            huffCode="00";
        if(cat==1)
            huffCode="01";
        if(cat==2)
            huffCode="10";
        if(cat==3)
            huffCode="110";
        if(cat==4)
            huffCode="1110";
        if(cat==5)
            huffCode="11110";
        if(cat==6)
            huffCode="111110";
        if(cat==7)
            huffCode="1111110";
        if(cat==8)
            huffCode="11111110";
        if(cat==9)
            huffCode="111111110";
        if(cat==10)
            huffCode="1111111110";
        if(cat==11)
            huffCode="11111111110";
        
        
        
        fprintf(F,"%s",huffCode);
        
        
        int am = data[n][1];
        char * amVLI = VLI(am);
        
        fprintf(F,"%s",amVLI);
        
    }
    
    fclose(F);
}


//-------------------------------------------------------------
//-------------------------Ecriture----------------------------
//-------------------------------------------------------------


void ecrireLuminanceAC(Matrix T,int ligneGarde,char const*out)
{
    DCAC daTab = createDCAC(T);
    daTab = quantificationY(daTab , 5);
    
    
    daTab =  zigzag(daTab);
    
    
    
    int l = totalLongueurAC(daTab);
    int ** t = totalIntermediaAC(daTab);
    HuffmanLumAC(t,l,out);
}



void ecrireChrominanceAC(Matrix T,int ligneGarde,char const *out)
{
    DCAC daTab = createDCAC(T);
    daTab = quantificationCbCr(daTab , 5);
    daTab =  zigzag(daTab);
    
    
    
    int l = totalLongueurAC(daTab);
    int ** t = totalIntermediaAC(daTab);
    HuffmanChrAC(t,l,out);
}

void ecrireLuminanceDC(Matrix T,int ligneGarde,char const *out)
{
    DCAC daTab = createDCAC(T);
    daTab = quantificationY(daTab , 5);
    int ** t = intermediaDC(daTab);
    
    HuffmanLumDC(t,daTab.nb,out);
}

void ecrireChrominanceDC(Matrix T,int ligneGarde,char const *out)
{
    DCAC daTab = createDCAC(T);
    daTab = quantificationCbCr(daTab , 5);
    int ** t = intermediaDC(daTab);
    
    HuffmanChrDC(t,daTab.nb,out);
}



//ecrire les codages finals
void ecritureBinaire(const char *in,const char *out)
{
    FILE *F = NULL;
    FILE *Fout = NULL;
    char *buf = (char *)malloc(8*sizeof(unsigned char));
    
    
    
    if ( (F = fopen(in,"rb+")) == NULL)
    {
        printf("Pb composante de l'image inexistante");
    }
    Fout=fopen(out,"wb");
    
    unsigned char  value;
    while(!feof(F))
    {
        fread(buf,1,8,F);
        value = (*buf)*128 + *(buf+1)*64 + *(buf+2)*32 + *(buf+3)*16 + *(buf+4)*8 + *(buf+5)*4 + *(buf+6)*2 + *(buf+7);
        fprintf(Fout,"%x",value);
    }
    
    
    
    fclose(F);
    
}
