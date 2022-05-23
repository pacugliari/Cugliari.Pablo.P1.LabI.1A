#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED


typedef struct{
    int id;
    char descripcion [20];
}eTipo;


#endif // TIPO_H_INCLUDED

/** \brief genera una lista de los tipos mostrando ID,tipo
 *
 * \param eTipo tipos[],vector de tipos
 * \param int tamT, tamanio del vector de tipos
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int listarTipos (eTipo tipos[],int tamT);

/** \brief busca en el vector de tipos la posicion del tipo cuya id corresponde a la del parametro
 *
 * \param eTipo tipos[],vector de tipos
 * \param int tamT,tamanio del vector de tipos
 * \param int id, id que se desea buscar su posicion en el vector
 * \param int* pIndice,donde se almacena la posicion del tipo cuya id corresponde a la del parametro, si no se encuentra
 * se almacena el valor de -1
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int buscarTipo (eTipo tipos[],int tamT,int id,int* pIndice);

/** \brief carga en el parametro descripcion, el valor del campo descripcion del elemento del vector cuya id es igual a la pasada por parametro
 *
 * \param eTipo tipos[],vector de tipos
 * \param int tamT,tamanio del vector de tipos
 * \param int id, id del elemento que se quiere obtener su descripcion
 * \param char descripcion[],cadena de caracteres donde se almacena el valor del campo descripcion
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int cargarDescripcionTipo (eTipo tipos[],int tamT,int id,char descripcion[]);

/** \brief valida que la id pasada por parametro este dada de alta
 *
 * \param eTipo tipos[], vector de tipos
 * \param int tamT,tamaño del vector de tipos
 * \param int id, id que se desea saber si es valida
 * \return id valida retorna 1, id invalida retorna 0
 *
 */
int validarTipo (eTipo tipos[],int tamT,int id);


/** \brief pide al usuario que ingrese un ID de tipos valida
 *
 * \param eTipo tipos[], vector de tipos
 * \param int tamT,tamaño del vector de tipos
 * \param int* idTipo, puntero a entero donde se almacena la ID ingresada por el usuario
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int pedirTipos(eTipo tipos[],int tamT,int* idTipo);
