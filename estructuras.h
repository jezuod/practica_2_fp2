#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
#include "librerias.h"

/**
* \file estructuras.h
* \brief Declaracion de estructuras
*/

/** \brief Tabla Paciente
 *
 * \param DNI -> dni del paciente unico
 * \param NOMBRE -> nombre del paciente
 * \param APELLIDOS -> apellido  del paciente
 * \param TELEFONO -> telefono del paciente
 * \param DIRECCION -> direccion del paciente
 * \param FECHA_NACIMIENTO -> fecha de nacimiento del paciente
 * \param IDENTIFICADOR -> identificador del grupo poblacional al que pertenece el paciente
 * \return
 *
 */

struct paciente
{
    char *dni; /**<  pk */
    char *nombre;
    char *apellidos;
    int telefono;
    char *direccion;
    char *fecha_nacimiento;
    char *identificador; /**<  fk de grupo poblacional */
};
/** \brief Tabla Vacuna
 *
 * \param NUM_SERIE -> numero de serie de la vacuna
 * \param EMPRESA -> empresa que produce la vacuna
 * \param FECHA_APROBACION -> fecha de la aprobacion del uso de la vacuna
 * \param LOTE -> cantidad de vacuna disponible
 * \return
 *
 */
struct vacuna
{
    char *num_serie; /**<  pk */
    char *empresa;
    char *fecha_aprobacion;
    int lote;
};
/** \brief Tabla Grupo Poblacional
 *
 * \param IDENTIFICADOR -> identificador del grupo poblacional
 * \param DESCRIPCION -> descripcion del grupo poblacional
 * \return
 *
 */
struct grupo_poblacional
{
    char *identificador; /**<  pk */
    char *descripcion;
};
/** \brief Tabla Paciente_Vacuna , hace referencia a las inoculaciones
 *
 * \param IDENTIFICADOR -> identificador FORMATO   <DNI>_<Id>_DD_MM_AAAA
 * \param DNI -> dni del paciente que se ha inoculado
 * \param NUM_SERIE -> numero de serie de la vacuna inoculada
 * \param FECHA -> fecha de la inoculacion
 * \return
 *
 */
struct paciente_vacuna
{
    char *identificador; /**<  FORMATO   <DNI>_<Id>_DD_MM_AAAA */
    char *dni; /**<  clave primaria de paciente */
    char *num_serie; /**<  clave primaria de vacuna */
    char *fecha; /**<  fecha */
};


#endif // ESTRUCTURAS_H_INCLUDED
