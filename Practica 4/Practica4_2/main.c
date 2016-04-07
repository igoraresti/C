/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 19 de octubre de 2012, 10:34
 */

#include <stdio_ext.h>
#include <stdlib.h>

/*
 * 
 */
int CalculaMCD(int, int);

void main(){
    
    int Num1,Num2,MCD,nuevoNum1,nuevoNum2;
    
    printf("\nIntroduce el zenbakitzailea: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&Num1);
    
    printf("\nIntroduce el izendatzailea: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&Num2);
    
    MCD=CalculaMCD(Num1,Num2);
    nuevoNum1=Num1/MCD;
    nuevoNum2=Num2/MCD;
    
    printf("\n%d  %d\n---= ---\n%d   %d",Num1,nuevoNum1,Num2,nuevoNum2);
    
}

int CalculaMCD(int Num1,int Num2){
    
    int MCD;
    printf("\nEntra");
    do{
        
        if(Num1>Num2){
            Num1=Num1-Num2;}
            
        
        if(Num2>Num1){
            Num2=Num2-Num1;}
        
        
    }while (Num1!=Num2);
    
    MCD=Num1;
    
    return MCD;
}