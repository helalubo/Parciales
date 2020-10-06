
#include <stdlib.h>
#include "Alumno.h"
#include "input.h"
#include "validate.h"
#define T 10

void menu();

int main()
{
    int opc;
    char rta;



    eAlumno listaAlumnos[T]= {{100, 7, 9, 8, "Maria", "maria@gmail.com", OCUPADO},{101,10,10,10,"Juan","juan@gmail.com", OCUPADO},{102,7,7,7,"Ana", "ana@gmail.com", OCUPADO},
        {104,10,10,10,"Ana Maria", "ana1@gmail.com", OCUPADO},{105,8,8,8,"Ana", "ana2@gmail.com", OCUPADO}
    };
    //Crear funcion para hardcodear
    //eAlumno aux = {100, 7, 9, 8, "Maria", "maria@gmail.com" , OCUPADO};
    //inicializarAlumnos(listaAlumnos, T);

    //listaAlumnos[0] =  aux;

//printf("CARGO LISTA DE ALUMNOS\n");
    //cargarListadoDeAlumnos(listaAlumnos,T);
    // cargarListadoDeAlumnos(listaAlumnos,T);
    //cargarListadoDeAlumnos(listaAlumnos,T);
    // printf("MUESTRO LISTA DE ALUMNOS\n");
     mostrarListadoDeAlumnos(listaAlumnos,T);
    /*printf("TEST Modificar\n");
    modificarAlumno(listaAlumnos, T);

     printf("MUESTRO LISTA DE ALUMNOS MODIFICADO\n");
    mostrarListadoDeAlumnos(listaAlumnos,T);*/

    //printf("TEST Eliminar\n");
    //eliminarAlumno(listaAlumnos, T);
    //   printf("MUESTRO LISTA DE ALUMNOS MODIFICADO\n");
//   mostrarListadoDeAlumnos(listaAlumnos,T);
    /*printf("MUESTRO LISTA DE ALUMNOS PROMOCIONADOS\n");
    mostrarListadoDeAlumnosPromocionados(listaAlumnos, T, 6);
    printf("MUESTRO LISTA DE ALUMNOS ORDENADO POR NOMBRE\n");
    ordenarListadoDeAlumnosPorNombre(listaAlumnos,T);
    mostrarListadoDeAlumnos(listaAlumnos,T);
    printf("MUESTRO LISTA DE ALUMNOS ORDENADO POR NOMBRE Y LUEGO POR PROMEDIO\n");
    ordenarListadoDeAlumnosPorNombreYporPromedio(listaAlumnos,T);
    mostrarListadoDeAlumnos(listaAlumnos,T);
    printf("MUESTRO LISTA DE ALUMNOS CON MAYOR PROMEDIO\n");
    mostrarAlumnosConMaximoPromedio(listaAlumnos,T);*/

    do
    {

        menu();
        opc = getInt("\n Ingrese opcion: ");



        switch(opc){



    case 1:
        cargarUnAlumno();
        break;




    case 2:
       BuscarUnAlumnoYMostrarlo(listaAlumnos,T);
        break;



    case 3:
        break;



    case 4:
        break;



    case 5:
        break;



    case 6:
        break;



    case 7:
        break;



        }



    }
    while(opc != 0);




        return 0;
}
void menu()
{

    printf("\n1-Alta Alumno \n2-Mostrar alumno \n3-Mostrar alumnos en orden alfabetico\n4-Mostrar alumno con maximo promedio\n5-Modificar alumno\n6-Baja alumno \n0-Salir");



}
