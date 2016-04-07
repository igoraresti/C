/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 5 de octubre de 2012, 10:50
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void main(){
    
    char a;
    int letra=0, blanco=0, numero=0;
    
    printf("\nEscribe una frase para contar numero de letras, blancos y numeros,"
            " para terminar pulsa enter: ");
    
    do{
        scanf("%c",&a);
        
        if(a==32)
            blanco++;
        if(a>47 && a<58)
            numero++;
        if(a>64 && a<91)
            letra++;
        if(a>96 && a<123)
            letra++;
                    
          
        
        
    }while(a!=10);
    
    printf("\nLetras: %d\nEspacios: %d\nNumeros: %d",letra,blanco,numero);
    
    
  
    
    
    
}
