/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 8 de noviembre de 2012, 10:10
 */

#include <stdio_ext.h>
#include <stdlib.h>

/*
 * 
 */
int CreaArrayLetras(char []);
void AsignaCantidades(char [],int [],int);
void SimplificaArray(char [],int [],int);

void main(){
    
    
    char letras[20];
    int cantidad[20],n,i;
    
    
    
    n=CreaArrayLetras(letras);
    
    AsignaCantidades(letras,cantidad,n);
    
    SimplificaArray(letras,cantidad,n);
  
    
    
    for(i=0;i<n;i++){
        if(cantidad[i]!=0)
        printf("\nLetras: %c Cantidad: %d",letras[i],cantidad[i]);
    }
    
    
    
}

int CreaArrayLetras(char letras[]){
    
    char a;
    int n=0;
    
    printf("\nIntroduce una sucesion de caracteres: ");
    fflush(stdout);
    __fpurge(stdin);
    
    do{
    scanf("%c",&a);
    letras[n]=a;
    n++;
    
    
    }while(a!='\n');
    n--;
    return n;
}

void AsignaCantidades(char letras[],int cantidad[],int n){
    int i,j;
    
    for(i=0;i<n;i++)
    {
        cantidad[i]=0;
        for(j=0;j<n;j++){
        if(letras[i]==letras[j])
            cantidad[i]++;
        }
        
    }
}

void SimplificaArray(char letras[],int cantidad[],int n){
    
    int i,j;
    
    for(i=0;i<n;i++){
        
        for(j=i+1;j<n;j++){
            
            if(letras[i]==letras[j]){
                letras[j]='/'; //Cualquier caracter que no sea letra
                cantidad[j]=0;
                }
        }
            
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        {
            if(cantidad[i]>cantidad[j]){
                letras[j]='/'; //cualquier caracter que no sea letra
                cantidad[j]=0; 
            }
            
        }
    }
    
}

