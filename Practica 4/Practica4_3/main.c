/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 19 de octubre de 2012, 11:20
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <math.h>

double CalculaFactorial(int N);
double CalculaPotencias(float x,int N);

void main(){
    
    float x,cos=1,NuevoTermino;
    int N=0,signo,variador=1;
    double potencia,factorial;
    
    printf("\nIntroduce el cos que quieres calcular: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%f",&x);
    
    do{
        N=N+2;
        
        potencia=CalculaPotencias(x,N);
        factorial=CalculaFactorial(N);
        
        
        NuevoTermino=potencia/factorial;
        
        signo=pow(-1,variador);
        variador++;
        cos=cos+(signo*(NuevoTermino));
        printf("\nPotencia= %lf y factorial %lf",potencia,factorial);
        
        printf("\nN es %d y el signo: %d",N,signo);
        printf("\nValor del nuevo termino: %f",NuevoTermino);
        
        
        
    }while(NuevoTermino>000.5);
    
    printf("\nCOS(X) de %f es %f",x,cos);
    
}

double CalculaPotencias(float x,int N){
    
    int i;
    double potencia=1;
    for(i=N;i>0;i--){
        
        
        
        
        potencia=potencia*x;
        
    }
    
    return potencia;
}

double CalculaFactorial(int N){
    
    double factorial=N;
    
    do{
        N--;
        factorial=factorial*N;
        
        
    }while(N>1);
    
    
    
    return factorial;
}