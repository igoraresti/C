/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 5 de octubre de 2012, 11:01
 */

#include <stdio_ext.h>
#include <stdlib.h>

/*
 * 
 */
void main(){
    
    int numero,i,sumatorio=0,j,multipli;
    
    printf("\nIntroduce un numero para calcular sumatorio de(i^i) desde 1 a numero introducido ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&numero);
    
    for(i=numero;i>=1;i--){
        
        j=i;
        multipli=1;
        do{
            
            multipli=multipli*i;
        j--;
        }while(j>0);
        sumatorio=sumatorio+multipli;
    }
    
    printf("\nEl sumatorio es: %d",sumatorio);
}

