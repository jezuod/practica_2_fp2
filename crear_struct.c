#include "librerias.h"
#include "estructuras.h"
#include "operaciones_struct.h"
/**
* \file crear_struct.c
* \brief Implementacion de la modificacion y listado de estructuras
*/


/** \brief añadir grupos poblacionales
 */
 struct grupo_poblacional *crear_grupo(struct grupo_poblacional *g,int *conta_grupo)
{
         /**< char buffer[255] */
    char *buffer = (char *)malloc(sizeof(char)*TAM_BUFFER);
    /**< ARRAY DINAMICO SIN PACIENTES */
    if  (*conta_grupo == 0)
    {
        g = (struct grupo_poblacional *)malloc(sizeof(struct grupo_poblacional));
    }
    /**< ARRAY DINAMICO CON PACIENTES YA REGISTRADOS */
    else
    {
        g = (struct grupo_poblacional *)realloc(g,sizeof(struct grupo_poblacional)*((*conta_grupo)+1));
    }
    printf("IDENTIFICADOR: ");fflush(stdin);gets(buffer);
    g[*conta_grupo].identificador = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(g[*conta_grupo].identificador,buffer);

    printf("NOMBRE: ");fflush(stdin);gets(buffer);
    g[*conta_grupo].descripcion = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(g[*conta_grupo].descripcion,buffer);




    (*conta_grupo) = (*conta_grupo) + 1;
    free(buffer);
    return g;

};

/** \brief añadir pacientes
 */
struct paciente *crear_paciente (struct paciente *p,int *conta_pacientes)
{
         /**< char buffer[255] */
    char *buffer = (char *)malloc(sizeof(char)*TAM_BUFFER);
    /**< ARRAY DINAMICO SIN PACIENTES */
    if  (*conta_pacientes == 0)
    {
        p = (struct paciente *)malloc(sizeof(struct paciente));
    }
    /**< ARRAY DINAMICO CON PACIENTES YA REGISTRADOS */
    else
    {
        p = (struct paciente *)realloc(p,sizeof(struct paciente)*((*conta_pacientes)+1));
    }
    printf("DNI: ");fflush(stdin);gets(buffer);
    p[*conta_pacientes].dni = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(p[*conta_pacientes].dni,buffer);

    printf("NOMBRE: ");fflush(stdin);gets(buffer);
    p[*conta_pacientes].nombre = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(p[*conta_pacientes].nombre,buffer);

    printf("APELLIDOS: ");fflush(stdin);gets(buffer);
    p[*conta_pacientes].apellidos = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(p[*conta_pacientes].apellidos,buffer);

    printf("DIRECCION: ");fflush(stdin);gets(buffer);
    p[*conta_pacientes].direccion = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(p[*conta_pacientes].direccion,buffer);

    printf("FECHA DE NACIMIENTO: ");fflush(stdin);gets(buffer);
    p[*conta_pacientes].fecha_nacimiento = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(p[*conta_pacientes].fecha_nacimiento,buffer);

    printf("Identificador del grupo: ");fflush(stdin);gets(buffer);
    p[*conta_pacientes].identificador = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(p[*conta_pacientes].identificador,buffer);

    printf("Numero de telefono: ");fflush(stdin); scanf("%d",&p[*conta_pacientes].telefono);


    (*conta_pacientes) = (*conta_pacientes) + 1;
    free(buffer);
    return p;

};
/** \brief añadir vacunas
 */
struct vacuna *crear_vacuna(struct vacuna *v,int *conta_vacunas)
{
             /**< char buffer[255] */
    char *buffer = (char *)malloc(sizeof(char)*TAM_BUFFER);
    /**< ARRAY DINAMICO SIN VACUNAS */
    if  (*conta_vacunas == 0)
    {
        v = (struct vacuna *)malloc(sizeof(struct vacuna));
    }
    /**< ARRAY DINAMICO CON VACUNAS YA REGISTRADOS */
    else
    {
        v = (struct vacuna *)realloc(v,sizeof(struct vacuna)*((*conta_vacunas)+1));
    }
    printf("NUM SERIE: ");fflush(stdin);gets(buffer);
    v[*conta_vacunas].num_serie = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(v[*conta_vacunas].num_serie,buffer);

    printf("EMPRESA: ");fflush(stdin);gets(buffer);
    v[*conta_vacunas].empresa = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(v[*conta_vacunas].empresa,buffer);

    printf("FECHA APROBACION: ");fflush(stdin);gets(buffer);
    v[*conta_vacunas].fecha_aprobacion = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(v[*conta_vacunas].fecha_aprobacion,buffer);

    printf("Lote: ");fflush(stdin); scanf("%d",&v[*conta_vacunas].lote);



    (*conta_vacunas) = (*conta_vacunas) + 1;
    free(buffer);
    return v;
};
/** \brief registrar las inoculaciones en pacientes
 */
struct paciente_vacuna *crear_pacientes_vacunas(struct paciente_vacuna *pv,int *conta_pacientes_vacunas)
{
              /**< char buffer[255] */
    char *buffer = (char *)malloc(sizeof(char)*TAM_BUFFER);
    /**< ARRAY DINAMICO SIN VACUNAS */
    if  (*conta_pacientes_vacunas == 0)
    {
        pv = (struct paciente_vacuna *)malloc(sizeof(struct paciente_vacuna));
    }
    /**< ARRAY DINAMICO CON VACUNAS YA REGISTRADOS */
    else
    {
        pv = (struct paciente_vacuna *)realloc(pv,sizeof(struct paciente_vacuna)*((*conta_pacientes_vacunas)+1));
    }
    /*
    printf("IDENTIFICADOR: ");fflush(stdin);gets(buffer);
    pv[*conta_pacientes_vacunas].identificador = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(pv[*conta_pacientes_vacunas].identificador,buffer);
    */
    printf("DNI: ");fflush(stdin);gets(buffer);
    pv[*conta_pacientes_vacunas].dni = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(pv[*conta_pacientes_vacunas].dni,buffer);

    printf("NUM SERIE: ");fflush(stdin);gets(buffer);
    pv[*conta_pacientes_vacunas].num_serie = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(pv[*conta_pacientes_vacunas].num_serie,buffer);

    printf("FECHA: ");fflush(stdin);gets(buffer);
    pv[*conta_pacientes_vacunas].fecha = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(pv[*conta_pacientes_vacunas].fecha,buffer);

    /**< creacion del identificador */
    strcpy(buffer,pv[*conta_pacientes_vacunas].dni);
    strcat(buffer,"_");
    strcat(buffer,pv[*conta_pacientes_vacunas].num_serie);
    strcat(buffer,"_");
    strcat(buffer,pv[*conta_pacientes_vacunas].fecha);
    pv[*conta_pacientes_vacunas].identificador = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(pv[*conta_pacientes_vacunas].identificador,buffer);

    puts("\nLa inoculacion ha sido dado de alta con exito\nEl identificador asignado a la inoculacion es:");
    printf("%s",pv[*conta_pacientes_vacunas].identificador);
    (*conta_pacientes_vacunas) = (*conta_pacientes_vacunas) + 1;
    free(buffer);
    return pv;

};
/** \brief baja de pacientes
 */
struct paciente *baja_paciente(struct paciente *p,int *conta_pacientes,char dni[255],int conta_pacientes_vacunas)
{
    int encontrado=0,i=0,k;
    while ((i < *conta_pacientes) && (encontrado == 0))
            {
                if(strcmp(dni,p[i].dni) == 0)
                {
                    encontrado=1;
                    int num=0;
                    //PACIENTE ENCONTRADO
                    free(p[i].dni);
                    for (k = i; k < (*conta_pacientes - 1); k++)
                        {
                            p[k] = p[k+1];
                        }
                    (*conta_pacientes)--;
                    p = (struct paciente *)realloc(p,sizeof(struct paciente)*(*conta_pacientes));

                    printf("\nPaciente eliminado correctamente.\n");
                }
                i++;
            }
    return p;

};
/** \brief registrar baja inoculaciones en pacientes por dni
 */
struct paciente_vacuna *baja_inoculaciones_paciente(struct paciente_vacuna *pv,int *conta_paciente_vacuna,char id[255])
{
    int encontrado=0,i=0,k;
    while (i < *conta_paciente_vacuna)
            {
                if (strcmp(pv[i].dni,id) == 0)
                {
                    //INOCULACION ENCONTRADO
                    free(pv[i].identificador);
                    for (k = i; k < (*conta_paciente_vacuna - 1); k++)
                    {
                        pv[k] = pv[k+1];
                    }

                    (*conta_paciente_vacuna)--;
                    pv = (struct paciente_vacuna *)realloc(pv,sizeof(struct paciente_vacuna)*(*conta_paciente_vacuna));

                    printf("\nInoculacion eliminada correctamente.\n");
                }
                i++;
            }
    return pv;

};
/** \brief registrar baja inoculaciones en pacientes por identificador
 */
struct paciente_vacuna *baja_paciente_vacuna(struct paciente_vacuna *pv,int *conta_paciente_vacuna,char identificador[255])
{
    int encontrado=0,i=0,k;
    while ((i < *conta_paciente_vacuna) && (encontrado == 0))
            {
                if (strcmp(pv[i].identificador,identificador) == 0)
                {
                    encontrado=1;
                    //INOCULACION ENCONTRADO
                    free(pv[i].identificador);
                    for (k = i; k < (*conta_paciente_vacuna - 1); k++)
                    {
                        pv[k] = pv[k+1];
                    }

                    (*conta_paciente_vacuna)--;
                    pv = (struct paciente_vacuna *)realloc(pv,sizeof(struct paciente_vacuna)*(*conta_paciente_vacuna));

                    printf("\nInoculacion eliminada correctamente.\n");
                }
                i++;
            }
    return pv;

};
/** \brief mostrar los pacientes
 */
void mostrar_pacientes(struct paciente *p,int contador)
{
    int i=0;
    for(int i=0;i<contador;i++)
    {
         printf("\nDNI: ");puts((p+i)->dni);
        printf("nombre: ");puts((p+i)->nombre);
        printf("apellidos: ");puts((p+i)->apellidos);
        printf("telefono: %d\n",(p+i)->telefono);
        printf("direccion: ");puts((p+i)->direccion);
        printf("fecha_nacimiento: ");puts((p+i)->fecha_nacimiento);
        printf("grupo: ");puts((p+i)->identificador);
    }



}
/** \brief mostar las vacunas
 */
void mostrar_vacunas(struct vacuna *v,int contador)
{
    int i=0;
    for(int i=0;i<contador;i++)
    {
    printf("\nNum Serie: ");puts((v+i)->num_serie);
    printf("empresa: ");puts((v+i)->empresa);
    printf("fecha_aprobacion: ");puts((v+i)->fecha_aprobacion);
    printf("lote: %d\n",(v+i)->lote);
    }


}
/** \brief mostrar los grupos poblacionales
 */
void mostrar_grupo(struct grupo_poblacional *g,int conta_grupo)
{

    for(int i=0;i<conta_grupo;i++)
    {
        printf("Descripcion: ");puts((g+i)->identificador);
        printf("Identificador: ");puts((g+i)->descripcion);
    }

}
/** \brief mostrar las inoculaciones
 */
void mostrar_pacientes_vacunas(struct paciente_vacuna *pv,int contador)
{

    int i=0;
    for(int i=0;i<contador;i++)
    {
        printf("Identificador: ");puts((pv+i)->identificador);
        printf("DNI: ");puts((pv+i)->dni);
        printf("Numero Serie: ");puts((pv+i)->num_serie);
        printf("Fecha: ");puts((pv+i)->fecha);

    }

}
/** \brief conteo de inoculaciones
 */
int conteo_inoculaciones(struct paciente_vacuna *pv,int contador,char dni[255])
{
    int i=0;
    int num_ino=0;
    for(int i=0;i<contador;i++)
    {
        if(strcmp(pv[i].dni,dni)==0)
        {
            printf("\nInoculacion encontrada del paciente %s",dni);
            ++num_ino;
        }
    }
    return num_ino;
}
