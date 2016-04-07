/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 9 de noviembre de 2012, 10:51
 */

#include <stdio_ext.h>
#include <stdlib.h>

/*
 * 
 */
void NumeroCuenta(int []);
int OperacionSuma(int cuenta[]);
int OperacionResta(int cuenta[]);
int OperacionMultiplicar(int cuenta[]);
void Verificar(int cuenta[],int codigo);
char ValidaNumero(int);

void main(){
    
    int cuenta[10],codigo;
    
    NumeroCuenta(cuenta);
    
    if(cuenta[0]==1){
        codigo=OperacionSuma(cuenta);
        
    }
    
    if(cuenta[0]==2){
        codigo=OperacionResta(cuenta);
    }
    
    if(cuenta[0]==3){
        codigo=OperacionMultiplicar(cuenta);
    }
    
    Verificar(cuenta,codigo);
    
    
}

void NumeroCuenta(int cuenta[]){
    
    int i,n; 
    char t;
    printf("\nIntroduce el codigo de cuenta: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&i);
    cuenta[0]=i;
    
    printf("\nIntroduce el numero de cuenta: ");
    fflush(stdout);
    
    for(i=1;i<10;i++){
        
        do{
            
        printf("\nNumero %d: ",i);
        fflush(stdout);
        __fpurge(stdin);
        scanf("%d",&n);
        
        t=ValidaNumero(n);
        
        }while(t=='n');
        cuenta[i]=n;
    }
}
int OperacionSuma(int cuenta[]){
    
    int suma=0,i;
    
    for(i=1;i<9;i++){
        suma=suma+cuenta[i];
    }
    
    return suma;
}

int OperacionResta(int cuenta[]){
    
    int resta=0,i;
    
    for(i=1;i<9;i++){
        resta=resta-cuenta[i];
    }
    
    resta=resta*(-1);
    
    return resta;
}

int OperacionMultiplicar(int cuenta[]){
    
    int multiplicacion=1,i;
    
    for(i=1;i<9;i++){
        multiplicacion=multiplicacion*cuenta[i];
    }
    
    return multiplicacion;
    
}
 
void Verificar(int cuenta[],int codigo){
    
    do{
        
        codigo=codigo-10;
        
        
    }while(codigo>10);
     
    
    if(cuenta[9]==codigo)
        printf("\nCódigo válido!");
    else
        printf("\nCódigo errónero!");
}
    
    
char ValidaNumero(int numero){
    
    char t;
    
    if (numero>9 || numero<1)
    {
        t='n';
        printf("\nNumero erroneo, vuelve a introducir");
    }
    else
        t='s';
    
    return t;
    
}
                                
