#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

typedef struct{
    int id;
    char descripcion [20];
}eEmpresa;

#endif // EMPRESA_H_INCLUDED

/** \brief genera una lista de las empresas mostrando ID,destino
 *
 * \param eEmpresa empresas[],vector de empresas
 * \param int tamE, tamanio del vector de empresas
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int listarEmpresas (eEmpresa empresas[],int tamE);

/** \brief carga en el parametro descripcion, el valor del campo descripcion del elemento del vector cuya id es igual a la pasada por parametro
 *
 * \param eEmpresa empresas[],vector de empresas
 * \param int tamE,tamanio del vector de empresas
 * \param int id, id del elemento que se quiere obtener su descripcion
 * \param char descripcion[],cadena de caracteres donde se almacena el valor del campo descripcion
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int cargarDescripcionEmpresa (eEmpresa empresas[],int tamE,int id,char descripcion[]);

/** \brief busca en el vector de empresas la posicion de la empresa cuya id corresponde a la del parametro
 *
 * \param eEmpresa empresas[],vector de empresas
 * \param int tamE,tamanio del vector de empresas
 * \param int id, id que se desea buscar su posicion en el vector
 * \param int* pIndice,donde se almacena la posicion de la empresa cuya id corresponde a la del parametro, si no se encuentra
 * se almacena el valor de -1
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int buscarEmpresa (eEmpresa empresas[],int tamE,int id,int* pIndice);

/** \brief valida que la id pasada por parametro este dada de alta
 *
 * \param eEmpresa empresas[], vector de empresas
 * \param int tamE,tamaño del vector de empresas
 * \param int id, id que se desea saber si es valida
 * \return id valida retorna 1, id invalida retorna 0
 *
 */
int validarEmpresa (eEmpresa empresas[],int tamE,int id);

/** \brief pide al usuario que ingrese un ID de empresa valido
 *
 * \param eEmpresa empresas[], vector de empresas
 * \param int tamE,tamaño del vector de empresas
 * \param int* idEmpresa,puntero a entero donde se almacena la ID de la empresa ingresada
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int pedirEmpresa(eEmpresa empresas[],int tamE,int* idEmpresa);
