#define ANIO_ACTUAL 2022

#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

#endif // FECHA_H_INCLUDED


/** \brief valida que la fecha pasada por parametro sea valida, el año no puede ser mayor al actual ni menor a año actual -100
 * validando el numero de mes este entre 1 y 12 y los dias de los meses sean correspondiente a cada cual
 *
 * \param eFecha fecha, fecha que se desea validar
 * \return retorna 1 si la fecha pasada por parametro es correcta o 0 si la fecha es erronea
 *
 */
int validarFecha(eFecha fecha);

/** \brief pide al usuario una Fecha valida
 *
 * \param eFecha* fecha, puntero a tipo eFecha donde se almacena dia,mes y anio que ingresa el usuario
 * \return si los parametros son correctos retorna 1 , si los parametros son incorrectos retorna 0
 *
 */
int pedirFecha(eFecha* fecha);

/** \brief compara las fechas pasadas por parametro
 *
 * \param eFecha fecha1, estructura del tipo fecha que se quiere comparar
 * \param eFecha fecha2, estructura del tipo fecha que se quiere comparar
 * \return si las fechas son iguales retorna 1, si son distintas retorna 0
 *
 */
int compararFechas(eFecha fecha1,eFecha fecha2);
