#include <stdio.h>
#include <stdlib.h>


///Ejemplo crea un puntero a un archivo y lo guardo
int main()
{
    FILE* miArchivo;

    int legajo;
    char nombre[20] = "Maria";
    char texto[50];
    legajo = 123;
    int edad;

    int listado[10];

    miArchivo=fopen("elLegajo.txt","w");
    fprintf(miArchivo,"legajo");
    fclose(miArchivo);



    miArchivo=fopen("elNombre.txt","w");
    fprintf(miArchivo,nombre);
    fclose(miArchivo);

    //Asi se crea un archivo de texto en C


    miArchivo=fopen("elNombre.txt","r");
    fgets(texto,50,miArchivo);
    puts("El texto es: ");
    puts(texto);

    ///Asi se trae informacion del archivo

    miArchivo=fopen("numeros.txt","w");



    for(int i = 0; i<10; i++)
    {
        printf("\nIngrese edad: ");
        scanf("%d",edad);

        fwrite(&edad,sizeof(int),1,miArchivo);
    }

 /*       for(int i = 0; i<10; i++)
    {


        fwrite(&i,sizeof(int),1,miArchivo);
    }
*/

    fclose(miArchivo);

    miArchivo=fopen("numeros.txt","r");
    int indice =0;

    while(!feof(miArchivo))
    {
        fread(&listado[indice],sizeof(int),1,miArchivo);
        indice++;
    }

    for(int i = 0; i<10; i++)
    {


        printf("\n %d : ",listado[i]);
    }


    return 0;
}
