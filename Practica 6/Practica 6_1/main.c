/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 15 de noviembre de 2012, 10:16
 */

#include <stdio_ext.h>
#include <stdlib.h>

/*
 * 
 */
void EligeDimensiones(int *,int *);
void RellenaMatriz(int filas,int columnas,int **matriz);
void PrintaMatriz(int filas, int columnas, int **matriz);
int BuscaPosicionMenorDeFila(int fila,int columna,int **matriz,int Nfila);
int BuscaPosicionMayorDeColumna(int fila,int columna,int **matriz,int POSFilaMenor);
int BuscaPosicionMayorDeFila(int fila,int columna,int **matriz,int Nfila);
int BuscaPosicionMenorDeColumna(int fila,int columna,int **matriz,int POSFilaMayor);
void PuntoDeSillaFilaMenorColumnaMayor(int filas,int columnas,int **matriz);
void PuntoDeSillaFilaMayorColumnaMenor(int filas,int columnas,int **matriz);
int **ReservaMemoria(int filas,int columnas);
void LiberaMemoria(int filas,int columnas,int **matriz);

void main(){
    
    int filas,columnas,**matriz,i;
    
    EligeDimensiones(&filas,&columnas);
    
    //Crea matriz
    matriz=ReservaMemoria(filas,columnas);
    
    //Matriz creada ahora se rellena
   
    RellenaMatriz(filas,columnas,matriz);
    
    //La Printamos
    PrintaMatriz(filas,columnas,matriz);
    
    
    //Buscamos punto de silla
    
    //Primero buscamos punto de silla que se menor de la fila y mayor de columna
    PuntoDeSillaFilaMenorColumnaMayor(filas,columnas,matriz);
    
    //Ahora buscamos punto de silla mayor de la fila menor de la columna
    PuntoDeSillaFilaMayorColumnaMenor(filas,columnas,matriz);
    
    //Liberamos memoria de la matriz
    
    LiberaMemoria(filas,columnas,matriz);
    
   
}

void EligeDimensiones(int *filas,int *columnas){
    
    printf("Introduce las dimensiones de la matriz: \nFilas: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",filas);
    
    printf("\nColumnas: ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",columnas);
    
 }

void RellenaMatriz(int filas,int columnas,int **matriz){
    
    int i,j,n;
    
    for(i=0; i<filas; i++)
    for(j=0; j<columnas; j++){
      printf("Introduce el elemento fila %d columna %d: ", i+1, j+1);
      fflush(stdout);
      __fpurge(stdin);
      scanf("%d",&n);
      matriz[i][j]=n;
      
    }
    
    
}

void PrintaMatriz(int filas, int columnas, int **matriz){
    
    int i,j;
    
    for(i=0; i<filas; i++){
        printf("\n");
        for(j=0; j<columnas; j++)
        printf(" %d ",matriz[i][j]);
    }
    
}

int BuscaPosicionMenorDeFila(int fila,int columna,int **matriz,int Nfila){
    
    int i,numero,posicion;
    
    numero=matriz[Nfila][0];
    posicion=0;
    for(i=0;i<columna;i++){
       
        if(matriz[Nfila][i]<numero)
        {
            posicion=i;
        }
        
        
    }
    
    
    
    return posicion;
}

int BuscaPosicionMayorDeColumna(int fila,int columna,int **matriz,int POSFilaMenor){
    
    int i,numero,posicion;
    
    numero=matriz[0][POSFilaMenor];
    posicion=0;
    
    for(i=0;i<fila;i++){
        
        if(matriz[i][POSFilaMenor]>numero)
        {
            posicion=i;
        }
        
    }
    
    
    
    return posicion;
}

int BuscaPosicionMayorDeFila(int fila,int columna,int **matriz,int Nfila){
    
    int i,numero,posicion;
    
    numero=matriz[Nfila][0];
    posicion=0;
    for(i=0;i<columna;i++){
       
        if(matriz[Nfila][i]>numero)
        {
            posicion=i;
        }
        
        
    }
    
    
    return posicion;
}

int BuscaPosicionMenorDeColumna(int fila,int columna,int **matriz,int POSFilaMayor){
    
    int i,numero,posicion;
    
    numero=matriz[0][POSFilaMayor];
    posicion=0;
    
    for(i=0;i<fila;i++){
        
        if(matriz[i][POSFilaMayor]<numero)
        {
            posicion=i;
        }
        
    }
    
    
    return posicion;
}

void PuntoDeSillaFilaMenorColumnaMayor(int filas,int columnas,int **matriz){
    
    int i,POSFilaMenor,POSColumnaMayor;
    
    for(i=0; i<filas; i++){
        
        POSFilaMenor=BuscaPosicionMenorDeFila(filas,columnas,matriz,i);
        
        POSColumnaMayor=BuscaPosicionMayorDeColumna(filas,columnas,matriz,POSFilaMenor);
        
        
        //Si la posicion que devuelve la funcion coincide con la fila que estamos, es punto de silla
        if(i==POSColumnaMayor){
            printf("\nPunto de silla el numero %d en la posicion fila:%d columna:%d",matriz[POSColumnaMayor][POSFilaMenor],POSColumnaMayor+1,POSFilaMenor+1);
            
        }
    }
    
}

void PuntoDeSillaFilaMayorColumnaMenor(int filas,int columnas,int **matriz){
    
    int i,POSFilaMayor,POSColumnaMenor;
    
    for(i=0;i<filas;i++){
        
        POSFilaMayor=BuscaPosicionMayorDeFila(filas,columnas,matriz,i);
        
        POSColumnaMenor=BuscaPosicionMenorDeColumna(filas,columnas,matriz,POSFilaMayor);
        
        if(i==POSColumnaMenor)
           printf("\nPunto de silla el numero %d en la posicion fila:%d columna:%d",matriz[POSColumnaMenor][POSFilaMayor],POSColumnaMenor+1,POSFilaMayor+1); 
    }
    
    
}

int **ReservaMemoria(int filas,int columnas){
    int i,**matriz;
    
    matriz=(int **)malloc(filas*sizeof(int*));
    
    for(i=0; i<filas; i++)
    matriz[i] = (int*)malloc(sizeof(int)*columnas);
    
    return matriz;
    
}

void LiberaMemoria(int filas,int columnas,int **matriz){
    
    int i;
    
    for(i=0;i<filas;i++)
        free(matriz[i]);
    
    free(matriz);
}
