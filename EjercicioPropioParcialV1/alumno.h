#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "validate.h"

#define OCUPADO 1
#define LIBRE 0
#define TAMANIOMAXIMODECOMENTARIO 30
//#define TAM 5
//#define NOTAPARAAPROBAR 6

#include "string.h"
#include "limits.h"

//#include "mostrar.h"
//#include "alumno.h"

typedef struct
{

    int legajo;
    char nombre[20];
    char apellido[20];
    int nota1;
    int nota2;
    float promedio;
    char email[30];
    int estado;
    char comentario[200];


} eAlumno;

void inicializarEstado(eAlumno listado[], int tam);
int buscarIndiceLibre(eAlumno listado[], int tam);
void Alta(eAlumno listado[], int tam);
float getPromedio(int num1, int num2);
void mostrarAlumno(eAlumno alumno);
void mostrarListaDeAlumnos(eAlumno listado[],int tam);
int buscarLegajo(eAlumno listado[], int tam);
void BuscarAlumnoYMostrar(eAlumno listado[], int tam);
void mostrarMailAlfabeticamente(eAlumno listado[], int tam);
void alumnosAprobados(eAlumno listado[], int tam, int notaParaAprobar);
void alumnosDesaprobados(eAlumno listado[], int tam, int notaParaAprobar);
void modificarAlumno(eAlumno listado[], int tam);
void baja(eAlumno listado[], int tam);
void mayorPromedio(eAlumno listado[], int tam);

