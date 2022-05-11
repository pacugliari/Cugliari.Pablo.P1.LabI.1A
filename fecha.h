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
