/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 18 de octubre de 2012, 11:19
 */

#include <stdio_ext.h>
#include <stdlib.h>

/*
 * 
 */
void main(){
    
    char ascii=33;
    int i,j,numero=33;
    
    for(i=0;i<28;i++){
        
        printf("\n");
        fflush(stdout);
        for(j=0;j<8;j++){
            printf("%d %c ",numero,ascii);
            fflush(stdout);
            numero++;
            ascii++;
        }
    }
    
    
    
    
}

