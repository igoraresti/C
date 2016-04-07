/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 4 de octubre de 2012, 10:52
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void main(){
    
    int i,factorial;
    
    printf("\nIntroduce numero: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&factorial);
    i=factorial;
    do{
        i--;
        factorial=factorial*i;
        
        
    }while(i>1);
    
    printf("\nEl factorial de tu numero es: %d",factorial);
    
}

