
#include "Cliente.h"
//nombre, apellido,localidad,teléfono,edad,sexo)

int contIdCliente = 1;
int contIndex =0;
int sizeListadoDeClientes = 2;

int MostrarPantallaPorLegajo(eCliente listado[], int tam)
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

    int ids[6] = {1,2,3,4,5,6};
    char nombres[6][50] = {"Una mujer","Un senior","Una chica","Un chico","Otro senior","Alejandro"};
    char apellidos[6][50] = {"Una mujer","Un senior","Una chica","Un chico","Otro senior","De Moraiz"};
    char localidades[6][50] = {"Almagro ","Palermo","La Boca","Boedo","Recoleta","La Boca"};
    char telefonos[6][50] = {"43033913","1564491741","1565911112","1132426886","1568991515","1564491741"};
    int edades[6] = {15,69,40,56,16,24};
    char sexos[6] = {'f','m','f','m','m','m'};

    for(int i = 0; i< 6; i++)
    {


        listado[i].idCliente =ids[i];
        strcpy(listado[i].nombre,nombres[i]);
        strcpy(listado[i].apellido,apellidos[i]);
        strcpy(listado[i].localidad,localidades[i]);
        strcpy(listado[i].telefono,telefonos[i]);
        listado[i].edad = edades[i];
        listado[i].sexo = sexos[i];

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
/*
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

    }
    else
    {

        printf("\nLegajo no encontrado\n");

    }
}
*/




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
//(nombre, apellido,localidad,teléfono,edad,sexo) .
void mostrarListaDeClientes(eCliente listado[],int tam)
{

    printf("%s%16s%16s%16s%16s%16s%16s\n","Id","Nombre","apellido","localidad","telefono","edad","sexo");




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

    printf("%d%16s%16s%16s%16s%16d%16c\n",cliente.idCliente
           ,cliente.nombre
           ,cliente.apellido
           ,cliente.localidad
           ,cliente.telefono
           ,cliente.edad
           ,cliente.sexo);




}


/*

void Alta(eCliente listado[], int tam)
{

    eCliente aux;
    int index;
    char rta;

    index =  buscarIndiceLibre(listado,tam);

    if(index != -1)
    {
//(nombre, apellido,localidad,teléfono,edad,sexo) .


        aux.idCliente = contIdCliente++;
        getOnlyLetters( aux.nombre,"\nIngrese nombre: ","\nNombre invalido");
        getOnlyLetters( aux.apellido,"\nIngrese apellido: ","\apellido invalido");
        getOnlyLetters( aux.localidad,"\nIngrese localidad: ","\ndireccion invalida");
        getPhoneNumber(aux.telefono,"\nIngrese numero de telefono: ","\nNumero de telefono incorrecto");
        aux.edad = getInt("\nIngrese edad:","\nEdad indalida" );

        aux.sexo = verificarMF("\nIngrese sexo\nm o f: ");
        // aux.estado = OCUPADO;


        rta = verificarSN("Esta seguro que desea ingresar esta pantalla? s/n");

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
    else
    {
        printf("No hay lugar");

    }



}
*/



/*

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
*/

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
    printf("\n\t\t*******Menu de modificaciones*******\n1-Modificar Nombre\n2-Modificar apellido\n3-localidad\n4-telefono\n5-edad\n6sexo\n0-Salir");

}

int cantidadDeClientesActivas(eCliente listado[],int tam)
{

    int cantDePantallasCargadas = 0;
    for(int i = 0; i<tam; i++)
    {

        if(listado[i].estado == OCUPADO )
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


void mostrarCantidadDeDueniosConMasDe50Anios(eCliente listado[],int tam)
{


    int cont = 0;


    for(int i = 0; i<tam; i++)
    {

        if(listado[i].edad >50)
        {

            cont++;
        }



    }

    mostrarListaDeClientes(listado,tam);


    printf("\nLa cantidad de clientes con mas de 50 anios es de %d",cont);










}


void mostrarDueniosConMasDe50AniosAlfabeticamente(eCliente listado[],int tam)
{


    eCliente aux;


    for(int i = 0; i<tam-1; i++)
    {



        for(int j = i+1; j<tam; j++)
        {

            if(stricmp(listado[i].nombre,listado[j].nombre)<0)
            {



                aux = listado[i];
                listado[i] = listado[j];
                listado[j] = aux;

            }


        }


    }







    for(int i = 0; i<tam; i++)
    {

        if(listado[i].edad >50)
        {

            mostrarCliente(listado[i]);
        }



    }












}

void promedioDeDueniosMujeres(eCliente listado[],int tam)
{

    int cont = 0;
    int cantidadTotal=0;
    float promedio;



    for(int i = 0; i<tam-1; i++)
    {





        if(listado[i].sexo == 'f')
        {

            cont++;




        }
        if(listado[i].estado == OCUPADO)
        {

            cantidadTotal++;
        }




    }

    promedio = (float)cont/cantidadTotal;

    printf("\nEl promedio de mujeres es de %.2f",promedio);

}
/*
///***************************
///***************************
///***************************
///***************************
///***************************

eCliente** cliente_crearLista()
{
    eCliente** listaAux =(eCliente**) malloc(sizeof(eCliente*)*sizeListadoDeClientes);

 return listaAux;
}
int initArray(eCliente** listaDeClientes, int valor)
{

    int retorno= -1;
    if(listaDeClientes !=NULL && sizeListadoDeClientes>0)
    {
        retorno =0;
        for(int i = 0; i<sizeListadoDeClientes; i++)
        {

            *(listaDeClientes+i) = valor;
        }

    }

    return retorno;


}

void showCliente(eCliente* pCliente)
{

    if(pCliente != NULL)
    {

        printf("id: %d\nApellido: %s \n nombre: %s\n",pCliente->idCliente,pCliente->apellido,pCliente->nombre);



        /*
        {
    int idCliente;
    char nombre[51];
    char apellido[51];
    char localidad[51];
    char telefono[20];
    int edad;
    char sexo;
    int estado;
    }



}*/
/*
int imprimirClientes(eCliente** pListaCliente)
{



    int retorno =-1;

    if(pListaCliente != NULL && sizeListadoDeClientes >0)
    {

        for(int i=0; i<sizeListadoDeClientes; i++)
        {

            showCliente(*(pListaCliente+i));


        }
    }



    return retorno;



}

eCliente* eCliente_new()
{

    eCliente* cliente;
    cliente = (eCliente*) calloc(sizeof(eCliente),1);



    return cliente;
}
eCliente* eCliente_newConParametros(eCliente* cliente)
{


    eCliente* pCliente;

    pCliente = eCliente_new();

    if(pCliente != NULL)
    {

        pCliente = cliente;


    }



    return pCliente;






}

int buscarIndiceLibre(eCliente** listado)
{


    int index = -1;
    int i;

    for( i = 0; i< sizeListadoDeClientes; i++)
    {
        if(listado[i]->estado != 1 )

            index =i;
            break;


    }





    return index;


}

void Alta(eCliente** listado)
{

    eCliente* aux;
    int index = -1;
    char rta;


    index =  buscarIndiceLibre(listado);
    printf("*-");

    if(index != -1)
    {
//(nombre, apellido,localidad,teléfono,edad,sexo) .


        aux->idCliente = contIdCliente++;
        getOnlyLetters( aux->nombre,"\nIngrese nombre: ","\nNombre invalido");
        getOnlyLetters( aux->apellido,"\nIngrese apellido: ","\apellido invalido");






        rta = verificarSN("Esta seguro que desea ingresar esta pantalla? s/n");

        if(rta=='s')
        {


            aux->estado = OCUPADO;
             contIndex++;



            if(contIndex == sizeListadoDeClientes)
            {

                printf("\nSin memoria\n");
            }

            eCliente_newConParametros(aux);

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

*/

eCliente* eCliente_new()
{

    eCliente* pNewCliente = NULL;

    pNewCliente = (eCliente*) malloc(sizeof(eCliente));

    return pNewCliente;

}


int eCliente_inicializarPunteros(eCliente** listadoCliente, int len)
{


    int rta = 1;
    if(listadoCliente != NULL && len >0)
    {

        rta=0;

        for(int i = 0; i<len; i++)
        {

            *(listadoCliente+i) = NULL; //OJO



        }
    }
    return rta;

}

int eCliente_getEmplyIndex(eCliente* listadoCliente[], int len)
{






    int index = -1;
    int i;

    for( i = 0; i< sizeListadoDeClientes; i++)
    {
        if(listadoCliente[i] == NULL )

            index =i;
        break;


    }





    return index;


}








void Alta(eCliente* listado[], int tam)
{

    eCliente* aux;
    int index;
    char rta;

    index =  eCliente_getEmplyIndex(listado,tam);



    if(index != -1)
    {
//(nombre, apellido,localidad,teléfono,edad,sexo) .
        aux = eCliente_new();

        if(aux != NULL)
        {



            aux->idCliente = contIdCliente++;
            getOnlyLetters( aux->nombre,"\nIngrese nombre: ","\nNombre invalido");
            getOnlyLetters( aux->apellido,"\nIngrese apellido: ","\apellido invalido");
            getOnlyLetters( aux->localidad,"\nIngrese localidad: ","\ndireccion invalida");
            getPhoneNumber(aux->telefono,"\nIngrese numero de telefono: ","\nNumero de telefono incorrecto");
            aux->edad = getInt("\nIngrese edad:","\nEdad invalida" );

            aux->sexo = verificarMF("\nIngrese sexo\nm o f: ");
            // aux.estado = OCUPADO;


            rta = verificarSN("\nEsta seguro que desea ingresar esta pantalla? s/n");

            if(rta=='s')
            {


                aux->estado = OCUPADO;
                listado[index] = aux;

                eCliente_show(listado[index]);

                printf("\nOperacion exitosa\n");

            }
            else
            {
                printf("\nOperacion cancelada\n");
            }

        }
    }
    else
    {
        printf("No hay lugar");

    }



}







void eCliente_show(eCliente* pCliente)
{

    if(pCliente != NULL)
    {

        printf("\n%d%16s%16s%16s%16s%16d%16c\n",pCliente->idCliente
               ,pCliente->apellido
               ,pCliente->nombre
               ,pCliente->localidad
               ,pCliente->telefono
               ,pCliente->edad
               ,pCliente->sexo);


    }




}

void eCliente_printList(eCliente** listadoCliente, int len)
{


    for(int i = 0.; i< len; i++)
    {

        eCliente_show(listadoCliente[i]);
    }




}

eCliente* eCliente_newParametros(char* nombre,char* apellido,char* telefono, char* localidad,int edad, char sexo)
{

    eCliente* aux = NULL;

    aux = eCliente_new();

    if(aux != NULL)
    {
        aux->idCliente = contIdCliente++;
        strcpy(aux->nombre,nombre);
        strcpy(aux->apellido,apellido);
        strcpy(aux->telefono,telefono);
        strcpy(aux->localidad,localidad);
        aux->edad = edad;
        aux->sexo =sexo;

    }


    return aux;





}

int eCliente_deleteIndexInArray(eCliente** listadoCliente,int limite, int indice)
{


//ES PARA ELIMITAR UN CLIENTE
///tiene que ver con el array, recibir el indice es la clave
///Free esta asiciado a liberar RAM, recordar luego de usar free esa misma posicion la pongo en NULL
    int rta =-1;

    if(listadoCliente != NULL && indice >0 && indice < limite &&listadoCliente[indice] != NULL)
    {
        free(listadoCliente[indice]);
        listadoCliente[indice] = NULL;

        rta = 0;
    }



    return rta;





}


int eCliente_buscarPorIdArray(eCliente** listadoCliente,int limite,int id)
{

    int rta = -1;

    if(listadoCliente != NULL && id >0 && limite >0)
    {

        for(int i=0; i<limite; i++)
        {
            if(listadoCliente[i] != NULL &&  listadoCliente[i]->idCliente == id)
            {

                rta = i;
                break;
            }

        }


    }


    return rta;



}


int eCliente_borrarPorIdArray(eCliente** listadoCliente,int limite)
{

    int index;
    int id;
    char confirmacion;
    int rta = -1;

    if(listadoCliente != NULL && limite> 0 )
    {
        rta = 0;

        eCliente_printList(listadoCliente,limite);

        id = getInt("\nIngrese id correspondiente a realizar eliminacion: ","\nError, ingrese id valido");

      index =  eCliente_buscarPorIdArray(listadoCliente,limite,id);

        eCliente_show(listadoCliente[index]);
        confirmacion=verificarSN("\nEsta seguro que desea eliminar este usuario? s/n");

        if(confirmacion == 's')
        {
            eCliente_deleteIndexInArray(listadoCliente,limite,index);

        }
        else
        {


            printf("\nSe ha cancelado la eliminacion");


        }
    }



    return rta;







}











