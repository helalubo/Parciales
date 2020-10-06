
#include "pantalla-contratacion.h"



int main()
{

    ePantalla listadoDePantallas[T];

    inicializarEstado(listadoDePantallas,T);

    Hardcodeo(listadoDePantallas,T);
    mostrarListaDePantallas(listadoDePantallas,T);



    eContratacion listadoDeContrataciones[T];

    inicializarEstadoContratacion(listadoDeContrataciones,T);

    HardcodeoContratacion(listadoDeContrataciones,T);


    printf("\n**************************************************\n");
     mostrarListaDePantallas(listadoDePantallas,T);

         printf("\n**************************************************\n");

         mostrarListaDeContrataciones(listadoDeContrataciones,T);
  //  Consultafacturacion(listadoDeContrataciones,T,listadoDePantallas,T);

//******************************************************************************************
  //  modificarAbonado(listadoDeAbonados,T);
  //  MostrarAbonadoPorLegajo(listadoDeAbonados,T);
  //  baja(listadoDeAbonados,T);
  //  mostrarListaDeAbonados(listadoDeAbonados,T);

   // MostrarContratosPorCuil(listadoDeContrataciones,T,listadoDePantallas,T);
       printf("\n**************************************************\n");

    mostrarPrecioTotal(listadoDeContrataciones,T,listadoDePantallas,T);
//******************************************************************************************

}


