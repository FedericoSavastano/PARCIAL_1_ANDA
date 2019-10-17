

typedef struct{
    int dia;
    int mes;
    int anio;

}eFechaReferi;

typedef struct{
    int codigoReferi;
    char apellido[31];
    char nombre[31];
    char sexo;
    char email[31];
    eFechaReferi fechaNacimiento;

    int estaVacioReferi;  /**CERO PARA CIERTO, 1 PARA FALSO*/


}eReferi;


void hardcodeoReferies (eReferi* listaReferies, int cantidad);

void mostrarUnReferi(eReferi* listaReferis, int cantidad, int codigo);

int inicializarReferis (eReferi * listaReferis, int cantidadReferis);
