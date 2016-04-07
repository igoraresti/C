/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 22 de noviembre de 2012, 10:19
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
/*
 * 
 */
int CuentaPalabras(char []);
void DevuelveCadenaSinEspaciosAlPrincipio(char []);
void DevuelveCadenaSinEspaciosAlFinal(char frase[]);
void QuitaEspaciosIntermedios(char frase[]);
void main(){
    
    int NumeroPalabras;
    char frase[50];
    printf("\nIntroduce una frase: ");
    fflush(stdout);
    __fpurge(stdin);
    fgets(frase,50,stdin);
    
    
    
    NumeroPalabras=CuentaPalabras(frase);
    
    
    
    printf("\nLa frase:%s(Hasta Aqui) tiene %d palabras",frase,NumeroPalabras);
    
    DevuelveCadenaSinEspaciosAlPrincipio(frase);
    
    printf("\nLa frase sin espacios al inicio:%s(Hasta Aqui)",frase);
    
    DevuelveCadenaSinEspaciosAlFinal(frase);
    
    printf("\nLa frase sin espacios al final:%s(Hasta Aqui)",frase);
    
    QuitaEspaciosIntermedios(frase);
    
    printf("\nFrase sin espacios:%s",frase);
}

int CuentaPalabras(char frase[]){ 
    
    int i,contador=0;
    
    
    for(i=0;frase[i]!='\0';i++){
        
        if(frase[i]==' ' && (frase[i+1]>'a'-1 && frase[i+1]<'z'+1) || (frase[i+1]>'A'-1 && frase[i+1]<'Z'+1)){ //mirar que haya un espacio seguido de una letra para saber que es palabra
            contador++;  
        }
    }
        
    
    
    return contador;
}

void DevuelveCadenaSinEspaciosAlPrincipio(char frase[]){
    int j;
    
    
   
    
    do{
        if(frase[0]==' ')
        {
            
            for(j=0;frase[j]!='\0';j++){
                frase[j]=frase[j+1];
            }
            
        }
        
        
    }while(frase[0]==' ');
    
    
    
    
}

void DevuelveCadenaSinEspaciosAlFinal(char frase[]){
    int i;
    
    
    
    i=strlen(frase);
    do{
        
        
        if(frase[i-1]==' ')
        {
            
            frase[i-1]='\0';
        }
        i=strlen(frase);
        
    }while(frase[i-1]==' ');
    
    
    
    
}

void QuitaEspaciosIntermedios(char frase[]){
    
    int i,j;
    
    for(i=0;i<strlen(frase);i++){
        
        if(frase[i]==' '){
            j=i; //cuando hay un espacio entra y en el do lo elimina desde ahi hasta el final
            i--; // porque si hay mas de un espacio seguido se deja uno de ellos
            do{
                frase[j]=frase[j+1];
                j++;
                
            }while(frase[j]!='\0');
        }
        
    }
    
}