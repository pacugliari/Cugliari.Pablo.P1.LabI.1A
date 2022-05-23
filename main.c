#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "empresa.h"
#include "tipo.h"
#include "destino.h"
#include "micro.h"
#include "viaje.h"

#define TAME 4
#define TAMT 4
#define TAMD 4
#define TAMM 20
#define TAMV 20

#define ID_MICRO 10000
#define ID_VIAJE 30000

char menu();
int menuInformes(eViaje viajes[],int tamV,eMicro micros[],int tamM,eDestino destinos[],int tamD,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT);

int main()
{
    char respuesta = 'N';
    int idMicro = ID_MICRO;
    int idViaje = ID_VIAJE;

    eEmpresa empresas [TAME] = {{1000,"Plusmar"},
                            {1001,"Flecha Bus"},
                            {1002,"Tas"},
                            {1003,"El Rapido"}};

    eTipo tipos [TAMT] = {{5000,"Comun"},
                             {5001,"CocheCama"},
                             {5002,"Doble"},
                             {5003,"Vip"}};

    eDestino destinos [TAMD] = {{20000,"Calafate",22250},
                                  {20001,"Bariloche",103000},
                                  {20002,"Iguazu",84400},
                                  {20003,"Mendoza",95600}};


    eMicro micros [TAMM];
    eViaje viajes [TAMV];

    inicializarMicros(micros,TAMM);
    inicializarViajes(viajes,TAMV);

    hardcodearMicros(micros,TAMM,5,&idMicro);
    hardcodearViajes(viajes,TAMV,5,&idViaje);

    do{
        switch(respuesta=menu()){
            case 'A':
                if(altaMicro(micros,TAMM,empresas,TAME,tipos,TAMT,&idMicro)){
                    printf("Alta de micro de manera exitosa \n\n");
                }else
                    printf("No se pudo realizar el alta del micro \n\n");
                break;
            case 'B':
                if(idMicro != ID_MICRO && modificarMicro(micros,TAMM,empresas,TAME,tipos,TAMT)){
                    printf("Se modifico el micro de manera exitosa \n");
                }else
                    printf("No se pudo modificar el micro \n");
                break;
            case 'C':
                if(idMicro != ID_MICRO && bajaMicro (micros,TAMM,empresas,TAME,tipos,TAMT)){
                    printf("Baja de micro de manera exitosa \n\n");
                }else
                    printf("No se pudo realizar la baja del micro \n");
                break;
            case 'D':
                listarMicros(micros,TAMM,empresas,TAME,tipos,TAMT);
                break;
            case 'E':
                listarEmpresas(empresas,TAME);
                break;
            case 'F':
                listarTipos (tipos,TAMT);
                break;
            case 'G':
                listarDestinos (destinos,TAMD);
                break;
            case 'H':
                if(altaViaje(viajes,TAMV,micros,TAMM,destinos,TAMD,empresas,TAME,tipos,TAMT,&idViaje)){
                    printf("Alta de viaje realizada de manera exitosa \n\n");
                }else
                    printf("No se pudo realizar el alta del viaje \n\n");
                break;
            case 'I':
                listarViajes(viajes,TAMV,micros,TAMM,destinos,TAMD,empresas,TAME,tipos,TAMT);
                break;
            case 'L':
                menuInformes(viajes,TAMV,micros,TAMM,destinos,TAMD,empresas,TAME,tipos,TAMT);
                break;
            case 'S':
                respuesta = 'S';
                break;
            default:
                system("cls");
                printf("Opcion de menu incorrecta \n\n");
            break;
        }

        if(idMicro == ID_MICRO && (respuesta == 'B' || respuesta == 'C')){
            printf("Debe ingresar al menos 1 micro para ingresar a esta opcion \n\n");
        }

        system("pause");
        system("cls");
    }while (respuesta != 'S');

    return 0;
}

int menuInformes(eViaje viajes[],int tamV,eMicro micros[],int tamM,eDestino destinos[],int tamD,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT){
    int todoOk = 0;
    char respuesta;
    system("cls");

    if(viajes && micros && destinos && empresas && tipos && tamV> 0 && tamM && tamD >0 && tamE >0 && tamT > 0){
        do{
            printf("0-Mostrar micros de la empresa seleccionada por el usuario\n");
            printf("1-Mostrar micros de un tipo seleccionado.\n");
            printf("2-Informar Promedio de micros de tipo Vip sobre el total de micros de una empresa\n");
            printf("3-Mostrar un listado de los micros separados por empresa.\n");
            printf("4-Informar la o las empresas que pueden transportar mas pasajeros (mayor acumulador de capacidades de sus micros)\n");
            printf("5-Mostrar la empresa con menor cantidad de micros\n");
            printf("6-Pedir un micro y mostrar todos los viajes que hizo el mismo.\n");
            printf("7-Pedir un micro e informar la suma de los precios (costo) de todos los viajes que realizo.\n");
            printf("8-Pedir un destino y mostrar los micros que viajaron a ese destino y en que fecha\n");
            printf("9-Pedir una fecha y mostrar todos los viajes realizados en la misma.\n");
            printf("S-Salir \n\n");
            scanf("%c",&respuesta);
            fflush(stdin);

            respuesta = toupper(respuesta);

            switch(respuesta){
                case '0':
                        mostrarMicrosPorEmpresa(micros,empresas,tipos,tamM,tamE,tamT);
                    break;
                case '1':
                       mostrarMicrosPorTipo(micros,empresas,tipos,tamM,tamE,tamT);
                    break;
                case '2':
                        mostrarPromedioVipPorEmpresa(micros,empresas,tipos,tamM,tamE,tamT);
                    break;
                case '3':
                       mostrarMicrosPorEmpresas(micros,empresas,tipos,tamM,tamE,tamT);
                    break;
                case '4':
                       mostrarEmpresasConMasCapacidad(micros,empresas,tamM,tamE);
                    break;
                case '5':
                        mostrarEmpresaConMenosMicros(micros,empresas,tamM,tamE);
                    break;
                case '6':
                        mostrarViajesPorMicro(viajes,tamV,micros,tamM,destinos,tamD,empresas,tamE,tipos,tamT);
                    break;
                case '7':
                       mostrarImporteViajePorMicro(viajes,tamV,micros,tamM,destinos,tamD,empresas,tamE,tipos,tamT);
                    break;
                case '8':
                       mostrarViajesPorDestino(viajes,tamV,micros,tamM,destinos,tamD,empresas,tamE,tipos,tamT);
                    break;
                case '9':
                        mostrarViajesPorFecha(viajes,tamV,micros,tamM,destinos,tamD,empresas,tamE,tipos,tamT);
                    break;
                case 'S':
                    respuesta = 'S';
                    break;
                default:
                    system("cls");
                    printf("Opcion de menu incorrecta \n\n");
                break;
            }

        system("pause");
        system("cls");
    }while (respuesta != 'S');

        todoOk = 1;
    }

    return todoOk;
}

char menu(){
    char respuesta;

    printf("A-Alta Micro \n");
    printf("B-Modificar Micro \n");
    printf("C-Baja Micro \n");
    printf("D-Listar Micros \n");
    printf("E-Listar Empresas\n");
    printf("F-Listar Tipos \n");
    printf("G-Listar Destinos \n");
    printf("H-Alta Viaje \n");
    printf("I-Listar Viajes \n");
    printf("L-Menu de informes \n");
    printf("S-Salir \n\n");

    scanf("%c",&respuesta);
    fflush(stdin);

    respuesta = toupper(respuesta);

    return respuesta;

}

