/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 22 de noviembre de 2012, 15:06
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
/*
 * 
 */
void EliminaCaracteresNoAlfabeticos(char frase[]);
void PasaTodoAMayusculas(char frase[]);
void CompruebaSiEsPalindromo(char frase[]);

void main(){
    
    char frase[50];
    
    printf("\nIntroduce una frase o palabra: ");
    fflush(stdout);
    __fpurge(stdin);
    fgets(frase,50,stdin);
    
    EliminaCaracteresNoAlfabeticos(frase);
    
    PasaTodoAMayusculas(frase);
    
    CompruebaSiEsPalindromo(frase);
    
    
}

void EliminaCaracteresNoAlfabeticos(char frase[]){
    
    int i=0,j;
    
    do{
        if(frase[i]<'A' || (frase[i]>'Z' && frase[i]<'a') || frase[i]>'z' ){
            
            for(j=i;j<strlen(frase);j++){
            frase[j]=frase[j+1];}
            
            
        }
        
        
        i++;
        
    }while( frase[i]!='\0');
    
    printf("\nPalabra solo letras: %s",frase);
}

void PasaTodoAMayusculas(char frase[]){
    
    int i;
    
    for(i=0;frase[i]!='\0';i++){
        
        if(frase[i]>='a' && frase[i]<='z'){
            
            frase[i]=frase[i]-32;
        }
        
    }
    
    printf("\nfrase todo mayusculas: %s",frase);
    
}

void CompruebaSiEsPalindromo(char frase[]){
    
    int inicio,final,CuentaBucle=0;
    
    inicio=-1;
    final=strlen(frase);
    
    
    do{
        
        inicio++;
        final--;
        CuentaBucle++;
        
    }while(frase[inicio]==frase[final] && CuentaBucle>strlen(frase)/2);
    
    /*Hay que crear la excepcion en la que solo se mete una letra, porque el bucle
     compara el Nº de interaciones con la longitud de la frase entre 2. Y 1 entre
     2 es 0.5, y al ser un int coge el 0 y haria mas interacciones no deseadas.
     */
    
    if(strlen(frase)!=1){
    if(frase[inicio]==frase[final]){
        printf("\nTu palabra o frase es palindromo!");
    }
    else{
        printf("\nTu palabra o frase NO es palindromo");
    }
    }
    else{
        printf("\nTu Letra es palindromo!!");
    }
    
}