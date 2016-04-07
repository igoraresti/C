/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 28 de noviembre de 2012, 13:01
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
/*
 * 
 */
struct stand{
    
    char Nombre[20];
    int NumeroPabellon;
    int Dias;
    int Metros;
    int Precio;
    
};

struct pabellon{
    
    int Tarifa;
    int MetrosAlquilados;
};

void RellenaInformacionPabellones(struct pabellon Pabellones[]);
int Menu();
struct stand *ReservaMemoria(struct stand *GuardaEmpresas,int NumeroEmpresas);
struct stand *AddStand(struct stand *GuardaEmpresas,int NumeroEmpresas);
void CalculaPrecioStand(struct stand *GuardaEmpresas,int NumeroEmpresas,struct pabellon Pabellones[]);
void MuestraStandYPabellones(struct stand *GuardaEmpresas,int NumeroEmpresas,struct pabellon Pabellones[]);
void OrdenaAlfabeticamenteEmpresas(struct stand *GuardaEmpresas,int NumeroEmpresas);
int PosicionEliminaStand(struct stand *GuardaEmpresas,int NumeroEmpresas);
void PoneStandAEliminarUltimaPosicion(struct stand *GuardaEmpresas,int NumeroEmpresas,int posicion);
void ActualizaMetrosPabellon(struct stand *GuardaEmpresas,int NumeroEmpresas,struct pabellon Pabellones[]);
int ModificaTarifa(struct pabellon Pabellones[]);
void ActualizaPrecioStand(struct stand *GuardaEmpresas,int NumeroEmpresas,struct pabellon Pabellones[],int PabellonNuevaTarifa);

void main(){
    
    struct pabellon Pabellones[5];
    struct stand *GuardaEmpresas=NULL;
    
    int menu,NumeroEmpresas=0,EliminaPosicion,NuevaTarifaPabellon;
   
    RellenaInformacionPabellones(Pabellones);
    
    do{
        menu=Menu();
        
        if(menu==1){
            NumeroEmpresas++;
            GuardaEmpresas=AddStand(GuardaEmpresas,NumeroEmpresas);
            CalculaPrecioStand(GuardaEmpresas,NumeroEmpresas,Pabellones);
            OrdenaAlfabeticamenteEmpresas(GuardaEmpresas,NumeroEmpresas);
            
        }
        
        if(menu==2){
            EliminaPosicion=PosicionEliminaStand(GuardaEmpresas,NumeroEmpresas);
            ActualizaMetrosPabellon(GuardaEmpresas,EliminaPosicion,Pabellones);
            PoneStandAEliminarUltimaPosicion(GuardaEmpresas,NumeroEmpresas,EliminaPosicion);
            NumeroEmpresas--;
            GuardaEmpresas=ReservaMemoria(GuardaEmpresas,NumeroEmpresas);
            
        }
        
        if(menu==3){
            NuevaTarifaPabellon=ModificaTarifa(Pabellones);
            ActualizaPrecioStand(GuardaEmpresas,NumeroEmpresas,Pabellones,NuevaTarifaPabellon);
        }
        
        if(menu==4){
            MuestraStandYPabellones(GuardaEmpresas,NumeroEmpresas,Pabellones);
        }
        
    }while(menu!=5);
    
}

void RellenaInformacionPabellones(struct pabellon Pabellones[]){
    
    int i;
    
    for(i=0;i<5;i++){
        
        Pabellones[i].MetrosAlquilados=0;
        printf("\nIntroduce el precio por metro cuadrado del pabellon %d: ",i+1);
        fflush(stdout);
        __fpurge(stdin);
        scanf("%d",&Pabellones[i].Tarifa);
        
    }
    
}

int Menu(){
    
    int n;
    
    printf("\nElige opcion: \n1-Añadir Stand\n2-Eliminar Stand\n3-Modificar la tarifa de un pabellon\n4-Visualizar la informacion de los stands y pabellones\n5-Salir\n\n");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&n);
    
    return n;
    
}

struct stand *AddStand(struct stand *GuardaEmpresas,int NumeroEmpresas){
    
    
    
    GuardaEmpresas=ReservaMemoria(GuardaEmpresas,NumeroEmpresas);
    
    printf("\nDesea Añadir un stand.\n\nNombre de la empresa: ");
    fflush(stdout);
    __fpurge(stdin);
    fgets(GuardaEmpresas[NumeroEmpresas-1].Nombre,20,stdin);
    
    printf("\nNumero de pabellon: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&GuardaEmpresas[NumeroEmpresas-1].NumeroPabellon);
    
    printf("\nDias de alquiler: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&GuardaEmpresas[NumeroEmpresas-1].Dias);
    
    printf("\nMetros: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&GuardaEmpresas[NumeroEmpresas-1].Metros);
    
    return GuardaEmpresas;
    
}

struct stand *ReservaMemoria(struct stand *GuardaEmpresas,int NumeroEmpresas){
    
    
    
    GuardaEmpresas=(struct stand *)realloc(GuardaEmpresas,sizeof(struct stand )*NumeroEmpresas);
    
    return GuardaEmpresas;
}

void CalculaPrecioStand(struct stand *GuardaEmpresas,int NumeroEmpresas,struct pabellon Pabellones[]){
    
    int pabellon,precio;
    
    pabellon=GuardaEmpresas[NumeroEmpresas-1].NumeroPabellon;
    
    precio=GuardaEmpresas[NumeroEmpresas-1].Metros*Pabellones[pabellon-1].Tarifa*GuardaEmpresas[NumeroEmpresas-1].Dias;
    
    Pabellones[pabellon-1].MetrosAlquilados=Pabellones[pabellon-1].MetrosAlquilados+GuardaEmpresas[NumeroEmpresas-1].Metros;
    
    GuardaEmpresas[NumeroEmpresas-1].Precio=precio;
}

void MuestraStandYPabellones(struct stand *GuardaEmpresas,int NumeroEmpresas,struct pabellon Pabellones[]){
    
    int i;
    
    for(i=0;i<NumeroEmpresas;i++){
        
        printf("\nEmpresa: %sNumero Pabellon: %d\nDias alquiler: %d\nMetros: %d\nPrecio: %d \n\n",GuardaEmpresas[i].Nombre,GuardaEmpresas[i].NumeroPabellon,GuardaEmpresas[i].Dias,GuardaEmpresas[i].Metros,GuardaEmpresas[i].Precio);
    }
    
    for(i=0;i<5;i++){
        printf("\nPabellon %d:\nMetros Alquilados: %d",i+1,Pabellones[i].MetrosAlquilados);
    }
    
}

void OrdenaAlfabeticamenteEmpresas(struct stand *GuardaEmpresas,int NumeroEmpresas){
    
    int i=NumeroEmpresas-1,metros,precio,pabellon,dias;
    char palabra[20];
    
    if(NumeroEmpresas!=1){
    
        while(strcmp(GuardaEmpresas[i].Nombre,GuardaEmpresas[i-1].Nombre)<0){
           
            strcpy(palabra,GuardaEmpresas[i-1].Nombre);
            metros=GuardaEmpresas[i-1].Metros;
            precio=GuardaEmpresas[i-1].Precio;
            pabellon=GuardaEmpresas[i-1].NumeroPabellon;
            dias=GuardaEmpresas[i-1].Dias;
            
            strcpy(GuardaEmpresas[i-1].Nombre,GuardaEmpresas[i].Nombre);
            GuardaEmpresas[i-1].Metros=GuardaEmpresas[i].Metros;
            GuardaEmpresas[i-1].Precio=GuardaEmpresas[i].Precio;
            GuardaEmpresas[i-1].NumeroPabellon=GuardaEmpresas[i].NumeroPabellon;
            GuardaEmpresas[i-1].Dias=GuardaEmpresas[i].Dias;
            
            strcpy(GuardaEmpresas[i].Nombre,palabra);
            GuardaEmpresas[i].Metros=metros;
            GuardaEmpresas[i].Precio=precio;
            GuardaEmpresas[i].NumeroPabellon=pabellon;
            GuardaEmpresas[i].Dias=dias;
            
            i--;
        
        }
  
    }
   
}

int PosicionEliminaStand(struct stand *GuardaEmpresas,int NumeroEmpresas){
    
    char PalabraAEliminar[20];
    int i,posicion;
    
    printf("\nDesea Eliminar un stand.\n\nNombre de la empresa: ");
    fflush(stdout);
    __fpurge(stdin);
    fgets(PalabraAEliminar,20,stdin);
    
    for(i=0;i<NumeroEmpresas;i++){
        
        if(strcmp(PalabraAEliminar,GuardaEmpresas[i].Nombre)==0){
            posicion=i;
        }
    }
   
    return posicion;
    
    
}

void PoneStandAEliminarUltimaPosicion(struct stand *GuardaEmpresas,int NumeroEmpresas,int posicion){
    
    int i=posicion,metros,precio,pabellon,dias;
    char palabra[20];
    
    while(i<NumeroEmpresas){
        
        
            
            strcpy(palabra,GuardaEmpresas[i+1].Nombre);
            metros=GuardaEmpresas[i+1].Metros;
            precio=GuardaEmpresas[i+1].Precio;
            pabellon=GuardaEmpresas[i+1].NumeroPabellon;
            dias=GuardaEmpresas[i+1].Dias;
            
            strcpy(GuardaEmpresas[i+1].Nombre,GuardaEmpresas[i].Nombre);
            GuardaEmpresas[i+1].Metros=GuardaEmpresas[i].Metros;
            GuardaEmpresas[i+1].Precio=GuardaEmpresas[i].Precio;
            GuardaEmpresas[i+1].NumeroPabellon=GuardaEmpresas[i].NumeroPabellon;
            GuardaEmpresas[i+1].Dias=GuardaEmpresas[i].Dias;
            
            strcpy(GuardaEmpresas[i].Nombre,palabra);
            GuardaEmpresas[i].Metros=metros;
            GuardaEmpresas[i].Precio=precio;
            GuardaEmpresas[i].NumeroPabellon=pabellon;
            GuardaEmpresas[i].Dias=dias;
            
            i++;
        
        }
    
}

void ActualizaMetrosPabellon(struct stand *GuardaEmpresas,int EliminaPosicion,struct pabellon Pabellones[]){
    
    int i=EliminaPosicion,pabellon,metros;
    
    pabellon=GuardaEmpresas[i].NumeroPabellon;
    metros=GuardaEmpresas[i].Metros;
    
    Pabellones[pabellon-1].MetrosAlquilados=Pabellones[pabellon-1].MetrosAlquilados-metros;
    
}


int ModificaTarifa(struct pabellon Pabellones[]){
    
    int pabellon;
    
    printf("\nIntroduce el pabellon que quieres modificar su tarifa: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&pabellon);
    
    printf("Introduce la nueva tarifa del pabellon %d, la actual es %d: ",pabellon,Pabellones[pabellon-1].Tarifa);
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&Pabellones[pabellon-1].Tarifa);
    
    return pabellon;
}

void ActualizaPrecioStand(struct stand *GuardaEmpresas,int NumeroEmpresas,struct pabellon Pabellones[],int PabellonNuevaTarifa){
    
    int precio,i;
    
    for(i=0;i<NumeroEmpresas;i++){
        
        if(GuardaEmpresas[i].NumeroPabellon==PabellonNuevaTarifa){
            
            precio=Pabellones[PabellonNuevaTarifa-1].Tarifa*GuardaEmpresas[i].Dias*GuardaEmpresas[i].Metros;
            
            GuardaEmpresas[i].Precio=precio;
        }
        
    }
    
   
}