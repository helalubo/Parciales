#include <stdio.h>
#include <stdlib.h>





#include "Publicacion.h"

#define TPUBLICACIONES 20
#define TCLIENTES 10

int main()
{

    eCliente listadoClientes[TCLIENTES];
    inicializarEstado(listadoClientes,TCLIENTES);
    Hardcodeo(listadoClientes,TCLIENTES);


    ePublicacion listadoPublicaciones[TPUBLICACIONES];
    inicializarEstadoPublicacion(listadoPublicaciones,TPUBLICACIONES);
    HardcodeoPublicacion(listadoPublicaciones,TPUBLICACIONES);

    int opc;


    do
    {


        printf("\n1-Alta Cliente\n2-Modificar Cliente\n3-Baja Cliente\n4-Publicar\n5-Pausar/Activar publicacion\n6-Imprimir clientes\n7-Imprimir publicaciones\n8-Informar clientes\n9-Informar rubros\n0-salir");
        opc = getInt("\nIngrese opcion: ","Ingrese opcion valida");

        switch(opc)
        {


        case 1:
            Alta(listadoClientes,TCLIENTES);//OK
            break;

        case 2:
            modificarCliente(listadoClientes,TCLIENTES);//OK
            break;


        case 3:
             bajaCliente(listadoClientes,TCLIENTES,listadoPublicaciones,TPUBLICACIONES);//OK
            break;

        case 4:
            AltaPublicacion(listadoPublicaciones,TPUBLICACIONES,listadoClientes,TCLIENTES);//OK
            break;

        case 5:
           modificarPublicacion(listadoPublicaciones,TPUBLICACIONES,listadoClientes,TCLIENTES); //ok
            break;

           case 6:
           mostrarClienteConPublicacion(listadoPublicaciones,TPUBLICACIONES,listadoClientes,TCLIENTES); //ok
            break;

            case 7:
            mostrarPublicacionConCuil(listadoPublicaciones,TPUBLICACIONES,listadoClientes,TCLIENTES); //ok
            break;

              case 8:
            informacionesClientes(listadoPublicaciones,TPUBLICACIONES,listadoClientes,TCLIENTES);
            break;

            case 9:
            informacionesPublicaciones(listadoPublicaciones,TPUBLICACIONES,listadoClientes,TCLIENTES);
            break;


        case 0:
            printf("\nGracias por utilizar la app");
            break;








        }

    }
    while(opc !=0);
}






