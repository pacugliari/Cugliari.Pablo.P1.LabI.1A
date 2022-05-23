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
                          {30002,10002,20002,{13,6,2022},0},
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
                mostrarViaje(viajes[i],micros,tamM,destinos,tamD,empresas,tamE,tipos,tamT);
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
            if(pedirMicro(micros,empresas,tipos,tamM,tamE,tamT,&viajeNuevo.idMicro,&indiceMicro)&&
               pedirDestino(destinos,tamD,&viajeNuevo.idDestino) &&
               pedirFecha(&viajeNuevo.fecha)){
                viajeNuevo.isEmpty = 0;
                viajeNuevo.id = *pId;
                viajes[indice] = viajeNuevo;
                (*pId)++;
                todoOk = 1;
            }else
               printf("Error en el ingreso de datos para el alta de viajes \n");

        }else{
            printf("No hay espacio disponible para el alta de viaje\n");
        }
    }else{
        printf("Error en los parametros del alta de viaje\n");
    }

    return todoOk = 1;
}



int mostrarViajesPorMicro (eViaje viajes[],int tamV,eMicro micros[],int tamM,eDestino destinos[],int tamD,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT){
    int todoOk = 0;
    int idMicro;
    int hayViajes = 0;
    int indiceMicroActual;
    char descripcionEmpresa[20];
    char descripcionTipo [20];
    int indiceDestinoActual;

    if(viajes && micros && destinos && empresas && tipos && tamT> 0&& tamE>0 && tamV >0 && tamM >0 && tamD >0 ){

        listarMicros(micros,tamM,empresas,tamE,tipos,tamT);
        printf("Ingrese el ID del micro \n");
        scanf("%d",&idMicro);
        fflush(stdin);

        while(!validarMicro(micros,tamM,idMicro)){
                printf("Error en la ID del auto.Vuelva a ingresar \n");
                scanf("%d",&idMicro);
                fflush(stdin);
        }

        system("cls");
        printf("\t\t\t\t     ***LISTADO DE VIAJES***\n");
        printf("------------------------------------------------------------------------------------------------------------\n");
        printf("ID\t   Empresa\t  Tipo\t   \tCapacidad\tDestino\t\tPrecio\t\tFecha\n");
        printf("------------------------------------------------------------------------------------------------------------\n");
        for(int i=0;i<tamV;i++){
            if(viajes[i].idMicro == idMicro && !viajes[i].isEmpty){
                mostrarViaje(viajes[i],micros,tamM,destinos,tamD,empresas,tamE,tipos,tamT);
               hayViajes = 1;
            }
        }

        if(!hayViajes){
            listarMicros(micros,tamM,empresas,tamE,tipos,tamT);
            printf("No hay viajes realizados para el micro con ID: %d \n",idMicro);
        }

        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}



int mostrarImporteViajePorMicro (eViaje viajes[],int tamV,eMicro micros[],int tamM,eDestino destinos[],int tamD,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT){
    int todoOk = 0;
    int idMicro;
    int hayViajes = 0;
    float sumaImportes = 0;
    int indiceDestino;
    int indiceMicro;

    if(viajes && micros && destinos && empresas && tipos && tamT> 0&& tamE>0 && tamV >0 && tamM >0 && tamD >0 ){

        listarMicros(micros,tamM,empresas,tamE,tipos,tamT);
        printf("Ingrese el ID del micro \n");
        scanf("%d",&idMicro);
        fflush(stdin);

        while(!validarMicro(micros,tamM,idMicro)){
                printf("Error en la ID del micro.Vuelva a ingresar \n");
                scanf("%d",&idMicro);
                fflush(stdin);
        }

        system("cls");
        for(int i=0;i<tamV;i++){
            if(viajes[i].idMicro == idMicro && !viajes[i].isEmpty){
                buscarDestino(destinos,tamD,viajes[i].idDestino,&indiceDestino);
                sumaImportes += destinos[indiceDestino].precio;
                hayViajes = 1;
            }
        }

        listarMicros(micros,tamM,empresas,tamE,tipos,tamT);

        if(!hayViajes){
            printf("No hay viajes realizados para el micro con ID: %d \n",idMicro);
        }else
            printf("La suma de importes de los viajes realizados para el micro con ID: %d es $%0.2f \n",idMicro,sumaImportes);

        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}



int mostrarViajesPorDestino (eViaje viajes[],int tamV,eMicro micros[],int tamM,eDestino destinos[],int tamD,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT){
    int todoOk = 0;
    int idDestino;
    int hayViajes = 0;
    char descripcionDestino[20];
    int indiceMicroActual;
    char descripcionEmpresa[20];
    char descripcionTipo [20];
    int indiceDestinoActual;

    if(viajes && micros && destinos && empresas && tipos && tamT> 0&& tamE>0 && tamV >0 && tamM >0 && tamD >0  ){
        listarDestinos(destinos,tamD);
        printf("Ingrese el ID del destino \n");
        scanf("%d",&idDestino);
        fflush(stdin);

        while(!validarDestino(destinos,tamD,idDestino)){
            printf("Error en la ID del destino.Vuelva a ingresar \n");
            scanf("%d",&idDestino);
            fflush(stdin);
        }

        system("cls");
        printf("\t\t\t\t     ***LISTADO DE VIAJES***\n");
        printf("------------------------------------------------------------------------------------------------------------\n");
        printf("ID\t   Empresa\t  Tipo\t   \tCapacidad\tDestino\t\tPrecio\t\tFecha\n");
        printf("------------------------------------------------------------------------------------------------------------\n");
        for(int i=0;i<tamV;i++){
            if(viajes[i].idDestino == idDestino){
                mostrarViaje(viajes[i],micros,tamM,destinos,tamD,empresas,tamE,tipos,tamT);
                hayViajes = 1;
            }
        }
        cargarDescripcionDestino(destinos,tamD,idDestino,descripcionDestino);
        if(!hayViajes)
            printf("No hay viajes para el destino de %s \n",descripcionDestino);

        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int mostrarViaje(eViaje viaje,eMicro micros[],int tamM,eDestino destinos[],int tamD,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT){
    int indiceMicroActual;
    char descripcionEmpresa[20];
    char descripcionTipo [20];
    int indiceDestinoActual;
    int todoOk = 0;
    if(empresas && micros && tipos && destinos && tamE >0 && tamM >0 && tamT >0  && tamD >0 ){
        buscarMicro(micros,tamM,viaje.idMicro,&indiceMicroActual);
        cargarDescripcionEmpresa(empresas,tamE,micros[indiceMicroActual].idEmpresa,descripcionEmpresa);
        cargarDescripcionTipo(tipos,tamT,micros[indiceMicroActual].idTipo,descripcionTipo);
        buscarDestino(destinos,tamD,viaje.idDestino,&indiceDestinoActual);
        printf("%d\t   %-10s\t  %-10s\t%d\t\t%-10s\t%0.2f\t%02d/%02d/%02d\n",viaje.id,descripcionEmpresa,descripcionTipo,micros[indiceMicroActual].capacidad,
               destinos[indiceDestinoActual].descripcion,destinos[indiceDestinoActual].precio,viaje.fecha.dia,viaje.fecha.mes,
               viaje.fecha.anio);
        todoOk = 1;
    }
    return todoOk;
}


int mostrarViajesPorFecha (eViaje viajes[],int tamV,eMicro micros[],int tamM,eDestino destinos[],int tamD,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT){
    int todoOk = 0;
    eFecha fecha;
    int hayViajes = 0;

    if(viajes && micros && destinos && empresas && tipos && tamT> 0&& tamE>0 && tamV >0 && tamM >0 && tamD >0  ){
        printf("Ingrese la fecha ej: XX/XX/XXXX: ");
        scanf("%d/%d/%d",&fecha.dia,&fecha.mes,&fecha.anio);
        fflush(stdin);

        while(!validarFecha(fecha)){
            printf("Error en la fecha.Ingrese la fecha ej: XX/XX/XXXX: ");
            scanf("%d/%d/%d",&fecha.dia,&fecha.mes,&fecha.anio);
            fflush(stdin);
        }

        system("cls");
        printf("\t\t\t\t     ***LISTADO DE VIAJES***\n");
        printf("------------------------------------------------------------------------------------------------------------\n");
        printf("ID\t   Empresa\t  Tipo\t   \tCapacidad\tDestino\t\tPrecio\t\tFecha\n");
        printf("------------------------------------------------------------------------------------------------------------\n");
        for(int i=0;i<tamV;i++){
            if(compararFechas(fecha,viajes[i].fecha)){
                mostrarViaje(viajes[i],micros,tamM,destinos,tamD,empresas,tamE,tipos,tamT);
                hayViajes=1;
            }
        }
        if(!hayViajes)
            printf("No hay viajes para la fecha %d/%d/%d \n",fecha.dia,fecha.mes,fecha.anio);
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}
