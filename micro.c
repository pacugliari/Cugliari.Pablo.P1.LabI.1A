#include "micro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int inicializarMicros (eMicro micros[],int tamM){
    int todoOk = 0;
    if(micros && tamM >0){
        for(int i=0;i<tamM;i++){
            micros[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;

}

int hardcodearMicros (eMicro micros[],int tamM,int cantidad,int* pId){
    int todoOk = 0;
    eMicro microsHard [] = {{10000,1001,5000,10,0},
                          {10001,1002,5001,20,0},
                          {10002,1003,5002,30,0},
                          {10003,1001,5003,40,0},
                          {10004,1000,5000,50,0},};

    if (micros && tamM && pId && cantidad > 0 && cantidad <= tamM){
        for(int i=0;i<cantidad;i++){
            micros[i] = microsHard[i];
            micros[i].id = (*pId);
            (*pId)++;
        }
        todoOk = 1;
    }
    return todoOk;
}

int ordenarMicrosPorEmpresaYCapacidad (eMicro micros[],int tamM,eEmpresa empresas[],int tamE){
    int todoOk = 0;
    char descripcionEmpresaActual[20];
    char descripcionEmpresaSiguiente[20];
    eMicro microAux;

    if(micros && empresas && tamM >0 && tamE > 0){
        for(int i=0;i<tamM-1;i++){
            for(int j=i+1;j<tamM;j++){
                if(!micros[i].isEmpty){
                    cargarDescripcionEmpresa(empresas,tamE,micros[i].idEmpresa,descripcionEmpresaActual);
                    cargarDescripcionEmpresa(empresas,tamE,micros[j].idEmpresa,descripcionEmpresaSiguiente);
                    if((strcmp(descripcionEmpresaActual,descripcionEmpresaSiguiente) > 0)  ||
                        ((strcmp(descripcionEmpresaActual,descripcionEmpresaSiguiente) == 0) && micros[i].capacidad > micros[j].capacidad)){
                        microAux = micros[i];
                        micros[i] = micros[j];
                        micros[j] = microAux;
                    }
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}



int listarMicros (eMicro micros[],int tamM,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT){
    int todoOk = 0;
    int hayMicros = 0;

    if(micros && empresas && tipos && tamM >0 && tamE >0 && tamT >0 ){
        eMicro microsAux [tamM];
        for(int i=0;i<tamM;i++){
            microsAux[i] = micros[i];
        }
        ordenarMicrosPorEmpresaYCapacidad (microsAux,tamM,empresas,tamE);
        system("cls");
        printf("\t     ***LISTADO DE MICROS***\n");
        printf("-------------------------------------------------------\n");
        printf("ID\t   Empresa\t  Tipo\t   \tCapacidad\n");
        printf("-------------------------------------------------------\n");
        for(int i=0;i<tamM;i++){
            if(!microsAux[i].isEmpty){
                mostrarMicro(microsAux[i],empresas,tamE,tipos,tamT);
                hayMicros = 1;
            }

        }
        if(!hayMicros){
            printf("\t     No hay micros cargados \n");
        }
        printf("-------------------------------------------------------\n\n");
        todoOk= 1;
    }
    return todoOk;
}


int mostrarMicro (eMicro microI,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT){
    int todoOk = 0;
    char descripcionEmpresa [20];
    char descripcionTipo [20];

    if(empresas && tipos && tamE >0 && tamT >0){
        cargarDescripcionEmpresa (empresas,tamE,microI.idEmpresa,descripcionEmpresa);
        cargarDescripcionTipo (tipos,tamT,microI.idTipo,descripcionTipo);

        printf("%d\t   %-10s\t  %-10s\t%d\n",microI.id,descripcionEmpresa,descripcionTipo,microI.capacidad);
        todoOk = 1;
    }
    return todoOk;
}


int buscarMicroLibre (eMicro micros[],int tamM,int* pIndice){
    int todoOk = 0;
    if(micros && tamM && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamM;i++){
            if(micros[i].isEmpty){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int altaMicro (eMicro micros[],int tamM,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT,int* pId){
    int todoOk = 0;
    int indice;
    eMicro microNuevo;

    if(micros && empresas && tipos && tamM >0 && tamE >0 && tamT >0 && pId){
        buscarMicroLibre (micros,tamM,&indice);
        if(indice != -1){
            //INGRESO DE DATOS
            listarEmpresas(empresas,tamE);
            printf("Ingrese el ID de la empresa \n");
            scanf("%d",&microNuevo.idEmpresa);
            fflush(stdin);

            while(!validarEmpresa(empresas,tamE,microNuevo.idEmpresa)){
                printf("Error en la ID de la empresa.Vuelva a ingresar \n");
                scanf("%d",&microNuevo.idEmpresa);
                fflush(stdin);
            }

            listarTipos(tipos,tamT);
            printf("Ingrese el ID del tipo \n");
            scanf("%d",&microNuevo.idTipo);
            fflush(stdin);

            while(!validarTipo(tipos,tamT,microNuevo.idTipo)){
                printf("Error en la ID del color.Vuelva a ingresar \n");
                scanf("%d",&microNuevo.idTipo);
                fflush(stdin);
            }

            system("cls");

            printf("Ingrese la capacidad del micro,numero entre 1 y 50 \n");
            scanf("%d",&microNuevo.capacidad);
            fflush(stdin);

            while(microNuevo.capacidad < 1 || microNuevo.capacidad > 50){
                printf("Error en la capacidad del micro.Vuelva a ingresar \n");
                scanf("%d",&microNuevo.capacidad);
                fflush(stdin);
            }

            system("cls");

            microNuevo.isEmpty = 0;
            microNuevo.id = *pId;
            micros[indice] = microNuevo;
            (*pId)++;
            todoOk = 1;
        }else{
            printf("No hay espacio disponible para el alta de micros\n");
        }
    }else{
        printf("Error en los parametros del alta de micros\n");
    }

    return todoOk = 1;
}

char menuModificar (){
    char respuesta;

    printf("\n1) Capacidad \n");
    printf("2) Tipo \n");
    printf("S) Salir \n");
    scanf("%c",&respuesta);
    fflush(stdin);

    respuesta = toupper(respuesta);

    return respuesta;
}


int buscarMicro (eMicro micros[],int tamM,int id,int* pIndice){
    int todoOk = 0;
    if(micros && tamM >0 && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamM;i++){
            if(micros[i].id == id && !micros[i].isEmpty){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}



int modificarMicro (eMicro micros[],int tamM,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT){
    int todoOk = 0;
    int indice;
    int idIngresado;
    char respuestaModificar='n';

    if(micros && empresas && tipos && tamM >0 && tamE >0 && tamT >0 ){
        listarMicros(micros,tamM,empresas,tamE,tipos,tamT);
        printf("Ingrese el ID del micro a modificar ");
        scanf("%d",&idIngresado);
        fflush(stdin);

        if(buscarMicro (micros,tamM,idIngresado,&indice)){
            if(indice != -1){
                printf("-------------------------------------------------------\n");
                printf("ID\t   Empresa\t  Tipo\t   \tCapacidad\n");
                printf("-------------------------------------------------------\n");
                mostrarMicro(micros[indice],empresas,tamE,tipos,tamT);

                do{
                    switch(menuModificar()){
                        case '1':
                            printf("Ingrese la capacidad del micro,numero entre 1 y 50 \n");
                            scanf("%d",&micros[indice].capacidad);
                            fflush(stdin);

                            while(micros[indice].capacidad < 1 || micros[indice].capacidad > 50){
                                printf("Error en la capacidad del micro.Vuelva a ingresar \n");
                                scanf("%d",&micros[indice].capacidad);
                                fflush(stdin);
                            }
                            printf("Capacidad modificada de manera exitosa \n");
                            break;
                        case '2':
                            listarTipos(tipos,tamT);
                            printf("Ingrese el ID del tipo \n");
                            scanf("%d",&micros[indice].idTipo);
                            fflush(stdin);

                            while(!validarTipo(tipos,tamT,micros[indice].idTipo)){
                                printf("Error en la ID del tipo.Vuelva a ingresar \n");
                                scanf("%d",&micros[indice].idTipo);
                                fflush(stdin);
                            }
                            printf("Tipo modificado de manera exitosa \n");
                            break;
                        case 'S':
                            respuestaModificar = 'S';
                        break;
                    }

                }while(respuestaModificar != 'S');
                todoOk = 1;

            }else
                printf("\nNo exite el micro con el id: %d \n",idIngresado);
        }else{
            printf("\nProblema al buscar el micro \n");
        }

    }else{
        printf("\nError en los parametros de la baja del micro \n");
    }

    return todoOk;
}


int bajaMicro (eMicro micros[],int tamM,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT){
    int todoOk = 0;
    int indice;
    int idIngresado;
    char respuestaBorrado='n';

    if(micros && empresas && tipos && tamE >0 && tamM >0 && tamT >0 ){
        listarMicros(micros,tamM,empresas,tamE,tipos,tamT);
        printf("Ingrese la ID a dar de baja: ");
        scanf("%d",&idIngresado);
        fflush(stdin);
        if(buscarMicro(micros,tamM,idIngresado,&indice)){
            if(indice != -1){
                printf("-------------------------------------------------------\n");
                printf("ID\t   Empresa\t  Tipo\t   \tCapacidad\n");
                printf("-------------------------------------------------------\n");
                mostrarMicro(micros[indice],empresas,tamE,tipos,tamT);
                printf("\nConfirma baja? s-SI \n");
                scanf("%c",&respuestaBorrado);
                fflush(stdin);
                respuestaBorrado = tolower(respuestaBorrado);

                if(respuestaBorrado == 's'){
                    micros[indice].isEmpty = 1;
                    todoOk = 1;
                }else{
                    printf("\nBaja cancelada \n");
                }

            }else
                printf("\nNo exite el micro con el id: %d \n",idIngresado);
        }else{
            printf("\nProblema al buscar el micro \n");
        }

    }else{
        printf("\nError en los parametros de la baja \n");
    }

    return todoOk;
}
