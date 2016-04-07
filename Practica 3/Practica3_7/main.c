/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 18 de octubre de 2012, 11:32
 */

#include <stdio_ext.h>
#include <stdlib.h>

/*
 * 
 */
void main()
{
    char letras;
    int distancia,bucle;
    
    printf("\nIntroduce una sucesion de caracteres que termine en punto, ademas,"
            "elige la distancia a la que quieres desplazar las letras: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&distancia);
    printf("\n");
    fflush(stdout);
    do
    {
        scanf("%c",&letras);
        if(letras>='a' && letras<='z'){
            letras=letras+distancia;
            if(letras>'z')
            {
                bucle=letras-'z';
                letras='a'-1+bucle;
            }
            printf("%c",letras);
        }
        
        if(letras>='A' && letras<='Z'){
            letras=letras+distancia;
            if(letras>'Z')
            {
                bucle=letras-122;
                letras='Z'-1+bucle;
            }
            printf("%c",letras);
        }
            
        
    }while(letras!='.');
    
    
}

