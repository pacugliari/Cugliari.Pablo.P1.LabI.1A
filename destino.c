#include "destino.h"
#include "stdlib.h"
#include "stdio.h"
#include <string.h>


int listarDestinos (eDestino destinos[],int tamD){
    int todoOk = 0;

    if(destinos && tamD>0){
        system("cls");
        printf("  ***LISTADO DE DESTINOS***\n");
        printf("-------------------------------\n");
        printf("ID\tDestino\t\tPrecio\n");
        printf("-------------------------------\n");
        for(int i=0;i<tamD;i++){
            printf("%d\t%-10s\t$%0.2f\n",destinos[i].id,destinos[i].descripcion,destinos[i].precio);
        }
        printf("-------------------------------\n\n");
        todoOk= 1;
    }

    return todoOk;
}


int buscarDestino (eDestino destinos[],int tamD,int id,int* pIndice){
    int todoOk = 0;
    if(destinos && tamD >0 && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamD;i++){
            if(destinos[i].id == id ){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int validarDestino (eDestino destinos[],int tamD,int id){
    int todoOk = 0;
    int indice;
    if(destinos && tamD > 0){
        buscarDestino (destinos,tamD,id,&indice);
        if(indice != -1)
            todoOk = 1;
    }
    return todoOk;
}


int pedirDestino(eDestino destinos[],int tamD,int* idDestino){
    int todoOk=0;
    if(destinos && tamD >0 && idDestino){
        listarDestinos(destinos,tamD);
        printf("Ingrese el ID del destino \n");
        scanf("%d",idDestino);
        fflush(stdin);

        while(!validarDestino(destinos,tamD,*idDestino)){
            printf("Error en la ID del destino.Vuelva a ingresar \n");
            scanf("%d",idDestino);
            fflush(stdin);
        }
        todoOk = 1;
    }
    return todoOk;

}


int cargarDescripcionDestino (eDestino destinos[],int tamD,int id,char descripcion[]){
    int todoOk = 0;
    int indice;
    if(destinos && tamD >0 && descripcion && buscarDestino(destinos,tamD,id,&indice)){
        strcpy(descripcion,destinos[indice].descripcion);
        todoOk = 1;
    }
    return todoOk;
}
