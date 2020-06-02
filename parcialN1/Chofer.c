
#include "Chofer.h"
//nombre, apellido,localidad,teléfono,edad,sexo)

int cont = 7;



int MostrarChoferPorLegajo(eChofer listado[], int tam)
{

    int index = buscarId(listado,tam);


    if(index != -1)
    {

        mostrarChofer(listado[index]);
    }
    else
    {

        printf("\nNo existen resultados para la busqueda.\n");
    }



    return index;
}


//nombre, apellido,localidad,teléfono,edad,sexo)
void Hardcodeo(eChofer listado[], int tam)
{




    int ids[6] = {1,2,3,4,5,6};
    char apellidos[6][50] = {"Uzumaki","Haruno","Uchiha","Hatake","Namikaze","De Moraiz"};
    char nombres[6][50] = {"Lucrecia","Jorge","Natalia","Matias","Jeremias","Alejandro"};
    char legajos[6][50] = {"111","222","333","444","555","666"};
    char dnis[6][50] = {"39068081","25625548","65895542","54879953","20336654","54852658"};
    char nacionalidades[6][50] = {"Argentino","Argentino","Brasilero","Venezolano","Ingles","Holandes"};
    char telefonos[6][50] = {"43033913","1564491741","1565911112","1132426886","1568991515","1554455668"};
    int edades[6] = {25,40,56,45,50,22};
    char sexos[6] = {'f','m','f','m','m','m'};

    for(int i = 0; i< 6; i++)
    {


        listado[i].idChofer =ids[i];
        strcpy(listado[i].apellido,apellidos[i]);
        strcpy(listado[i].nombre,nombres[i]);
        strcpy(listado[i].legajo,legajos[i]);
        strcpy(listado[i].dni,dnis[i]);
        strcpy(listado[i].nacionalidad,nacionalidades[i]);
        strcpy(listado[i].telefono,telefonos[i]);
        listado[i].edad = edades[i];
        listado[i].sexo = sexos[i];
        listado[i].estado = OCUPADO;

    }


}


/*

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

*/
/*
    int idChofer;
    char apellido[51];
    char dni[51];
    char nacionalidad[20];
    char telefono[20];
    int edad;
    char sexo;
    int estado;*/

void modificarChofer(eChofer listado[], int tam)
{

    int opc;
    int index;
    char auxString[200];
    int auxInt;
    char auxChar;


    char rta;


    mostrarListaDeChoferes(listado,tam);


    index = buscarId(listado,tam);

    mostrarChofer(listado[index]);





    if(index != -1)
    {



        printf("\n1-Modificar nombre\n2-Modificar Apellido\n3-Modificar DNI\n4-Modificar nacionalidad\n5-Modificar Telefono\n6-Modificar edad\n7-Modificar sexo");
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


            getOnlyLetters(auxString,"\nIngrese nuevo apellido: ","\nApellido invalido");

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


            getDNI(auxString,"\nIngrese nuevo DNI: ","\nDNI invalido");

            rta = verificarSN("\nEsta seguro que desea cambiar el dni? s/n: ");

            if(rta == 's')
            {


                strcpy(listado[index].dni,auxString);
                printf("\n Se ha cambiado el valor exitosamente.");

            }
            else
            {

                printf("\nCAMBIO ABORTADO.");
            }
            break;


        case 4:


            getStringWithDefineSize(auxString,"\nIngrese nacionalidad: ",19,"\nNacionalidad invalida");

            rta = verificarSN("\nEsta seguro que desea cambiar la nacionalidad? s/n: ");

            if(rta == 's')
            {


                strcpy(listado[index].nacionalidad,auxString);
                printf("\n Se ha cambiado el valor exitosamente.");

            }
            else
            {

                printf("\nCAMBIO ABORTADO.");
            }
            break;


        case 5:


            getPhoneNumber(auxString,"\nIngrese numero de telefono: ","\nNumero de telefono invalido");

            rta = verificarSN("\nEsta seguro que desea cambiar el telefono? s/n: ");

            if(rta == 's')
            {


                strcpy(listado[index].telefono,auxString);
                printf("\n Se ha cambiado el valor exitosamente.");

            }
            else
            {

                printf("\nCAMBIO ABORTADO.");
            }
            break;


        case 6:


            auxInt =  getNumberWithDefinedRange("\nIngrese nueva edad",65,18,"\nLa edad es invalida para ser un conductor");

            rta = verificarSN("\nEsta seguro que desea cambiar la edad del conductor? s/n: ");

            if(rta == 's')
            {


                listado[index].edad = auxInt;
                printf("\n Se ha cambiado el valor exitosamente.");

            }
            else
            {

                printf("\nCAMBIO ABORTADO.");
            }
            break;



        case 7:


            auxChar =  verificarMF("\nIngrese nuevo sexo\n m o f: ");
            rta = verificarSN("\nEsta seguro que desea cambiar la edad del conductor? s/n: ");

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





int buscarId(eChofer listado[], int tam)
{

    int index  = -1;
    int legajo;
    legajo = getInt("\nIngrese ID: ","\nError ID incorrecto");




    for(int i = 0; i<=tam; i++)
    {

        if(listado[i].estado == OCUPADO)
        {

            if(listado[i].idChofer == legajo)
            {


                index = i;
                break;


            }



        }


    }








    return index;

}
//(nombre, apellido,localidad,teléfono,edad,sexo) .

void mostrarListaDeChoferes(eChofer listado[],int tam)
{

    printf("%s%16s%16s%16s%16s%16s%16s%16s%16s\n","Id","Nombre","apellido","DNI","legajo","nacionalidad","telefono","edad","sexo");




    for(int i = 0; i<tam; i++)
    {

        if(listado[i].estado == OCUPADO)
        {

            mostrarChofer(listado[i]);


        }


    }


}






void mostrarChofer(eChofer chofer)
{

    printf("%d%16s%16s%16s%16s%16s%16s%16d%16c\n",chofer.idChofer
           ,chofer.nombre
           ,chofer.apellido
           ,chofer.dni
           ,chofer.legajo
           ,chofer.nacionalidad
           ,chofer.telefono
           ,chofer.edad
           ,chofer.sexo);




}


/*
int idChofer;
    char apellido[51];
    char dni[51];
    char legajo[51];
    char nacionalidad[20];
    char telefono[20];
    int edad;
    char sexo;
    int estado;*/



void Alta(eChofer listado[], int tam)
{

    eChofer aux;
    int index;
    char rta;

    index =  buscarIndiceLibre(listado,tam);

    if(index != -1)
    {
//(nombre, apellido,localidad,teléfono,edad,sexo) .


        aux.idChofer = cont++;
        getOnlyLetters( aux.nombre,"\nIngrese nombre: ","\nNombre invalido");
        getOnlyLetters( aux.apellido,"\nIngrese apellido: ","\apellido invalido");
        getonlyAlphanumeric(aux.legajo,"\nIngrese legajo: ","\n legajo invalido, TIENE QUE TENER TANTO LETRA COMO NUMEROS");

        for(int i = 0; i<tam; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                while(stricmp(aux.legajo,listado[i].legajo) == 0)
                {
                    getonlyAlphanumeric(aux.legajo,"\nEl legajo ingresado ya se encuentra en sistema, ingrese legajo unico: ","\n legajo invalido");
                }

            }

        }

        getDNI(aux.dni,"\nIngrese DNI: ","\n\nDNI invalido");
        getStringWithDefineSize(aux.nacionalidad,"\nIngrese nacionalidad: ",19,"\nNacionalidad invalida");
        getPhoneNumber(aux.telefono,"\nIngrese numero de telefono: ","\nNumero de telefono invalido");
        aux.edad = getNumberWithDefinedRange("\nIngrese nueva edad",65,18,"\nLa edad es invalida para ser un conductor");
        aux.sexo = verificarMF("\nm-Masculino\nf-Femenino\nIngrese sexo: ");






        rta = verificarSN("\nEsta seguro que desea ingresar este chofer? s/n");

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






int buscarIndiceLibre(eChofer listado[], int tam)
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


void inicializarEstado(eChofer listado[], int tam)
{
    int i;
    for( i = 0; i< tam; i++)
    {


        listado[i].estado = LIBRE;

    }


}


/*

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
*/


void promedioDeEdadChoferes(eChofer listado[], int tam)
{


    float promedio;
    int edades = 0;
    int contador = 0;

    for(int i = 0; i<tam; i++)
    {

        if(listado[i].estado == OCUPADO)
        {

            edades+= listado[i].edad;
            contador++;

        }

    }

    promedio = (float)edades/contador;

    printf("\nEl promedio de edades es de %.2f.",promedio);




}

void promedioDeMoFentreChoferes(eChofer listado[], int tam)
{

    float promedioM;
    //float promedioF;

    int contTotal = 0;
    int contM = 0 ;
    int contF = 0;



    for(int i = 0; i<tam; i++)
    {
        if(listado[i].estado == OCUPADO)
        {

            if(listado[i].sexo == 'm')
            {
                contM++;
            }
            else
            {
                contF++;
            }
            contTotal++;


        }

    }

    promedioM = (float)contM/contTotal;

  //   promedioF = (float)contF/contTotal;


    printf("El porcentaje de  de varones es de: %.2f ",promedioM *100);

}

