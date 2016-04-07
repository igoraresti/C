/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 9 de noviembre de 2012, 10:38
 */

#include <stdio_ext.h>
#include <stdlib.h>

/*
 * 
 */
void CreaArrayYX(int [],int [],int);
void ComparaYCreaArrayZ(int arrayX[],int arrayY[],int arrayZ[],int N,int*,int*);
void MuestraTabla(int arrayX[],int arrayY[],int arrayZ[],int N,int contadorYmayor,int contadorXmayor);

void main(){
    
    int N,contadorYmayor,contadorXmayor;
    int arrayZ[10],arrayX[10],arrayY[10];
    
    printf("Cuantos numeros vas a meter? (menor de 10): ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&N);
    
    CreaArrayYX(arrayX,arrayY,N);
    ComparaYCreaArrayZ(arrayX,arrayY,arrayZ,N,&contadorYmayor,&contadorXmayor);
    MuestraTabla (arrayX,arrayY,arrayZ,N,contadorYmayor,contadorXmayor);
    
    
}

void CreaArrayYX(int arrayX[],int arrayY[],int N){
    
    int i,n;
    
    for(i=0;i<N;i++){
        
        printf("\nIntroduce el elemento %d de X: ",i+1);
        fflush(stdout);
        __fpurge(stdin);
        scanf("%d",&n);
        arrayX[i]=n;
        
        printf("\nIntroduce el elemento %d de Y: ",i+1);
        fflush(stdout);
        __fpurge(stdin);
        scanf("%d",&n);
        arrayY[i]=n;
    }
    
    
}

void ComparaYCreaArrayZ(int arrayX[],int arrayY[],int arrayZ[],int N,int *contadorYmayor,int *contadorXmayor ){
    
    int i;
    *contadorYmayor=0;
    *contadorXmayor=0;
    for(i=0;i<N;i++){
        
        if(arrayX[i]>arrayY[i]){
            *contadorXmayor=*contadorXmayor+1;
            arrayZ[i]=1;}
                    
        if(arrayX[i]<arrayY[i]){
            *contadorYmayor=*contadorYmayor+1;
            arrayZ[i]=-1;}
                    
        if(arrayX[i]==arrayY[i])
            arrayZ[i]=0;
    }
   
    
    
}

void MuestraTabla(int arrayX[],int arrayY[],int arrayZ[],int N,int contadorYmayor,int contadorXmayor){
    
    int i;
    printf("\nX Y Z");
    for(i=0;i<N;i++){
        
        printf("\n%d %d %d",arrayX[i],arrayY[i],arrayZ[i]);
    }
    
    printf("\n\nNº Elementos X mayores que Y: %d\nNº Elementos Y mayores que X: %d",contadorXmayor,contadorYmayor);
}