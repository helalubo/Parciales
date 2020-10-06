#include <stdio.h>
#define LIBRE 0
#define OCUPADO 1
typedef struct
{
    int legajo;
    int nota1;
    int nota2;
    float promedio;
    char nombre[25];
    char email[20];
    int estado;
} eAlumno;
int buscarLibre(eAlumno[],int);
void inicializarAlumnos(eAlumno[], int);
void mostrarUnAlumno(eAlumno miAlumno);
void BuscarUnAlumnoYMostrarlo(eAlumno listado[], int tam);
eAlumno cargarUnAlumno(void);
int compararAlumnosPorLegajo(eAlumno unAlumno, eAlumno otroAlumno);
void cargarListadoDeAlumnos(eAlumno listado[], int tam);
void mostrarListadoDeAlumnos(eAlumno listado[], int tam);
void mostrarListadoDeAlumnosPromocionados(eAlumno listado[], int tam, int minAprobado);
void ordenarListadoDeAlumnosPorNombre(eAlumno listado[], int tam);
void ordenarListadoDeAlumnosPorNombreYporPromedio(eAlumno listado[], int tam);
void mostrarAlumnosConMaximoPromedio(eAlumno listado[], int tam);
float calcularMaximoPromedio(eAlumno listado[], int tam);
void mostrarListadoDeAlumnosConMaximo(eAlumno listado[], int tam, int maximo);

void modificarAlumno(eAlumno[], int);
void eliminarAlumno(eAlumno[], int);



