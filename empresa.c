#include "empresa.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"


int listarEmpresas (eEmpresa empresas[],int tamE){
    int todoOk = 0;

    if(empresas && tamE>0){
        system("cls");
        printf("  ***LISTADO DE EMPRESAS***\n");
        printf("-------------------------------\n");
        printf("ID\tEmpresa\n");
        printf("-------------------------------\n");
        for(int i=0;i<tamE;i++){
            printf("%d\t%-10s\n",empresas[i].id,empresas[i].descripcion);
        }
        printf("-------------------------------\n\n");
        todoOk= 1;
    }

    return todoOk;
}

int buscarEmpresa (eEmpresa empresas[],int tamE,int id,int* pIndice){
    int todoOk = 0;
    if(empresas && tamE >0 && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamE;i++){
            if(empresas[i].id == id){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int cargarDescripcionEmpresa (eEmpresa empresas[],int tamE,int id,char descripcion[]){
    int todoOk = 0;
    int indice;
    if(empresas && tamE >0 && descripcion && buscarEmpresa(empresas,tamE,id,&indice)){
        strcpy(descripcion,empresas[indice].descripcion);
        todoOk = 1;
    }
    return todoOk;
}


int validarEmpresa (eEmpresa empresas[],int tamE,int id){
    int todoOk = 0;
    int indice;
    if(empresas && tamE > 0){
        buscarEmpresa(empresas,tamE,id,&indice);
        if(indice != -1)
            todoOk = 1;
    }
    return todoOk;
}


int pedirEmpresa(eEmpresa empresas[],int tamE,int* idEmpresa){
    int todoOk = 0;
    if(empresas && tamE > 0 && idEmpresa){
        listarEmpresas(empresas,tamE);
        printf("Ingrese el ID de la empresa \n");
        scanf("%d",idEmpresa);
        fflush(stdin);

        while(!validarEmpresa(empresas,tamE,*idEmpresa)){
            printf("Error en la ID de la empresa.Vuelva a ingresar \n");
            scanf("%d",idEmpresa);
            fflush(stdin);
        }

       todoOk = 1;
    }
    return todoOk ;
}


