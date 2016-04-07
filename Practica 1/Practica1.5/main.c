/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 28 de septiembre de 2012, 10:59
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void main(){
    
    
    int dia, mes, anio;
    
    printf("\nIntroduce dia: ");
    __fpurge(stdin);
    fflush(stdout);
    scanf("%d",&dia);
    
    printf("\nIntroduce mes: ");
    __fpurge(stdin);
    fflush(stdout);
    scanf("%d",&mes);
    
    printf("\nIntroduce año: ");
    __fpurge(stdin);
    fflush(stdout);
    scanf("%d",&anio);
    
    printf("\nFecha introducida: %d/%d/%d",dia,mes,anio);
}

