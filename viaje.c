#include "viaje.h"
#include <stdio.h>
#include <stdlib.h>

int inicializarViajes (eViaje viajes[],int tamV){
    int todoOk = 0;
    if(viajes && tamV >0){
        for(int i=0;i<tamV;i++){
            viajes[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;

}


int hardcodearViajes (eViaje viajes[],int tamV,int cantidad,int* pId){
    int todoOk = 0;
    eViaje viajesHard [] = {{30000,10000,20000,{11,5,2022},0},
                          {30001,10001,20001,{13,6,2022},0},
                          {30002,10002,20002,{24,1,2022},0},
                          {30003,10003,20003,{17,2,2022},0},
                          {30004,10004,20000,{16,5,2022},0},};

    if (viajes && tamV && pId && cantidad > 0 && cantidad <= tamV){
        for(int i=0;i<cantidad;i++){
            viajes[i] = viajesHard[i];
            viajes[i].id = (*pId);
            (*pId)++;
        }
        todoOk = 1;
    }
    return todoOk;
}


int listarViajes (eViaje viajes[],int tamV,eMicro micros[],int tamM,eDestino destinos[],int tamD,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT){
    int todoOk = 0;
    int hayViajes = 0;
    char descripcionEmpresa[20];
    char descripcionTipo [20];
    int indiceMicroActual;
    int indiceDestinoActual;

    if(viajes && micros && destinos && empresas && tipos && tamT> 0&& tamE>0 && tamV >0 && tamM >0 && tamD >0 ){
        system("cls");
        printf("\t\t\t\t     ***LISTADO DE VIAJES***\n");
        printf("------------------------------------------------------------------------------------------------------------\n");
        printf("ID\t   Empresa\t  Tipo\t   \tCapacidad\tDestino\t\tPrecio\t\tFecha\n");
        printf("------------------------------------------------------------------------------------------------------------\n");
        for(int i=0;i<tamV;i++){
            buscarMicro(micros,tamM,viajes[i].idMicro,&indiceMicroActual);
            if(!viajes[i].isEmpty && !micros[indiceMicroActual].isEmpty){
                cargarDescripcionEmpresa(empresas,tamE,micros[indiceMicroActual].idEmpresa,descripcionEmpresa);
                cargarDescripcionTipo(tipos,tamT,micros[indiceMicroActual].idTipo,descripcionTipo);
                buscarDestino(destinos,tamD,viajes[i].idDestino,&indiceDestinoActual);
                printf("%d\t   %-10s\t  %-10s\t%d\t\t%-10s\t%0.2f\t%02d/%02d/%02d\n",viajes[i].id,descripcionEmpresa,descripcionTipo,micros[indiceMicroActual].capacidad,
                       destinos[indiceDestinoActual].descripcion,destinos[indiceDestinoActual].precio,viajes[i].fecha.dia,viajes[i].fecha.mes,
                       viajes[i].fecha.anio);
                hayViajes = 1;
            }

        }
        if(!hayViajes){
            printf("\t     No hay viajes cargados \n");
        }
        printf("------------------------------------------------------------------------------------------------------------\n\n");
        todoOk= 1;
    }
    return todoOk;
}


int buscarViajeLibre (eViaje viajes[],int tamV,int* pIndice){
    int todoOk = 0;
    if(viajes && tamV && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamV;i++){
            if(viajes[i].isEmpty){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int altaViaje (eViaje viajes[],int tamV,eMicro micros[],int tamM,eDestino destinos[],int tamD,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT,int* pId){
    int todoOk = 0;
    int indice;
    int indiceMicro;
    eViaje viajeNuevo;


    if(viajes && micros && destinos && empresas && tipos && tamT> 0&& tamE>0 && tamV >0 && tamM >0 && tamD >0 && pId){
        buscarViajeLibre (viajes,tamV,&indice);
        if(indice != -1){
            //INGRESO DE DATOS
            listarMicros (micros,tamM,empresas,tamE,tipos,tamT);
            printf("Ingrese el ID del micro \n");
            scanf("%d",&viajeNuevo.idMicro);
            fflush(stdin);

            buscarMicro(micros,tamM,viajeNuevo.idMicro,&indiceMicro);

            while(indiceMicro == -1){
                printf("No exite el micro con la ID: %d \n",viajeNuevo.idMicro);
                printf("Ingrese el ID del micro \n");
                scanf("%d",&viajeNuevo.idMicro);
                fflush(stdin);

                buscarMicro(micros,tamM,viajeNuevo.idMicro,&indiceMicro);
            }

            viajeNuevo.idMicro = micros[indiceMicro].id;

            listarDestinos(destinos,tamD);
            printf("Ingrese el ID del destino \n");
            scanf("%d",&viajeNuevo.idDestino);
            fflush(stdin);

            while(!validarDestino(destinos,tamD,viajeNuevo.idDestino)){
                printf("Error en la ID del destino.Vuelva a ingresar \n");
                scanf("%d",&viajeNuevo.idDestino);
                fflush(stdin);
            }

            printf("Ingrese la fecha ej: XX/XX/XXXX: ");
            scanf("%d/%d/%d",&viajeNuevo.fecha.dia,&viajeNuevo.fecha.mes,&viajeNuevo.fecha.anio);
            fflush(stdin);

            while(!validarFecha(viajeNuevo.fecha)){
                printf("Error en la fecha.Ingrese la fecha ej: XX/XX/XXXX: ");
                scanf("%d/%d/%d",&viajeNuevo.fecha.dia,&viajeNuevo.fecha.mes,&viajeNuevo.fecha.anio);
                fflush(stdin);
            }

            viajeNuevo.isEmpty = 0;
            viajeNuevo.id = *pId;
            viajes[indice] = viajeNuevo;
            (*pId)++;
            todoOk = 1;

        }else{
            printf("No hay espacio disponible para el alta de viaje\n");
        }
    }else{
        printf("Error en los parametros del alta de viaje\n");
    }

    return todoOk = 1;
}
