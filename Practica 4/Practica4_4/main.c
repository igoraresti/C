/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 2 de noviembre de 2012, 10:22
 */

#include <stdio_ext.h>
#include <stdlib.h>

/*
 * 
 */
void CentroNumerico(int);
int SumaGrupos(int,int*,int*);

void main(){
    
    int teclado;
    
    printf("\nIntroduce un numero menor que 7000: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&teclado);
    do{
        
    CentroNumerico(teclado);
    teclado--;
    
    }while(teclado>0);
    
    
}

void CentroNumerico(int numero){
    
    int CuentaAbajo,CuentaArriba,FinCuenta;
    
    CuentaAbajo=SumaGrupos(numero,&CuentaArriba,&FinCuenta);
    
    
    if(CuentaArriba==CuentaAbajo){
            printf("\nEl numero %d es centro numerico desde 1 a %d y desde %d a %d, suma por ambos lados %d",numero,numero-1,numero+1,FinCuenta,CuentaAbajo);
        }
    
    
}

int SumaGrupos(int numero,int *CuentaArriba,int *FinCuenta){
    
    int i,CuentaAbajo=0;
    *CuentaArriba=0;
    for(i=1;i<numero;i++){
        
        CuentaAbajo=CuentaAbajo+i;
    }
    
    i=numero;
    
    do{
        i++;
        *CuentaArriba=*CuentaArriba+i;
        
        
        
    }while(CuentaAbajo>*CuentaArriba);
    *FinCuenta=i;
    
    return CuentaAbajo;
}