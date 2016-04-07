/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 4 de octubre de 2012, 10:19
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void main()
{
    int a,b,c,d;
    
    printf("\nIntroduce numero 1: ");
    
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&a);
    
    printf("\nIntroduce numero 2: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&b);
    
    if(a<b){
        c=a;
        a=b;
        b=c;
    }
    
    printf("\nIntroduce numero 3: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&c);
    
    if(b<c){
        d=b;
        b=c;
        c=d;
        if(a<b)
        {
            d=a;
            a=b;
            b=d;
        }
    }
    
    printf("\nOrden creciente: %d %d %d",c,b,a);
    
}

