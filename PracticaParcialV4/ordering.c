#include <string.h>




void ordenamientoBurbuja(int desordenado[], int tam)
{

    int i;
    int j;




    for(i = 0; i<tam-1; i++)
    {



        for(j = i+1; j<tam; j++)
        {

            if(desordenado[i]> desordenado[j])
            {

                int aux;

                aux = desordenado[i];
                desordenado[i] = desordenado[j];
                desordenado[j] = aux;

            }


        }


    }




}

void ordenamientoStringsBurbuja(char desordenado[], int tam, int estados[],int valorInicial)
{




    char auxString[20];


    for(int i = 0; i<tam-1; i++)
    {

        if(estados[i] != valorInicial);
        continue;

        for(int j = i+1; j<tam; j++)
        {


            if(strcmp(desordenado[j],desordenado[i])<1)
            {


                strcpy(auxString,desordenado[i]);

                strcpy(desordenado[i],desordenado[j]);

                strcpy(desordenado[j],auxString);

                //tambien ordenar si o si estados

            }


        }

    }

    for(int i = 0; i<tam; i++)
    {

        if(estados[i] != -1)
        {

            printf("%s \n",desordenado[i]);


        }




    }


}







