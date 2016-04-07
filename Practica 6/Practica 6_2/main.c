/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 15 de noviembre de 2012, 17:58
 */

#include <stdio_ext.h>
#include <stdlib.h>

/*
 * 
 */
void EligeDimensiones(int *filas,int *columnas);
void RellenaMatriz(int filas,int columnas,int **matriz);
void CreaMapa(int filas,int columnas, int **matriz,char **mapa);
int **ReservaMemoria(int filas,int columnas);
void LiberaMemoria(int filas,int columnas,int **matriz,char **mapa);
char **ReservaMemoriaMapa(int filas,int columnas);
void MuestraMapa(int filas,int columnas,char **mapa);

void main(){
    
    int filas,columnas,**matriz;
    char **mapa;
    
    EligeDimensiones(&filas,&columnas);
    
    //Crea matriz
    matriz=ReservaMemoria(filas,columnas);
    mapa=ReservaMemoriaMapa(filas,columnas);
    
    
    //Matriz creada ahora se rellena
   
    RellenaMatriz(filas,columnas,matriz);
    
    CreaMapa(filas,columnas,matriz,mapa);
    
    MuestraMapa(filas,columnas,mapa);
    
    LiberaMemoria(filas,columnas,matriz,mapa);
    
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
        do{
      printf("Introduce el elemento fila %d columna %d: ", i+1, j+1);
      fflush(stdout);
      __fpurge(stdin);
      scanf("%d",&n);
      
      
    }while(n>20);
    matriz[i][j]=n;
    }
    
    
}

void CreaMapa(int filas,int columnas, int **matriz,char **mapa){
    
    int i,j;
    float cantidad;
    
    for(i=0;i<filas;i++)
        for(j=0;j<columnas;j++)
            mapa[i][j]='.';
    
    
    
    for(i=1;i<filas-1;i++){
        printf("\n");
        for(j=1;j<columnas-1;j++){
            
            
            cantidad=(matriz[i][j]+matriz[i-1][j-1]+matriz[i-1][j]+matriz[i-1][j+1]+matriz[i][j-1]+matriz[i][j+1]+matriz[i+1][j-1]+matriz[i][j+1]+matriz[i+1][j+1])/9;
            if(cantidad>6){
                mapa[i][j]='*';
            }
            
                
            
        }
    }
    
    
    
}

int **ReservaMemoria(int filas,int columnas){
    
    int i,**matriz;
    
    matriz=(int **)malloc(filas*sizeof(int*));
    
    for(i=0; i<filas; i++)
        matriz[i] = (int*)malloc(sizeof(int*)*columnas);
    
    return matriz;
    
}

void LiberaMemoria(int filas,int columnas,int **matriz,char **mapa){
    
    int i;
    
    for(i=0;i<filas;i++)
    {
        free(matriz[i]);
        free(mapa[i]);
    }
    
    free(mapa);
    free(matriz);
}

char **ReservaMemoriaMapa(int filas,int columnas){
    
    int i;
    char **matriz;
    
    matriz=(char **)malloc(filas*sizeof(char*));
    
    for(i=0;i<columnas;i++)
        matriz[i]=(char*)malloc(columnas*sizeof(char*));
    
    return matriz;
}

void MuestraMapa(int filas,int columnas,char **mapa){
    
    int i,j;
    
    for(i=0;i<filas;i++){
        printf("\n");
        for(j=0;j<columnas;j++)
            printf(" %c ",mapa[i][j]);
    }
    
    
}