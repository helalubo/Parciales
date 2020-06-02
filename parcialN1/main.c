
/**
*
* Nombre: Miguel Alejandro De Moraiz
* Curso: 1B
*
*
*
*
*/





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

    eMarca listadoMarcas[3];
    hardcodeoMarcas(listadoMarcas,3);

    int opc;
    do
    {

        printf("\n1-Mostrar listado de choferes con camiones\n2-Mostrar listado de choferes\n3- mostrar Lista De Camiones Con Chofer **PRIMERA MODIFICACION DEL PARCIAL**\n4-Alta camion **SEGUNDA MODIFICION PARCIAL**\n5-Baja Camion\n6-modificar camion**MOSTRAR DE PARCIAL**\n7-Alta chofer\n8-Baja chofer\n9-Ordenar camiones por tipo y mostrarlos con choferes\n10-Modificar chofer\n11-Mostrar choferes con mas de un camion \n12-Mostrar camiones con mas de 10 anios de antiguedad con duenios\n13-Mostrar camiones por marca\n14- odenar Choferes Por Cantidad De Camiones\n15-odenar Choferes Por Cantidad De Camiones Y Alfabeticamente***TERCER MODIFICACION PARCIAL***\n16-Promedio de edades choferes\n17-Promedio de antiguedad de flota de camiones\n18-Promedio de conductores varones y mujeres**CUARTA MODIFICACION PARCIAL\n19-Mostrar Camiones por marca seleccionada**MOSTRAR MODIFICADO DE PARCIAL");
        //  printf("\n*********EXTRAS*********");
        //   printf("\n19-Mostrar Camiones por marca seleccionada\n20-Mostrar camiones mas antiguos\n21-mostrar listado por marca\n22-mostrar Cantidad De Un Tipo Y Una Marca Al Mismo Tiempo\n23-Mostrar marca mas elegida por los choferes\n24-Mostrar acumulado de antiguedad de camiones\n25-mostrar Camiones Con Mayor Cantidad De Ruedas Y Nombre De Duenio\n26-Mostrar camiones con menor peso y nombre de duenio\n27-camiones De Duenos Mujeres Ordenados Por Peso\n28-Mostrar Camiones Que Superen El Peso Y tengan Antiguedad Mayor A 15 anios\n29-Mostrar Camion Con Mayor Peso Dependiendo La Marca\n30-promedio De llantas Que Usa Cada Chofer En Su Flota\n31-chofer Con Mayor Cantidad De Ruedas En Su Flota\n32-mostrar Camion Larga Distancia Con Mayor Peso\n");


        printf("\n************************");

        printf("\n0-Salir");
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

        case 19:

            MostrarCamionesDelMarcaSeleccionada(listadoCamiones,TCAMIONES,listadoChoferes,T);
            break;


        case 20:
            mostrarCamionesMasViejos(listadoCamiones,TCAMIONES);
            break;

        case 21:
            MostrarCamionesSeparadasPorMarca(listadoCamiones,TCAMIONES);
            break;
        case 22:
            mostrarCantidadDeUnTipoYUnaMarcaAlMismoTiempo(listadoCamiones,TCAMIONES);
            break;
        case 23:
            mostrarMarcaMasElegidaPorLosChoferes(listadoCamiones,TCAMIONES);
            break;
        case 24:
            mostrarAniosDeAntiguedadAcumuladoDeTodosLosCamiones(listadoCamiones,TCAMIONES);
            break;

        case 25:
            mostrarCamionesConMayorCantidadDeRuedasYNombreDeDuenio(listadoChoferes,T,listadoCamiones,TCAMIONES);
            break;
        case 26:
            mostrarCamionConPesoMenorYDuenio(listadoChoferes,T,listadoCamiones,TCAMIONES);
            break;
        case 27:
            camionesDeDuenosMujeresOrdenadosPorPeso(listadoChoferes,T,listadoCamiones,TCAMIONES);
            break;
        case 28:
            MostrarCamionesQueSuperenElPesoYtenganAntiguedadMayorA15anios(listadoChoferes,T,listadoCamiones,TCAMIONES);
            break;
        case 29:
            MostrarCamionConMayorPesoDependiendoLaMarca(listadoChoferes,T,listadoCamiones,TCAMIONES);
            break;

        case 30:
            promedioDellantasQueUsaCadaChoferEnSuFlota(listadoChoferes,T,listadoCamiones,TCAMIONES);
            break;
        case 31:
            choferConMayorCantidadDeRuedasEnSuFlota(listadoChoferes,T,listadoCamiones,TCAMIONES);
            break;

        case 32:
            mostrarCamionLargaDistanciaConMayorPeso(listadoChoferes,T,listadoCamiones,TCAMIONES);
            break;

        case 0:
            printf("\nGracias por utilizar");
            break;

        }



    }
    while(opc != 0);



    return 0;
}
