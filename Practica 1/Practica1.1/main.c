/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 28 de septiembre de 2012, 10:10
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void main(){
   
    int C,F;
    printf("\nIntroduce los grados celsius para convertirlos a fahrenheit: ");
    //__fpurge(stdout);
    fflush(stdout);
    scanf("%d",&C);
    
    F=(1.8*C)+32;
    
    printf("\nGrados fahrenheit: %d",F);
    
}
