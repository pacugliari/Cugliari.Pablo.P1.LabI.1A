#include "empresa.h"
#include "tipo.h"

#ifndef MICRO_H_INCLUDED
#define MICRO_H_INCLUDED

typedef struct{
    int id;
    int idEmpresa;
    int idTipo;
    int capacidad;
    int isEmpty;
}eMicro;

#endif // MICRO_H_INCLUDED

//INICIALIZAR
/** \brief completa todo el vector de micros el campo isEmpty en 1
 *
 * \param eMicro micros[], vector de micros
 * \param int tamM, tamanio del vector de micros
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int inicializarMicros (eMicro micros[],int tamM);

/** \brief carga elementos de prueba con datos falsos en el vector de micros para hacer pruebas en el codigo
 *
 * \param eMicro micros[],vector de micros
 * \param int tamM,tamanio del vector de micros
 * \param int cantidad, cantidad de elementos de prueba que se quieren cargar en el vector de micros
 * \param int* pId,puntero al contador que lleva el control de la id de micros
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int hardcodearMicros (eMicro micros[],int tamM,int cantidad,int* pId);

//ABM

/** \brief realiza un alta de un dato eMicro en el vector de micros pidiendo y mostrando los datos necesarios al usuario con sus respectivas validaciones
 *
 * \param eMicro micros[],vector de micros
 * \param int tamM, tamanio del vector de micros
 * \param eEmpresa empresas[],vector de empresas
 * \param int tamE, tamanio del vector de empresas
 * \param eTipo tipos[],vector de tipos
 * \param int tamT, tamanio del vector de tipos
 * \param int* pId,puntero al contador que lleva el control de la id de viajes
 * \return si los parametros, los datos ingresados por el usuario y hay lugar para el alta son correctos retorna 1 , si se genera un error en lo anterior  retorna 0
 *
 */
int altaMicro (eMicro micros[],int tamM,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT,int* pId);

/** \brief realiza una baja logica de un dato eMicro en el vector de micros pidiendo y mostrando los datos necesarios al usuario con sus respectivas validaciones
 *
 * \param eMicro micros[],vector de micros
 * \param int tamM, tamanio del vector de micros
 * \param eEmpresa empresas[],vector de empresas
 * \param int tamE, tamanio del vector de empresas
 * \param eTipo tipos[],vector de tipos
 * \param int tamT, tamanio del vector de tipos
 * \return si los parametros, los datos ingresados por el usuario y hay lugar para el alta son correctos retorna 1 , si se genera un error en lo anterior  retorna 0
 *
 */
int bajaMicro (eMicro micros[],int tamM,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT);

/** \brief realiza una modificacion de un dato eMicro en el vector de micros mostrando un submenu del campo a modificar y validando los datos ingresados por el usuario
 *
 * \param eMicro micros[],vector de micros
 * \param int tamM, tamanio del vector de micros
 * \param eEmpresa empresas[],vector de empresas
 * \param int tamE, tamanio del vector de empresas
 * \param eTipo tipos[],vector de tipos
 * \param int tamT, tamanio del vector de tipos
 * \return si los parametros, los datos ingresados por el usuario y hay lugar para el alta son correctos retorna 1 , si se genera un error en lo anterior  retorna 0
 *
 */
int modificarMicro (eMicro micros[],int tamM,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT);

//BUSCAR
/** \brief busca en el vector de micros la primer posicion que encuentre un elemento con el campo isEmpty = 1 y guarda dicha posicion el *pIndice
 *
 * \param eMicro micros[],vector de micros
 * \param int tamM,tamnio del vector de micros
 * \param int* pIndice, puntero donde se almacena la posicion del primer lugar libre en el vector, si no hay lugar se almacena -1
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 */
int buscarMicroLibre (eMicro micros[],int tamM,int* pIndice);

/** \brief busca en el vector de micros la posicion del micro cuya id corresponde a la del parametro
 *
 * \param eMicro micros[],vector de micros
 * \param int tamM,tamanio del vector de micros
 * \param int id, id que se desea buscar su posicion en el vector
 * \param int* pIndice,donde se almacena la posicion del micro cuya id corresponde a la del parametro, si no se encuentra
 * se almacena el valor de -1
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int buscarMicro (eMicro micros[],int tamM,int id,int* pIndice);

//LISTADO
/** \brief genera una lista de los micros mostrando ID,empresa,tipo,capacidad
 *
 * \param eMicro micros[],vector de micros
 * \param int tamM, tamanio del vector de micros
 * \param eEmpresa empresas[],vector de empresas
 * \param int tamE, tamanio del vector de empresas
 * \param eTipo tipos[],vector de tipos
 * \param int tamT, tamanio del vector de tipos
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int listarMicros (eMicro micros[],int tamM,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT);

/** \brief muestra la informacion de ID,empresa,tipo y capacidad un elemento del tipo eMicro
 *
 * \param eMicro micros[],vector de micros
 * \param int tamM, tamanio del vector de micros
 * \param eEmpresa empresas[],vector de empresas
 * \param int tamE, tamanio del vector de empresas
 * \param eTipo tipos[],vector de tipos
 * \param int tamT, tamanio del vector de tipos
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int mostrarMicro (eMicro microI,eEmpresa empresas[],int tamE,eTipo tipos[],int tamT);

//ORDENAMIENTO
/** \brief ordena en un vector auxiliar los micros por empresa y capacidad
 *
 * \param eMicro micros[],vector de micros
 * \param int tamM, tamanio del vector de micros
 * \param eEmpresa empresas[],vector de empresas
 * \param int tamE, tamanio del vector de empresas
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int ordenarMicrosPorEmpresaYCapacidad (eMicro micros[],int tamM,eEmpresa empresas[],int tamE);

//MENU
/** \brief muestra el menu de la operacion ABM modificar mostrando tipo y capacidad
 *
 * \return retorna la respuesta del tipo char ingresada por el usuario,
 *
 */
char menuModificar ();
