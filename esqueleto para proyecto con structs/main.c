


#include "llamada.h"



int main()
{

    eAbonado listadoDeAbonados[T];
    inicializarEstado(listadoDeAbonados,T);
    Hardcodeo(listadoDeAbonados,T);

    eLlamada listadoLlamadas[TLLAMADAS];
    inicializarEstadoLlamada(listadoLlamadas,TLLAMADAS);
    HardcodeoLlamadas(listadoLlamadas,TLLAMADAS);

    mostrarListaDeAbonados(listadoDeAbonados,T);

//******************************************************************************************
    //  modificarAbonado(listadoDeAbonados,T);
    //  MostrarAbonadoPorLegajo(listadoDeAbonados,T);
    //  baja(listadoDeAbonados,T);
    //  mostrarListaDeAbonados(listadoDeAbonados,T);
//   NuevaLlamada(listadoLlamadas,TLLAMADAS,listadoDeAbonados,T);
//   finLlamada(listadoLlamadas,TLLAMADAS,listadoDeAbonados,T);

    //  printf("%8s %8s %8s %8s %8s\n","id","idAbonado","motivo","estado","demora");



    //nombreYApellidoDelAbonadoConMasReclamos(listadoLlamadas,TLLAMADAS,listadoDeAbonados,T);


    // reclamoMasRealizado(listadoLlamadas,TLLAMADAS);
    // reclamoMasDemoroEnPromedio(listadoLlamadas,TLLAMADAS);

    int opc;


    do
    {
        printf("\n1-Alta Abonado\n2-Modificar abonado\n3-Baja Abonado\n4-Nueva llamada\n5-Fin de llamada\n 6-Informar\n0-Salir");
        opc= getInt("\nIngrese opcion: ");

        switch(opc)
        {

        case 1:

                 system("cls");

                Alta(listadoDeAbonados,T);
                system("pause");
                system("cls");

            break;


              case 2:
                  system("cls");
                  modificarAbonado(listadoDeAbonados,T);
                  system("pause");
                  system("cls");
            break;


              case 3:
                  system("cls");
                    baja(listadoDeAbonados,T);
                    system("pause");
                    system("cls");
            break;



              case 4 :
                  system("cls");
                  NuevaLlamada(listadoLlamadas,TLLAMADAS,listadoDeAbonados,T);
                  system("pause");
                  system("cls");
            break;


              case 5:
                  system("cls");
                  finLlamada(listadoLlamadas,TLLAMADAS,listadoDeAbonados,T);
                  system("pause");
                  system("cls");
            break;


              case 6:
                  system("cls");
                  nombreYApellidoDelAbonadoConMasReclamos(listadoLlamadas,TLLAMADAS,listadoDeAbonados,T);
                  reclamoMasRealizado(listadoLlamadas,TLLAMADAS);
                  reclamoMasDemoroEnPromedio(listadoLlamadas,TLLAMADAS);
                  system("pause");
                  system("cls");
            break;



              case 0:
                  printf("\nSaliendo del programa");
            break;

            default: printf("\nOpcion invalida\n");
        }

    }
    while(opc != 0);


}



