
#include "alumno.h"
#include "mostrar.h"

void baja(eAlumno listado[], int tam)
{

    int index;
    char rta;

    index = buscarLegajo(listado,tam);


    if(index != tam)
    {

        printf("\n  Legajo encontrado \n ");
        mostrarAlumno(listado[index]);
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





}

void modificarAlumno(eAlumno listado[], int tam)
{

    int opc;
    int index;
    char auxString[200];
    int auxInt;

    char rta;

    index = buscarLegajo(listado,tam);



    if(index != tam)
    {



        menuConfiguracion();
        opc = getInt("\nIngrese opcion: ");

        //n1-Cambiar nombre\n2-Cambiar apellido \n3-Cambiar nota 1
        // \n4-Cambiar nota 2 \n5-Cambiar Email\n");
        switch(opc)
        {


        case 1:

            getString(auxString,"\nIngrese nuevo nombre: ");

            rta = verificarSN("\nEsta seguro que desea cambiar el nombre? s/n: ");

            if(rta == 's')
            {

                // listado[index].nombre = auxString;
                strcpy(listado[index].nombre,auxString);
                printf("\n Se ha cambiado el valor exitosamente.");

            }
            else
            {

                printf("\nCAMBIO ABORTADO.");
            }



            break;

        case 2:


            getString(auxString,"\nIngrese nuevo apellido: ");

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

             auxInt= getNumberWithDefinedRange("Ingrese nueva nota",10,1,"\nError\n");

            rta = verificarSN("\nEsta seguro que desea cambiar la nota 1? s/n: ");

            if(rta == 's')
            {

                listado[index].nota1 = auxInt;
                listado[index].promedio = getPromedio(listado[index].nota1,listado[index].nota2);
                printf("\n Se ha cambiado el valor exitosamente.");

            }
            else
            {

                printf("\nCAMBIO ABORTADO.");
            }
            break;


        case 4:

             auxInt= getNumberWithDefinedRange("Ingrese nueva nota",10,1,"\nError\n");


            rta = verificarSN("\nEsta seguro que desea cambiar la nota 2? s/n: ");

            if(rta == 's')
            {

                listado[index].nota2 = auxInt;
                listado[index].promedio = getPromedio(listado[index].nota1,listado[index].nota2);
                printf("\n Se ha cambiado el valor exitosamente.");

            }
            else
            {

                printf("\nCAMBIO ABORTADO.");
            }
            break;



        case 5:


            getEmail(auxString,"\nIngrese nuevo mail: ");

            rta = verificarSN("\nEsta seguro que desea cambiar el email? s/n: ");

            if(rta == 's')
            {

                strcpy(listado[index].email,auxString);
                printf("\n Se ha cambiado el valor exitosamente.");

            }
            else
            {

                printf("\nCAMBIO ABORTADO.");
            }

            break;

        case 6:


            getStringWithDefineSize(auxString,"\nIngrese nuevo comentario: ",TAMANIOMAXIMODECOMENTARIO);

            rta = verificarSN("\nEsta seguro que desea cambiar el comentario? s/n: ");

            if(rta == 's')
            {

                strcpy(listado[index].comentario,auxString);
                printf("\n Se ha cambiado el valor exitosamente.");

            }
            else
            {

                printf("\nCAMBIO ABORTADO.");
            }

            break;


        }


    }
    else
    {

        printf("\nCAMBIO ABORTADO.");
    }







}


void alumnosDesaprobados(eAlumno listado[], int tam, int notaParaAprobar)
{


    for(int i = 0; i< tam; i++)
    {

        if(listado[i].estado== OCUPADO)
        {


            if(listado[i].promedio < notaParaAprobar)
            {

                printf("\n*****DESAPROBADOS*****\n");
                mostrarAlumno(listado[i]);

            }

        }




    }


}

void alumnosAprobados(eAlumno listado[], int tam, int notaParaAprobar)
{


    for(int i = 0; i< tam; i++)
    {

        if(listado[i].estado== OCUPADO)
        {


            if(listado[i].promedio >= notaParaAprobar)
            {

                printf("\n*****APROBADOS*****\n");
                mostrarAlumno(listado[i]);

            }

        }




    }


}


void mostrarMailAlfabeticamente(eAlumno listado[], int tam)
{
    int i;
    int k;
    eAlumno aux;



    for(i = 0; i< tam-1; i++)
    {

        for(k = i+1; k<tam; k++)




            if(strcmpi(listado[i].email,listado[k].email)>0)
            {

                aux = listado[i];
                listado[i] = listado[k];
                listado[k] = aux;


            }


    }

    printf("%8s%20s%20s%8s%8s%15s%20s\n ","legajo","nombre","apellido","nota 1", "nota 2", "promedio","email");


    for(int i = 0; i< tam; i++)
    {

        if(listado[i].estado== OCUPADO)
        {


            mostrarAlumno(listado[i]);

        }




    }


}

void BuscarAlumnoYMostrar(eAlumno listado[], int tam)
{

    int index;

    index = buscarLegajo(listado,tam);

    if(index != -1)
    {

        printf("%8s%20s%20s%8s%8s%15s%20s\n ","legajo","nombre","apellido","nota 1", "nota 2", "promedio","email");
        mostrarAlumno(listado[index]);

        printf("\n\n Comentario: \n \t %s",listado[index].comentario);

    }
    else
    {

        printf("\n No se encontro legajo\n ");

    }










}

int buscarLegajo(eAlumno listado[], int tam)
{

    int index  = -1;
    int legajo;
    legajo = getInt("\nIngrese legajo: ");

    for(int i = 0; i<=tam; i++)
    {

        if(listado[i].estado == OCUPADO)
        {

            if(listado[i].legajo == legajo)
            {


                index = i;
                break;


            }



        }


    }



    return index;

}

void mostrarListaDeAlumnos(eAlumno listado[],int tam)
{

    printf("%8s%20s%20s%8s%8s%15s%20s\n ","legajo","nombre","apellido","nota 1", "nota 2", "promedio","email");


    for(int i = 0; i<tam; i++)
    {

        if(listado[i].estado == OCUPADO)
        {

            mostrarAlumno(listado[i]);


        }


    }


}



void mostrarAlumno(eAlumno alumno)
{

    printf("%8d%20s%20s%8d%8d%15.2f%20s\n ",alumno.legajo,
           alumno.nombre,
           alumno.apellido,
           alumno.nota1,
           alumno.nota2,
           alumno.promedio,
           alumno.email);






}




void Alta(eAlumno listado[], int tam)
{

    eAlumno aux;
    int index;
    char rta;

    index =  buscarIndiceLibre(listado,tam);

    if(index != -1)
    {

//getNumberWithDefinedRange("Ingrese nueva nota",10,1,"\nError\n");


        aux.legajo = getInt("\nIngrese legajo: ");
        getString( aux.nombre,"\nIngrese nombre: ");
        getString(aux.apellido,"\nInngrese apellido: ");
        aux.nota1 = getNumberWithDefinedRange("\nIngrese nota 1: ",10,1,"\nError!\n");
        aux.nota2= getNumberWithDefinedRange("\nIngrese nota 2: ",10,1,"\nError!\n");
        aux.promedio = getPromedio(aux.nota1,aux.nota2);
        getEmail(aux.email,"\nIngrese Email: ");
        getStringWithDefineSize(aux.comentario,"Ingrese comentario del profesor: ",TAMANIOMAXIMODECOMENTARIO);
        aux.estado = OCUPADO;


        rta = verificarSN("Esta seguro que desea ingresar este usuario? s/n");

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
float getPromedio(int num1, int num2)
{

    return (float)(num1 + num2) / 2;
}





int buscarIndiceLibre(eAlumno listado[], int tam)
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

void inicializarEstado(eAlumno listado[], int tam)
{
    int i;
    for( i = 0; i< tam; i++)
    {


        listado[i].estado = LIBRE;

    }


}
void mayorPromedio(eAlumno listado[], int tam)
{

    float max;
    max= INT_MIN;

    for(int i = 0; i< tam; i++)
    {

        if(listado[i].estado == OCUPADO)
        {

            if(max < listado[i].promedio)
            {


                max = listado[i].promedio;
            }


        }



    }

    for(int i = 0; i< tam; i++)
    {

        if(listado[i].estado == OCUPADO)
        {

            if(listado[i].promedio == max)
            {


                mostrarAlumno(listado[i]);
            }

        }
    }




}

