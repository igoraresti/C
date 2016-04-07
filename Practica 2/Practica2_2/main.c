/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 4 de octubre de 2012, 10:34
 */

#include <stdio_ext.h>
#include <stdlib.h>

/*
 * 
 */
void main(){
    
    float gasto,descuento,importe;
    
    printf("\nIntroduce el gasto: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%f",&gasto);
    
    if(gasto<6000){
        printf("\nTipo de descuento es NULO");
        
        descuento=(gasto*0)/100;
        
        printf("\nDescuento: %.2f",descuento);
        
        importe=gasto-descuento;
        
        printf("\nImporte final: %.2f",importe);
    }
    
    if(gasto>6000 && gasto<10000){
        printf("\nTipo de descuento BAJO");
        
        descuento=(gasto*10)/100;
        
        printf("\nDescuento: %.2f",descuento);
        
        importe=gasto-descuento;
        
        printf("\nImporte final: %.2f",importe);
    }
    
    if(gasto>10000 && gasto<20000){
        printf("\nTipo de descuento MEDIO");
        
        descuento=(gasto*20)/100;
        
        printf("\nDescuento: %.2f",descuento);
        
        importe=gasto-descuento;
        
        printf("\nImporte final: %.2f",importe);
    }
    
    if(gasto>20000 ){
        printf("\nTipo de descuento ALTO");
        
        descuento=(gasto*30)/100;
        
        printf("\nDescuento: %.2f",descuento);
        
        importe=gasto-descuento;
        
        printf("\nImporte final: %.2f",importe);
    }
    
    
    
}
