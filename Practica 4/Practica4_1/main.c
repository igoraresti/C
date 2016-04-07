/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 19 de octubre de 2012, 10:11
 */

#include <stdio_ext.h>
#include <stdlib.h>

/*
 * 
 */
int CalculaRebote(float, float, float);
float CalculaAltura(float R,float H,int nRebote);

void main(){
    
    float R,H,AlturaRebote;
    int nRebote;
    int menu;
    printf("\nIntroduce el factor de rebote menor que 1: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%f",&R);
    
    printf("\nIntroduce la altura a la que se lanza la pelota: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%f",&H);
    
    printf("\n1. Calcular numero de rebotes para una altura.\n"
            "2. Calcular para un rebote que altura es.");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&menu);
    
    if(menu==1){
        printf("\nIntroduce la altura de rebote que se desea calcular(menor que la altura inicial): ");
        fflush(stdout);
        __fpurge(stdin);
        scanf("%f",&AlturaRebote);

        nRebote=CalculaRebote(R,H,AlturaRebote);

        printf("\nLa pelota ha alcanzado %d rebotes.",nRebote);
    }
    
    if(menu==2){
        printf("\nIntroduce el rebote que deseas: ");
        fflush(stdout);
        __fpurge(stdin);
        scanf("%d",&nRebote);
        
        AlturaRebote=CalculaAltura(R,H,nRebote);
        
        printf("\nLa pelota en el rebote %d tiene %f altura.",nRebote,AlturaRebote);
    }
    
}

int CalculaRebote(float R, float H, float AlturaRebote){
    
    float altura;
    int nRebote=0;
    
    
    do{
        
        
        if(nRebote!=0){
            altura=altura*R;
            nRebote++;
        }
        
        if(nRebote==0){
            altura=H*R;
            nRebote++;
        } 
        
        
    }while(altura>=AlturaRebote);
    
    
    
    return nRebote;
    
}

float CalculaAltura(float R,float H,int nRebote){
    float altura;
    int rebote=0;
    
    do{
        
        
        if(rebote!=0){
            altura=altura*R;
            rebote++;
        }
        
        if(rebote==0){
            altura=H*R;
            rebote++;
        } 
        
        
    }while(rebote!=nRebote);
    
    
    return altura;
}