#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "partido.h"
#include "funciones.h"


#define CANT_EQUIPOS 10
#define CANT_JUGADORES 16
#define CANT_PARTIDOS 10
#define CANT_REFERIS 10

#define TRUE 0
#define FALSE 1


void hardcodeoPartidos(ePartido* listaPartidos, int cantidad)
{
    int codigoPartido[]={1,2,3,4,5,6,7,8,9,10};
    int codigoVisitante[]={8,9,10,4,6,7,3,4,10};
    int codigoLocal[]={4,2,5,2,5,7,3,10,9,8};
    int codigoReferi[]={2,1,3,2,4,5,3,3,1,3};


    int dia[]={20,5,16,2,3,3,5,6,7};
    int mes[]={8,3,4,5,6,6,6,6,6,6};
    int anio[]={2019,2019,2019,2019,2019,2019,2019,2019,2019,2019};

    int i;

    for(i=0;i<cantidad;i++)
    {
        listaPartidos[i].codigoPartido=codigoPartido[i];
        listaPartidos[i].codigoVisitante=codigoVisitante[i];
        listaPartidos[i].codigoLocal=codigoLocal[i];
        listaPartidos[i].codigoReferi=codigoReferi[i];

        listaPartidos[i].fechaPartido.dia=dia[i];
        listaPartidos[i].fechaPartido.mes=mes[i];
        listaPartidos[i].fechaPartido.anio=anio[i];

        listaPartidos[i].estaVacioPartido=FALSE;

    }

}


 int introducirFechaPartido( eFechaPartido * fechaAux)
 {
    eFechaPartido fechaPartido;
    int validDia;
    int validMes;
    int validAnio;
    printf("Ingrese la fecha del partido\n");

   validDia= getValidInt("Dia : ", "Dia no valido", &fechaPartido.dia,1,31,3 );
   validMes= getValidInt("Mes : ", "Mes no valido", &fechaPartido.mes, 1,12,3 );
   validAnio= getValidInt("Anio : ", "Anio no valido", &fechaPartido.anio,1940,2019,3  );

   if(validDia==0 && validMes==0 && validAnio==0)
    {
        *fechaAux = fechaPartido;
        return 0;
    }
    return -1;

 }


 int agregarPartido(ePartido* listaPartidos, int cantidad, eFechaPartido fechaPartido, int codigoPartido, int codigoVisitante, int codigoLocal, int codigoReferi ,  int lugarVacio )
 {
     if(listaPartidos!=NULL && cantidad==CANT_PARTIDOS)
    {
        listaPartidos[lugarVacio].codigoPartido=codigoPartido;
        listaPartidos[lugarVacio].codigoVisitante=codigoVisitante;
        listaPartidos[lugarVacio].codigoLocal=codigoLocal;
        listaPartidos[lugarVacio].codigoReferi=codigoReferi;
        listaPartidos[lugarVacio].fechaPartido=fechaPartido;
        listaPartidos[lugarVacio].estaVacioPartido=FALSE;

        return 0;
    }

    return -1;
 }



 int inicializarPartidos(ePartido* listaPartidos, int cantidadPartidos)
 {

    int returnInit;

    if(listaPartidos!=NULL && cantidadPartidos==CANT_PARTIDOS)
    {
        int i;
        for(i=0;i<cantidadPartidos;i++)
        {
            listaPartidos[i].estaVacioPartido=TRUE;
            returnInit=0;
        }
    }else{
        returnInit= -1;
    }

    return returnInit;
 }






int buscarlugarVacioPartidos(ePartido* listaPartidos, int cantidadPartidos   )
{
    int i;
    int lugarVacioValido=0;
    int indiceEncontrado;

    for(i=0;i<cantidadPartidos;i++)
    {
        if(listaPartidos[i].estaVacioPartido==TRUE)
        {
            indiceEncontrado=i;
            lugarVacioValido=1;
            break;
        }else if(listaPartidos[i].estaVacioPartido=='\0' && lugarVacioValido==0)
        {
            indiceEncontrado=-1;
        }
    }

    return indiceEncontrado;
}











/*


void mostrarPartidos (ePartido* listaPartidos, int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        printf("El dia %d / %d / %d juegan : \n", listaPartidos[i].fechaPartido.dia, listaPartidos[i].fechaPartido.mes, listaPartidos[i].fechaPartido.anio);


        printf(" %s  (local)  vs.  %s (visitante) \n", listaPartidos[i].)
    }
}
*/

void organizarPartidosxFecha(ePartido* listaPartidos, int cantidad)
{
    int i;
    int j;
    ePartido auxPartido;

     for(i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if(listaPartidos[i].fechaPartido.anio > listaPartidos[j].fechaPartido.anio)
            {
                auxPartido=listaPartidos[i];
                listaPartidos[i]=listaPartidos[j];
                listaPartidos[j]=auxPartido;
            }

            if(listaPartidos[i].fechaPartido.anio == listaPartidos[j].fechaPartido.anio)
            {
                if(listaPartidos[i].fechaPartido.mes > listaPartidos[j].fechaPartido.mes)
                {
                     auxPartido=listaPartidos[i];
                    listaPartidos[i]=listaPartidos[j];
                    listaPartidos[j]=auxPartido;
                }

            }

            if(listaPartidos[i].fechaPartido.mes == listaPartidos[j].fechaPartido.mes)
            {
                if(listaPartidos[i].fechaPartido.dia > listaPartidos[j].fechaPartido.dia)
                {
                     auxPartido=listaPartidos[i];
                    listaPartidos[i]=listaPartidos[j];
                    listaPartidos[j]=auxPartido;
                }
            }



        }
    }
}




int contadorPartidosReferi(ePartido* listaPartidos, int cantidadPartidos)
{
    char existe[cantidadPartidos];
    int numeroOcurrencias;
    int i;
    int maximo=0;
    int codigoReferiMaximo;

    for(i=0;i<cantidadPartidos;i++)
    {
        existe[i]=0;
    }

    for(i=0;i<cantidadPartidos;i++)
    {
        numeroOcurrencias=contadorOcurrencias(listaPartidos,existe,cantidadPartidos,listaPartidos[i].codigoReferi);
        if(numeroOcurrencias){
            existe[i] = 1;
            //printf("el codigo de referi %d aparece %d veces \n", listaPartidos[i].codigoReferi, numeroOcurrencias);

        }


        if(maximo<numeroOcurrencias)
        {
            maximo=numeroOcurrencias;

        }

         if(numeroOcurrencias){
            existe[i] = 1;
            //printf("el codigo de referi %d aparece %d veces \n", listaPartidos[i].codigoReferi, numeroOcurrencias);
            if(numeroOcurrencias==maximo){
                codigoReferiMaximo=listaPartidos[i].codigoReferi;



            }

        }


    }

    printf("Con una cantidad de : %d", maximo);

    return codigoReferiMaximo;

    //return 0;



}



int contadorOcurrencias(ePartido* listaPartidos, char existe[], int cantidad, int codigoReferi)
{
    int i;
    int contador = 0;
    for( i= 0; i< cantidad; i++)
    {
        if(listaPartidos[i].codigoReferi == codigoReferi)
        {
            if(existe[i] !=0) return 0;

            ++contador;
        }
    }
    return (contador);
}




