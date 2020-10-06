
#include "Cliente.h"
//nombre, apellido,localidad,teléfono,edad,sexo)

int cont = 1;

int MostrarClientePorLegajo(eCliente listado[], int tam)
{

    int index = buscarId(listado,tam);


    if(index != -1)
    {

        mostrarCliente(listado[index]);
    }
    else
    {

        printf("\nNo existen resultados para la busqueda.\n");
    }



    return index;
}

//nombre, apellido,localidad,teléfono,edad,sexo)
void Hardcodeo(eCliente listado[], int tam)
{




    int ids[5] = {1,2,3,4,5};
    char nombres[5][50] = {"Itachi","Sasuke","Naruto","Neji","Sakura"};
    char apellidos[5][50] = {"Uchiha","Uchiha","Uzumaki","Hyuga","Haruno"};
    char cuils[5][50] = {"20390680814","20658425698","20358633654","20365996354","21354852564"};


    for(int i = 0; i< 5; i++)
    {


        listado[i].idCliente =ids[i];
        strcpy(listado[i].nombre,nombres[i]);
        strcpy(listado[i].apellido,apellidos[i]);

        strcpy(listado[i].cuil,cuils[i]);


        listado[i].estado = OCUPADO;

    }


}




void baja(eCliente listado[], int tam)
{

    int index;
    char rta;

    index = buscarId(listado,tam);


    if(index != -1)
    {

        printf("\n  Legajo encontrado \n ");
        mostrarCliente(listado[index]);
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


    printf("\n LA BAJA A SIDO ABORTADA.");







}

void modificarCliente(eCliente listado[], int tam)
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


            getOnlyLetters(auxString,"\nIngrese nuevo apellido: ","\nApellido invalido\n");

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
        case 3:


            getCuil(auxString,"\nIngrese Cuil","\nError,Cuil invalido");

            rta = verificarSN("\nEsta seguro que desea cambiar la direccion? s/n: ");

            if(rta == 's')
            {


                strcpy(listado[index].cuil,auxString);
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





int buscarId(eCliente listado[], int tam)
{

    int index  = -1;
    int legajo;
    legajo = getInt("\nIngrese ID: ","\nError ID incorrecto");




    for(int i = 0; i<=tam; i++)
    {

        if(listado[i].estado == OCUPADO)
        {

            if(listado[i].idCliente == legajo)
            {


                index = i;
                break;


            }



        }


    }








    return index;

}


void mostrarListaDeClientes(eCliente listado[],int tam)
{

    printf("%s%35s%35s%35s\n","Id","Nombre","apellido","cuil");




    for(int i = 0; i<tam; i++)
    {

        if(listado[i].estado == OCUPADO)
        {

            mostrarCliente(listado[i]);


        }


    }


}



void mostrarCliente(eCliente cliente)
{

    printf("%d%35s%35s%35s\n",cliente.idCliente
           ,cliente.nombre
           ,cliente.apellido
           ,cliente.cuil);



}




void Alta(eCliente listado[], int tam)
{




    eCliente aux;
    int index;
    char rta;

    index =  buscarIndiceLibre(listado,tam);

    if(index != -1)
    {



        aux.idCliente = cont++;
        getOnlyLetters(aux.nombre,"\nIngrese nombre: ","\nNombre invalido");
        getOnlyLetters( aux.apellido,"\nIngrese apellido: ","\apellido invalido");

        getCuil(aux.cuil,"\nIngrese Cuil: ","\nError, cuil invalido");



        rta = verificarSN("Esta seguro que desea ingresar esta pantalla? s/n");

        if(rta=='s')
        {


            aux.estado = OCUPADO;
            listado[index] = aux;

            printf("\nOperacion exitosa, su ID es %d\n",listado[index].idCliente);

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






int buscarIndiceLibre(eCliente listado[], int tam)
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

void inicializarEstado(eCliente listado[], int tam)
{
    int i;
    for( i = 0; i< tam; i++)
    {


        listado[i].estado = LIBRE;

    }


}

void menuModificacion()
{
//(nombre, apellido,localidad,teléfono,edad,sexo) .
    printf("\n\t\t*******Menu de modificaciones*******\n1-Modificar Nombre\n2-Modificar apellido\n3-Modificar cuil\n0-Salir");

}

int cantidadDeClientesActivas(eCliente listado[],int tam)
{

    int cantClientes;
    for(int i = 0; i<tam; i++)
    {

        if(listado[i].estado == OCUPADO )
        {
            cantClientes ++;

        }

    }

    return cantClientes;

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

int retornarMenor(int numeros[], int cant)
{

    int min;
    min = INT_MAX;

    for(int i = 0; i<cant; i++)
    {

        if(min > numeros[i])
        {

            min = numeros[i];
        }

    }
    return min;
}


