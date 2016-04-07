/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 22 de noviembre de 2012, 16:33
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
 * 
 */
char CompruebaDNI(char dni[]);
char CalculaLetraNIF(char dni[]);
int ConvierteStringAEntero(char dni[]);
void CreaNif(char dni[],char nif[],char letra);

void main(){
    
    char dni[9],validacion,letra,nif[13];
    
    do{
    printf("\nIntroduce dni: ");
    fflush(stdout);
    __fpurge(stdin);
    fgets(dni,9,stdin);
    
    
    
    validacion=CompruebaDNI(dni);
    }while(validacion!='s');
    
    letra=CalculaLetraNIF(dni);
    
    CreaNif(dni,nif,letra);
    
    printf("\nDNI: %s\nNIF: %s",dni,nif);
    
}

char CompruebaDNI(char dni[]){
    
    char validacion;
    int nan;
    
    
    if(strlen(dni)==8){
    nan=ConvierteStringAEntero(dni);
    
    
        if(nan>=100000 && nan<=99999999)
        {
            validacion='s';
            printf("\nDNI valido");
        }
        else
        {
            printf("\nDNI no valido");
            validacion='n';
        }
    }
    else
    {
        printf("\nDNI no valido");
        validacion='n';
    }
    return validacion;
}

char CalculaLetraNIF(char dni[]){
    
    char letra[23]={'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
    int numero;
    
    numero=ConvierteStringAEntero(dni);
    
    numero=numero%23;
    
   
    return letra[numero];
}


int ConvierteStringAEntero(char dni[]){
    
    int numero=0,i;
    int digito;
    
    
    
    for(i=0;i<8;i++){
	digito=dni[i]-'0';
        
        
        numero=numero+digito*pow(10,7-i);
        
        
    }
    
    return numero;
}

void CreaNif(char dni[],char nif[],char letra){
    
    int i;
    strcpy(nif,dni);
    
    nif[2]='.';
    nif[3]=dni[2];
    nif[4]=dni[3];
    nif[5]=dni[4];
    nif[6]='.';
    nif[7]=dni[5];
    nif[8]=dni[6];
    nif[9]=dni[7];
    nif[10]=' ';
    nif[11]=letra;
    
}
