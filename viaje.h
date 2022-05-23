#include "fecha.h"
#include "micro.h"
#include "destino.h"

#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

typedef struct{
    int id;
    int idMicro;
    int idDestino;
    eFecha fecha;
    int isEmpty;
}eViaje;

#endif // VIAJE_H_INCLUDED

//INICIALIZAR
/** \brief completa todo el vector de viajes el campo isEmpty en 1
 *
 * \param eViaje viajes[], vector de viajes
 * \param int tamV, tamanio del vector de viajes
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */

int inicializarViajes (eViaje viajes[],int tamV);

/** \brief carga elementos de prueba con datos falsos en el vector de viajes para hacer pruebas en el codigo
 *
 * \param eViaje viajes[],vector de viajes
 * \param int tamV,tamanio del vector de viajes
 * \param int cantidad, cantidad de elementos de prueba que se quieren cargar en el vector de viajes
 * \param int* pId,puntero al contador que lleva el control de la id de viajes
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int hardcodearViajes (eViaje viajes[],int tamV,int cantidad,int* pId);

//ABM

/** \brief realiza un alta de un dato eViaje en el vector de viajes pidiendo y mostrando los datos necesarios al usuario con sus respectivas validaciones
 *
 * \param eViaje viajes[],vector de viajes
 * \param int tamV, tamanio del vector de viajes
 * \param eMicro micros[],vector de micros
 * \param int tamM, tamanio del vector de micros
 * \param eDestino destinos[],vector de destinos
 * \param int tamD, tamanio del vector de destinos
 * \param eEmpresa empresas[],vector de empresas
 * \param int tamE, tamanio del vector de empresas
 * \param eTipo tipos[],vector de tipos
 * \param int tamT, tamanio del vector de tipos
 * \param int* pId,puntero al contador que lleva el control de la id de viajes
 * \return si los parametros, los datos ingresados por el usuario y hay lugar para el alta son correctos retorna 1 , si se genera un error en lo anterior  retorna 0
 *
 */
int altaViaje (eViaje viajes[],int tamV,eMicro micros[],int tamM,eDestino destinos[],int tamD,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT,int* pId);

//LISTADO

/** \brief genera una lista de los viajes mostrando ID,empresa,tipo,capacidad,destino,precio y fecha
 *
 * \param eViaje viajes[],vector de viajes
 * \param int tamE, tamanio del vector de empresas
 * \param eMicro micros[],vector de micros
 * \param int tamM, tamanio del vector de micros
 * \param eDestino destinos[],vector de destinos
 * \param int tamD, tamanio del vector de destinos
 * \param eEmpresa empresas[],vector de empresas
 * \param int tamE, tamanio del vector de empresas
 * \param eTipo tipos[],vector de tipos
 * \param int tamT, tamanio del vector de tipos
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int listarViajes (eViaje viajes[],int tamV,eMicro micros[],int tamM,eDestino destinos[],int tamD,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT);

//BUSQUEDA
/** \brief busca en el vector de viajes la primer posicion que encuentre un elemento con el campo isEmpty = 1 y guarda dicha posicion el *pIndice
 *
 * \param eViaje viajes[],vector de viajes
 * \param int tamV,tamnio del vector de viajes
 * \param int* pIndice, puntero donde se almacena la posicion del primer lugar libre en el vector, si no hay lugar se almacena -1
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 */

int buscarViajeLibre (eViaje viajes[],int tamV,int* pIndice);


/** \brief muestra los campos del viaje pasado por parametro
 *
 * \param eViaje viaje,estructura del tipo viaje a mostrar
 * \param eMicro micros[],vector de micros
 * \param int tamM, tamanio del vector de micros
 * \param eDestino destinos[],vector de destinos
 * \param int tamD, tamanio del vector de destinos
 * \param eEmpresa empresas[],vector de empresas
 * \param int tamE, tamanio del vector de empresas
 * \param eTipo tipos[],vector de tipos
 * \param int tamT, tamanio del vector de tipos
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int mostrarViaje(eViaje viaje,eMicro micros[],int tamM,eDestino destinos[],int tamD,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT);


/** \brief pide un micro e informa la suma de los precios (costo) de todos los viajes que realizo.
 *
 * \param eViaje viajes[],vector de viajes
 * \param int tamE, tamanio del vector de empresas
 * \param eMicro micros[],vector de micros
 * \param int tamM, tamanio del vector de micros
 * \param eDestino destinos[],vector de destinos
 * \param int tamD, tamanio del vector de destinos
 * \param eEmpresa empresas[],vector de empresas
 * \param int tamE, tamanio del vector de empresas
 * \param eTipo tipos[],vector de tipos
 * \param int tamT, tamanio del vector de tipos
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int mostrarImporteViajePorMicro (eViaje viajes[],int tamV,eMicro micros[],int tamM,eDestino destinos[],int tamD,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT);


/** \brief pide un destino y muestra los micros que viajaron a ese destino y en que fecha
 *
 * \param eViaje viajes[],vector de viajes
 * \param int tamE, tamanio del vector de empresas
 * \param eMicro micros[],vector de micros
 * \param int tamM, tamanio del vector de micros
 * \param eDestino destinos[],vector de destinos
 * \param int tamD, tamanio del vector de destinos
 * \param eEmpresa empresas[],vector de empresas
 * \param int tamE, tamanio del vector de empresas
 * \param eTipo tipos[],vector de tipos
 * \param int tamT, tamanio del vector de tipos
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int mostrarViajesPorDestino (eViaje viajes[],int tamV,eMicro micros[],int tamM,eDestino destinos[],int tamD,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT);


/** \brief pide una fecha y muestra todos los viajes realizados en la misma
 *
 * \param eViaje viajes[],vector de viajes
 * \param int tamE, tamanio del vector de empresas
 * \param eMicro micros[],vector de micros
 * \param int tamM, tamanio del vector de micros
 * \param eDestino destinos[],vector de destinos
 * \param int tamD, tamanio del vector de destinos
 * \param eEmpresa empresas[],vector de empresas
 * \param int tamE, tamanio del vector de empresas
 * \param eTipo tipos[],vector de tipos
 * \param int tamT, tamanio del vector de tipos
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int mostrarViajesPorFecha (eViaje viajes[],int tamV,eMicro micros[],int tamM,eDestino destinos[],int tamD,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT);

/** \brief pide un micro y muestra todos los viajes que hizo el mismo.
 *
 * \param eViaje viajes[],vector de viajes
 * \param int tamE, tamanio del vector de empresas
 * \param eMicro micros[],vector de micros
 * \param int tamM, tamanio del vector de micros
 * \param eDestino destinos[],vector de destinos
 * \param int tamD, tamanio del vector de destinos
 * \param eEmpresa empresas[],vector de empresas
 * \param int tamE, tamanio del vector de empresas
 * \param eTipo tipos[],vector de tipos
 * \param int tamT, tamanio del vector de tipos
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int mostrarViajesPorMicro (eViaje viajes[],int tamV,eMicro micros[],int tamM,eDestino destinos[],int tamD,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT);
