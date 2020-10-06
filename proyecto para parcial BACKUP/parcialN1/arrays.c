
#include <limits.h>
#include <stdio.h>



void inicializarArray(int numeros[], int cant, int valorDeInicio)
{

    for(int i = 0; i<cant; i++)
    {

        numeros[i] = valorDeInicio;

    }



}
void mostrarArray(int numeros[], int cant)
{
    for(int i = 0; i<cant; i++)
    {

        printf("\n numero en la posicion #%d: %d\n",i+1,numeros[i]);
    }

}
int CantidadCargadaArray(int estados[], int tam,int valorDeInicio)
{

    int cant = 0;


    for(int i = 0; i<tam; i++)
    {


        if(estados[i] != valorDeInicio)
        {


            cant++;

        }

    }
return cant;


}


int CantidadNoCargadaArray(int numeros[], int cant,int valorDeInicio)
{

    int aux = 0;


    for(int i = 0; i<cant; i++)
    {

        if(numeros[i] == valorDeInicio)
        {

            aux++;
        }
    }

    return aux;


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
float retornarMayorFlotante(float numeros[], float cant)
{

    float max;
    max = INT_MIN;

    for(int i = 0; i<cant; i++)
    {

        if(max < numeros[i])
        {

            max = numeros[i];
        }

    }
   // printf("\n***%.2f*****\n",max);
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

float retornarMenorFlotante(float numeros[], float cant,int valorInicial)
{

    float min;
    min = INT_MAX;

    for(int i = 0; i<cant; i++)
    {

        if(min > numeros[i] && numeros[i] != valorInicial)
        {

            min = numeros[i];
        }

    }
    return min;
}

int indiceLibre(int numeros[],int cant)
{

    int i;

    for( i =0; i<cant; i++)
    {

        if(numeros[i] == -1)
        {

            break;

        }

    }

    if(i == cant)
    {

        i = -1;
    }

    return i;
}



int sumarTotalEnArray(int array[],int estados[],int tam, int valorInicial){

 int total = 0;


    for(int i = 0; i<tam; i++)
    {


        if(estados[i] != valorInicial)
        {



            total += array[i];
        }



    }
    return total;

}








float promedioDeArray(int estados[], int array[],int tam, int valorDeInicio )
{

    float promedio;
    int acum;
    int total;






           acum = CantidadCargadaArray(estados,tam,valorDeInicio);
            total = sumarTotalEnArray(array,estados,tam,valorDeInicio);



        promedio = (float)total / acum;









    return promedio;
}


void modificarPorIndex(int posicion,int array[],int nuevoValor)
{


    array[posicion-1] = nuevoValor;

}
