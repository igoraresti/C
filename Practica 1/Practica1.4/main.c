/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 28 de septiembre de 2012, 10:42
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void main(){
    
    float cantidad;
    int b500,b200,b100,b50,b20,b10,b5,M2,M1,m50,m20,m10,m5,m2,m1;
    printf("\nIntroduce una cantidad: ");
    __fpurge(stdin);
    fflush(stdout);
    scanf("%f",&cantidad);
    
    b500=cantidad/500;
    cantidad=cantidad-(b500*500);
    
    b200=cantidad/200;
    cantidad=cantidad-(b200*200);
    
    b100=cantidad/100;
    cantidad=cantidad-(b100*100);
    
    b50=cantidad/50;
    cantidad=cantidad-(b50*50);
    
    b20=cantidad/20;
    cantidad=cantidad-(b20*20);
    
    b10=cantidad/10;
    cantidad=cantidad-(b10*10);
    
    b5=cantidad/5;
    cantidad=cantidad-(b5*5);
    
    M2=cantidad/2;
    cantidad=cantidad-(M2*2);
    
    M1=cantidad/1;
    cantidad=cantidad-(M1*1);
    
    m50=cantidad/0.5;
    cantidad=cantidad-(m50*0.5);
    
    m20=cantidad/0.2;
    cantidad=cantidad-(m20*0.2);
    
    m10=cantidad/0.1;
    cantidad=cantidad-(m10*0.1);
    
    m5=cantidad/0.05;
    cantidad=cantidad-(m5*0.05);
    
    m2=cantidad/0.02;
    cantidad=cantidad-(m2*0.02);
    
    m1=cantidad/0.01;
    cantidad=cantidad-(m1*0.01);
    
    printf("\nCantidad de billetes y monedas:\n500: %d\n200: %d\n100: %d\n"
            "50: %d\n20: %d\n10: %d\n5: %d\n2: %d\n1: %d\n0.50: %d\n0.20: %d\n"
            "0.10: %d\n0.05: %d\n0.02: %d\n0.01: %d",b500,b200,b100,b50,b20,b10,b5,M2,M1,m50,m20,m10,m5,m2,m1);
    
}
