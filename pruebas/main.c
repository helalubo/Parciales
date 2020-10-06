#include <stdio.h>
#include <stdlib.h>


int main()
{

    int* punteroEntero;
    int* aux;
    int* otra;
    int i;


    // punteroEntero = (int*) calloc(1,sizeof(int));




    punteroEntero = (int*) malloc(sizeof(int)*5);
    otra = (int*) malloc(sizeof(int));

    *otra = 5000;

    //free(otra);
    otra = NULL;
    if(punteroEntero!=NULL)
    {
        for(i=0; i<5; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", punteroEntero+i);
        }

        for(i=0; i<5; i++)
        {
            printf("%d\n", *(punteroEntero+i));
        }

        aux =(int*) realloc(punteroEntero, 10);
        if(aux!=NULL)
        {
            punteroEntero = aux;
            printf("Redimensiono a 10\n\n");
            for(i=5; i<10; i++)
            {
                printf("Ingrese un numero: ");
                scanf("%d", punteroEntero+i);
            }
            for(i=0; i<10; i++)
            {
                printf("%d\n", *(punteroEntero+i));
            }



            aux = (int*) realloc(punteroEntero, sizeof(int)*3);
            if(aux!=NULL)
            {
                printf("Redimensiono a 3\n\n");
                punteroEntero = aux;
                //free(aux);

                for(i=0; i<3; i++)
                {
                    printf("%d\n", *(punteroEntero+i));
                }
            }



        }

    }
        return 0;
    }
