#include <stdio.h>
#include <stdlib.h>


#define TAM 5
#define NOTAPARAAPROBAR 6

#include "mostrar.h"
#include "alumno.h"
#include "input.h"

/*

Crear proyecto de alumnos donde se permita
1- dar el alta de un alumno (legajo, nombre, apellido, nota1, nota2, promedio,
                             email);
 2- mostrar alumno segun legajo
 3- mostrar listado de alumnos
 4-mostrar listado de alumnos alfabeticamente y por promedio
 5- mostrar alumno con mayor promedio
 6-mostrar emails alfabeticamente
 7 alumnos aprobados
 8-alumnos desaprobados
 9-modificar alumno
 10-baja de alumno




*/









int main()
{


    int opc;

    eAlumno lista[TAM];
    inicializarEstado(lista,TAM);


    do
    {
        menuPrincipal();
        opc = getInt("Ingrese opcion: ");


        switch(opc)
        {

        case 1:
            Alta(lista,TAM);
            break;

        case 2:
            BuscarAlumnoYMostrar(lista,TAM);
            break;


        case 3:

            mostrarListaDeAlumnos(lista,TAM);
            break;


        case 4:
            mostrarMailAlfabeticamente(lista,TAM);
            break;

        case 5:
            modificarAlumno(lista,TAM);
            break;


        case 6:
            alumnosAprobados(lista,TAM,NOTAPARAAPROBAR);
            break;

        case 7:
            alumnosDesaprobados(lista,TAM,NOTAPARAAPROBAR);
            break;

        case 8:
            mayorPromedio(lista,TAM);
            break;

        case 9:
            baja(lista,TAM);
            break;

        case 0:
            break;

        default:
            printf("\n Ingrese opcion valida");


        }





    }
    while(opc != 0);





    return 0;
}

