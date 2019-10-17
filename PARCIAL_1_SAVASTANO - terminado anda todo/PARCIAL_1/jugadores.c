
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "validaciones.h"
#include "equipos.h"
#include "jugadores.h"

#define CANT_EQUIPOS 10
#define CANT_JUGADORES 16
#define CANT_PARTIDOS 10
#define CANT_REFERIS 10

#define TRUE 0
#define FALSE 1




void hardcodeoJugadores(eJugador* listaJugadores, int cantidad)
{
    int codigoJugador[] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160};
    char apellidoJugador[] [31] = {/*"Rodriguez"*/"Wayne", "Marquez","Pelaez",/*"Mantuqui"*/"Wayne","Garchulo","Wayne",/*"Oltorno"*/"Wayne","Ostorno","Arquitequi","Procenex","Hache","Rainer","Ultron" ,"Lombos" ,"Bolos" ,"Dachunqui" };
    char nombreJugador[] [31] = {"Juan", "John","Joao","Joco","Orcho","Mocho","Acho","Pacho","Cuacho","Racho","Tacho","Uno","Cuarentaytres" ,"Lombos" ,"Kofler" ,"Queda" };
    int codigoEquipoJugador [] ={ 1,1,1, 10,10,9,8,8,8,8,3 ,3 ,5, 5, 5 ,6    }; //REVISAR SI ESTO TIENE QUE ESTAR LIGADO AL ESTRUC DE EQUIPOS
    char sexo[]={'m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m'};
    //eFechaJugador fechaNacimiento[];
    int dia={10};
    int mes={8};
    int anio[] ={1999,1990,1992,1990,1982,1980,1992,1998,1995,1990,1992,1998,1993,1994,1995,1996};

    int i;
    for(i=0;i<cantidad;i++)
    {
        listaJugadores[i].codigoJugador=codigoJugador[i];
        listaJugadores[i].codigoEquipoJugador=codigoEquipoJugador[i];
        listaJugadores[i].fechaNacimiento.dia=dia;
        listaJugadores[i].fechaNacimiento.mes=mes;
        listaJugadores[i].fechaNacimiento.anio=anio[i];
        listaJugadores[i].sexo=sexo[i];

        strcpy(listaJugadores[i].apellidoJugador,apellidoJugador[i]);
        strcpy(listaJugadores[i].nombreJugador,nombreJugador[i]);

        listaJugadores[i].estaVacioJugador=FALSE;
    }


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
int agregarJugador(eJugador* listaJugadores, int cantidad, int codigoJugador, char apellido[] ,char nombre[], char sexo, int codigoEquipo, eFechaJugador fechaJugador ,int lugarVacio)
{
    if(listaJugadores!=NULL && cantidad==CANT_JUGADORES)
    {
        ponerMayusculas(nombre);
        ponerMayusculas(apellido);

        listaJugadores[lugarVacio].codigoJugador=codigoJugador;
        strcpy(listaJugadores[lugarVacio].nombreJugador,nombre);
        strcpy(listaJugadores[lugarVacio].apellidoJugador,apellido);


        listaJugadores[lugarVacio].codigoEquipoJugador=codigoEquipo;
        ///CODIGO DE EQUIPO VALIDAR

        listaJugadores[lugarVacio].sexo=sexo;

        listaJugadores[lugarVacio].fechaNacimiento=fechaJugador;

        listaJugadores[lugarVacio].estaVacioJugador=FALSE;

        return 0;
    }

    return -1;

}

/** \brief Guarda la fecha de nacimiento de un jugador
 *
 * \return la estructura de fecha jugador
 *
 */

 int introducirFechaJugador2( eFechaJugador * fechaAux)
 {
    eFechaJugador fechaDeUnJugador;
    int validDia;
    int validMes;
    int validAnio;
    printf("Ingrese la fecha de nacimiento del jugador\n");

   validDia= getValidInt("Dia : ", "Dia no valido", &fechaDeUnJugador.dia,1,31,3 );
   validMes= getValidInt("Mes : ", "Mes no valido", &fechaDeUnJugador.mes, 1,12,3);
   validAnio= getValidInt("Anio : ", "Anio no valido", &fechaDeUnJugador.anio,1940,2019,3  );

   if(validDia==0 && validMes==0 && validAnio==0)
    {
        *fechaAux = fechaDeUnJugador;
        return 0;
    }
    return -1;

 }

/*
eFechaJugador introducirFechaJugador ()
{
    eFechaJugador fechaDeUnJugador;
    int validDia;
    int validMes;
    int validAnio;

    printf("Ingrese la fecha de nacimiento del jugador\n");
   // printf("Dia : ");
   validDia= getValidInt("Dia : ", "Dia no valido", &fechaDeUnJugador.dia,1,31,3 );
    //scanf("%d",&fechaDeUnJugador.dia);
   validMes= getValidInt("Mes : ", "Mes no valido", &fechaDeUnJugador.mes, 1,12,3);
   validAnio= getValidInt("Anio : ", "Anio no valido", &fechaDeUnJugador.anio,1940,2019,3  );
   // printf("Mes : ");
   // scanf("%d",&fechaDeUnJugador.mes);
    //printf("Anio : ");
    //scanf("%d",&fechaDeUnJugador.anio);

    if(validDia==0 && validMes==0 && validAnio==0)
    {
        return fechaDeUnJugador;
    }



}
*/









/** \brief busca lugar vacio en el array de jugadores, devuelve el indice del primer lugar vacio
 *
 * \param listaJugadores eJugador* array de jugadores
 * \param cantidad int cantidad de elementos del array
 * \return int el indice encontrado o -1 si no hay mas lugar
 *
 */
int buscarLugarVacioJugadores(eJugador* listaJugadores, int cantidad   )
{
    int i;
    int lugarVacioValido=0;
    int indiceEncontrado;

    for(i=0;i<cantidad;i++)
    {
        if(listaJugadores[i].estaVacioJugador==TRUE)
        {
            indiceEncontrado=i;
            lugarVacioValido=1;
            break;
        }else if(listaJugadores[i].estaVacioJugador=='\0' && lugarVacioValido==0)
        {
            indiceEncontrado=-1;
        }
    }

    return indiceEncontrado;
}







/** \brief inicializa el array de jugadores poniendo el esta vacio en true
 *
 * \param lista de array de jugadores
 * \param cantidad de elementos del array
 * \return 0 si lo realizó o -1 si no hubo una falla
 *
 */
int inicializarJugadores (eJugador* listaJugadores, int cantidad )
{
    int returnInit;
    if(listaJugadores!=NULL && cantidad==CANT_JUGADORES)
    {
        int i;
        for(i=0;i<cantidad;i++)
        {
            listaJugadores[i].estaVacioJugador=TRUE;
            returnInit = 0;
        }
    }else{
        returnInit= -1;
    }

    return returnInit;
}


void mostrarJugadores(eJugador* listaJugadores, int cantidad )
{
    printf("JUGADORES\n");
    //printf("\n\tCodigo\tApellido\tNombre\tSexo\tFecha de Nacimiento\tCodigo de Equipo\t\n\n");
    printf("\n");
    //printf("Codigo\t"); printf("Apellido\t");printf("Nombre\t");printf("Sexo\t");
    printf("Codigo "); printf("  Apellido  ");printf("  Nombre  ");printf(" Sexo ");printf("  Fecha de Nac.  ");printf(" Codigo de Equipo ");
    printf("\n");printf("\n");
    int ij;
    for(ij=0;ij<cantidad;ij++)
    {
        if(listaJugadores[ij].estaVacioJugador==FALSE)
        {
            printf("\n %3d\t %8s\t %4s\t  %2c\t   %4d/%3d/%5d\t   %3d\t \n", listaJugadores[ij].codigoJugador, listaJugadores[ij].apellidoJugador,
                   listaJugadores[ij].nombreJugador, listaJugadores[ij].sexo, listaJugadores[ij].fechaNacimiento.dia, listaJugadores[ij].fechaNacimiento.mes,
                   listaJugadores[ij].fechaNacimiento.anio, listaJugadores[ij].codigoEquipoJugador);
        }
    }
}


void mostrarUnJugador(eJugador* listaJugadores, int codigo, int cantidadJugadores)
{
    int ij;
    for(ij=0;ij<cantidadJugadores;ij++)
    {
        if( (listaJugadores[ij].estaVacioJugador==FALSE) && (listaJugadores[ij].codigoJugador==codigo) )
        {
            printf("\n %3d\t %8s\t %4s\t  %2c\t   %4d/%3d/%5d\t   %3d\t \n", listaJugadores[ij].codigoJugador, listaJugadores[ij].apellidoJugador,
                   listaJugadores[ij].nombreJugador, listaJugadores[ij].sexo, listaJugadores[ij].fechaNacimiento.dia, listaJugadores[ij].fechaNacimiento.mes,
                   listaJugadores[ij].fechaNacimiento.anio, listaJugadores[ij].codigoEquipoJugador);
        }
    }



}





void ordenarJugadoresAlfabeticamente(eJugador* listaJugadores, int cantidad)
{
    int i;
    int j;
    eJugador auxJugador;

    for(i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if( ( strcmp(listaJugadores[i].apellidoJugador,listaJugadores[j].apellidoJugador) > 0 )   )
            {
                auxJugador= listaJugadores[i];
                listaJugadores[i]= listaJugadores[j];
                listaJugadores[j]= auxJugador;
            }//if( ( strcmp(listaEquipos[i].nombre,listaEquipos[j].nombre) > 0 )



            if(  ( strcmp(listaJugadores[i].apellidoJugador,listaJugadores[j].apellidoJugador) == 0 )    )
            {
                if(   ( strcmp(listaJugadores[i].nombreJugador,listaJugadores[j].nombreJugador) > 0 ) ){
                    auxJugador= listaJugadores[i];
                    listaJugadores[i]= listaJugadores[j];
                    listaJugadores[j]= auxJugador;

                  }
            }
        }//for(j=i-1;i<cantidad;j++)
    }//for(i=0;i<cantidad-1;i++)
}






int bajaJugadorConfirm (eJugador* listaJugadores, int cantidad, int codigo)
{
    int i;

    char confirmaSN;
    //int retorno;
    //printf("EL CODIGO QUE LE LLEGA A LA FUNCION ES %d\n\n",codigo);


    if(listaJugadores!=NULL && cantidad==CANT_JUGADORES)
    {
        for(i=0;i<cantidad;i++)
        {
            //printf("LOS CODIGOS QUE SE ESTAN MANEJANDO ACA SON : %d\n\n", listaEquipos[i].codigoEquipo);

            if(listaJugadores[i].estaVacioJugador==FALSE)
            {


                if(listaJugadores[i].codigoJugador == codigo )
                {
                    printf(" Esta a punto de dar de baja a %s  , %s ", listaJugadores[i].apellidoJugador , listaJugadores[i].nombreJugador);
                    confirmaSN=getChar("Confirma? [ S / N ]\n");
                    if(confirmaSN=='s' || confirmaSN=='S')
                    {
                       listaJugadores[i].estaVacioJugador=TRUE;
                        return 0;
                        break;
                    }else{
                        return -1;
                        break;
                    }

                }




            }else if(listaJugadores[cantidad].estaVacioJugador==FALSE){
               printf("\nNo se encuentra ese codigo \n");
                return -1;
                break;
            }
        }//FOR
    }

    return -1;

}











int sacarPromedioEdadesJugadores( int codigoEquipo, int cantidadEquipos , eJugador* listaJugadores, int cantidadJugadores)
{

    int j;
    int edadJugador;
    int acumuladorEdades=0;
    int promedioEdades=0;
    int cantidadJugadoresDelEquipo=0;


        for(j=0;j<cantidadJugadores;j++)
        {
            if(codigoEquipo == listaJugadores[j].codigoEquipoJugador)
            {
                 edadJugador= 2019 - listaJugadores[j].fechaNacimiento.anio;
                 //printf("Nacio en el anio %d  \n",listaJugadores[j].fechaNacimiento.anio);
                 //printf("la edad de este jugador %s %s  me esta dando : %d \n", listaJugadores[j].nombreJugador,listaJugadores[j].apellidoJugador,edadJugador);
                cantidadJugadoresDelEquipo++;
                acumuladorEdades=acumuladorEdades + edadJugador;

            }

        }

    //printf("El la suma de edades esta en : %d ",acumuladorEdades);
    promedioEdades=acumuladorEdades/cantidadJugadoresDelEquipo;


    //printf("El promedio de edades de este equipo es de : %d ",promedioEdades);

    return promedioEdades;



}

void equipoMasJoven(/*int codigoEquipo,*/ int cantidadEquipos, eJugador* listaJugadores, int cantidadJugadores , eEquipo* listaEquipos )
{
    int i;
    int indiceEquipoMasJoven;
    int min=110;
    int promedio;

    for(i=0;i<cantidadEquipos;i++)
    {
        promedio=sacarPromedioEdadesJugadores(listaJugadores[i].codigoEquipoJugador,cantidadEquipos,listaJugadores,cantidadJugadores);
        if(promedio<min)
        {
            min=promedio;
            indiceEquipoMasJoven=i;

        }

    }
    printf("El equipo mas joven es el :  ");
    mostrarUnEquipo(listaEquipos,cantidadEquipos,listaJugadores[indiceEquipoMasJoven].codigoEquipoJugador);
    printf("  con un promedio de %d ", min);








}


