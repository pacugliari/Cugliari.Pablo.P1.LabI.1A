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


/** \brief pide al usuario un ID de micro valido
 *
 * \param eMicro micros[],vector de micros
 * \param int tamM, tamanio del vector de micros
 * \param eEmpresa empresas[],vector de empresas
 * \param int tamE, tamanio del vector de empresas
 * \param eTipo tipos[],vector de tipos
 * \param int tamT, tamanio del vector de tipos
 * \param int* pIdMicro,puntero a entero donde se almacena el ID ingresado por el usuario
 * \param int* pIndice, puntero a entero donde se almacena el indice del ID en el vector de micros, si no esta se almacena -1
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int pedirMicro(eMicro micros[],eEmpresa empresas[],eTipo tipos[],int tamM,int tamE,int tamT,int* pIdMicro,int* pIndice);

/** \brief pide al usuario que ingrese una capacidad valida
 *
 * \param int* capacidad, puntero a entero donde se almacena la capacidad ingresada por el usuario
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int pedirCapacidad(int* capacidad);


/** \brief muestra micros de la empresa seleccionada por el usuario
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
int mostrarMicrosPorEmpresa (eMicro micros[],eEmpresa empresas[],eTipo tipos[],int tamM,int tamE,int tamT);

/** \brief muestra los micros de un tipo seleccionado.
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
int mostrarMicrosPorTipo (eMicro micros[],eEmpresa empresas[],eTipo tipos[],int tamM,int tamE,int tamT);

/** \brief informa el promedio de micros de tipo Vip sobre el total de micros de una empresa
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
int mostrarPromedioVipPorEmpresa (eMicro micros[],eEmpresa empresas[],eTipo tipos[],int tamM,int tamE,int tamT);

/** \brief muestra un listado de los micros separados por empresa.
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
int mostrarMicrosPorEmpresas (eMicro micros[],eEmpresa empresas[],eTipo tipos[],int tamM,int tamE,int tamT);

/** \brief informa la o las empresas que pueden transportar mas pasajeros (mayor acumulador de capacidades de sus micros)
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
int mostrarEmpresasConMasCapacidad (eMicro micros[],eEmpresa empresas[],int tamM,int tamE);

/** \brief muestra la empresa con menos cantidad de micros
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
int mostrarEmpresaConMenosMicros (eMicro micros[],eEmpresa empresas[],int tamM,int tamE);

/** \brief valida que la id pasada por parametro este dada de alta
 *
 * \param eMicro micros[], vector de micros
 * \param int tamM,tamaño del vector de micros
 * \param int id, id que se desea saber si es valida
 * \return id valida retorna 1, id invalida retorna 0
 *
 */
int validarMicro (eMicro micros[],int tamM,int id);
