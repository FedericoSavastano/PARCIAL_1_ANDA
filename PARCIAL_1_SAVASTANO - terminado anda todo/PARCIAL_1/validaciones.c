#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "equipos.h"
#include "funciones.h"
#include "jugadores.h"
#include "partido.h"
#include "referi.h"
#include "validaciones.h"

#define CANT_EQUIPOS 10
#define CANT_JUGADORES 16
#define CANT_PARTIDOS 10
#define CANT_REFERIS 10
#define MAX_EQUIPOS 11
#define MAX_JUGADORES 17
#define MAX_REFERIS 11
#define MAX_PARTIDOS 11

#define TRUE 0
#define FALSE 1

void mostrarJugadoresPorEquipo(eEquipo* listaEquipos, eJugador* listaJugadores, int cantidadEquipos, int cantidadJugadores);
void mostrarJugadoresxEquipo( eEquipo* listaEquipos, eJugador* listaJugadores, int cantidadEquipos, int cantidadJugadores   );
void mostrarPartidos (ePartido* listaPartidos, eEquipo* listaEquipos, eReferi* listaReferis , int cantidadPartidos, int cantidadEquipos, int cantidadReferis);


void mostraparti(ePartido* listaPartidos,int cantidadPartidos);

void ingresarNombreMostrarJugador(eJugador* listaJugadores, int cantidadJugadores, eEquipo* listaEquipos, int cantidadEquipos );


void ingresarSoloApellidoMostrarJugador(eJugador* listaJugadores, int cantidadJugadores, eEquipo* listaEquipos, int cantidadEquipos );


void funcionIngresaJugadorMuestraTodo(eJugador* listaJugadores, int cantidadJugadores, eEquipo* listaEquipos, int cantidadEquipos  );



void funcionIngresaFechaMuestraTodo(ePartido* listaPartidos, int cantidadPartidos, eEquipo* listaEquipos, int cantidadEquipos , eReferi* listaReferis, int cantidadReferis );

void sumarnumero(int *numerogarlompa)
{
    *numerogarlompa=*numerogarlompa+8;
    printf("Tu numero garlompa en la funcion es %d", *numerogarlompa);
}

void comosifueseelmain()
{
    int numeroGarlompa;
    numeroGarlompa=2;

    sumarnumero(&numeroGarlompa);

    printf("\nEl numero garlompa en el pseudo main es %d", numeroGarlompa );


}


int inicializarEquipos (eEquipo listaEquipos[], int cantidad)
{
    int returnInit;
    if(listaEquipos!=NULL && cantidad==CANT_EQUIPOS)
    {
        int i;
        for(i=0;i<cantidad;i++)
        {
            listaEquipos[i].estaVacioEquipo=TRUE;
            returnInit = 0;
        }
    }else{
        returnInit= -1;
    }

    return returnInit;
}


int buscarLugarVacioEquipos(eEquipo* listaEquipos, int cantidad   )
{
    int i;
    int lugarVacioValido=0;
    int indiceEncontrado;

    for(i=0;i<cantidad;i++)
    {
        if(listaEquipos[i].estaVacioEquipo==TRUE)
        {
            indiceEncontrado=i;
            lugarVacioValido=1;
            break;
        }else if(listaEquipos[i].estaVacioEquipo=='\0' && lugarVacioValido==0)
        {
            indiceEncontrado=-1;
        }
    }

    return indiceEncontrado;
}













void mostrarMenu()
{
    int opcionMenu;
    int codigoEquiposAcumulador=0;
    int codigoJugadoresAcumulador=0;
    int codigoPartidosAcumulador=0;
    int codigoReferiAcumulador=0;


    eEquipo listaEquipos[CANT_EQUIPOS];
    int validarInicializarEquipos;
    int lugarVacioEquipo;
    //int validarNombreEquipo;
    //int validarLocalidadEquipo;
    //int validarEquipo;
    int ingresoEquipoValidado;
    int auxCodigoEquipo;
    int auxIndiceEquipo;

    eJugador listaJugadores[CANT_JUGADORES];
    int validarInicializarJugadores;
    int lugarVacioJugadores;

    int ingresoJugadorValidado;
    int auxCodigoJugador;
    int auxIndiceJugador;




    int referi1;
    int promedioedades;

    eReferi listaReferis[CANT_REFERIS];
    int validarInicializarReferis;
    int lugarVacioReferis;

    ePartido listaPartidos[CANT_PARTIDOS];
    int validarInicializarPartidos;
    int lugarVacioPartidos;


    int indiceMasLargo;

    char confirmaSN;


    validarInicializarEquipos=inicializarEquipos(listaEquipos,CANT_EQUIPOS);
    validarInicializarJugadores=inicializarJugadores(listaJugadores,CANT_JUGADORES);
    validarInicializarReferis=inicializarReferis(listaReferis,CANT_REFERIS);
    validarInicializarPartidos=inicializarPartidos(listaPartidos,CANT_PARTIDOS);
    /**GUARDA PUEDE QUE HAYA QUE VALIDAR TODOS Y HACER QUE EL IF RECONOZCA TODOS PARA EMPEZAR**/



    if (  (validarInicializarEquipos==0)&&(validarInicializarJugadores==0) )
           if( /*(validarInicializarPartidos==0) && */(validarInicializarReferis==0) ){

        imprimirMenu();
        opcionMenu=getInt("\nElija una opcion : \n");
            fflush(stdin);

        while(opcionMenu!=17)
        {
            if(opcionMenu>0 && opcionMenu<17)
            {
                switch(opcionMenu)
                {
                case 1:
                    /**EQUIPOS**/

                    hardcodeoEquipos(listaEquipos,CANT_EQUIPOS);
                    printf("hardcodeo de equipos hecho");
                    ingresoEquipoValidado=1;
                    //validarInicializarEquipos=inicializarEquipos(listaEquipos,CANT_EQUIPOS);
                    break;

                    /*
                    printf("\nDar de alta un equipo\n");
                    confirmaSN=getChar("Ingresar un equipo? [ S / N ] \n");

                    if(confirmaSN=='s' || confirmaSN=='S'){
                        lugarVacioEquipo=buscarLugarVacioEquipos(listaEquipos,CANT_EQUIPOS);
                        printf("lugar vacio equipo es : %d\n",lugarVacioEquipo);
                        if(lugarVacioEquipo>-1 && listaEquipos!=NULL && CANT_EQUIPOS<MAX_EQUIPOS)
                        {

                            //int auxCodigoEquipo;
                            char auxNombreEquipo[51];
                            char auxLocalidadEquipo[33];

                            //validarNombreEquipo=getValidString("Ingrese el nombre del equipo : ", "nombre no valido ", "nombre demasiado largo ",
                                                         //      auxNombreEquipo,51,3);
                           // validarLocalidadEquipo=getValidString("Ingrese la localidad del equipo : ", "Localidad no valida ", "Nombre demasiado largo ",
                                                             //     auxLocalidadEquipo,51,3);

                            if( ( getValidString(" Ingrese el nombre del equipo : ", " nombre no valido \n", "nombre demasiado largo \n",
                                                               auxNombreEquipo,51,3) )==0

                               && (  getValidString(" Ingrese la localidad del equipo : ", "Localidad no valida \n", "Nombre demasiado largo \n",
                                                                  auxLocalidadEquipo,51,3) )==0)
                            {
                                auxCodigoEquipo=incrementarID(&codigoEquiposAcumulador);
                               // validarEquipo= agregarEquipo(listaEquipos,CANT_EQUIPOS,auxCodigoEquipo,auxNombreEquipo,auxLocalidadEquipo,lugarVacioEquipo);
                                if(  ( agregarEquipo(listaEquipos,CANT_EQUIPOS,auxCodigoEquipo,auxNombreEquipo,auxLocalidadEquipo,lugarVacioEquipo)  ) ==0)
                                {
                                    ingresoEquipoValidado=1;
                                    listaEquipos[lugarVacioEquipo].estaVacioEquipo=FALSE;
                                    printf("\n");
                                    printf("Equipo agregado exitosamente!");
                                    printf("\n\n");
                                    break;
                                }else{
                                printf("No se pudo agregar a ese equipo\n");
                                break;
                                }//if(validarEquipo==0)

                            }else{
                                printf("No se pudo agregar a ese equipo\n");
                                break;
                            }//if(validarNombreEquipo==0 && validarLocalidadEquipo==0)



                        }else{
                            printf("\nNo hay mas lugar para agregar equipos\n");
                            break;
                        }//if(validarNombreEquipo==0 && validarLocalidadEquipo==0)



                        /** PONER UN FLAG DE QUE SE CARGO ALGO PARA PASAR AL MODIFICAR Y DEMAS*/
                        /*int i;
                        for(i=0;i<CANT_EQUIPOS;i++)
                        {
                            printf("\nINGRESAMO UN EQUIPO NO MA\n");

                            printf("\nEl esta vacio de los equipos es : %d \n",listaEquipos[i].estaVacioEquipo);


                            //break;
                        }
                        //*
                        /** PONER UN FLAG DE QUE SE CARGO ALGO PARA PASAR AL MODIFICAR Y DEMAS
                    }else{
                       printf( "Cancelado el ingreso de equipo" );
                        break;
                    }//(confirmaSN=='s' || confirmaSN=='S')

                */

                    //break;

                case 2:
                    if(ingresoEquipoValidado==1)
                    {
                        ordenarEquiposAlfabeticamente(listaEquipos,CANT_EQUIPOS);
                        mostrarEquipos(listaEquipos,CANT_EQUIPOS);
                        break;

                    }else{
                        printf("\nPrimero ingrese un equipo\n");
                        break;
                    }//if(ingresoEquipoValidado==1)




                    break;
                case 3:
                    if(ingresoEquipoValidado==1)
                    {
                        ordenarEquiposAlfabeticamente(listaEquipos,CANT_EQUIPOS);
                        mostrarEquipos(listaEquipos,CANT_EQUIPOS);


                       auxCodigoEquipo=getInt("Elija el codigo del equipo a modificar : ");

                       auxIndiceEquipo=buscarEquipoPorCodigo(listaEquipos,CANT_EQUIPOS,auxCodigoEquipo);

                      if (  (  modificarEquipo(listaEquipos,auxIndiceEquipo ) ==0    ) )
                      {
                          printf("Modificacion Terminada");
                          break;
                      }else{
                        printf("no se modifico una chorga");
                        break;
                      }

                    }



                    break;
                case 4:
                     if(ingresoEquipoValidado==1)
                    {

                        ordenarEquiposAlfabeticamente(listaEquipos,CANT_EQUIPOS);
                        mostrarEquipos(listaEquipos,CANT_EQUIPOS);
                        if(getValidInt("Ingrese el codigo del equipo a dar de baja [x para cancelar] : ","Codigo no valido ", &auxCodigoEquipo,0,CANT_EQUIPOS,3)==0)
                        {
                            printf("El codigo que elegi para dar de baja es el %d \n",auxCodigoEquipo);

                            if(bajaEquipoConfirm(listaEquipos,CANT_EQUIPOS,auxCodigoEquipo)==0)
                            {
                                printf("Baja exitosa ");
                                break;
                            }else{
                                printf("baja fallida ");
                                break;
                            }

                        }else{
                            printf("\n No se pudo hacer la baja \n");
                        }
                        break;

                    }else{
                        printf("\nPrimero ingrese un equipo \n");
                        break;
                    }//if(ingresoEquipoValidado==1)

                    break;




                case 5:
                    /**JUGADORES**/
                    if(ingresoEquipoValidado==1)
                {
                    hardcodeoJugadores(listaJugadores,CANT_JUGADORES);
                    printf("Hardcodeo de jugadores hecho");
                    break;
                }else{printf("Primero ingrese un equipo"); break;}


                    /*


                if(ingresoEquipoValidado==1)
                {
                    printf("\nDar de alta un Jugador\n");
                    confirmaSN=getChar("Ingresar un jugador? [ S / N ] \n");

                    if(confirmaSN=='s' || confirmaSN=='S'){
                        lugarVacioJugadores=buscarLugarVacioJugadores(listaJugadores,CANT_JUGADORES);
                        printf("lugar vacio jugadores es : %d\n",lugarVacioJugadores);

                        if(lugarVacioJugadores>-1 && listaJugadores!=NULL && CANT_JUGADORES<MAX_JUGADORES)
                        {

                            int auxCodigoJugador;
                            char auxApellidoJugador[31];
                            char auxNombreJugador[31];
                            int auxCodigoEquipoJugador; //REVISAR SI ESTO TIENE QUE ESTAR LIGADO AL ESTRUC DE EQUIPOS
                            char auxSexo;
                            //int codigoEquipo;
                            eFechaJugador auxFechaNacimiento;

                            if( getValidString( "Ingrese el apellido del jugador : ", "Apellido no valido \n", "Apellido demasiado largo \n", auxApellidoJugador, 31,3 ) ==0
                                    && ( getValidString( "Ingrese el nombre del jugador : ", " Nombre no valido \n", " Nombre demasiado largo \n", auxNombreJugador,31,3)  ==0 )

                            ){
                                auxSexo= getChar("Ingrese el sexo del jugador M o F : ");
                                if(validSexo(auxSexo)==0)
                                {
                                    printf("CULOOOO");
                                    if(   introducirFechaJugador2(&auxFechaNacimiento) ==0  )
                                    {
                                        printf("estAMOS ACA");
                                        mostrarEquipos(listaEquipos,CANT_EQUIPOS);
                                        if(getValidInt("Ingrese el codigo del equipo al que el jugador pertenece : ", "Codigo no valido ",&auxCodigoEquipoJugador,1,CANT_EQUIPOS,3) == 0 )
                                       if(buscarEquipoPorCodigo(listaEquipos,CANT_EQUIPOS,auxCodigoEquipoJugador)>-1 )
                                       {
                                                int mostrarIndice;
                                                mostrarIndice=buscarEquipoPorCodigo(listaEquipos,CANT_EQUIPOS,auxCodigoEquipoJugador);
                                                printf("OK pertenece al : %s ", listaEquipos[mostrarIndice].nombre);

                                                confirmaSN=getChar("Ingresar un jugador? [ S / N ] \n");

                                                    if(confirmaSN=='s' || confirmaSN=='S'){
                                           auxCodigoJugador=incrementarID(&codigoJugadoresAcumulador);

                                           if (agregarJugador(listaJugadores,CANT_JUGADORES,auxCodigoJugador,auxApellidoJugador,auxNombreJugador,
                                                          auxSexo,auxCodigoEquipoJugador,auxFechaNacimiento,lugarVacioJugadores) == 0 )
                                                          {
                                                              printf("\n Alta de jugador realizada exitosamente \n\n");
                                                              break;
                                                          }else { printf("No se pudo cargar al jugador \n"); break;}
                                                    }else{printf("Carga cancelada "); break;}



                                       }//if(buscarEquipoPorCodigo(listaEquipos,CANT_EQUIPOS,codigoEquipo)>-1 )

                                    }else{printf(" AAAAA Fecha no valida AAAAA");break;}//if(  ( introducirFechaJugador2(auxFechaNacimiento) ) ==0  )




                            }else{printf("Sexo no valido");break;}//if(auxSexo=='m' || auxSexo=='M' || auxSexo=='f' ||auxSexo'F')
                            }else{printf("Nombre no valido");break;}//if( getValidString( "Ingrese el apellido del jugador : ", "Apellido no valido \n", "Apellido demasiado largo \n", auxApellidoJugador, 31,3 ) ==0
                                   // && ( getValidString( "Ingrese el nombre del jugador : ", " Nombre no valido \n", " Nombre demasiado largo \n", auxNombreJugador,31,3)  ==0 )

                        }else{printf("no hay mas lugar");break;}//if(lugarVacioJugadores>-1 && listaJugadores!=NULL && CANT_JUGADORES<MAX_JUGADORES)
                    }else{printf("saliendo"); break;}//if(confirmaSN=='s' || confirmaSN=='S')










                        break;

                }else//if(ingresoEquipoValidado==1)
                    {printf("Primero ingrese un equipo\n\n");
                    break;}


                    */

                case 6:
                    printf(" MOSTRAR JUGADORES ");

                    if(ingresoEquipoValidado==1)
                    {
                        ordenarJugadoresAlfabeticamente(listaJugadores,CANT_JUGADORES);
                        mostrarJugadores(listaJugadores,CANT_JUGADORES);
                        break;

                    }else{
                        printf("\nPrimero ingrese un equipo\n");
                        break;
                    }//if(ingresoEquipoValidado==1)


                    break;

                case 7:
                     if(ingresoEquipoValidado==1)
                    {

                        ordenarJugadoresAlfabeticamente(listaJugadores,CANT_JUGADORES);
                        mostrarJugadores(listaJugadores,CANT_JUGADORES);
                        if(getValidInt("Ingrese el codigo del jugador a dar de baja [x para cancelar] : ","Codigo no valido ", &auxCodigoJugador,0,500,3)==0)
                        {
                            printf("El codigo que elegi para dar de baja es el %d \n",auxCodigoJugador);

                            if(bajaJugadorConfirm(listaJugadores,CANT_JUGADORES,auxCodigoJugador)==0)
                            {
                                printf("Baja exitosa ");
                                break;
                            }else{
                                printf("baja fallida ");
                                break;
                            }

                        }else{
                            printf("\n No se pudo hacer la baja \n");
                        }
                        break;

                    }else{
                        printf("\nPrimero ingrese un equipo \n");
                        break;
                    }//if(ingresoEquipoValidado==1)



                    break;



                case 8:

                    hardcodeoReferies(listaReferis,CANT_REFERIS);
                    printf("Referis\n");
                    for(int ir=0;ir<CANT_REFERIS;ir++)
                    {
                        printf("\n");
                        printf("Codigo: %d\n",listaReferis[ir].codigoReferi);
                        printf("Apellido: %s\n",listaReferis[ir].apellido);
                        printf("Nombre: %s\n",listaReferis[ir].nombre);
                        printf("Email: %s\n",listaReferis[ir].email);
                        printf("Sexo : %c\n",listaReferis[ir].sexo);
                        printf("Fecha nac. : %d/%d/%d \n",listaReferis[ir].fechaNacimiento.dia,listaReferis[ir].fechaNacimiento.mes,listaReferis[ir].fechaNacimiento.anio);
                        printf("\n");printf("\n");
                    }




                /*
                    if(ingresoEquipoValidado==1)
                    {
                        printf("\nDar de alta un Referi\n");
                        confirmaSN=getChar("Ingresar un referi? [ S / N ] \n");

                        if(confirmaSN=='s' || confirmaSN=='S'){
                            lugarVacioReferis=buscarLugarVacioReferis(listaReferis,CANT_REFERIS);
                            printf("lugar vacio referis es : %d\n",lugarVacioReferis);

                            if(lugarVacioReferis>-1 && listaReferis!=NULL && CANT_REFERIS<MAX_REFERIS)
                            {
                                int auxCodigoReferi;
                                char auxApellidoReferi[31];
                                char auxNombreReferi[31];
                                char auxSexo;
                                char auxEmailReferi[31];
                                //int codigoEquipo;
                                eFechaReferi auxFechaNacimiento;

                                if( getValidString( "Ingrese el apellido del referi : ", "Apellido no valido \n", "Apellido demasiado largo \n", auxApellidoReferi, 31,3 ) ==0
                                        && ( getValidString( "Ingrese el nombre del referi : ", " Nombre no valido \n", " Nombre demasiado largo \n", auxNombreReferi,31,3)  ==0 )

                                ){
                                    auxSexo= getChar("Ingrese el sexo del referi M o F : ");
                                    if(validSexo(auxSexo)==0 && introducirFechaReferi(&auxFechaNacimiento)==0)
                                    {
                                        getEmail(auxEmailReferi,31);

                                        confirmaSN=getChar("Ingresar al referi? [ S / N ] \n");

                                        if(confirmaSN=='s' || confirmaSN=='S'){
                                           auxCodigoReferi=incrementarID(&codigoReferiAcumulador);

                                           if (agregarReferi(listaReferis,CANT_REFERIS,lugarVacioReferis,auxCodigoReferi,auxApellidoReferi,auxNombreReferi,
                                                             auxSexo,auxEmailReferi,auxFechaNacimiento) == 0 )
                                                          {
                                                              printf("\n Alta de referi realizada exitosamente \n\n");
                                                              break;

                                                          }else { printf("No se pudo cargar al referi \n"); break;}
                                                    }else{printf("Carga cancelada "); break;}

                                    }else { printf("No se pudo cargar al referi \n"); break;}
                                 }else { printf("No se pudo cargar al referi \n"); break;}
                            }else { printf("No se pudo cargar al referi \n"); break;}


                            }else{printf("Carga cancelada "); break;}
                    }else { printf("No se pudo cargar al referi \n"); break;}


                    */








                    break;
                case 9:

                    hardcodeoPartidos(listaPartidos,CANT_PARTIDOS);
                    printf("hardcodeo de partidos hecho\n\n");

                    /*
                    if(ingresoEquipoValidado==1)
                    {
                        printf("\nDar de alta un Partido\n");
                        confirmaSN=getChar("Ingresar un partido? [ S / N ] \n");

                        if(confirmaSN=='s' || confirmaSN=='S'){
                            lugarVacioPartidos=buscarlugarVacioPartidos(listaPartidos,CANT_PARTIDOS);
                            printf("lugar vacio partidos es : %d\n",lugarVacioPartidos);

                            if(lugarVacioPartidos>-1 && listaPartidos!=NULL && CANT_PARTIDOS<MAX_PARTIDOS)
                            {
                                int auxCodigoPartido;
                                int auxCodigoVisitante;
                                int auxCodigoLocal;
                                int auxCodigoReferi;

                                int auxIndiceEquipoVisitante;
                                int auxIndiceEquipoLocal;
                                int auxIndiceReferi;
                                eFechaPartido auxFechaPartido;

                                mostrarEquipos(listaEquipos,CANT_EQUIPOS);

                                if( (( getValidInt("Ingrese el codigo del equipo visitante : ","Codigo no valido ",&auxCodigoVisitante,0,CANT_EQUIPOS,3) )== 0 )
                                   &&  (( getValidInt("Ingrese el codigo del equipo local : ","Codigo no valido ",&auxCodigoLocal,0,CANT_EQUIPOS,3) )== 0 )  )
                                {
                                    auxIndiceEquipoVisitante = buscarEquipoPorCodigo(listaEquipos,CANT_EQUIPOS,auxCodigoVisitante);
                                        auxIndiceEquipoLocal = buscarEquipoPorCodigo(listaEquipos,CANT_EQUIPOS,auxCodigoLocal);

                                    if( (auxIndiceEquipoVisitante>-1) && (auxIndiceEquipoLocal>-1) ){
                                    if(auxIndiceEquipoLocal!=auxIndiceEquipoVisitante){
                                    {
                                       mostrarListaReferis(listaReferis,CANT_REFERIS);

                                       if((getValidInt(" Ingrese el codigo del referi : ", "Codigo no valido ",&auxCodigoReferi,0,CANT_REFERIS,3))==0 )
                                       {
                                           auxIndiceReferi=encontrarReferixCodigo(listaReferis,CANT_REFERIS,auxCodigoReferi);

                                           if(auxIndiceReferi>-1)
                                           {
                                              if( introducirFechaPartido(&auxFechaPartido) == 0 )

                                                printf("\n\nEl dia %d / %d / %d \n",auxFechaPartido.dia, auxFechaPartido.mes, auxFechaPartido.anio);
                                               printf("\n\n Se enfrentaran %s ( local ) vs.  %s  ( visitante )", listaEquipos[auxIndiceEquipoLocal].nombre, listaEquipos[auxIndiceEquipoVisitante].nombre);
                                               printf("\n Seran dirigidos por %s  %s \n", listaReferis[auxIndiceReferi].nombre, listaReferis[auxIndiceReferi].apellido);
                                               confirmaSN=getChar("\nIngresar el partido? [ S / N ] \n");

                                                if(confirmaSN=='s' || confirmaSN=='S'){

                                                        auxCodigoPartido=incrementarID(&codigoPartidosAcumulador);

                                                        if((agregarPartido(listaPartidos,CANT_PARTIDOS,auxFechaPartido,auxCodigoPartido,auxCodigoVisitante,auxCodigoLocal,auxCodigoReferi,lugarVacioPartidos))==0 )
                                                        {
                                                            printf("Partido agregado exitosamente \n\n");
                                                            break;
                                                        }printf("No se pudo agregar el partido\n"); break;

                                                }printf("accion cancelada\n");break;


                                           }printf("No se pudo agregar el partido\n"); break;
                                       }printf("No se pudo agregar el partido\n"); break;



                                    }printf("No se pudo agregar el partido\n"); break;
                                }printf("No puede elegir los dos equipos al mismo tiempo\n");break;
                                }printf("No se pudo agregar el partido\n"); break;
                            }printf("No se pudo agregar el partido\n"); break;
                            }printf("accion cancelada\n");break;
                            }printf("No se pudo agregar el partido\n"); break;


                    */




                    break;
                case 10:
                    //mostraparti(listaPartidos,CANT_PARTIDOS);
                    mostrarPartidos(listaPartidos,listaEquipos,listaReferis,CANT_PARTIDOS,CANT_EQUIPOS,CANT_REFERIS);
                    break;

                case 11:

                    mostrarJugadoresxEquipo(listaEquipos,listaJugadores,CANT_EQUIPOS,CANT_JUGADORES);
                    break;

                case 12:


                    //mostraparti(listaPartidos,CANT_PARTIDOS);

                    referi1=contadorPartidosReferi(listaPartidos,CANT_PARTIDOS); /*tengo el cod del referi */
                    //referi2= encontrarReferixCodigo(listaReferis,CANT_REFERIS, referi1 ); /*el indice en la lista de referis*/
                    printf("   Quien mas partididos dirigio fue  : ");
                    mostrarUnReferi(listaReferis,CANT_REFERIS, referi1    );



                    break;

                case 13:

                    //ingresarNombreMostrarJugador(listaJugadores,CANT_JUGADORES,listaEquipos,CANT_EQUIPOS);

                    //ingresarSoloApellidoMostrarJugador(listaJugadores,CANT_JUGADORES,listaEquipos,CANT_EQUIPOS);

                    funcionIngresaJugadorMuestraTodo(listaJugadores,CANT_JUGADORES,listaEquipos,CANT_EQUIPOS);

                    break;

                case 14:

                    indiceMasLargo=equipoNombreMasLargo(listaEquipos,CANT_EQUIPOS);

                    printf("El equipo con el nombre mas largo es : %s ",listaEquipos[indiceMasLargo].nombre);
                    break;

                case 15:

                    funcionIngresaFechaMuestraTodo(listaPartidos,CANT_PARTIDOS,listaEquipos,CANT_EQUIPOS,listaReferis,CANT_REFERIS);
                    break;

                case 16:
                    //contadorPartidosReferi(listaPartidos,CANT_PARTIDOS);
                    //promedioedades=getInt("Ingrese el codigo del equipo que quiere saber el promedio de edades : ");
                    //sacarPromedioEdadesJugadores(promedioedades,CANT_EQUIPOS,listaJugadores,CANT_JUGADORES);

                    equipoMasJoven(CANT_EQUIPOS,listaJugadores,CANT_JUGADORES,listaEquipos);
                    break;


                default:
                    printf("Opcion no valida pindongas");
                    break;


                }//switch(opcionMenu)














        }else{
        printf("\nOpcion no valida. Ingrese una de las opciones del menu.\n");
        opcionMenu=17;


        //continue;
        }   //if(opcionMenu>0)



        printf("\n\n");
        system("pause");
        system("cls");
        imprimirMenu();
        opcionMenu=getInt("\nElija una opcion : \n");
        fflush(stdin);
        printf("\n\n");

    }//while(opcionMenu!=17)
}else{
    printf("\nHa ocurrido un error, no se puede cargar en este momento\n\n");
}//if(validarInicializarEquipos==0)





}

void imprimirMenu()
{

    printf("\n");
    printf("Equipos");
    printf("\n");
    printf("  1. Alta\n");
    printf("  2. Listar\n");
    printf("  3. Modificar\n");
    printf("  4. Baja\n");
    printf("\n");
    printf("\n");
    printf("Jugadores");
    printf("\n");
    printf("  5. Alta\n");
    printf("  6. Listar\n");
    printf("  7. Baja\n");
    printf("\n");
    printf("\n");
    printf("Referis");
    printf("\n");
    printf("  8. Alta\n");
    printf("\n");
    printf("\n");
    printf("Partidos");
    printf("\n");
    printf("  9. Alta\n");
    printf("  10. Listar\n");
    printf("\n");
    printf("\n");
    printf("Informes y Listados");
    printf("\n");
    printf("  11. Listado de Jugadores por Equipo\n");
    printf("  12. Referi que mas partidos dirigió\n");
    printf("  13. Buscar por jugador\n");
    printf("  14. Equipo con el nombre mas largo\n");
    printf("  15. Buscar por fecha\n");
    printf("  16. Mostrar equipo con promedio de edad mas joven\n");
    printf("\n");
    printf("\n");
    printf("  17. Salir\n");
    printf("\n");
}







/*

void mostrarJugadoresPorEquipo(eEquipo* listaEquipos, eJugador* listaJugadores, int cantidadEquipos, int cantidadJugadores)
{
    printf("EQUIPOS\n");
    printf("\t Codigo  \t  Nombre  \t   Localidad\n");

    int ix;
    int ij;
    for(ix=0;ix<cantidadEquipos;ix++)
    {
      for(ij=0;ij<cantidadJugadores;ij++)
        {
            if(listaEquipos[ix].estaVacioEquipo==FALSE)
            {
                if(listaEquipos[ix].codigoEquipo == listaJugadores[ij].codigoEquipoJugador )

                printf("\n\t %2d  \t %18s  \t %18s\n",listaEquipos[ix].codigoEquipo,listaEquipos[ix].nombre,listaEquipos[ix].localidad);

                if(listaJugadores[ij].estaVacioJugador==FALSE)
        {

             printf("JUGADOR\n");
            printf("\n %3d\t %8s\t %4s\t  %2c\t   %4d/%3d/%5d\t   %3d\t \n", listaJugadores[ij].codigoJugador, listaJugadores[ij].apellidoJugador,
                   listaJugadores[ij].nombreJugador, listaJugadores[ij].sexo, listaJugadores[ij].fechaNacimiento.dia, listaJugadores[ij].fechaNacimiento.mes,
                   listaJugadores[ij].fechaNacimiento.anio, listaJugadores[ij].codigoEquipoJugador);
        }
            }
        }
    }
}

*/



void mostrarJugadoresxEquipo( eEquipo* listaEquipos, eJugador* listaJugadores, int cantidadEquipos, int cantidadJugadores   )

{
    printf("EQUIPOS\n");
    printf("\t Codigo  \t  Nombre  \t   Localidad\n");
    int ix;
    int i;
    for(ix=0;ix<cantidadEquipos;ix++)
    {
        if(listaEquipos[ix].estaVacioEquipo==FALSE)
        {
            printf("\n");
            printf("\----------------------------------------------");
            printf("\n");
            printf("EQUIPO\n");
            printf("\n");
            printf("\n\t %2d  \t %18s  \t %18s\n",listaEquipos[ix].codigoEquipo,listaEquipos[ix].nombre,listaEquipos[ix].localidad);
            printf("\n");
            printf("JUGADORES\n");printf("\n");printf("\n");

           for(i=0;i<cantidadJugadores;i++)
           {

                //printf("JUGADORES\n");
                if(listaJugadores[i].codigoEquipoJugador == listaEquipos[ix].codigoEquipo)
                {
                    printf(" \t %s , %s \t\n ",listaJugadores[i].apellidoJugador, listaJugadores[i].nombreJugador);
                }

            }
        }
    }



            printf("\n");
            printf("\----------------------------------------------");
            printf("\n");
}









void mostrarPartidos (ePartido* listaPartidos, eEquipo* listaEquipos, eReferi* listaReferis , int cantidadPartidos, int cantidadEquipos, int cantidadReferis)
{
    int i;
    int j;
    int equipoLocalIndice;
    int equipoVisitanteIndice;
    int referiIndice;

    printf("\nLista de partidos\n\n");

    for(i=0;i<cantidadPartidos;i++)
    {
        if(listaPartidos[i].estaVacioPartido==FALSE)
        {



        printf("\n");
        organizarPartidosxFecha(listaPartidos,CANT_PARTIDOS);
        printf("El dia %d / %d / %d juegan : \n", listaPartidos[i].fechaPartido.dia, listaPartidos[i].fechaPartido.mes, listaPartidos[i].fechaPartido.anio);
        for(j=0;j<cantidadEquipos;j++)
        {
            equipoLocalIndice=buscarEquipoPorCodigo(listaEquipos,cantidadEquipos,listaPartidos[i].codigoLocal);
            equipoVisitanteIndice=buscarEquipoPorCodigo(listaEquipos,cantidadEquipos,listaPartidos[i].codigoVisitante);

            referiIndice=encontrarReferixCodigo(listaReferis,CANT_REFERIS,listaPartidos[i].codigoReferi);

            printf(" %s  (local)  vs.  %s (visitante) \n", listaEquipos[equipoLocalIndice].nombre, listaEquipos[equipoVisitanteIndice].nombre);

            printf("Lo dirige %s %s ",listaReferis[referiIndice].nombre, listaReferis[referiIndice].apellido);
            printf("\n\n");
            break;
        }

        }else if(listaPartidos[CANT_PARTIDOS-1].estaVacioPartido==FALSE){

            printf("No hay partidos ingresados aun\n\n");
        }


    }
}



void mostraparti(ePartido* listaPartidos,int cantidadPartidos)
{
    int i;
     for(i=0;i<cantidadPartidos;i++)
    {
        printf("\n");
        organizarPartidosxFecha(listaPartidos,CANT_PARTIDOS);


        printf("El dia %d / %d / %d juegan : \n", listaPartidos[i].fechaPartido.dia, listaPartidos[i].fechaPartido.mes,
               listaPartidos[i].fechaPartido.anio);




        }
}




void funcionIngresaJugadorMuestraTodo(eJugador* listaJugadores, int cantidadJugadores, eEquipo* listaEquipos, int cantidadEquipos  )
{
    char auxNombreJugador[31];
    char auxApellidoJugador[31];

    int i;
    int h;

    printf("Ingrese los datos del jugador que busca \n");
    if(  (getValidString("Apellido : ","Apellido no valido\n", "Apellido demasiado largo\n", auxApellidoJugador, 31,3) == 0 ))
    {
            fflush(stdin);
            ponerMayusculas(auxApellidoJugador); ponerMayusculas(auxNombreJugador);


            for(i=0;i<cantidadJugadores;i++)
            {

                if(  ( strcmp( listaJugadores[i].apellidoJugador , auxApellidoJugador ) )==0  )
                {
                    //arrayDeIndiceJugadorEncontrado[h]=i;
                    //h=h++;
                    printf("\n"); printf("\n");
                    printf("-----"); printf("\n");

                    printf("\n El Jugador : %s %s  \n",listaJugadores[i].apellidoJugador,
                           listaJugadores[i].nombreJugador);

                    printf("\n");


                    printf("juega en: \n");
                    mostrarUnEquipo(listaEquipos,cantidadEquipos,listaJugadores[i].codigoEquipoJugador);
                    printf("\n");
                    printf("-----"); printf("\n"); printf("\n");


                }


                //printf("---------");
            }

    }




}







void funcionIngresaFechaMuestraTodo(ePartido* listaPartidos, int cantidadPartidos, eEquipo* listaEquipos, int cantidadEquipos , eReferi* listaReferis, int cantidadReferis )
{
    int auxDia;
    int auxMes;
    int auxAnio;

    int i;
    int h;

    if ( ( (getValidInt("dia : ", "dia no valido \n", &auxDia, 1,31,3) )==0 )
        && ( (getValidInt("mes : ","mes no valido \n", &auxMes,1,12,3) )==0  )
        &&  (  ( getValidInt("anio : ","anio no valido\n", &auxAnio, 1950,2019,3) ) ==0    )  )
    {

       for( i=0;i<cantidadPartidos;i++  ){

        if( (  auxDia == listaPartidos[i].fechaPartido.dia   ) && ( auxMes == listaPartidos[i].fechaPartido.mes ) &&
            ( auxAnio == listaPartidos[i].fechaPartido.anio  ) )
            {
                printf("\n\n");
                printf("\n El dia %d / %d /  %d   \n", listaPartidos[i].fechaPartido.dia, listaPartidos[i].fechaPartido.mes,
                       listaPartidos[i].fechaPartido.anio );
                printf("Se jugara : \n");
                 mostrarUnEquipo(listaEquipos,cantidadEquipos,listaPartidos[i].codigoLocal);
                 printf(" \n VS. \n");
                 mostrarUnEquipo(listaEquipos,cantidadEquipos,listaPartidos[i].codigoVisitante);
                 printf("\n el referi sera \n");
                 mostrarUnReferi(listaReferis,cantidadReferis,listaPartidos[i].codigoReferi);
                 printf("\n\n");



            }

        }

    }
}








/*

void funcionIngresaFechaMuestraTodo(ePartido* listaPartidos, int cantidadPartidos, eEquipo* listaEquipos, int cantidadEquipos , eReferi* listaReferis, int cantidadReferis )
{
    int auxDia;
    int auxMes;
    int auxAnio;

    int i;
    int h;

    if ( ( (getValidInt("dia : ", "dia no valido \n", &auxDia, 1,31,3) )==0 )
        && ( (getValidInt("mes : ","mes no valido \n", &auxMes,1,12,3) )==0  )
        &&  (  ( getValidInt("anio : ","anio no valido\n", &auxAnio, 1950,2019,3) ) ==0    )  )
    {

       for( i=0;i<cantidadPartidos;i++  ){

        if( (  auxDia == listaPartidos[i].fechaPartido.dia   ) && ( auxMes == listaPartidos[i].fechaPartido.mes ) &&
            ( auxAnio == listaPartidos[i].fechaPartido.anio  ) )
            {
                printf("\n\n");
                printf("\n El dia %d / %d /  %d   \n", listaPartidos[i].fechaPartido.dia, listaPartidos[i].fechaPartido.mes,
                       listaPartidos[i].fechaPartido.anio );
                printf("Se jugará : \n);
                 mostrarUnEquipo(listaEquipos,cantidadEquipos,listaPartidos[i].codigoLocal);
                 printf(" \n VS. \n");
                 mostrarUnEquipo(listaEquipos,cantidadEquipos,listaPartidos[i].codigoVisitante);
                 printf("\n el referi será \n");
                 mostrarUnReferi(listaReferis,cantidadReferis,listaPartidos[i].codigoReferi);
                 printf("\n\n");



            }

        }

    }

    printf("Ingrese la fecha que busca \n");
    if(  (getValidString("Apellido : ","Apellido no valido\n", "Apellido demasiado largo\n", auxApellidoJugador, 31,3) == 0 ))
    {
            fflush(stdin);
            ponerMayusculas(auxApellidoJugador); ponerMayusculas(auxNombreJugador);


            for(i=0;i<cantidadJugadores;i++)
            {

                if(  ( strcmp( listaJugadores[i].apellidoJugador , auxApellidoJugador ) )==0  )
                {
                    //arrayDeIndiceJugadorEncontrado[h]=i;
                    //h=h++;
                    printf("\n"); printf("\n");
                    printf("-----"); printf("\n");

                    printf("\n El Jugador : %s %s  \n",listaJugadores[i].apellidoJugador,
                           listaJugadores[i].nombreJugador);

                    printf("\n");


                    printf("juega en: \n");
                    mostrarUnEquipo(listaEquipos,cantidadEquipos,listaJugadores[i].codigoEquipoJugador);
                    printf("\n");
                    printf("-----"); printf("\n"); printf("\n");


                }


                //printf("---------");
            }

    }




}

*/












void ingresarNombreMostrarJugador(eJugador* listaJugadores, int cantidadJugadores, eEquipo* listaEquipos, int cantidadEquipos )
{
    char auxNombreJugador[31];
    char auxApellidoJugador[31];
    int auxIndiceJugadorEncontrado;
    int auxIndiceEquipoEncontrado;
    int i;
    int j;
    int validacion = 0;


    printf("Ingrese los datos del jugador que busca \n");
    if(  (getValidString("Apellido : ","Apellido no valido\n", "Apellido demasiado largo\n", auxApellidoJugador, 31,3) == 0 )
       && (getValidString("Nombre : ", "Nombre no valido\n","Nombre demasiado largo\n", auxNombreJugador,31,3)==0  )      )
    {
            fflush(stdin);
            ponerMayusculas(auxApellidoJugador); ponerMayusculas(auxNombreJugador);
            printf("El nombre es %s ",auxNombreJugador); printf("El apellido es %s\n",auxApellidoJugador);

        for(i=0;i<cantidadJugadores;i++)
        {
            //printf("Los apellidos que esta chequeando %s\n",listaJugadores[i].apellidoJugador);
            fflush(stdin);
            if( (  strcmp(listaJugadores[i].apellidoJugador , auxApellidoJugador )== 0) &&
                (strcmp(listaJugadores[i].nombreJugador , auxNombreJugador)==0)   )
            {


                fflush(stdin);
                auxIndiceJugadorEncontrado=i;
                printf("ENCONTRE AL JUGADOR, el codigo es : %d \n",listaJugadores[auxIndiceJugadorEncontrado].codigoJugador);
                printf("ENCONTRE AL JUGADOR, el codigo de su equipo es : %d \n",listaJugadores[auxIndiceJugadorEncontrado].codigoEquipoJugador);

                for(j=0;j<cantidadEquipos;j++)
                    {


                        if( listaJugadores[auxIndiceJugadorEncontrado].codigoEquipoJugador == listaEquipos[j].codigoEquipo )
                        {
                            validacion=1;
                            auxIndiceEquipoEncontrado=j;


                            printf("El jugador %s %s, juega en el equipo %s de %s", listaJugadores[auxIndiceJugadorEncontrado].nombreJugador,
                                   listaJugadores[auxIndiceJugadorEncontrado].apellidoJugador, listaEquipos[auxIndiceEquipoEncontrado].nombre,
                                   listaEquipos[auxIndiceEquipoEncontrado].localidad);

                        }

                    }






                }

            }//else{

                //printf("Ese jugador no esta en ningun equipo en este momento\n");
            //}


        //}


    }else{
        printf("Jugador no encontrado\n");

        //break;
    }




}







void ingresarSoloApellidoMostrarJugador(eJugador* listaJugadores, int cantidadJugadores, eEquipo* listaEquipos, int cantidadEquipos )
{
    char auxNombreJugador[31];
    char auxApellidoJugador[31];
    int arrayJugadoresEncontrados[10];
    int arrayCodigoEquipoDeJugadoresEncontrados[10];
    int auxIndiceJugadorEncontrado;
    int auxIndiceEquipoEncontrado;
    int i;
    int j;
    int h;
    int validacion = 0;


    printf("Ingrese los datos del jugador que busca \n");
    if(  (getValidString("Apellido : ","Apellido no valido\n", "Apellido demasiado largo\n", auxApellidoJugador, 31,3) == 0 ) )
    {
            fflush(stdin);
            ponerMayusculas(auxApellidoJugador); ponerMayusculas(auxNombreJugador);
             printf("El apellido es %s\n",auxApellidoJugador);

        for(i=0;i<cantidadJugadores;i++)
        {
        //for(j=0;j<11;j++){

            if( (  strcmp(listaJugadores[i].apellidoJugador , auxApellidoJugador )== 0)   )
            {

                //auxIndiceJugadorEncontrado=i;
                //arrayJugadoresEncontrados[h]=i;
                //h++;
                printf("Los jugadores encontrados son: %s y su indice es: %d \n",listaJugadores[i].apellidoJugador, i);

                arrayJugadoresEncontrados[j]=i;


                printf("En mi array array jugadores encontrados esta: %d\n",arrayJugadoresEncontrados[j]);


                if(  listaJugadores[ arrayJugadoresEncontrados[j]  ].codigoEquipoJugador   == listaEquipos[i].codigoEquipo  )
                {
                    printf("El jugador %s %s juega en el equipo %s de %s \n", listaJugadores[arrayJugadoresEncontrados[j] ].apellidoJugador,
                           listaJugadores[arrayJugadoresEncontrados[j] ].nombreJugador, listaEquipos[i].nombre, listaEquipos[i].localidad);
                }


            }

            j=j+1;
            //}
        }
/*
        for(h=0;h<10;h++)
        {
             printf("los numeros en el array de jugadores encontrados es : %d", arrayJugadoresEncontrados[h]);
        }

*/

    /*
     printf("El jugador con el nombre %s ",listaJugadores[auxIndiceJugadorEncontrado].apellidoJugador);

                for(h=0;h<10;h++)
                {
                    //
                    arrayCodigoEquipoDeJugadoresEncontrados[h]=listaJugadores[arrayCodigoEquipoDeJugadoresEncontrados[h]].codigoEquipoJugador;

                    for(i;i<CANT_EQUIPOS;i++)
                        {
                           for(h=0;h<10;h++)
                           {
                               //printf("En el array de codigo equipo de jugadore sencontrados esta : %d\n",arrayCodigoEquipoDeJugadoresEncontrados[h]);


                                if(arrayCodigoEquipoDeJugadoresEncontrados[h] == listaEquipos[i].codigoEquipo)
                                {
                                    //printf("El jugador con el nombre %s",listaJugadores)
                                    printf("\nJuega en %s \n",listaEquipos[i].nombre);
                                }

                            }
                        }
                }






*/
    /*

    for(j=0;j<cantidadEquipos;j++)
                    {


                        if( listaJugadores[h].codigoEquipoJugador == listaEquipos[j].codigoEquipo )
                        {
                            validacion=1;
                            auxIndiceEquipoEncontrado=j;


                            printf("El jugador %s %s, juega en el equipo %s de %s", listaJugadores[h].nombreJugador,
                                   listaJugadores[h].apellidoJugador, listaEquipos[auxIndiceEquipoEncontrado].nombre,
                                   listaEquipos[auxIndiceEquipoEncontrado].localidad);

                        }
                        //h++;
                    }

        */
    /*
            for(h=0;h<10;h++)
                           {
                               printf("En el array de codigo equipo de jugadore sencontrados esta : %d\n",arrayCodigoEquipoDeJugadoresEncontrados[h]);
                           }

    */


    }
}








