


typedef struct{
    int codigoEquipo;
    char nombre[51];
    char localidad[33];

    int estaVacioEquipo;  /**CERO PARA CIERTO, 1 PARA FALSO*/



}eEquipo;



int agregarEquipo(eEquipo* listaEquipos, int cantidad, int codigo, char nombre[], char localidad[], int lugarVacio);
void mostrarEquipos(eEquipo* listaEquipos, int cantidad );
void ordenarEquiposAlfabeticamente(eEquipo* listaEquipos, int cantidad);

int bajaEquipoConfirm (eEquipo listaEquipos[], int cantidad, int codigo);


int modificarEquipo( eEquipo listaEquipos[], int indice);
int buscarEquipoPorCodigo(eEquipo* listaDeEquipos, int cantidad, int codigo);


///PASAR LAS FUNCIONES QUE ESTAN EN VALIDACIONES QUE TIENEN EQUIPO, TRAERLAS ACA//


void hardcodeoEquipos(eEquipo* listaEquipos, int cantidad);

int equipoNombreMasLargo (eEquipo* listaEquipos, int cantidad);



