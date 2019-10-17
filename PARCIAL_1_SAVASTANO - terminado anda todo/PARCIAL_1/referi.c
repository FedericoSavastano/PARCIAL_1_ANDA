

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "referi.h"
#include "funciones.h"
#include "validaciones.h"
#include "equipos.h"
#include "jugadores.h"


#define CANT_REFERIS 10

#define TRUE 0
#define FALSE 1



void hardcodeoReferies (eReferi* listaReferies, int cantidad)
{

    int codigoReferi[] = {1,2,3,4,5,6,7,8,9,10};
    char apellido[] [31] = {"Asfancur","Hochbiu","Motoco","Polonio","Rubeola","Mulini","Montongo","Umpal","Ostral","Kudasai"};
    char nombre[] [31] ={"Marcelino","Marcelina","Marcelo","Marcela","Marce","Marceimar","Marcecho","Marchelo","Marcerdo","Marceceloloide"};
    char sexo[] ={'M','F','M','F','M','M','M','M','F'};
    char email[] [31] ={"fulbito@altavista.com","pocopipi@yahoo.com","arbitruqui@ormail.com","marpolonio@gmail.com","marponio@gmail.com","marolonio@gmail.com","maio@gmail.com","marpoo@gmail.com","marlonio@gmail.com","maronio@gmail.com"};
    /*
    int dia[]={31};
    int mes[]={10};
    int anio[]={1992};

    */

    int i;

    for(i=0;i<cantidad;i++)
    {

        listaReferies[i].codigoReferi=codigoReferi[i];
        strcpy(listaReferies[i].apellido,apellido[i]);
        strcpy(listaReferies[i].nombre,nombre[i]);
        listaReferies[i].sexo=sexo[i];
        strcpy(listaReferies[i].email,email[i]);
        listaReferies[i].fechaNacimiento.dia=10;
        listaReferies[i].fechaNacimiento.mes=3;
        listaReferies[i].fechaNacimiento.anio=1998;

        listaReferies[i].estaVacioReferi=FALSE;


    }


    printf("Hardcodeo de referis realizado\n");

}



int inicializarReferis (eReferi * listaReferis, int cantidadReferis)
{
    int returnInit;

    if(listaReferis!=NULL && cantidadReferis==CANT_REFERIS)
    {
        int i;
        for(i=0;i<cantidadReferis;i++)
        {
            listaReferis[i].estaVacioReferi=TRUE;
            returnInit=0;
        }
    }else{
        returnInit= -1;
    }

    return returnInit;

}




int buscarLugarVacioReferis(eReferi* listaReferis, int cantidad   )
{
    int i;
    int lugarVacioValido=0;
    int indiceEncontrado;

    for(i=0;i<cantidad;i++)
    {
        if(listaReferis[i].estaVacioReferi==TRUE)
        {
            indiceEncontrado=i;
            lugarVacioValido=1;
            break;
        }else if(listaReferis[i].estaVacioReferi=='\0' && lugarVacioValido==0)
        {
            indiceEncontrado=-1;
        }
    }

    return indiceEncontrado;
}














int introducirFechaReferi( eFechaReferi * fechaAux)
 {
    eFechaReferi fechaDeUnReferi;
    int validDia;
    int validMes;
    int validAnio;
    printf("Ingrese la fecha de nacimiento del referi \n");

   validDia= getValidInt("Dia : ", "Dia no valido", &fechaDeUnReferi.dia,1,31,3 );
   validMes= getValidInt("Mes : ", "Mes no valido", &fechaDeUnReferi.mes, 1,12,3);
   validAnio= getValidInt("Anio : ", "Anio no valido", &fechaDeUnReferi.anio,1940,2019,3  );

   if(validDia==0 && validMes==0 && validAnio==0)
    {
        *fechaAux = fechaDeUnReferi;
        return 0;
    }
    return -1;

 }




int agregarReferi ( eReferi* listaReferis, int cantidadReferis, int lugarVacioReferi, int codigoReferi, char apellido[], char nombre[], char sexo, char email[], eFechaReferi fechaReferi)
{
    if(listaReferis!=NULL && cantidadReferis==cantidadReferis)
    {
        ponerMayusculas(nombre);
        ponerMayusculas(apellido);

    listaReferis[lugarVacioReferi].codigoReferi=codigoReferi;
    strcpy(listaReferis[lugarVacioReferi].apellido,apellido);
    strcpy(listaReferis[lugarVacioReferi].nombre,nombre);
    listaReferis[lugarVacioReferi].sexo=sexo;
    strcpy(listaReferis[lugarVacioReferi].email,email);

    listaReferis[lugarVacioReferi].fechaNacimiento=fechaReferi;

    listaReferis[lugarVacioReferi].estaVacioReferi=FALSE;
     return 0;
    }

    return -1;




}







int encontrarReferixCodigo(eReferi* listaReferis, int cantidad, int codigo)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(codigo == listaReferis[i].codigoReferi)
        {
            return i;
            break;
        }
    }

    return -1;
}



void mostrarUnReferi(eReferi* listaReferis, int cantidad, int codigo)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(codigo == listaReferis[i].codigoReferi)
        {
            printf("%s %s", listaReferis[i].nombre, listaReferis[i].apellido);
        }
    }

}



void mostrarListaReferis(eReferi* listaReferis, int cantidad)
{
    int ir;
    printf("Lista de referis\n\n");
    for(ir=0;ir<cantidad;ir++)
    {
        if(listaReferis[ir].estaVacioReferi==FALSE){
        printf("\n");
        printf("Codigo: %d\n",listaReferis[ir].codigoReferi);
        printf("Apellido: %s\n",listaReferis[ir].apellido);
        printf("Nombre: %s\n",listaReferis[ir].nombre);
        printf("Email: %s\n",listaReferis[ir].email);
        printf("Sexo : %c\n",listaReferis[ir].sexo);
        printf("Fecha nac. : %d/%d/%d \n",listaReferis[ir].fechaNacimiento.dia,listaReferis[ir].fechaNacimiento.mes,listaReferis[ir].fechaNacimiento.anio);
        printf("\n");printf("\n");
        }
    }
}


