//*******************************************************************************/
#include <stdio.h>

int main()
{
   // printf("archivos");
    FILE* miArchivo;
    int legajo;
    char nombre[20]="maria";
    char texto[50];
    int i;
    int listado[10] ={10,9,8,5,6,3,2,5,1,4};
    legajo=123;
    int edad;

    //escritura simple
    /*miArchivo=fopen("elLegajo.txt","w");
    fprintf(miArchivo,"legajo");
    fclose(miArchivo);
     miArchivo=fopen("miNombre.txt","w");
    fprintf(miArchivo,nombre);
    fclose(miArchivo);
    */

    //escritura de varios datos
/*
    for(i=0;i<10;i++)
    {
        printf("\ningrese edad :");
        scanf("%d",&edad);
        listado[i]=edad;
    }
*/


    //funcion guardar(listado de enteros,tamanio)

    miArchivo=fopen("numero.txt","w");
    for(i=0;i<10;i++)
    {
        fwrite(&listado[i],sizeof(int),1,miArchivo);

    }
    fclose(miArchivo);




    //leer
    //ABM
    //guardar


    miArchivo=fopen("numero.txt","r");
    int indice=0;
    while(!feof(miArchivo))
    {
        fread(&listado[indice],sizeof(int),1,miArchivo);
        indice++;
    }

     for(i=0;i<10;i++)
    {
       printf(" \n%d : ",listado[i]);
    }




    /*

    miArchivo=fopen("miNombre.txt","r");
    fgets(texto,50,miArchivo);
    puts("el texto es :");
    puts(texto);
*/
    return 0;
}

