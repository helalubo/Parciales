#include "pantalla-contratacion.h"






int MostrarContratosPorCuil(eContratacion listContratos[], int tamContratos, ePantalla listPantallas[],int tamPantallas)
{

    int cantContratos;
    char auxCuil[20];
    int index ;
    int flag =0;



    cantContratos = cantidadDeContratacionesActivas(listContratos,tamContratos);

    index =  buscarPorCuil(listContratos,tamContratos);

    strcpy(auxCuil,listContratos[index].cuilCliente);


    for(int i = 0; i<cantContratos; i++)
    {

        if(listContratos[i].estado == OCUPADO)
        {

            if(strcmp(auxCuil,listContratos[i].cuilCliente)==0)
            {


                mostrarContrataciones(listContratos[i]);

                flag= 1;
            }


        }


    }

    if(flag ==0)
    {

        printf("\nNo se encontraron resultados\n ");
    }

    return index;

}

void mostrarPrecioTotal(eContratacion listContratos[], int tamContratos, ePantalla listPantallas[],int tamPantallas)
{

    int index;

    char auxCuil[20];
  //  int cantContrataciones = cantidadDeContratacionesActivas(listContratos,tamContratos);
    //int idPantalla;
    float totalAPagar;

    index = MostrarContratosPorCuil(listContratos,tamContratos,listPantallas,tamPantallas);

    strcpy(auxCuil,listContratos[index].cuilCliente);



    for(int i = 0; i<tamContratos; i++)
    {


        for(int k = 0; k<tamPantallas; k++)
        {


            if(strcmp(auxCuil,listContratos[i].cuilCliente)==0)
            {

                    if(listContratos[i].idPantalla == listPantallas[k].idPantalla )
                    {


                totalAPagar= (float)listPantallas[k].precioPublicidad * listContratos[i].cantidadDeDias;
                printf("\n***************************************************************\n");
                printf("El total a pagar es de %.2f \n",totalAPagar);


                    }
               // mostrarContrataciones(listContratos[i]);

            }


        }





    }


}
