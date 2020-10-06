

//#include "Mascota.h"
#include "Cliente.h"
#define TMASCOTAS 20
#define TCLIENTES 20

int main()
{
    int sizePunteroAClientes;


    ///REFACTORIZAR A MEMORIA DINAMICA
    //  eCliente* pC;
    eCliente* punterosAClientes[TCLIENTES];

    eCliente_inicializarPunteros(punterosAClientes,TCLIENTES);
       sizePunteroAClientes = sizeof(punterosAClientes);

   // Alta(punterosAClientes,TCLIENTES);
    eCliente* maite;
    eCliente* ale;
   maite= eCliente_newParametros("Maite","Rodriguez","43033913","CABA",15,'f');
   ale= eCliente_newParametros("Alejandro","De Moraiz","1564491741","CABA",24,'m');

    punterosAClientes[1] = maite;
    punterosAClientes[2] = ale;

    eCliente_printList(punterosAClientes,TCLIENTES);

    printf("\n**************\n");

    eCliente_borrarPorIdArray(punterosAClientes,TCLIENTES);



    eCliente_printList(punterosAClientes,TCLIENTES);





    /*
    pC = eCliente_new();
    pC->edad = 24;
    punterosAClientes[0] = pC;

    //  printf("\n%d\n",punterosAClientes[0]->edad);

    */








    /*
        eCliente** listadoClientes = NULL;
        //eCliente** pAux = NULL;
        listadoClientes = cliente_crearLista();
        initArray(listadoClientes,0);
        Alta(listadoClientes);

        */


    /*
    eCliente* auxCliente;
    auxCliente = eCliente_newConParametros("De moraiz","Alejandro");

    eCliente* auxCliente2;
    auxCliente2 = eCliente_newConParametros("Rodriguez","Maite");

    listadoClientes[0]= auxCliente;
    listadoClientes[1]= auxCliente2;

    imprimirClientes(listadoClientes);
    */

    //  int sizeListadoDeClientes = 2;
//   Hardcodeo(listadoClientes,TCLIENTES);




    //eMascota listadoMascotas[TMASCOTAS];
    //inicializarEstadoMascota(listadoMascotas,TMASCOTAS);
    //  HardcodeoMascota(listadoMascotas,TMASCOTAS);


    int opc;


    do
    {


        printf("\n1-Alta mascota\n2-Baja Mascota\n3-Ver listado de clientes y mascotas\n4-Modificar mascota\n5-Mostrar mascotas con duenio\n6-Alta cliente");
        printf("\n7-Mostrar clientes que tienen perros\n8-Mostrar clientes que tienen gatos\n9-Mascotas con sun duenios nombres\n10-Duenios con gatos ordenados alfabeticamente por nombre\n11-Mostrar duenios con mas de una mascota de la boca");
        printf("\n12-Mostrar cantidad de duenios con mas de 50 anios\n13-Mostrar duenios con mas de 50 anios alfabeticamente\n14-Promedio duenios mujeres\n15-Mostrar  cantidad de mascotas con raza otra\n16-Mostrar mascota con mas de 7 anios\n17-CnatidadDeMascotasMacho");
        printf("\n18-Mostrar duenios de gatos con mas de 30 anios\n19-Promedio de duenios con gatos\n20-Mostrar cliente con mayor edad\n0-salir\n");
        opc = getInt("\nIngrese opcion: ","Ingrese opcion valida");
        /*
                switch(opc)
                {


                case 1:
                    AltaMascotas(listadoMascotas,TMASCOTAS,listadoClientes,TCLIENTES);
                    break;

                case 2:
                    bajaMascota(listadoMascotas,TMASCOTAS);
                    break;


                case 3:
                    mostrarClienteConMascota(listadoMascotas,TMASCOTAS,listadoClientes,TCLIENTES);
                    break;

                case 4:
                    modificarMascota(listadoMascotas,TMASCOTAS);
                    break;

                case 5:
                    mostrarListaDeMascotas(listadoMascotas,TMASCOTAS,listadoClientes,TCLIENTES);
                    break;

                case 6:
                    Alta(listadoClientes,TCLIENTES);
                    break;
                case 7:
                    mostrarDueniosConPerros(listadoMascotas,TMASCOTAS,listadoClientes,TCLIENTES);
                    break;

                case 8:
                    mostrarDueniosConGatos(listadoMascotas,TMASCOTAS,listadoClientes,TCLIENTES);
                    break;


                case 9:
                    nombresMascotasYsusDuenios(listadoMascotas,TMASCOTAS,listadoClientes,TCLIENTES);
                    break;

                case 10:
                    duenosConGatosOrdenadosAlfabeticamente(listadoMascotas,TMASCOTAS,listadoClientes,TCLIENTES);
                    break;


                case 11:
                    mostrarDueniosLaBocaConMasDeUnaMascota(listadoMascotas,TMASCOTAS,listadoClientes,TCLIENTES);
                    break;


                case 12:
                    mostrarCantidadDeDueniosConMasDe50Anios(listadoClientes,TCLIENTES);
                    break;


                case 13:
                    mostrarDueniosConMasDe50AniosAlfabeticamente(listadoClientes,TCLIENTES);
                    break;


                case 14:
                    promedioDeDueniosMujeres(listadoClientes,TCLIENTES);

                    break;

                case 15:
                    mostrarCantidadDeMascotaConRazaOtra(listadoMascotas,TMASCOTAS,listadoClientes,TCLIENTES);


                case 16:
                    mostrarMascotasCon7aniosOMas(listadoMascotas,TMASCOTAS);

                    break;

                case 17:
                    mostrarCantidadDeMascotasMacho(listadoMascotas,TMASCOTAS);
                    break;


                case 18:
                    mostrarDueniosDeGatosConMasDe30Anios(listadoMascotas,TMASCOTAS,listadoClientes,TCLIENTES);
                    break;

                case 19:
                    promedioDueniosConMascotasGatos(listadoMascotas,TMASCOTAS,listadoClientes,TCLIENTES);
                    break;

                     case 20:
                    mostrarClienteConMayorEdad(listadoClientes,TCLIENTES);
                    break;

                    break;


                case 0:
                    printf("\nGracias por utilizar la app");
                    break;








                }
        */
    }
    while(opc !=0);


}

