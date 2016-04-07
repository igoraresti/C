/* 
 * File:   main.c
 * Author: portatil
 *
 * Created on 23 de diciembre de 2012, 20:45
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
/*
 * 
 */
struct Cabecera{
    char I;
    char M;
    char G;
    char Tipo;
    int Anchura;
    int Altura;
};

struct RGBA{
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char A;
};

unsigned char **DescomprimirAMemoria(int *altura,int *anchura);
void MuestraImagen(unsigned char **Imagen,int altura,int anchura);
struct RGBA **GradienteAAzul(unsigned char **Imagen,int altura,int anchura);
void GuardaImagenColor(struct RGBA **ImagenColor,int altura,int anchura);
void LiberaMemoria(unsigned char **Imagen,struct RGBA **ImagenColor,int altura);

int main() {
    
    int altura,anchura;
    unsigned char **Imagen;
    struct RGBA **ImagenColor;
    
    Imagen=DescomprimirAMemoria(&altura,&anchura);
    if(Imagen!=NULL){
    MuestraImagen(Imagen,altura,anchura);
    ImagenColor=GradienteAAzul(Imagen,altura,anchura);
    GuardaImagenColor(ImagenColor,altura,anchura);
    LiberaMemoria(Imagen,ImagenColor,altura);
    }

    return (EXIT_SUCCESS);
}

unsigned char **DescomprimirAMemoria(int *altura,int *anchura){
    
    FILE *fp;
    char nombre[20],name[20];
    struct Cabecera cabeza;
    int i,j,posiciones,cantidad=0;
    unsigned char **Imagen,color;
    printf("\nIntroduce el nombre del fichero: ");
    fflush(stdout);
    __fpurge(stdin);
    fgets(nombre,20,stdin);
    
    //Quita el intro
    strncpy(name,nombre,strlen(nombre)-1);
    
    fp=fopen(name,"rb");
    
    if(fp==NULL){
        printf("\nFichero mal abierto");
        fflush(stdout);
    }
    else{
        
        fread(&cabeza,sizeof(struct Cabecera),1,fp);
        *altura=cabeza.Altura;
        *anchura=cabeza.Anchura;
        fflush(stdout);
        
        if(cabeza.Tipo==1){
            printf("\nFichero en color, no es valido");
            fflush(stdout);
        }
        else{
            Imagen=(unsigned char **)malloc(sizeof(unsigned char *)*cabeza.Altura);
            
            for(i=0;i<cabeza.Altura;i++){
                Imagen[i]=(unsigned char *)malloc(sizeof(unsigned char)*cabeza.Anchura);
            }
            i=0;
            j=0;
            do{
                        fread(&color,sizeof(unsigned char),1,fp);
                        fread(&posiciones,sizeof(int),1,fp);
                        cantidad=cantidad+posiciones;
                        
                        fflush(stdout);
                        if(posiciones!=0){
                        do{
                        Imagen[i][j]=color;
                        j++;
                        if(j==cabeza.Anchura){
                            j=0;
                            i++;
                        }
                         posiciones--;
                        
                        }while(posiciones>0);}
            }while(!feof(fp));
                        
                        
           
        }
        
    }
    
    fclose(fp);
    
    return Imagen;
    
}

void MuestraImagen(unsigned char **Imagen,int altura,int anchura){
    
    int i,j;
    
    for(i=0;i<altura;i++){
        printf("\n");
        for(j=0;j<anchura;j++){
            
            if(Imagen[i][j]==0){
                printf(" ");
            }
            if(Imagen[i][j]==255){
                printf("*");
            }
        }
    }
    
}

struct RGBA **GradienteAAzul(unsigned char **Imagen,int altura,int anchura){
    
    int i,j;
    struct RGBA **ImagenColor;
    
    ImagenColor=(struct RGBA **)malloc(sizeof(struct RGBA *)*altura);
    
    for(i=0;i<altura;i++){
        ImagenColor[i]=(struct RGBA *)malloc(sizeof(struct RGBA )*anchura);
    }
    
    for(i=0;i<altura;i++){
        for(j=0;j<anchura;j++){
            
            if(Imagen[i][j]==0){
                ImagenColor[i][j].R=0;
                ImagenColor[i][j].G=0;
                ImagenColor[i][j].B=0;
                ImagenColor[i][j].A=0;
            }
            if(Imagen[i][j]==255){
                ImagenColor[i][j].R=0;
                ImagenColor[i][j].G=0;
                ImagenColor[i][j].B=0;
                ImagenColor[i][j].A=i;
            }
        }
    }
    
    return ImagenColor;
}

void GuardaImagenColor(struct RGBA **ImagenColor,int altura,int anchura){
    
    char nombre[20],name[20];
    int i,j;
    FILE *f;
    
    printf("\nIntroduce el nombre del fichero para guardar la imagen a color: ");
    fflush(stdout);
    __fpurge(stdin);
    fgets(nombre,20,stdin);
    
    //Quita el intro
    strncpy(name,nombre,strlen(nombre)-1);
    
    f=fopen(name,"wb");
    
    if(f==NULL){
        printf("\nError al abrir el fichero %s",name);
        fflush(stdout);
    }
    
    else{
        
        for(i=0;i<altura;i++){
            for(j=0;j<anchura;j++){
                
                fwrite(&ImagenColor[i][j],sizeof(struct RGBA),1,f);
                
            }
        }
        
    }
    
    fclose(f);
}

void LiberaMemoria(unsigned char **Imagen,struct RGBA **ImagenColor,int altura){
    
    int i;
    
    for(i=0;i<altura;i++){
        free(Imagen[i]);
        free(ImagenColor[i]);
    }
    
    free(Imagen);
    free(ImagenColor);
    
}
