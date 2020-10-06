
#include "Publicacion.h"


int contPublicacion = 1;



void HardcodeoPublicacion(ePublicacion listado[], int tam)
{



    int idsPublicacion[5] = {1,2,3,4,5};
    int idsClientes[5] = {1,1,2,1,3};
    int numerosDeRubro[5] = {1,1,1,4,4};
    char textos[5][70] = {"El futbol es...","La fruta es... ","El virus es... ","La comida es...","Las peliculas son"};



    for(int i = 0; i< 5; i++)
    {


        listado[i].idPublicacion =idsPublicacion[i];
        listado[i].idCliente =idsClientes[i];
        listado[i].numeroRubro =numerosDeRubro[i];
        strcpy(listado[i].textoDeAviso,textos[i]);


        listado[i].estado = OCUPADO;

    }


}




void bajaPublicacion(ePublicacion listado[], int tam)
{

    int index;
    char rta;


    index = buscarPorIdPublicacion(listado,tam);


    if(index != -1)
    {

        printf("\n  id encontrado \n ");
        mostrarPublicacion(listado[index]);
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




int buscarPorIdPublicacion(ePublicacion listado[], int tam)
{

    int index  = -1;
    int legajo;
    legajo = getInt("\nIngrese id: ","\nid invalido");




    for(int i = 0; i<=tam; i++)
    {

        if(listado[i].estado == OCUPADO || listado[i].estado == PAUSA)
        {

            if(listado[i].idPublicacion == legajo)
            {


                index = i;
                break;


            }



        }


    }








    return index;




}





void mostrarListaDePublicacion(ePublicacion listado[],int tam, eCliente listadoCliente[],int tamClientes)
{

    printf("%s%10s%10s%10s%10s%\n","Cuil","idPublicacion","idCliente","numero de rubro","texto de aviso");


    for(int k =0 ; k<tamClientes; k++)
    {




        for(int i = 0; i<tam; i++)
        {

            if(listado[i].estado == OCUPADO)
            {



                if(listadoCliente[k].idCliente == listado[i].idCliente)
                {
                    printf("%10s",listadoCliente[k].cuil);
                    mostrarPublicacion(listado[i]);
                }


            }


        }

    }


}



void  mostrarPublicacion(ePublicacion publicacion)
{


    printf("%d%10d%10d%35s\n"
           ,publicacion.idCliente
           ,publicacion.idPublicacion
           ,publicacion.numeroRubro
           ,publicacion.textoDeAviso);


}





////////////////////////////////////primer cambio
void AltaPublicacion(ePublicacion listado[], int tam, eCliente listadoClientes[],int tamClientes)
{

    ePublicacion aux;
    int index;
    char rta;

    int idAux;


    index =  buscarIndiceLibrePublicacion(listado,tam);

    if(index != -1)
    {





        aux.idPublicacion = contPublicacion++;
        mostrarListaDeClientes(listadoClientes,tamClientes);
        idAux= buscarId(listadoClientes,tamClientes);

        while(idAux == -1)
        {
            printf("\nError id cliente no existente\n ");
            idAux= buscarId(listadoClientes,tamClientes);
        }

        aux.idCliente = listadoClientes[idAux].idCliente;

        aux.numeroRubro = getInt("\nIngrese numero de rubro: ","\nNumero de rubro invalido");
        getStringWithDefineSize(aux.textoDeAviso,"Ingrese Texto de aviso: ",64,"\nError, texto demasiado largo");

        rta = verificarSN("\nEsta seguro que desea ingresar esta Mascota? s/n");

        if(rta='s')
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



int buscarIndiceLibrePublicacion(ePublicacion listado[], int tam)
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


void inicializarEstadoPublicacion(ePublicacion listado[], int tam)
{
    int i;
    for( i = 0; i< tam; i++)
    {


        listado[i].estado = LIBRE;

    }


}

void menuModificacionPublicacion()
{
    // printf("%s%35s%35s%35s%35s%35s%35s%35s\n","idMascota","idCliente","nombre","tipo","raza","edad","peso","sexo");
    printf("\n\t\t*******Menu de modificaciones*******\n1-Pausar Publicacion\n2-Reanudar Publicacion\n0-Salir");

}

int cantidadDePublicacionesActivas(ePublicacion listado[],int tam)
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
void modificarPublicacion(ePublicacion listado[], int tam, eCliente listadoClientes[], int tamCliente)
{

    int opc;
    int index;

    int auxEntero;



    char rta;

    index = buscarPorIdPublicacion(listado,tam);





    if(index != -1)
    {


        //    printf("\n\t\t*******Menu de modificaciones*******\n1-Modificar nombre\n2-tipo\n3-raza\n4-edad\n5-peso\n6-sexo \n0-Salir");
        menuModificacionPublicacion();
        opc = getInt("\nIngrese opcion: ","\nOpcion invalida");


        switch(opc)
        {


        case 1:

            auxEntero = listado[index].idCliente;

            for(int i= 0; i<tamCliente; i++)
            {

                if(auxEntero == listadoClientes[i].idCliente)

                    mostrarCliente(listadoClientes[i]);

            }



            rta = verificarSN("\nEsta seguro que desea cambiar el estado a Pausa de la publicacion? s/n: ");

            if(rta == 's')
            {


                listado[index].estado = PAUSA;
                printf("\n Se ha pausado la publicacion exitosamente.");

            }
            else
            {

                printf("\nPausa ABORTADA.");
            }



            break;

        case 2:


            auxEntero = listado[index].idCliente;

            for(int i= 0; i<tamCliente; i++)
            {

                if(auxEntero == listadoClientes[i].idCliente)

                    mostrarCliente(listadoClientes[i]);

            }



            rta = verificarSN("\nEsta seguro que desea cambiar el estado a Activo de la publicacion? s/n: ");

            if(rta == 's')
            {


                listado[index].estado = OCUPADO;
                printf("\n Se ha Activado la publicacion exitosamente.");

            }
            else
            {

                printf("\nActivacion ABORTADA.");
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

void mostrarClienteConPublicacion(ePublicacion listado[], int tam, eCliente listadoClientes[],int tamClientes)
{

    int flag;
    int cont;

    for(int i =0; i<tamClientes; i++)
    {


        if(listadoClientes[i].estado==OCUPADO)
        {



            mostrarCliente(listadoClientes[i]);

            flag =0;
            cont = 0;
        }

        for(int k =0; k<tam; k++)
        {



            if(listadoClientes[i].idCliente == listado[k].idCliente && listado[k].estado == OCUPADO)
            {


                flag = 1;
                cont++;

            }



        }

        if(listadoClientes[i].estado==OCUPADO)
        {

            if(flag == 1)
            {

                printf("\nCANTIDAD DE PUBLICACIONES ACTIVAS: %d\n",cont);
            }


            if(flag == 0)
            {

                printf("\nNo tiene Publicaciones Activas\n");
            }


        }




    }



}

void bajaCliente(eCliente listado[], int tam,ePublicacion listadoPublicacion[], int tamPublicaciones)
{

    int index;
    char rta;
    int auxInt;

    index = buscarId(listado,tam);


    if(index != -1)
    {

        printf("\n  Legajo encontrado \n ");
        mostrarCliente(listado[index]);
        auxInt = listado[index].idCliente;

        for(int i=0; i<tamPublicaciones; i++)
        {
            if(listadoPublicacion[i].idCliente == auxInt)
            {

                mostrarPublicacion(listadoPublicacion[i]);
            }

        }


        rta = verificarSN("\nDesea dar de baja s/n: ");

        if(rta == 's')
        {


            listado[index].estado = LIBRE;
            for(int i=0; i<tamPublicaciones; i++)
            {
                if(listadoPublicacion[i].idCliente == auxInt)
                {

                    listadoPublicacion[i].estado =LIBRE;
                }

            }
            printf("\nSe a Eliminado el cliente y todas sus publicaciones");

        }
        else
        {

            printf("\n LA BAJA A SIDO ABORTADA.");

        }







    }


    printf("\n LA BAJA A SIDO ABORTADA.");







}

void mostrarPublicacionConCuil(ePublicacion listado[], int tam, eCliente listadoClientes[],int tamClientes)
{

    int flag;


    for(int i =0; i<tamClientes; i++)
    {


        if(listadoClientes[i].estado==OCUPADO)
        {


            printf( "\n*****Cuil: %s*****\n",  listadoClientes[i].cuil);

            flag =0;
        }

        for(int k =0; k<tam; k++)
        {



            if(listadoClientes[i].idCliente == listado[k].idCliente && listado[k].estado == OCUPADO)
            {
                mostrarPublicacion(listado[k]);
                flag = 1;

            }



        }

        if(listadoClientes[i].estado==OCUPADO)

            if(flag == 0)
            {

                printf("\nNo tiene Publicaciones registradas");
            }

    }





}

void informacionesClientes(ePublicacion listado[], int tam, eCliente listadoClientes[],int tamClientes)
{





    int cantidadesActivas[tamClientes];
    int cantidadesPausadas[tamClientes];
    int cantidadesTotales[tamClientes];

    int maxActivo;
    int maxPausadas;
    int maxTotal;

    int indiceActivo;
    int indicePausada;
    int indiceTotal;

    for(int i = 0; i< tamClientes; i++)
    {

        cantidadesActivas[i] = 0;
        cantidadesPausadas[i] = 0;
        cantidadesTotales[i] =0;

    }



    for(int i =0; i<tamClientes; i++)
    {




        for(int k =0; k<tam; k++)
        {



            if(listadoClientes[i].idCliente == listado[k].idCliente && listado[k].estado == OCUPADO)
            {


                cantidadesActivas[i]++;
                //    cont++;

            }


            if(listadoClientes[i].idCliente == listado[k].idCliente && listado[k].estado == PAUSA)
            {


                cantidadesPausadas[i]++;
                //    cont++;

            }

            if(listadoClientes[i].idCliente == listado[k].idCliente &&( listado[k].estado == OCUPADO || listado[k].estado == OCUPADO))
            {


                cantidadesTotales[i]++;
                //    cont++;

            }



        }






    }

    maxActivo = retornarMayor(cantidadesActivas,tamClientes);
    maxPausadas = retornarMayor(cantidadesPausadas,tamClientes);
    maxTotal = retornarMayor(cantidadesTotales,tamClientes);


    for(int i = 0; i<tamClientes; i++)
    {

        if(cantidadesActivas[i] == maxActivo)
        {
            indiceActivo = i;
        }

        if(cantidadesPausadas[i] == maxPausadas)
        {
            indicePausada = i;
        }

        if(cantidadesTotales[i] == maxTotal)
        {
            indiceTotal = i;
        }

    }


    printf("El cliente con mas avisos activos es:\n");
    mostrarCliente(listadoClientes[indiceActivo]);

    if(maxPausadas != 0)
    {

        printf("El cliente con mas avisos pausados es:\n");
        mostrarCliente(listadoClientes[indicePausada]);
    }
    else
    {

        printf("\nNo existen publicaciones pausadas\n");

    }

    printf("El cliente con mas avisos totales es:\n");
    mostrarCliente(listadoClientes[indiceTotal]);




}



void informacionesPublicaciones(ePublicacion listado[], int tam, eCliente listadoClientes[],int tamClientes)
{

    int rubro;
    int cont = 0;
    int contRubros[tam];

    int mayor;
    int RubroMayor;
    int RubroMenor;
    int menor;

    rubro = getInt("\nIngrese rubro: ","\nRubro invalido");


    for(int i = 0; i<tam; i++)
    {

        if(listado[i].numeroRubro == rubro && listado[i].estado == OCUPADO)
        {
            cont++;

        }


    }


    for(int i = 0; i<tam; i++)
    {

        contRubros[i] =LIBRE;


    }


    for(int i = 0; i<tam; i++)
    {

        for(int k = 0; k<tam; k++)
        {
            if(listado[i].numeroRubro == k && listado[i].estado == OCUPADO)
            {
                contRubros[k]++;
            }
        }

    }





    mayor=  retornarMayor(contRubros,tam);
    menor= retornarMenor(contRubros,tam);

    for(int i = 0; i<tam; i++)
    {

        if(contRubros[i] == mayor && listado[i].estado == OCUPADO)
        {
            RubroMayor = i;

        }
        if(contRubros[i] == menor && listado[i].estado == OCUPADO)
        {
            RubroMenor = i;

        }

    }





    printf("\nLa cantidad de publicaciones de ese rubro es %d",cont);

    printf("\nEl rubro con mayor cantidad de publicaciones activas es el %d",RubroMayor);

    printf("\nEl rubro con menor cantidad de publicaciones activas es el %d",RubroMenor);




}







