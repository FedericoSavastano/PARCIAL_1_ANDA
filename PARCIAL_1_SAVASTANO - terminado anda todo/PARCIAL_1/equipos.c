#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "validaciones.h"
#include "equipos.h"

#define CANT_EQUIPOS 10
#define CANT_JUGADORES 16
#define CANT_PARTIDOS 10
#define CANT_REFERIS 10

#define TRUE 0
#define FALSE 1

void hardcodeoEquipos(eEquipo* listaEquipos, int cantidad)
{
    int codigoEquipo[]={1,2,3,4,5,6,7,8,9,10};
    char nombre[][51]={"Independiente","Boca","Racing","River","Defensa Y Justicia", "SanLorenzo", "Pepitos", "Linternas Verdes", "Batmanes", "Flashes"};
    char localidad[] [33] ={"Avellaneda","La boca", "Avellaneda","La Plata",  "Varela", "Almagro", "Bagley", "Oa","Gotica","Star city"};

    //int estaVacioEquipo;

    int i;


    for(i=0;i<cantidad;i++)
    {
        listaEquipos[i].codigoEquipo=codigoEquipo[i];
        strcpy(listaEquipos[i].nombre,nombre[i]);
        strcpy(listaEquipos[i].localidad,localidad[i]);
        listaEquipos[i].estaVacioEquipo=FALSE;
    }


    //printf("el equipo %s es de %s, su codigo es %d y su estado %d \n",listaEquipos[2].nombre, listaEquipos[2].localidad, listaEquipos[2].codigoEquipo,  listaEquipos[2].estaVacioEquipo);
}




/** \brief Carga un equipo al array lista de equipos devuelve 0 si lo hizo bien, -1 si falló.
 *
 * \param listaEquipos eEquipo* puntero al array a donde cargar
 * \param cantidad int cantidad de elementos que tiene el array
 * \param codigo int codigo incrementado que se copia de otra funcion
 * \param nombre[] char nombre a cargar
 * \param localidad[] char localidad a cargar
 * \param lugarVacio int el indice donde cargar
 * \return int 0 si fue exitoso , -1 si falló
 *
 */
int agregarEquipo(eEquipo* listaEquipos, int cantidad, int codigo, char nombre[], char localidad[], int lugarVacio)
{
    if(listaEquipos!=NULL && cantidad==CANT_EQUIPOS)
    {
        ponerMayusculas(nombre);
        ponerMayusculas(localidad);

        listaEquipos[lugarVacio].codigoEquipo=codigo;
        strcpy(listaEquipos[lugarVacio].nombre,nombre);
        strcpy(listaEquipos[lugarVacio].localidad,localidad);

        listaEquipos[lugarVacio].estaVacioEquipo=FALSE;

        return 0;
    }

    return -1;

}


/** \brief imprime por pantalla la lista de equipos que esten cargados
 *
 * \param listaEquipos eEquipo* array de equipos
 * \param cantidad int cantidad elementos del array
 * \return void nada
 *
 */
void mostrarEquipos(eEquipo* listaEquipos, int cantidad )
{
    printf("EQUIPOS\n");
    printf("\t Codigo  \t  Nombre  \t   Localidad\n");
    int ix;
    for(ix=0;ix<cantidad;ix++)
    {
        if(listaEquipos[ix].estaVacioEquipo==FALSE)
        {
            printf("\n\t %2d  \t %18s  \t %18s\n",listaEquipos[ix].codigoEquipo,listaEquipos[ix].nombre,listaEquipos[ix].localidad);
        }
    }
}


/** \brief ordena los equipos del array alfabeticamente con swapeo, segundo criterio de orden: nombre del equipo
 *
 * \param listaEquipos eEquipo* array de equipos
 * \param cantidad int cantidad de elementos del array
 * \return void nada
 *
 */
void ordenarEquiposAlfabeticamente(eEquipo* listaEquipos, int cantidad)
{
    int i;
    int j;
    eEquipo auxEquipo;

    for(i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if( ( strcmp(listaEquipos[i].nombre,listaEquipos[j].nombre) > 0 )   )
            {
                auxEquipo= listaEquipos[i];
                listaEquipos[i]= listaEquipos[j];
                listaEquipos[j]= auxEquipo;
            }//if( ( strcmp(listaEquipos[i].nombre,listaEquipos[j].nombre) > 0 )



            if(  ( strcmp(listaEquipos[i].nombre,listaEquipos[j].nombre) == 0 )    )
            {
                if(   ( strcmp(listaEquipos[i].localidad,listaEquipos[j].localidad) > 0 ) ){
                    auxEquipo= listaEquipos[i];
                    listaEquipos[i]= listaEquipos[j];
                    listaEquipos[j]= auxEquipo;

                  }
            }
        }//for(j=i-1;i<cantidad;j++)
    }//for(i=0;i<cantidad-1;i++)
}


/** \brief busca equipos por el codigo , devuelve el indice del equipo si lo encontró, -1 si no lo encontró
 *
 * \param listaDeEquipos eEquipo* array de equipos
 * \param cantidad int cantidad de elementos del array
 * \param codigo int el codigo a buscar
 * \return int devuelve el indice del equipo si lo encontró, -1 si no lo encontró
 *
 */
int buscarEquipoPorCodigo(eEquipo* listaDeEquipos, int cantidad, int codigo)
{
    int i;
    if(listaDeEquipos!=NULL && cantidad==CANT_EQUIPOS)
    {
        for(i=0;i<cantidad;i++)
        {
            if(codigo== listaDeEquipos[i].codigoEquipo)
            {
                return i;
            }
        }
    }

    return -1;
}


void mostrarUnEquipo(eEquipo* listaDeEquipos, int cantidad, int codigo)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(codigo==listaDeEquipos[i].codigoEquipo)
        {
            printf(" %s  de %s ", listaDeEquipos[i].nombre, listaDeEquipos[i].localidad);
        }
    }
}




/** \brief da de baja un equipo poniendo el esta vacio en true, si no encontró devuelve -1
 *
 * \param listaDeEquipos eEquipo* array de equipos
 * \param cantidad int cantidad de elementos del array
 * \param codigo int el codigo a buscar
 * \return 0 si lo dio de baja, -1 si no se pudo
 *
 */

int bajaEquipoConfirm (eEquipo listaEquipos[], int cantidad, int codigo)
{
    int i;

    char confirmaSN;
    //int retorno;
    //printf("EL CODIGO QUE LE LLEGA A LA FUNCION ES %d\n\n",codigo);


    if(listaEquipos!=NULL) //&& cantidad==CANT_EQUIPOS)
    {
        for(i=0;i<cantidad;i++)
        {
            //printf("LOS CODIGOS QUE SE ESTAN MANEJANDO ACA SON : %d\n\n", listaEquipos[i].codigoEquipo);

            if(listaEquipos[i].estaVacioEquipo==FALSE)
            {


                if(listaEquipos[i].codigoEquipo == codigo )
                {
                    printf(" Esta a punto de dar de baja a %s ", listaEquipos[i].nombre);
                    confirmaSN=getChar("Confirma? [ S / N ]\n");
                    if(confirmaSN=='s' || confirmaSN=='S')
                    {
                       listaEquipos[i].estaVacioEquipo=TRUE;
                        return 0;
                        break;
                    }else{
                        return -1;
                        break;
                    }

                }




            }else if(listaEquipos[cantidad].estaVacioEquipo==FALSE){
               printf("\nNo se encuentra ese codigo \n");
                return -1;
                break;
            }
        }//FOR
    }

    return -1;

}

/** \brief modifica un elemento de la estructura equipo selccionada, mostrando un submenu para elegir el elemento.
 *
 * \param listaDeEquipos eEquipo* array de equipos
 * \param indice int indice del elemento del array a modificar
 *
 * \return 0 si lo hizo correctamente, -1 si falló
 *
 */

int modificarEquipo( eEquipo listaEquipos[], int indice)
{
    if( listaEquipos!= NULL && indice<CANT_EQUIPOS)
    {
        int opcion;
        char confirmaSN;

        char auxNombreEquipo[51];
        char auxLocalidadEquipo[33];

        printf("\n");
        printf("Elija que desea modificar : ");
        printf("\n");
        printf(" 1. Nombre del equipo ");
        printf("\n");
        printf(" 2. Localidad del equipo ");
        printf("\n");
        printf(" 3. Salir ");
        printf("\n");
        printf("\n");
        scanf("%d",&opcion);

        while(opcion!=3)
        {
            switch(opcion)
            {
            case 1:
                if(  (getValidString(" Ingrese el nuevo nombre : ", " Nombre no valido \n", " Nombre demasiado largo \n", auxNombreEquipo, 51, 3) )==0   )
                {
                    ponerMayusculas(auxNombreEquipo);
                    printf("Se va a modificar el nombre %s  por  %s  \n", listaEquipos[indice].nombre, auxNombreEquipo);
                    confirmaSN=getChar("Confirma? [ S / N ] \n");

                    if(confirmaSN=='s' || confirmaSN=='S')
                    {
                        strcpy( listaEquipos[indice].nombre, auxNombreEquipo );
                        printf("\n");
                        printf("Nombre modificado exitosamente \n");
                        printf("\n");
                        break;
                    }else{
                        printf("\n");
                        printf("No se pudo modificar el nombre. Intentelo de vuelta ");
                        printf("\n");
                        break;
                    }
                }
                break;

            case 2:
                if(  (getValidString(" Ingrese la nueva localidad : ", " Localidad no valida \n", " Localidad demasiado larga \n", auxLocalidadEquipo, 51, 3) )==0   )
                {
                    ponerMayusculas(auxLocalidadEquipo);
                    printf("Se va a modificar la localidad %s  por  %s  \n", listaEquipos[indice].localidad, auxLocalidadEquipo);
                    confirmaSN=getChar("Confirma? [ S / N ] \n");

                    if(confirmaSN=='s' || confirmaSN=='S')
                    {
                        strcpy( listaEquipos[indice].localidad, auxLocalidadEquipo );
                        printf("\n");
                        printf("Localidad modificada exitosamente \n");
                        printf("\n");
                        break;
                    }else{
                        printf("\n");
                        printf("No se pudo modificar la localidad. Intentelo de vuelta ");
                        printf("\n");
                        break;
                    }
                }
                break;

            }

        printf("\n");
        printf("Elija que desea modificar : ");
        printf("\n");
        printf(" 1. Nombre del equipo ");
        printf("\n");
        printf(" 2. Localidad del equipo ");
        printf("\n");
        printf(" 3. Salir ");
        printf("\n");
        printf("\n");
        scanf("%d",&opcion);


        }//while(opcion!=3)

        return 0;

    }//if( listaEquipos!= NULL && indice<CANT_EQUIPOS)


    return -1;
}



int equipoNombreMasLargo (eEquipo* listaEquipos, int cantidad)
{

    int masLargo = strlen(listaEquipos[0].nombre);
    int indiceMasLargo=0;
    int i;
    int largo;

    for(i=1;i<cantidad;i++)
    {
        largo=strlen(listaEquipos[i].nombre);
        if(masLargo<largo)
        {
            masLargo = largo;
            indiceMasLargo = i;
        }
    }

    //printf( "El mas largo es %s ",listaEquipos[indiceMasLargo].nombre);
    return indiceMasLargo;

}
