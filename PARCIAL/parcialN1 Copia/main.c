#include <stdio.h>
#include <stdlib.h>

#include "Camion.h"

int main()
{

    eChofer listadoChoferes[T];
    inicializarEstado(listadoChoferes,T);
    Hardcodeo(listadoChoferes,T);

    eCamion listadoCamiones[TCAMIONES];
    inicializarEstadoCamion(listadoCamiones,TCAMIONES);
    HardcodeoCamiones(listadoCamiones,TCAMIONES);

    int opc;
    do
    {

        printf("\n1-Mostrar listado de choferes con camiones\n2-Mostrar listado de choferes\n3- mostrar Lista De Camiones Con Chofer\n4-Alta camion \n5-Baja Camion\n6-modificar camion\n7-Alta chofer\n8-Baja chofer\n9-Ordenar camiones por tipo y mostrarlos con choferes\n10-Modificar chofer\n11-Mostrar choferes con mas de un camion \n12-Mostrar camiones con mas de 10 anios de antiguedad con duenios\n13-Mostrar camiones por marca\n14- odenar Choferes Por Cantidad De Camiones\n15-odenar Choferes Por Cantidad De Camiones Y Alfabeticamente\n16-Promedio de edades choferes\n17-Promedio de antiguedad de flota de camiones\n18-Promedio de conductores varones y mujeres\n0-salir");

        opc =   getInt("\nIngrese opcion:","\nOpcion invalida");

        switch(opc)
        {


        case 1:
            mostrarChoferConCamiones(listadoCamiones,TCAMIONES,listadoChoferes,T);
            break;


        case 2:
            mostrarListaDeChoferes(listadoChoferes,T);
            break;

        case 3:
            mostrarListaDeCamionesConChofer(listadoCamiones,TCAMIONES,listadoChoferes,T);
            break;

        case 4:
            AltaCamion(listadoCamiones,TCAMIONES,listadoChoferes,T);
            break;

        case 5:
            bajaCamion(listadoCamiones,TCAMIONES);
            break;

        case 6:
            modificarCamion(listadoCamiones,TCAMIONES,listadoChoferes,T);
            break;


        case 7:
            Alta(listadoChoferes,T);
            break;

        case 8:
            bajaChofer(listadoChoferes,T,listadoCamiones,TCAMIONES);
            break;


        case 9:
            mostrarChoferesPorTipo(listadoChoferes,T,listadoCamiones,TCAMIONES);
            break;


        case 10:
            modificarChofer(listadoChoferes,T);
            break;


        case 11:
            mostrarChoferesConMasDeUnCamion(listadoChoferes,T,listadoCamiones,TCAMIONES);
            break;


        case 12:
            mostrarCaminionesConMasDe10Anios(listadoChoferes,T,listadoCamiones,TCAMIONES);
            break;


        case 13:
            mostrarCamionesPorMarca(listadoCamiones,TCAMIONES);
            break;

        case 14:
            odenarChoferesPorCantidadDeCamiones(listadoChoferes,T,listadoCamiones,TCAMIONES);
            break;


        case 15:
            odenarChoferesPorCantidadDeCamionesYAlfabeticamente(listadoChoferes,T,listadoCamiones,TCAMIONES);
            break;

        case 16:
            promedioDeEdadChoferes(listadoChoferes,T);
            break;

        case 17:
            promedioDeAniosDeAntiguedadDeCamiones(listadoCamiones,TCAMIONES);
            break;


        case 18:
           promedioDeMoFentreChoferes(listadoChoferes,T);
            break;

        case 0:
            printf("\nGracias por utilizar");
            break;

        }



    }
    while(opc != 0);



    return 0;
}
