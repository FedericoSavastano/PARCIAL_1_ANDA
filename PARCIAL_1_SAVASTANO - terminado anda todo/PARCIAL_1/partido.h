typedef struct{
    int dia;
    int mes;
    int anio;

}eFechaPartido;




typedef struct{
    int codigoPartido;
    int codigoVisitante;
    int codigoLocal;
    int codigoReferi;
    eFechaPartido fechaPartido;

    int estaVacioPartido;

}ePartido;




void organizarPartidosxFecha(ePartido* listaPartidos, int cantidad);

 int inicializarPartidos(ePartido* listaPartidos, int cantidadPartidos);

 int contadorPartidosReferi(ePartido* listaPartidos, int cantidadPartidos);

 int contadorOcurrencias(ePartido* listaPartidos, char existe[], int cantidad, int codigoReferi);


int buscarlugarVacioPartidos(ePartido* listaPartidos, int cantidadPartidos   );

int inicializarPartidos(ePartido* listaPartidos, int cantidadPartidos);



 int agregarPartido(ePartido* listaPartidos, int cantidad, eFechaPartido fechaPartido, int codigoPartido, int codigoVisitante, int codigoLocal, int codigoReferi ,  int lugarVacio );

  int introducirFechaPartido( eFechaPartido * fechaAux);


void hardcodeoPartidos(ePartido* listaPartidos, int cantidad);
