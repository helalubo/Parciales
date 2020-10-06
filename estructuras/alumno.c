#include "Alumno.h"
#include "input.h"

void inicializarAlumnos(eAlumno listado[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        listado[i].estado = LIBRE;

    }
}

eAlumno cargarUnAlumno(void)
{
    eAlumno miAlumno;
    printf("Ingrese legajo: ");
    scanf("%d", &miAlumno.legajo);
    printf("Ingrese nota 1: ");
    scanf("%d", &miAlumno.nota1);
    printf("Ingrese nota 2: ");
    scanf("%d", &miAlumno.nota2);
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(miAlumno.nombre);
    printf("Ingrese email: ");
    fflush(stdin);
    gets(miAlumno.email);
    miAlumno.promedio = (float)(miAlumno.nota1+miAlumno.nota2)/2;

    miAlumno.estado = OCUPADO;
    return miAlumno;
}

void mostrarUnAlumno(eAlumno miAlumno)
{
    printf("%8d %8d %8d %10f %20s %20s\n", miAlumno.legajo,
           miAlumno.nota1,
           miAlumno.nota2,
           miAlumno.promedio,
           miAlumno.nombre,
           miAlumno.email);
}


void BuscarUnAlumnoYMostrarlo(eAlumno listado[], int tam)
{

    int legajo;
    int i;
    legajo = getInt("\nIngrese legajo del alumno que desea mostrar: ");


    for(i = 0; i<=tam; i++)
    {

        if(listado[i].estado == LIBRE)
        {



            if(listado[i].legajo == legajo)
            {

                mostrarUnAlumno(listado[i]);
                break;

            }
        }

    }
    if(i == tam)
    {

        printf("No se encontro el alumno");

    }



}

int compararAlumnosPorLegajo(eAlumno unAlumno, eAlumno otroAlumno)
{
    return unAlumno.legajo == otroAlumno.legajo;

}
int buscarLibre(eAlumno listado[],int tam)
{
    int i;
    int indice=-1;
    for(i=0; i<tam; i++)
    {
        if(listado[i].estado==LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
void cargarListadoDeAlumnos(eAlumno listado[], int tam)
{
    int i;
    int indice;
    indice = buscarLibre(listado, tam);
    if(indice != -1)
    {
        listado[indice] = cargarUnAlumno();
    }
    else
    {
        printf("No hay lugar");
    }

}





void mostrarListadoDeAlumnos(eAlumno listado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            mostrarUnAlumno(listado[i]);
        }

    }

}

void mostrarListadoDeAlumnosPromocionados(eAlumno listado[], int tam, int minAprobado)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].promedio >= minAprobado)
        {
            mostrarUnAlumno(listado[i]);
        }

    }
}

void ordenarListadoDeAlumnosPorNombre(eAlumno listado[], int tam)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].nombre,listado[j].nombre)>0)
            {
                auxAlumno  =  listado[i];
                listado[i] = listado[j];
                listado[j] = auxAlumno;
            }

        }
    }

}
void ordenarListadoDeAlumnosPorNombreYporPromedio(eAlumno listado[], int tam)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].nombre,listado[j].nombre)>0)
            {
                auxAlumno  =  listado[i];
                listado[i] = listado[j];
                listado[j] = auxAlumno;
            }
            else
            {
                if(strcmp(listado[i].nombre,listado[j].nombre)==0)
                {
                    if(listado[i].promedio>listado[j].promedio)
                    {
                        auxAlumno  =  listado[i];
                        listado[i] = listado[j];
                        listado[j] = auxAlumno;
                    }
                }
            }

        }
    }
}
float calcularMaximoPromedio(eAlumno listado[], int tam)
{
    float maxPromedio ;
    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].promedio>maxPromedio || i==0)
        {
            maxPromedio = listado[i].promedio;
        }
    }
    return maxPromedio;
}
void mostrarListadoDeAlumnosConMaximo(eAlumno listado[], int tam, int maximo)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(listado[i].promedio == maximo)
        {
            if(listado[i].estado == OCUPADO)
            {
                mostrarUnAlumno(listado[i]);
            }

        }
    }
}
void mostrarAlumnosConMaximoPromedio(eAlumno listado[], int tam)
{
    float maximoPromedio;
    int i;

    maximoPromedio = calcularMaximoPromedio(listado,tam);

    mostrarListadoDeAlumnosConMaximo(listado,tam, maximoPromedio);

}

void eliminarAlumno(eAlumno listado[], int tam)
{
    int i;
    int legajo;
    int band = 0;
    eAlumno aux;
    printf("Ingrese legajo a buscar: ");
    scanf("%d", &legajo);
    //Ojo, crear una funcion que busque un legajo
    for(i=0; i<tam; i++)
    {
        if(legajo == listado[i].legajo)
        {
            band = 1;
            break;
        }
    }
    if(band==1)
    {

        mostrarUnAlumno(listado[i]);
        listado[i].estado = LIBRE;
    }
    else
    {
        printf("No existe");
    }




}
void modificarAlumno(eAlumno listado[], int tam)
{
    int i;
    int legajo;
    int band = 0;
    eAlumno aux;
    printf("Ingrese legajo a buscar: ");
    scanf("%d", &legajo);
    //Ojo, crear una funcion que busque un legajo
    for(i=0; i<tam; i++)
    {
        if(legajo == listado[i].legajo)
        {
            band = 1;
            break;
        }
    }
    if(band==1)
    {
        aux = listado[i];
        mostrarUnAlumno(aux);
        printf("Reingrese EMAIL: ");
        fflush(stdin);
        gets(aux.email);
    }
    else
    {
        printf("No existe");
    }

    //preguntar si quiere modificar
    listado[i] = aux;

}

