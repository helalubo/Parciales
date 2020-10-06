#include "abonado.h"

int cont = 1;


int MostrarAbonadoPorLegajo(eAbonado listado[], int tam)
{

    int index = buscarLegajo(listado,tam);


    if(index != -1)
    {

        mostrarAbonado(listado[index]);
    }
    else
    {

        printf("\nNo existen resultados para la busqueda.\n");
    }



    return index;
}


void Hardcodeo(eAbonado listado[], int tam)
{

    int ids[5] = {1,2,3,4,5};
    char nombres[5][20] = {"Itachi","Sasuke","Naruto","Hinata","Sakura"};
    char apellidos[5][20] = {"Uchiha","Uchiha","Uzumaki","hyuga","Haruno"};
    char numeros[5][20] = {"43033913","43996655","77779999","58851236","43039112"};

    for(int i = 0; i< 5; i++)
    {


        listado[i].id =ids[i];
        strcpy(listado[i].nombre,nombres[i]);
        strcpy(listado[i].apellido,apellidos[i]);
        strcpy(listado[i].numero,numeros[i]);

        listado[i].estado = OCUPADO;

    }


}




void baja(eAbonado listado[], int tam)
{

    int index;
    char rta;

    index = buscarLegajo(listado,tam);


    if(index != -1)
    {

        printf("\n  Legajo encontrado \n ");
        mostrarAbonado(listado[index]);
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

void modificarAbonado(eAbonado listado[], int tam)
{

    int opc;
    int index;
    char auxString[200];


    char rta;

    index = buscarLegajo(listado,tam);





    if(index != -1)
    {


        mostrarAbonado(listado[index]);
        menuModificacion();
        opc = getInt("\nIngrese opcion: ");


        switch(opc)
        {


        case 1:

            getOnlyLetters(auxString,"\nIngrese nuevo nombre: ","\nNombre invalido");

            rta = verificarSN("\nEsta seguro que desea cambiar el nombre? s/n: ");

            if(rta == 's')
            {


                strcpy(listado[index].nombre,auxString);
                printf("\n Se ha cambiado el valor exitosamente.");

            }
            else
            {

                printf("\nCAMBIO ABORTADO.");
            }



            break;

        case 2:


            getOnlyLetters(auxString,"\nIngrese nuevo apellido: ","\nApellido invalido.");

            rta = verificarSN("\nEsta seguro que desea cambiar el apellido? s/n: ");

            if(rta == 's')
            {

                strcpy(listado[index].apellido,auxString);
                printf("\n Se ha cambiado el valor exitosamente.");

            }
            else
            {

                printf("\nCAMBIO ABORTADO.");
            }
            break;



        default:
            printf("\nOpcion invalida.\n");

        }

    }
    else
    {

        printf("\nLegajo no encontrado\n");

    }
}





int buscarLegajo(eAbonado listado[], int tam)
{

    int index  = -1;
    int legajo;
    legajo = getInt("\nIngrese legajo: ");




    for(int i = 0; i<=tam; i++)
    {

        if(listado[i].estado == OCUPADO)
        {

            if(listado[i].id == legajo)
            {


                index = i;
                break;


            }



        }


    }








    return index;

}

void mostrarListaDeAbonados(eAbonado listado[],int tam)
{

    printf("%16s%16s%16s%16s\n","Id","Nombre","Apellido","Numero");


    for(int i = 0; i<tam; i++)
    {

        if(listado[i].estado == OCUPADO)
        {

            mostrarAbonado(listado[i]);


        }


    }


}



void mostrarAbonado(eAbonado abonado)
{

    printf("%16d%16s%16s%16s\n",abonado.id,abonado.nombre,abonado.apellido,abonado.numero);






}




void Alta(eAbonado listado[], int tam)
{

    eAbonado aux;
    int index;
    char rta;

    index =  buscarIndiceLibre(listado,tam);

    if(index != -1)
    {



        aux.id = cont++;
        getOnlyLetters( aux.nombre,"\nIngrese nombre: ","\nNombre invalido");
        getOnlyLetters( aux.apellido,"\nIngrese apellido: ","\nNombre invalido");
        getPhoneNumber(aux.numero,"\nIngrese numero telefonico","\nNumero invalido");
        aux.estado = OCUPADO;


        rta = verificarSN("Esta seguro que desea ingresar este abonado? s/n");

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


int buscarIndiceLibre(eAbonado listado[], int tam)
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

void inicializarEstado(eAbonado listado[], int tam)
{
    int i;
    for( i = 0; i< tam; i++)
    {


        listado[i].estado = LIBRE;

    }


}

void menuModificacion()
{

    printf("\n\t\t*******Menu de modificaciones*******\n1-Modificar Nombre\n2-Modificar apellido\n");

}


int cantidadDeAbonadosActivos(eAbonado listadoAbonados[],int tam)
{

    int cantAbonadosCargadas;
    for(int i = 0; i<tam; i++)
    {

        if(listadoAbonados[i].estado != LIBRE )
        {
            cantAbonadosCargadas ++;

        }

    }

    return cantAbonadosCargadas;

}

///////////////////////////////////////////////////

