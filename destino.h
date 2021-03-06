#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct{
    int id;
    char descripcion [25];
    float precio;
}eDestino;


#endif // DESTINO_H_INCLUDED



/** \brief valida que la id pasada por parametro este dada de alta
 *
 * \param eDestino destinos[], vector de destinos
 * \param int tamD,tama?o del vector de destinos
 * \param int id, id que se desea saber si es valida
 * \return id valida retorna 1, id invalida retorna 0
 *
 */
int validarDestino (eDestino destinos[],int tamD,int id);


/** \brief busca en el vector de destinos la posicion del destino cuya id corresponde a la del parametro
 *
 * \param eDestino destinos[],vector de destinos
 * \param int tamD,tamanio del vector de destinos
 * \param int id, id que se desea buscar su posicion en el vector
 * \param int* pIndice,donde se almacena la posicion del destino cuya id corresponde a la del parametro, si no se encuentra
 * se almacena el valor de -1
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int buscarDestino (eDestino destinos[],int tamD,int id,int* pIndice);

/** \brief genera una lista de los destinos mostrando ID,destino y precio
 *
 * \param eDestino destinos[],vector de destinos
 * \param int tamD, tamanio del vector de destinos
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */

int listarDestinos (eDestino destinos[],int tamD);


/** \brief pide al usuario que ingrese un ID destino valido
 *
 * \param eDestino destinos[],vector de destinos
 * \param int tamD, tamanio del vector de destinos
  * \param int* idDestino, puntero a entero donde se almacena el ID ingresado por el usuario
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int pedirDestino(eDestino destinos[],int tamD,int* idDestino);


/** \brief carga en el parametro descripcion, el valor del campo descripcion del elemento del vector cuya id es igual a la pasada por parametro
 *
 * \param eDestino destinos[],vector de destinos
 * \param int tamD,tamanio del vector de destinos
 * \param int id, id del elemento que se quiere obtener su descripcion
 * \param char descripcion[],cadena de caracteres donde se almacena el valor del campo descripcion
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int cargarDescripcionDestino (eDestino destinos[],int tamD,int id,char descripcion[]);
