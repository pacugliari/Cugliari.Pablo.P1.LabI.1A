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
    printf("S-Salir \n\n");

    scanf("%c",&respuesta);
    fflush(stdin);

    respuesta = toupper(respuesta);

    return respuesta;

}

