/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 19 de noviembre de 2012, 12:08
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <math.h>
/*
 * 
 */
int *IntroduceNumeros(int*);
float Media(int *,int);
int *ReservaMemoria(int N,int *numeros);
int Moda(int *numeros, int N);
float DesviacionTipica(int *numeros,int N,int media);

void main(){
    
    int *numeros,N=0,moda,i;
    float media,desviacion;
    
    
    
    numeros=IntroduceNumeros(&N);
    
    
    
    printf("\nNumeros introducidos: %d",N);
    
    media=Media(numeros,N);
    
    printf("\nLa media es %.2f",media);
    
    moda=Moda(numeros,N);
    
    printf("\nLa moda es %d",moda);
    
    desviacion=DesviacionTipica(numeros,N,media);
    
    printf("\nLa desviacion típica: %f",desviacion);
    
    free(numeros);
}

int *IntroduceNumeros(int *N){
    
    
    int n,*numeros=NULL,memoria;
    char t;
    do{
        
        
        *N=*N+1;
        memoria=*N;
        
        numeros=ReservaMemoria(memoria,numeros);
        
        printf("\nIntroduce numero: ");
        fflush(stdout);
        __fpurge(stdin);
        scanf("%d",&n);
        
        
        numeros[*N-1]=n;
        
        
        printf("\nDeseas introducir un nuevo numero? s/n: ");
        fflush(stdout);
        __fpurge(stdin);
        scanf("%c",&t);
        
        
        
    }while (*N>50 || t=='s');
    
    
    
    
    
    return numeros;
}

float Media(int *numeros,int N){
    
    int i,sumatorio=0;
    float media,H;
    H=N;
    for(i=0;i<N;i++){
        
        sumatorio=sumatorio+numeros[i];
        
    }
    
    media=sumatorio/H;
    
    
    
    return media;
}

float DesviacionTipica(int *numeros,int N,int media){
    
    float sumatorio=0,resta,raiz,desviacion;
    int i;
    
    for(i=0;i<N;i++){
        
        resta=media-numeros[i];
        sumatorio=sumatorio+pow(resta,2);
        
    }
    raiz=sqrt(sumatorio);
    
    desviacion=raiz/N;
    
    return desviacion;
    
}

int *ReservaMemoria(int N,int *numeros)
{
    
    
    numeros=(int*) realloc (numeros, (N+1) *sizeof(int));
    
    
    return numeros;
}

int Moda(int *numeros, int N){
    
    int *CuentaNumeros=NULL,i,j,NumeroModa;
    
    
    CuentaNumeros=ReservaMemoria(N,CuentaNumeros);
    for(i=0;i<N;i++){
        CuentaNumeros[i]=0;
    }
    
    for(i=0;i<N;i++){
        
        for(j=0;j<N;j++){
            if(numeros[i]==numeros[j]){
                CuentaNumeros[i]=CuentaNumeros[i]+1;
                
            }
        }
        
    }
    
    
    
    NumeroModa=CuentaNumeros[0];
    i=0;
        
        for(j=0;j<N;j++){
            if(NumeroModa<CuentaNumeros[j]){
                NumeroModa=CuentaNumeros[j];
                i=j;
                
            }
        }
    
    return numeros[i];
        
    
    
}
