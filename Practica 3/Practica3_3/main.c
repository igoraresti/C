/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 5 de octubre de 2012, 10:14
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void main(){
    
    
    float N,epsilon, r,R;
    
    printf("\nIntroduce el numero N: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%f",&N);
    
    printf("\nIntroduce la precision epsilon: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%f",&epsilon);
    
    printf("\nIntroduce la aproximacion de la raiz cuadrada de N: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%f",&r);
    
    do{
        R=((N/r)+r)/2;
        
        
    }while(abs(r-R)>=epsilon);
    
    printf("\nLa raiz de %f es %f",N,R);
    
}
