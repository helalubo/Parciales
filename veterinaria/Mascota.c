
#include "Mascota.h"


int contMascota = 11;



void HardcodeoMascota(eMascota listado[], int tam)
{

    int idsMascotas[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int idsClientes[12] = {1,1,2,2,2,3,3,4,5,5,5,6};
    char nombres[12][51] = {"gata1","gata2","perro1","perro2","gato1","perro2","iguana","perro3","gato2","gato3","perro4","akamaru"};
    int tipoMascota[12] = {1,1,2,2,1,2,3,2,1,1,2,1};
    char raza[12][51] = {"Otra","Otra","Otra","Otra","Otra","Pitbull","Amazonica","Labrador","Otra","Otra","Bulldog","amarillo"};
    int edades[12] = {8,4,4,8,6,2,3,6,6,7,7,8};
    float pesos[12] = {11.2,10.8,6.6,7.7,8,9,2,6,4,9,6,7};
    char sexos[12] = {'f','f','m','m','m','m','f','m','m','m','m','m'};


    for(int i = 0; i< 12; i++)
    {


        listado[i].idMascota =idsMascotas[i];
        listado[i].idCliente =idsClientes[i];
        strcpy(listado[i].nombre,nombres[i]);
        listado[i].tipo =tipoMascota[i];
        strcpy(listado[i].raza,raza[i]);
        listado[i].edad =edades[i];
        listado[i].peso =pesos[i];
        listado[i].sexo =sexos[i];
        listado[i].estado = OCUPADO;

    }


}




void bajaMascota(eMascota listado[], int tam)
{

    int index;
    char rta;


    index = buscarPorIdMascota(listado,tam);


    if(index != -1)
    {

        printf("\n  id encontrado \n ");
        mostrarMascota(listado[index]);
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


    printf("\nId no encontrado\n");







}




int buscarPorIdMascota(eMascota listado[], int tam)
{

    int index  = -1;
    int legajo;
    legajo = getInt("\nIngrese id: ","\nid invalido");




    for(int i = 0; i<=tam; i++)
    {

        if(listado[i].estado == OCUPADO)
        {

            if(listado[i].idMascota == legajo)
            {


                index = i;
                break;


            }



        }


    }








    return index;




}





void mostrarListaDeMascotas(eMascota listado[],int tam, eCliente listadoCliente[],int tamClientes)
{

    printf("%s%16s%16s%16s%16s%16s%16s%16s%16s\n","Nombre duenio","idMascota","idCliente","nombre","tipo","raza","edad","peso","sexo");


    for(int k =0 ; k<tamClientes; k++)
    {




        for(int i = 0; i<tam; i++)
        {

            if(listado[i].estado == OCUPADO)
            {



                if(listadoCliente[k].idCliente == listado[i].idCliente)
                {
                    printf("%s",listadoCliente[k].nombre);
                    mostrarMascota(listado[i]);
                }


            }


        }

    }


}



void  mostrarMascota(eMascota mascota)
{
    char auxString[21];

    switch(mascota.tipo)
    {

    case 1:
        strcpy(auxString,"Gato");
        break;

    case 2:
        strcpy(auxString,"Perro");
        break;

    case 3:
        strcpy(auxString,"otro");
        break;

    }




    printf("%16d%16d%16s%16s%16s%16d%16.2f%16c\n"
           ,mascota.idMascota
           ,mascota.idCliente
           ,mascota.nombre
           ,auxString
           ,mascota.raza
           ,mascota.edad
           ,mascota.peso
           ,mascota.sexo);




}


////////////////////////////////////primer cambio
void AltaMascotas(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes)
{

    eMascota aux;
    int index;
    char rta;

    int idAux;


    index =  buscarIndiceLibreMascotas(listado,tam);

    if(index != -1)
    {





        aux.idMascota = contMascota++;
        mostrarListaDeClientes(listadoClientes,tamClientes);
        idAux= buscarId(listadoClientes,tamClientes);

        while(idAux == -1)
        {
            printf("\nError id cliente no existente\n ");
            idAux= buscarId(listadoClientes,tamClientes);
        }

        aux.idCliente = listadoClientes[idAux].idCliente;


        getString(aux.nombre,"\nIngrese nombre: ","\nContenido invalido");

        aux.tipo = getNumberWithDefinedRange("\n1-Gato\n2-Perro\n3-Otro\nIngrese tipo: ",3,1,"\nIngrese una de las opciones disponibles");
        getString(aux.raza,"\nIngrese raza: ","\nContenido invalido");
        aux.edad = getInt("\nIngrese edad: ","\nEdad invalida");
        aux.peso = getFloat("\nIngrese peso: ");
        aux.sexo = verificarMF("\nm-Macho\nf-Hembra\nIngrese sexo: ");








        rta = verificarSN("\nEsta seguro que desea ingresar esta Mascota? s/n");

        if(rta=='s')
        {

            aux.estado = OCUPADO;

            listado[index] = aux;

            printf("\nOperacion exitosa\n");

        }
        else
        {
            printf("\nOperacion cancelada\n");
        }
    }

    printf("No hay lugar");





}



int buscarIndiceLibreMascotas(eMascota listado[], int tam)
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


void inicializarEstadoMascota(eMascota listado[], int tam)
{
    int i;
    for( i = 0; i< tam; i++)
    {


        listado[i].estado = LIBRE;

    }


}

void menuModificacionMascota()
{
    // printf("%s%35s%35s%35s%35s%35s%35s%35s\n","idMascota","idCliente","nombre","tipo","raza","edad","peso","sexo");
    printf("\n\t\t*******Menu de modificaciones*******\n1-Modificar nombre\n2-tipo\n3-raza\n4-edad\n5-peso\n6-sexo \n0-Salir");

}

int cantidadDeMascotasActivas(eMascota listado[],int tam)
{

    int cant = 0;
    for(int i = 0; i<tam; i++)
    {

        if(listado[i].estado == OCUPADO )
        {
            cant ++;

        }

    }

    return cant;

}


////////////
void modificarMascota(eMascota listado[], int tam)
{

    int opc;
    int index;
    char auxString[200];
    int auxEntero;
    float  auxFloat;
    char auxChar;


    char rta;

    index = buscarPorIdMascota(listado,tam);





    if(index != -1)
    {


        //    printf("\n\t\t*******Menu de modificaciones*******\n1-Modificar nombre\n2-tipo\n3-raza\n4-edad\n5-peso\n6-sexo \n0-Salir");
        menuModificacion();
        opc = getInt("\nIngrese opcion: ","\nOpcion invalida");


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


            auxEntero = getNumberWithDefinedRange("\n1-Gato\n2-Perro\n3-Otro\nIngrese tipo: ",3,1,"\nIngrese una de las opciones disponibles");

            rta = verificarSN("\nEsta seguro que desea cambiar el apellido? s/n: ");

            if(rta == 's')
            {

                listado[index].tipo = auxEntero;
                printf("\n Se ha cambiado el valor exitosamente.");

            }
            else
            {

                printf("\nCAMBIO ABORTADO.");
            }
            break;



        case 3:


            getString(auxString,"\nIngrese nueva raza: ","\nContenido invalido");

            rta = verificarSN("\nEsta seguro que desea cambiar la raza? s/n: ");

            if(rta == 's')
            {

                strcpy(listado[index].raza,auxString);
                printf("\n Se ha cambiado el valor exitosamente.");

            }
            else
            {

                printf("\nCAMBIO ABORTADO.");
            }
            break;


        case 4:


            auxEntero = getInt("\nIngrese edad: ", "\nEdad invalida");

            rta = verificarSN("\nEsta seguro que desea cambiar la edad? s/n: ");

            if(rta == 's')
            {

                listado[index].edad = auxEntero;
                printf("\n Se ha cambiado el valor exitosamente.");

            }
            else
            {

                printf("\nCAMBIO ABORTADO.");
            }
            break;

        case 5:


            auxFloat = getFloat("\nIngrese peso: ");
            rta = verificarSN("\nEsta seguro que desea cambiar el peso? s/n: ");

            if(rta == 's')
            {

                listado[index].peso = auxFloat;
                printf("\n Se ha cambiado el valor exitosamente.");

            }
            else
            {

                printf("\nCAMBIO ABORTADO.");
            }
            break;

        case 6:


            auxChar = verificarMF("\nm-Macho\nf-Hembra\nIngrese nuevo sexo: ");
            rta = verificarSN("\nEsta seguro que desea cambiar el peso? s/n: ");

            if(rta == 's')
            {

                listado[index].sexo = auxChar;
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

void mostrarClienteConMascota(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes)
{

    int flag;


    for(int i =0; i<tamClientes; i++)
    {

        flag =0;
        if(listadoClientes[i].estado==OCUPADO)
        {



            mostrarCliente(listadoClientes[i]);


        }


        for(int k =0; k<tam; k++)
        {


            if(listadoClientes[i].idCliente == listado[k].idCliente && listado[k].estado == OCUPADO)
            {
                mostrarMascota(listado[k]);
                flag = 1;

            }



        }



        if(flag == 0 && listadoClientes[i].estado == OCUPADO)
        {

            printf("\t\t\tNo tiene mascotas registradas\n");

        }







    }



}


void mostrarDueniosConPerros(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes)
{

    for(int i=0; i<tam; i++)
    {

        if(listado[i].tipo == 2)
        {
            mostrarMascota(listado[i]);

            for(int k = 0; k<tamClientes ; k++)
            {


                if(listado[i].idCliente == listadoClientes[k].idCliente && listadoClientes[k].estado == OCUPADO)
                {
                    mostrarCliente(listadoClientes[k]);
                    break;
                }





            }

        }





    }




}

void mostrarDueniosConGatos(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes)
{

    for(int i=0; i<tam; i++)
    {

        if(listado[i].tipo == 1)
        {
            mostrarMascota(listado[i]);

            for(int k = 0; k<tamClientes ; k++)
            {


                if(listado[i].idCliente == listadoClientes[k].idCliente && listadoClientes[k].estado == OCUPADO)
                {
                    mostrarCliente(listadoClientes[k]);
                    break;
                }





            }

        }





    }




}



void nombresMascotasYsusDuenios(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes)
{


    for(int i=0; i<tam; i++)
    {


        // printf("\t%16s",listado[i].nombre);

        for(int k = 0; k<tamClientes ; k++)
        {


            if(listado[i].idCliente == listadoClientes[k].idCliente && listadoClientes[k].estado == OCUPADO)
            {
                printf("\t%16s",listado[i].nombre);
                printf("\t%16s\n",listadoClientes[k].nombre);
                break;
            }





        }







    }







}


void duenosConGatosOrdenadosAlfabeticamente(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes)
{

    eMascota auxMascota;



    for(int i = 0; i<tam-1; i++)
    {



        for( int j = i+1; j<tam; j++)
        {

            if(stricmp(listado[i].nombre,listado[j].nombre)>0)
            {


                if(listado[i].estado == OCUPADO)
                {

                    auxMascota = listado[i];
                    listado[i] = listado[j];
                    listado[j] = auxMascota;
                }



            }


        }


    }


    for(int i=0; i<tam; i++)
    {




        for(int k = 0; k<tamClientes ; k++)
        {


            if(listado[i].idCliente == listadoClientes[k].idCliente && listadoClientes[k].estado == OCUPADO && listado[i].estado == OCUPADO)
            {

                if(listado[i].tipo == 1)
                {
                    printf("\t%16s",listado[i].nombre);
                    printf("\t%16s\n",listadoClientes[k].nombre);

                }




            }





        }







    }





}



void mostrarDueniosLaBocaConMasDeUnaMascota(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes)
{

    int cont;


    for(int i=0; i<tamClientes; i++)
    {
        cont = 0;

        if(stricmp(listadoClientes[i].localidad,"la boca")==0)
        {

            for(int k=0; i<tam; k++)

            {
                if(listadoClientes[i].idCliente == listado[k].idCliente)
                {

                    cont++;
                    break;
                }


            }



        }


        if(cont >0)
        {
            mostrarCliente(listadoClientes[i]);
        }


    }





}






void mostrarCantidadDeMascotaConRazaOtra(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes)
{


    int cont = 0;


    for(int i = 0; i<tam; i++)
    {

        if(stricmp(listado[i].raza,"otra")==0)
        {

            cont++;
        }



    }

    mostrarListaDeMascotas(listado,tam,listadoClientes,tamClientes);


    printf("\nLa cantidad de mascotas con raza como OTRA es de: %d ",cont);










}
void mostrarMascotasCon7aniosOMas(eMascota listado[], int tam)
{



    for(int i= 0; i<tam; i++)
    {

        if(listado[i].edad >= 7 && listado[i].estado == OCUPADO)
        {
            mostrarMascota(listado[i]);
        }
    }







}

void mostrarCantidadDeMascotasMacho(eMascota lista [], int tam)
{
    int cont = 0;

    for(int i = 0; i<tam; i++)
    {

        if(lista[i].sexo == 'm')
        {

            cont++;

        }






    }

    printf("\nLa cantidad de mascotas macho es de %d",cont);

}



///////////////


void mostrarDueniosDeGatosConMasDe30Anios(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes)
{


    for(int i = 0; i<tamClientes; i++)
    {

        if(listadoClientes[i].edad>=30)
        {

            for(int j = 0; j<tam; j++)

                if(listado[j].idCliente == listadoClientes[i].idCliente && listado[j].tipo == 1)
                {

                printf("\n\tNombre duenio: %s %s \t Edad duenio: %d\t Nombre mascota: %s\n",listadoClientes[i].nombre,listadoClientes[i].apellido,listadoClientes[i].edad, listado[j].nombre);


                }

            }
    }




}



void promedioDueniosConMascotasGatos(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes){



    int cont =0;
    int cantTotal = 0;
    float promedio;



   for(int i = 0; i<tamClientes; i++)
    {

        if(listadoClientes[i].estado == OCUPADO)
        {

            for(int j = 0; j<tam; j++)

                if(listado[j].idCliente == listadoClientes[i].idCliente && listado[j].tipo == 1)
                {

                cont++;
                break;


                }

            cantTotal++;

        }
    }

    promedio = (float)cantTotal/cont;


    printf("\nEl promedio de duenios con mascotas gatos es de %.2f",promedio);



}


