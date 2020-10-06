
#include "pantalla.h"

int cont = 1;

int MostrarPantallaPorLegajo(ePantalla listado[], int tam){

  int index = buscarId(listado,tam);


    if(index != -1){

    mostrarPantalla(listado[index]);
    }else{

    printf("\nNo existen resultados para la busqueda.\n");
    }



    return index;
}


void Hardcodeo(ePantalla listado[], int tam)
{

    int ids[5] = {1,2,3,4,5};
    char nombres[5][50] = {"Pantalla 1 ","Pantalla 2","Pantalla 3","Pantalla 4","Pantalla 5"};
    char direcciones[5][50] = {"Hernandarias 957 ","Av Patricios 1052 ","Av 9 de julio 509","Av Corrientes 888","Moreno 500"};
    float precios[5] = {15999,11699.99,56000,120000,13000};

    for(int i = 0; i< 5; i++)
    {


        listado[i].idPantalla =ids[i];
        strcpy(listado[i].nombre,nombres[i]);
        strcpy(listado[i].direccion,direcciones[i]);
        listado[i].precioPublicidad = precios[i];

        listado[i].estado = OCUPADO;

    }


}




void baja(ePantalla listado[], int tam)
{

    int index;
    char rta;

    index = buscarId(listado,tam);


    if(index != -1)
    {

        printf("\n  Legajo encontrado \n ");
        mostrarPantalla(listado[index]);
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

void modificarPantalla(ePantalla listado[], int tam)
{

    int opc;
    int index;
    char auxString[200];


    char rta;

    index = buscarId(listado,tam);





    if(index != -1)
    {



        menuModificacion();
        opc = getInt("\nIngrese opcion: ","\nError,Ingrese opcion correcta");


        switch(opc)
        {


        case 1:

            getonlyAlphanumeric(auxString,"\nIngrese nuevo nombre: ","\nNombre invalido");

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


             getonlyAlphanumeric(auxString,"\nIngrese direccion nueva: ","\nDireccion invalida\n");

            rta = verificarSN("\nEsta seguro que desea cambiar la direccion? s/n: ");

            if(rta == 's')
            {

                strcpy(listado[index].direccion,auxString);
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

    }else{

        printf("\nLegajo no encontrado\n");

    }
}





int buscarId(ePantalla listado[], int tam)
{

    int index  = -1;
    int legajo;
    legajo = getInt("\nIngrese ID: ","\nError ID incorrecto");




        for(int i = 0; i<=tam; i++)
        {

            if(listado[i].estado == OCUPADO)
            {

                if(listado[i].idPantalla == legajo)
                {


                    index = i;
                    break;


                }



            }


        }








    return index;

}

void mostrarListaDePantallas(ePantalla listado[],int tam)
{

    printf("%s%35s%35s%35s\n","Id","Nombre","direccion","precio De Publicidad");


    for(int i = 0; i<tam; i++)
    {

        if(listado[i].estado == OCUPADO)
        {

            mostrarPantalla(listado[i]);


        }


    }


}



void mostrarPantalla(ePantalla pantalla)
{

    printf("%d%35s%35s%35.2f\n",pantalla.idPantalla,pantalla.nombre,pantalla.direccion,pantalla.precioPublicidad);




}




void Alta(ePantalla listado[], int tam)
{

    ePantalla aux;
    int index;
    char rta;

    index =  buscarIndiceLibre(listado,tam);

    if(index != -1)
    {



        aux.idPantalla = cont++;
        getonlyAlphanumeric( aux.nombre,"\nIngrese nombre: ","\nNombre invalido");
        getOnlyLetters( aux.direccion,"\nIngrese direccion: ","\ndireccion invalida");
        aux.precioPublicidad = getFloat("\nIngrese precio de publicidad:");
        aux.estado = OCUPADO;


        rta = verificarSN("Esta seguro que desea ingresar esta pantalla? s/n");

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






int buscarIndiceLibre(ePantalla listado[], int tam)
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

void inicializarEstado(ePantalla listado[], int tam)
{
    int i;
    for( i = 0; i< tam; i++)
    {


        listado[i].estado = LIBRE;

    }


}

void menuModificacion()
{

    printf("\n\t\t*******Menu de modificaciones*******\n1-Modificar Nombre\n2-Modificar direccion\n3-ModificarPrecio\n0-Salir");

}

int cantidadDePantallasActivas(ePantalla listadoPantallas[],int tam)
{

    int cantDePantallasCargadas;
    for(int i = 0; i<tam; i++)
    {

        if(listadoPantallas[i].estado == OCUPADO )
        {
            cantDePantallasCargadas ++;

        }

    }

    return cantDePantallasCargadas;

}

int retornarMayor(int numeros[], int cant)
{

    int max;
    max = INT_MIN;
    for(int i = 0; i<cant; i++)
    {

        if(max < numeros[i])
        {

            max = numeros[i];
        }

    }
    return max;
}
