/*
typedef struct {

int idMarca;
char nombre[50];
char pais[50];



}eMarca;
ahora(Ford de eeuu, FIAT italia,VW alemania)


*/

#include "marca.h"
#include <string.h>
void hardcodeoMarcas(eMarca listaDeMarcas[], int tamMarcas)
{


    int ids[3]= {1,2,3};
    char nombres[3][50] ={"FORD","FIAT","VW"};
    char paises[3][50] = {"EEUU","ITALIA","ALEMANIA"};


    for(int i = 0; i<3; i++)
    {

    listaDeMarcas[i].idMarca = ids[i];
    strcpy(listaDeMarcas[i].nombre,nombres[i]);
    strcpy(listaDeMarcas[i].pais ,paises[i]);


    }


}
