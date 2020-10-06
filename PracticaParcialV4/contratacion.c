
#include "contratacion.h"

int contContratacion = 0;


/*
int MostrarPantallaPorLegajo(ePantalla listado[], int tam){

  int index = buscarId(listado,tam);


    if(index != -1){

    mostrarPantalla(listado[index]);
    }else{

    printf("\nNo existen resultados para la busqueda.\n");
    }



    return index;
}
*/


void HardcodeoContratacion(eContratacion listado[], int tam)
{

    int ids[5] = {1,2,3,4,5};
    int idPantallas[5] = {1,2,3,4,1};
    char contenido[5][320] = {"Aventuras","Comedia","Terror","Drama","Fantasia", "otros"};
    char cuilCliente[5][20] = {"20-39068081-4","21-27068081-7","20-89068081-4","20-890685451-4","21-45852574-9"};
    int dias[5] = {7,6,5,4,3};
    char archivos[5][20] = {"aventuras.avi","terror2.avi","comedia5.avi","ufo.avi","free.avi"};


    for(int i = 0; i< 5; i++)
    {


        listado[i].idContratacion =ids[i];
           listado[i].idPantalla =idPantallas[i];

        strcpy(listado[i].contenidoPublicitario,contenido[i]);
        strcpy(listado[i].cuilCliente,cuilCliente[i]);

       listado[i].cantidadDeDias = dias[i];

    strcpy(listado[i].nombreArchivoVideo,archivos[i]);
        listado[i].estado = OCUPADO;

    }


}




void bajaContratacion(eContratacion listado[], int tam)
{

    int index;
    char rta;

    index = buscarPorCuil(listado,tam);


    if(index != -1)
    {

        printf("\n  Cuil encontrado \n ");
        mostrarContrataciones(listado[index]);
        rta = verificarSN("\nDesea dar de baja s/n: ");

        if(rta == 's')
        {


            listado[index].estado = LIBRE;


        }
        else
        {

            printf("\n LA BAJA A SIDO ABORTADA.");

        }







    }
    else
    {

        printf("\n LA BAJA A SIDO ABORTADA.");

    }





}




int buscarPorCuil(eContratacion listado[], int tam)
{

    int index  = -1;
    char cuil[20];
    getString(cuil,"\nIngrese Cuil: ","\nError Cuil incorrecto");





        for(int i = 0; i<=tam; i++)
        {

            if(listado[i].estado == OCUPADO)
            {

                if(strcmp(cuil,listado[i].cuilCliente)==0)
                {


                    index = i;
                    break;


                }



            }


        }








    return index;

}





void mostrarListaDeContrataciones(eContratacion listado[],int tam)
{

    printf("%s%35s%35s%35s%35s\n","Id","cuil Cliente","contenido","Id pantalla","Cantidad de dias");


    for(int i = 0; i<tam; i++)
    {

        if(listado[i].estado == OCUPADO)
        {

            mostrarContrataciones(listado[i]);


        }


    }


}



void  mostrarContrataciones(eContratacion contrato)
{

    printf("%d%35s%35s%35d%35d\n",contrato.idContratacion
                                ,contrato.cuilCliente
                                ,contrato.contenidoPublicitario
                                ,contrato.idPantalla
                                ,contrato.cantidadDeDias);




}



void AltaContrataciones(eContratacion listado[], int tam)
{

    eContratacion aux;
    int index;
    char rta;

    index =  buscarIndiceLibreContrataciones(listado,tam);

    if(index != -1)
    {





        aux.idContratacion = contContratacion++;
        aux.idPantalla = getInt("\nIngrese Id de pantalla");
        getString(aux.contenidoPublicitario,"\nIngrese tipo de contenido: ","\nContenido invalido");
        getString(aux.cuilCliente,"\nIngrese Cuil: ","\Cuil invalido"); // hacer validacion para ingresar cuil
        aux.cantidadDeDias = getInt("\nIngrese cantidad de dias de contratacion: ","\nCantidad invalida");
        getString(aux.nombreArchivoVideo,"\nIngrese nombre de contenido: ","\nContenido invalido");


        aux.estado = OCUPADO;


        rta = verificarSN("Esta seguro que desea ingresar esta Contratacion? s/n");

        if(rta='s')
        {



            listado[index] = aux;

            printf("\nOperacion exitosa\n");

        }
        else
        {
            printf("\nOperacion cancelada\n");
        }
    }
    else
    {
        printf("No hay lugar");

    }



}



int buscarIndiceLibreContrataciones(eContratacion listado[], int tam)
{


    int index = -1;
    int i;

    for( i = 0; i< tam; i++)
    {
        if(listado[i].estado == LIBRE )

            index =i;


    }





    return index;


}


void inicializarEstadoContratacion(eContratacion listado[], int tam)
{
    int i;
    for( i = 0; i< tam; i++)
    {


        listado[i].estado = LIBRE;

    }


}

void menuModificacionContratacion()
{

    printf("\n\t\t*******Menu de modificaciones*******\n1-Modificar Cantidad de dias \n0-Salir");

}

int cantidadDeContratacionesActivas(eContratacion listadoPantallas[],int tam)
{

    int cantDeContratacionesCargadas = 0;
    for(int i = 0; i<tam; i++)
    {

        if(listadoPantallas[i].estado == OCUPADO )
        {
            cantDeContratacionesCargadas ++;

        }

    }

    return cantDeContratacionesCargadas;

}



