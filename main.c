//* EJERCICIO BOLETIN 1*//
#include "librerias.h"
#include "estructuras.h"
#include "operaciones_struct.h"
/**
* \file main.c
* \brief Archivo con la funcion int main()
*/


/** \brief Funcion Principal, que usamos como punto de union
 */
int main()
{
    struct paciente *pacientes;
    struct vacuna *vacunas;
    struct grupo_poblacional *grupos_poblacional;
    struct paciente_vacuna *pacientes_vacunas;
    /**<  damos de alta los grupos poblacionales predeterminados */
    /*
    grupos_poblacional[0]=crear_grupo("ninos","niños de 6 a 14 años");
    grupos_poblacional[1]=crear_grupo("jovenes","de 14 a 18 años");
    grupos_poblacional[2]=crear_grupo("adultos_g1","de 19 a 30 años");
    grupos_poblacional[3]=crear_grupo("adultos_g2","de 30 a 55 años");
    grupos_poblacional[4]=crear_grupo("adultos_g3","de 55 a 65 años");
    grupos_poblacional[5]=crear_grupo("jubilados","jubilados de 65 en adelante");
    */
    int opcion=0;
    char id[255];
    char identificador[255];
    int conta_pacientes=0,conta_vacunas=0,conta_grupo=0,conta_pacientes_vacunas=0,conta_num_inoculaciones=0;
    int respuesta=0;
    int n_ino=0;
    int a;
    while(opcion!=8)
    {
        opcion=menu();
        /**<  alta pacientes sin fichero */
        if(opcion==1)
        {

            /**<  guardar paciente y contarlo */
            pacientes=crear_paciente(pacientes,&conta_pacientes);

        }
        /**<  baja pacientes sin fichero */
        if(opcion==2)
        {
            printf("ID:");fflush(stdin);gets(id);
            n_ino=conteo_inoculaciones(pacientes_vacunas,conta_pacientes_vacunas,id);
            if(n_ino==0)
            {
                pacientes=baja_paciente(pacientes,&conta_pacientes,id,conta_pacientes_vacunas);
            }
            else
            {
                puts("El paciente tiene inoculaciones asociadas. Se eliminaran tambien las inoculaciones.");
                puts("Desea continuar? 1(si) 2(no)");
                fflush(stdin); scanf("%d",&a);
                if(a==1)
                {
                    pacientes=baja_paciente(pacientes,&conta_pacientes,id,conta_pacientes_vacunas);
                    for(int i=0;i<n_ino;i++)
                    {
                        pacientes_vacunas=baja_inoculaciones_paciente(pacientes_vacunas,&conta_pacientes_vacunas,id);
                    }

                }
            }

        }
        /**< Alta vacuna por terminal*/
        if(opcion==3)
        {
            vacunas=crear_vacuna(vacunas,&conta_vacunas);
        }
        /**< Alta grupo por terminal*/
        if(opcion==4)
        {
            grupos_poblacional=crear_grupo(grupos_poblacional,&conta_grupo);
        }
        /**< Alta inoculaciones por terminal*/
        if(opcion==5)
        {
            printf("Introduzca el DNI del paciente para comprobar su numero de inoculaciones: ");fflush(stdin);gets(id);
            n_ino=conteo_inoculaciones(pacientes_vacunas,conta_pacientes_vacunas,id);
            if(n_ino==3)
            {
                puts("Limite de 3 inoculaciones alcanzado en el paciente");
            }
            else
            {
                pacientes_vacunas=crear_pacientes_vacunas(pacientes_vacunas,&conta_pacientes_vacunas);
            }

        }
        /**<  baja inoculaciones */
        if(opcion==6)
        {
            printf("IDENTIFICADOR:");fflush(stdin);gets(identificador);
            pacientes_vacunas=baja_paciente_vacuna(pacientes_vacunas,&conta_pacientes_vacunas,identificador);
        }
        /**<  listar */
        if(opcion==7)
        {
            puts("\n-------------------------");
            puts("GRUPO POBLACIONAL");
            puts("-------------------------");
            mostrar_grupo(grupos_poblacional,conta_grupo);
            puts("\n-------------------------");
            puts("PACIENTE");
            puts("-------------------------");
            mostrar_pacientes(pacientes,conta_pacientes);

            puts("\n-------------------------");
            puts("INOCULACIONES");
            puts("-------------------------");
            mostrar_pacientes_vacunas(pacientes_vacunas,conta_pacientes_vacunas);
            puts("\n-------------------------");
            puts("VACUNA");
            puts("-------------------------");
            mostrar_vacunas(vacunas,conta_vacunas);



            }


    }
}
