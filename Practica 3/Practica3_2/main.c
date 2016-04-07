/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 4 de octubre de 2012, 11:17
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void main(){
    
    int numero,vidas=10;
    
    printf("\nAcierta un numero de dos cifras, 10 intentos");
    
    do{
        
        
        printf("\nSuerte: ");
        fflush(stdout);
        __fpurge(stdin);
        scanf("%d",&numero);
        
        if(numero>14){
            vidas--;
            printf("\nEl numero que buscas es menor que %d\nNumero de intentos restantes: %d",numero,vidas);
            fflush(stdout);
            
        }
        if(numero<14){
            vidas--;
            printf("\nEl numero que buscas es mayor que %d\nNumero de intentos restantes: %d",numero,vidas);
            fflush(stdout);
            
        }
        
    
        
    }while(vidas>0 && numero!=14);
    
    
    printf("\nHas acertado! El numero era %d!\nHas necesitado: %d intentos",numero,10-vidas+1);
    
    
}
