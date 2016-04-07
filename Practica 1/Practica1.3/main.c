/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 28 de septiembre de 2012, 10:35
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void main(){
    
    int a;
    int uni,dec,cen;
    printf("Introduce un numero de tres cifras: ");
    __fpurge(stdin);
    fflush(stdout);
    scanf("%d",&a);
    
    uni=a/100;
    a=a-(uni*100);
    
    dec=a/10;
    a=a-(dec*10);
    
    cen=a;
    
    printf("\nTu numero al reves: %d%d%d",cen,dec,uni);
    
    
}

