/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 28 de septiembre de 2012, 10:20
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void main(){
    
    int cir,cua,tri;
    float area;
    
    printf("\nIntroduce radio del circulo: ");
    __fpurge(stdin);
    fflush(stdout);
    scanf("%d",&cir);
    
    printf("\nIntroduce lado del cudrado: ");
    __fpurge(stdin);
    fflush(stdout);
    scanf("%d",&cua);
    
    printf("\nIntroduce lado del triangulo: ");
    __fpurge(stdin);
    fflush(stdout);
    scanf("%d",&tri);
    
    area=cir*cir*3.14;
    printf("\nArea del circulo: %f",area);
    
    area=cua*cua;
    printf("\nArea del cuadrado: %f",area);
    
    area=(tri*tri)/2;
    printf("\nArea del triangulo: %f",area);
    
    
}