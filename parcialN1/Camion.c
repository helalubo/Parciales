
#include "Camion.h"


int contCamiones = 11;

/*
typedef struct {

int idMarca;
char nombre[50];
char pais[50];



}eMarca;



*/

//ahora(1Ford de eeuu, 2FIAT italia,3VW alemania)
void HardcodeoCamiones(eCamion listado[], int tam)
{
    //char nombres[6][50] = {"Lucrecia","Jorge","Natalia","Matías","Jeremias","Alejandro"};
    int idsCamiones[10] = {1,2,3,4,5,6,7,8,9,10};
    int idsChoferes[10] = {1,1,2,2,3,4,4,5,5,5};
    char patentes[10][51] = {"GAG105","FAF202","FSF303","QER684","TRT659","TRA707","PSO505","PFG888","GTH548","HJG542"};
    //1-ford 2-fiat 3-wv
    int idMarcas[10] = {1,1,2,2,3,1,1,1,1,1};
    int anios[10] = {2000,2000,1999,1999,2010,2005,2015,1999,1999,1999};
    float pesos[10] = {200.2,300.8,250.6,300.7,400.8,500.9,222.2,300,400,500};
    int cantidadRuedas[10] = {4,8,8,6,6,6,8,4,4,6};
    //1 corta distancia 0 larga distancia  //1-ford 2-fiat 3-wv
    int tipos[10] = {1,0,1,1,0,1,1,1,0,0};






    for(int i = 0; i< 10; i++)
    {


        listado[i].idCamion =idsCamiones[i];
        listado[i].idChofer =idsChoferes[i];
        strcpy(listado[i].patente,patentes[i]);
        listado[i].idMarca =idMarcas[i];
        listado[i].anio =anios[i];
        listado[i].peso =pesos[i];
        listado[i].cantidadRuedas =cantidadRuedas[i];
        listado[i].tipo =tipos[i];

        listado[i].estado = OCUPADO;

    }


}






int buscarPorIdCamion(eCamion listado[], int tam)
{

    int index  = -1;
    int legajo;
    legajo = getInt("\nIngrese id: ","\nid invalido");




    for(int i = 0; i<=tam; i++)
    {

        if(listado[i].estado == OCUPADO)
        {

            if(listado[i].idCamion == legajo)
            {


                index = i;
                break;


            }



        }


    }








    return index;




}









void  mostrarCamion(eCamion camion)
{
    char marca[21];
    char tipo[21];
    //1 corta distancia 0 larga distancia  //1-ford 2-fiat 3-wv
    switch(camion.idMarca)
    {

    case 1:
        strcpy(marca,"FORD");
        break;

    case 2:
        strcpy(marca,"FIAT");
        break;

    case 3:
        strcpy(marca,"WV");
        break;


    }


    switch(camion.tipo)
    {

    case 1:
        strcpy(tipo,"corta distancia");
        break;

    case 0:
        strcpy(tipo,"larga distacia");
        break;




    }

    /*
     int idCamion;
    int idChofer;
    char patente[21];
    int marca;
    int anio;
    float peso;
    int cantidadRuedas;
    int tipo;
    int estado;*/



    printf("%d%16d%16s%16s%16d%16.2f%16d%16s\n"
           ,camion.idCamion
           ,camion.idChofer
           ,camion.patente
           ,marca
           ,camion.anio
           ,camion.peso
           ,camion.cantidadRuedas
           ,tipo);




}





int buscarIndiceLibreCamion(eCamion listado[], int tam)
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


void inicializarEstadoCamion(eCamion listado[], int tam)
{
    int i;
    for( i = 0; i< tam; i++)
    {


        listado[i].estado = LIBRE;

    }


}

void mostrarListaDeCamionesConChofer(eCamion listado[],int tam, eChofer listadoChofer[],int tamChofer)
{

    printf("%s%16s%16s%16s%16s%16s%16s%16s%16s\n","Nombre chofer","id Camion","id chofer","patente","modelo","anio","peso","ruedas","tipo");

    //int flag;

    for(int k =0 ; k<tamChofer; k++)
    {




        for(int i = 0; i<tam; i++)
        {

            //  flag = 0;

            if(listado[i].estado == OCUPADO)
            {



                if(listadoChofer[k].idChofer == listado[i].idChofer)
                {

                    printf("%10s \t",listadoChofer[k].nombre);
                    mostrarCamion(listado[i]);
                    //    flag = 1;
                }


            }






        }


    }

}






void mostrarChoferConCamiones(eCamion listado[], int tam, eChofer listadoChoferes[],int tamChoferes)

{

    int flag;


    for(int i =0; i<tamChoferes; i++)
    {


        if(listadoChoferes[i].estado==OCUPADO)
        {

            printf("\n\t\t\t\t\t*******************Chofer*******************\n");

            mostrarChofer(listadoChoferes[i]);

            flag =0;


            for(int k =0; k<tam; k++)
            {



                if(listadoChoferes[i].idChofer == listado[k].idChofer && listado[k].estado == OCUPADO)
                {

                    printf("\n\t\t\t\t\t*******************Camion*******************\n");
                    mostrarCamion(listado[k]);
                    flag = 1;

                }



            }



            if(flag == 0)
            {

                printf("\t\t\t\t\tNo tiene camiones registrados\n");
                break;
            }



        }








    }



}

void AltaCamion(eCamion listado[], int tam, eChofer listadoChoferes[],int tamChoferes)
{





    eCamion aux;
    int index;
    char rta;

    int idAux;


    index =  buscarIndiceLibreCamion(listado,tam);

    if(index != -1)
    {





        aux.idCamion = contCamiones++;
        mostrarListaDeChoferes(listadoChoferes,tamChoferes);
        idAux= buscarId(listadoChoferes,tamChoferes);

        while(idAux == -1)
        {
            printf("\nError id cliente no existente\n ");
            idAux= buscarId(listadoChoferes,tamChoferes);
        }

        aux.idChofer = listadoChoferes[idAux].idChofer;




        getonlyAlphanumeric( aux.patente,"\nIngrese patente: ","\nPatente invalida");
        aux.idMarca = getNumberWithDefinedRange("\n1-Ford\n2-Fiat\n3-wv\nIngrese marca: ",3,1,"\nErro,marca invalida");

        aux.anio = getNumberWithDefinedRange("\nIngrese anio de modelo: ",2020,1950,"\nanio invalido");
        aux.peso = getFloat("\nIngrese peso: ");
        aux.cantidadRuedas = getNumberWithDefinedRange("\nIngrese cantidad de ruedas Entre 16 y 4: ",16,4,"\nCantidad de ruedas invalida");
        aux.tipo = getNumberWithDefinedRange("\n1-corta distancia\n0- larga distancia ",1,0,"\nErro,marca invalida");






        rta = verificarSN("\nEsta seguro que desea ingresar este camion? s/n");

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

    printf("No hay lugar");





}



void bajaCamion(eCamion listado[], int tam)
{

    int index;
    char rta;


    index = buscarPorIdCamion(listado,tam);


    if(index != -1)
    {

        printf("\n  id encontrado \n ");
        mostrarCamion(listado[index]);
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


    printf("\nId no encontrado\n");







}


void modificarCamion(eCamion listado[], int tam,eChofer listadoChoferes[],int tamChoferes)
{

    int opc;
    int index;

    int auxEntero;
    int idAux;



    char rta;
    mostrarListaDeCamionesConChofer(listado,tam,listadoChoferes,tamChoferes);
    printf("ID CAMION");
    index = buscarPorIdCamion(listado,tam);





    if(index != -1)
    {


        //6-Modificar CAMIONES,solo se puede modificar el tipo y el CHOFER .

        /*
         idAux= buscarId(listadoChoferes,tamChoferes);

           while(idAux == -1)
           {
               printf("\nError id cliente no existente\n ");
                idAux= buscarId(listadoChoferes,tamChoferes);
           }

           aux.idChofer = listadoChoferes[idAux].idChofer;


         */


        printf("1-Modificar marca\n2-Modificar chofer");
        opc = getInt("\nIngrese opcion: ","\nOpcion invalida");


        switch(opc)
        {

        //ahora(1Ford de eeuu, 2FIAT italia,3VW alemania)
        case 1:

            auxEntero = getNumberWithDefinedRange("\n1-FORD\n2-FIAT\n3-VW ",3,1,"\nError,marca invalida");
            // auxEntero = getNumberWithDefinedRange()
            //auxEntero = getInt("\n1-FORD\n2-FIAT\n3-VW ","\nError,marca invalida");

            rta = verificarSN("\nEsta seguro que desea cambiar el nombre? s/n: ");

            if(rta == 's')
            {


                listado[index].idMarca = auxEntero;
                printf("\n Se ha cambiado el valor exitosamente.");

            }
            else
            {

                printf("\nCAMBIO ABORTADO.");
            }



            break;

        case 2:

            mostrarListaDeChoferes(listadoChoferes,tamChoferes);
            idAux= buscarId(listadoChoferes,tamChoferes);

            while(idAux == -1)
            {
                printf("\nError id cliente no existente\n ");
                idAux= buscarId(listadoChoferes,tamChoferes);
            }

            auxEntero = listadoChoferes[idAux].idChofer;

            rta = verificarSN("\nEsta seguro que desea cambiar el conductor? s/n: ");

            if(rta == 's')
            {

                listado[index].idChofer = auxEntero;
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



void bajaChofer(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones)
{

    int index;
    char rta;
    int auxInt;


    mostrarListaDeChoferes(listado,tam);
    index = buscarId(listado,tam);


    if(index != -1)
    {

        printf("\n  Legajo encontrado \n ");
        mostrarChofer(listado[index]);
        auxInt = listado[index].idChofer;

        for(int i=0; i<tamCamiones; i++)
        {
            if(listadoCamiones[i].idChofer == auxInt)
            {

                mostrarCamion(listadoCamiones[i]);
            }

        }


        rta = verificarSN("\nDesea dar de baja s/n: ");

        if(rta == 's')
        {


            listado[index].estado = LIBRE;
            for(int i=0; i<tamCamiones; i++)
            {
                if(listadoCamiones[i].idChofer== auxInt)
                {

                    listadoCamiones[i].estado =LIBRE;
                }

            }
            printf("\nSe a Eliminado el chofer y todos sus camiones");

        }
        else
        {

            printf("\n LA BAJA A SIDO ABORTADA.");

        }







    }


    //printf("\n LA BAJA A SIDO ABORTADA.");







}


//9- ordenar los CAMIONES por tipo y mostrarlos con sus CHOFERES
/*Profe, en el punto nueve 9- ordenar los CAMIONES por tipo y mostrarlos con sus CHOFERES., alcanza con mostrarlo con el nombre del chofer? SI! */



void mostrarChoferesPorTipo(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones)
{


    eCamion aux;
    eChofer auxChofer;

    for(int i = 0; i<tamCamiones-1; i++)
    {



        for(int j = i+1; j<tam; j++)
        {

            if(listadoCamiones[i].tipo < listadoCamiones[j].tipo)
            {

                if(listadoCamiones[i].estado == OCUPADO &&listado[i].estado == OCUPADO)
                {


                    aux = listadoCamiones[i];
                    listadoCamiones[i] = listadoCamiones[j];
                    listadoCamiones[j] = aux;


                    auxChofer = listado[i];
                    listado[i] = listado[j];
                    listado[j] = auxChofer;
                }

            }


        }


    }


    for(int i = 0; i<tamCamiones; i++)
    {


        if(listadoCamiones[i].estado == OCUPADO &&listado[i].estado == OCUPADO)
        {

            mostrarChofer(listado[i]);
            mostrarCamion(listadoCamiones[i]);
        }



    }




}


//FALTA DEL 10 EN ADELANTE

void mostrarChoferesConMasDeUnCamion(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones)
{

    int cantidadCamionesPorChofer[tam];




    for(int i = 0; i<tam; i++)
    {

        cantidadCamionesPorChofer[i] = 0;
    }


    for(int k = 0; k<tam; k++)
    {



        for(int i = 0; i<tamCamiones; i++)
        {

            if(listado[k].idChofer == listadoCamiones[i].idChofer)
            {

                cantidadCamionesPorChofer[k]++;
                // printf("\nCantidad de camiones: %d",cantidadCamionesPorChofer[i]);
            }

        }




    }

    for(int j = 0; j<tam; j++)
    {
        if(listado[j].estado == OCUPADO && cantidadCamionesPorChofer[j]> 1)
        {



            mostrarChofer(listado[j]);
            printf("\nCantidad de camiones: %d\n",cantidadCamionesPorChofer[j]);

        }
    }



}

void mostrarCaminionesConMasDe10Anios(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones)
{

    int aniosdeAntiguedad[tamCamiones];





    for(int i = 0; i<tamCamiones; i++)
    {

        if(listadoCamiones[i].estado == OCUPADO)
        {

            aniosdeAntiguedad[i] = 2020 - listadoCamiones[i].anio;



        }

    }






    for(int j = 0; j<tamCamiones; j++)
    {
        if(listadoCamiones[j].estado == OCUPADO && aniosdeAntiguedad[j]> 10)
        {


            printf("\n****************************************\n");
            mostrarCamion(listadoCamiones[j]);
            //////////////////

            for(int k = 0; k<tam; k++)
            {
                if(listadoCamiones[j].idChofer == listado[k].idChofer)
                {
                    printf(" %s %s",listado[k].nombre,listado[k].nombre);

                }

            }




            /////////////////
            printf("\nCantidad de anios de antiguedad: %d\n",aniosdeAntiguedad[j]);



        }
    }



}

void mostrarCamionesPorMarca(eCamion list[], int tam)
{

    int aux;

    aux = getNumberWithDefinedRange("\n1-Ford\n2-Fiat\nIngrese marca: ",3,1,"\nErro,marca invalida");



    for(int i = 0 ; i<tam; i++)
    {

        if(aux == list[i].idMarca && list[i].estado == OCUPADO)
        {

            mostrarCamion(list[i]);
        }

    }




}

void odenarChoferesPorCantidadDeCamiones(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones)
{

    int cantidadCamionesPorChofer[tam];

    eChofer aux;


    for(int i = 0; i<tam; i++)
    {

        cantidadCamionesPorChofer[i] = 0;
    }


    for(int k = 0; k<tam; k++)
    {



        for(int i = 0; i<tamCamiones; i++)
        {

            if(listado[k].idChofer == listadoCamiones[i].idChofer && listadoCamiones[i].estado == OCUPADO)
            {

                cantidadCamionesPorChofer[k]++;

            }

        }




    }








    for(int i = 0; i<tam-1; i++)
    {



        for(int j = i+1; j<tam; j++)
        {

            if(cantidadCamionesPorChofer[i]< cantidadCamionesPorChofer[j])
            {



                aux = listado[i];
                listado[i] = listado[j];
                listado[j] = aux;

            }


        }


    }








    for(int j = 0; j<tam; j++)
    {
        if(listado[j].estado == OCUPADO )
        {



            mostrarChofer(listado[j]);



        }

    }




}


void odenarChoferesPorCantidadDeCamionesYAlfabeticamente(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones)
{

    int cantidadCamionesPorChofer[tam];

    eChofer aux;


    for(int i = 0; i<tam; i++)
    {

        cantidadCamionesPorChofer[i] = 0;
    }


    for(int k = 0; k<tam; k++)
    {



        for(int i = 0; i<tamCamiones; i++)
        {

            if(listado[k].idChofer == listadoCamiones[i].idChofer && listadoCamiones[i].estado == OCUPADO)
            {

                cantidadCamionesPorChofer[k]++;

            }

        }




    }








    for(int i = 0; i<tam-1; i++)
    {



        for(int j = i+1; j<tam; j++)
        {

            if((cantidadCamionesPorChofer[i]< cantidadCamionesPorChofer[j]) || (cantidadCamionesPorChofer[i] == cantidadCamionesPorChofer[j] && stricmp(listado[j].nombre,listado[i].nombre)>0))
            {



                aux = listado[i];
                listado[i] = listado[j];
                listado[j] = aux;

            }


        }


    }








    for(int j = 0; j<tam; j++)
    {
        if(listado[j].estado == OCUPADO )
        {



            mostrarChofer(listado[j]);




        }

    }




}

void promedioDeAniosDeAntiguedadDeCamiones(eCamion listadoCamiones[], int tamCamiones )
{

    int aniosdeAntiguedad=0;
    int cont = 0;
    float promedio;





    for(int i = 0; i<tamCamiones; i++)
    {

        if(listadoCamiones[i].estado == OCUPADO)
        {

            aniosdeAntiguedad += 2020 - listadoCamiones[i].anio;
            cont++;



        }

    }

    promedio = (float)aniosdeAntiguedad/cont;


    printf("\nEl promedio de anios de la flota de camiones es de %.2f",promedio);

}



///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////


///FALTA
void MostrarCamionesDelMarcaSeleccionada(eCamion listadoCamiones[], int tamCamiones, eChofer listado[], int TamChofer)
{

//1-ford 2-fiat 3-wv



    int aux;

    aux = getNumberWithDefinedRange("\n1-Ford\n2-Fiat\n3-WV\nIngrese marca: ",3,1,"\nError,marca invalida");



    for(int i = 0 ; i<tamCamiones; i++)
    {

        if(listadoCamiones[i].estado == OCUPADO && listadoCamiones[i].idMarca == aux)
        {
          //  mostrarCamion(listadoCamiones[i]);


          for(int k = 0; k<TamChofer;k++)
          {
              if(listado[k].estado == OCUPADO && listadoCamiones[i].idChofer == listado[k].idChofer)
              {

                  mostrarChofer(listado[k]);
              }
          }

        }



    }












}














void mostrarCamionesMasViejos(eCamion listadoCamiones[], int tamCamiones)
{


    int contador[tamCamiones];
    int menor;
    int cantCargada=0;

    for(int i = 0; i<tamCamiones; i++)
    {

        contador[i] = 0;


    }



    for(int k = 0; k<tamCamiones; k++)
    {


        if(listadoCamiones[k].estado == OCUPADO)
        {
            contador[k]= listadoCamiones[k].anio;
            cantCargada++;
            // printf("****\n%d\n******",contador[k]);

        }
    }


    menor = retornarMenor(contador,cantCargada);
    //  printf("%d",menor);


    for(int i = 0; i<tamCamiones; i++)
    {


        if(listadoCamiones[i].anio == menor && listadoCamiones[i].estado == OCUPADO )


            mostrarCamion(listadoCamiones[i]);





    }











}

void MostrarCamionesSeparadasPorMarca(eCamion listadoCamiones[], int tamCamiones)
{

    eCamion aux;



    for(int i = 0; i<tamCamiones-1; i++)
    {



        for(int j = i+1; j<tamCamiones; j++)
        {

            if(listadoCamiones[i].idMarca > listadoCamiones[j].idMarca)
            {



                aux = listadoCamiones[i];
                listadoCamiones[i] = listadoCamiones[j];
                listadoCamiones[j] = aux;

            }


        }


    }

    for(int i = 0; i<tamCamiones; i++)
    {

        if(listadoCamiones[i].estado == OCUPADO)
        {

            mostrarCamion(listadoCamiones[i]);

        }





    }









}

void mostrarCantidadDeUnTipoYUnaMarcaAlMismoTiempo(eCamion listadoCamiones[], int tamCamiones)
{


    //1 corta distancia 0 larga distancia  //1-ford 2-fiat 3-wv

    int auxTipo;
    int auxMarca;



    auxTipo = getNumberWithDefinedRange("\n1-corta distancia\n0- larga distancia\nIngrese tipo: ",1,0,"\nErro, ingrese valor valido");
    auxMarca = getNumberWithDefinedRange("\n1-ford 2-fiat 3-wv\nIngrese tipo: ",3,1,"\nIngrese opcion valida");


    for(int i =0; i<tamCamiones ; i++)
    {

        if(listadoCamiones[i].idMarca == auxMarca && listadoCamiones[i].tipo == auxTipo && listadoCamiones[i].estado == OCUPADO)
        {

            mostrarCamion(listadoCamiones[i]);

        }




    }


}



void mostrarMarcaMasElegidaPorLosChoferes(eCamion listadoCamiones[], int tamCamiones)
{


    //1 corta distancia 0 larga distancia  //1-ford 2-fiat 3-wv

    int ford = 0;
    int fiat = 0;
    int wv = 0;
    char marca[21];

    int masElegido;








    for(int i =0; i<tamCamiones ; i++)
    {

        if(listadoCamiones[i].estado == OCUPADO)
        {



            switch(listadoCamiones[i].idMarca)
            {
            case 1:
                ford++;
                break;


            case 2:
                fiat++;
                break;

            case 3:
                wv++;
                break;







            }


        }


    }


    int contadores[3] = {ford,fiat,wv};

    masElegido = retornarMayor(contadores,3);


    if(masElegido==ford)
    {
        strcpy(marca,"Fort");
    }
    else
    {


        if(masElegido == fiat)
        {
            strcpy(marca,"Fiat");

        }
        else
        {

            strcpy(marca,"Wv");

        }
    }







    printf("\nLa Marca mas elegida es: %s",marca);



}

int mostrarAniosDeAntiguedadAcumuladoDeTodosLosCamiones(eCamion listadoCamiones[], int tamCamiones)
{



    int contEdadTotal=0;

    for(int i = 0; i<tamCamiones; i++)
    {
        if(listadoCamiones[i].estado == OCUPADO)
        {

            contEdadTotal+= 2020 -listadoCamiones[i].anio;
        }

    }

    printf("\nEl acumulado de la antigueda de todos los camiones en total es de %d anios\n",contEdadTotal);
    return contEdadTotal;












}



void mostrarCamionesConMayorCantidadDeRuedasYNombreDeDuenio(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones)
{


    int cantidadesDeRuedas[tamCamiones];
    int ruedas;


    for(int i = 0; i<tamCamiones; i++)
    {

        cantidadesDeRuedas[i] = 0;




    }



    for(int i =0; i<tamCamiones ; i++)
    {

        if(listadoCamiones[i].estado == OCUPADO)
        {


            cantidadesDeRuedas[i] = listadoCamiones[i].cantidadRuedas;









        }


    }


    ruedas = retornarMayor(cantidadesDeRuedas,tamCamiones);


    for(int i = 0; i<tamCamiones; i++)
    {

        if(listadoCamiones[i].cantidadRuedas== ruedas)
        {

            mostrarCamion(listadoCamiones[i]);

            for(int k = 0; k<tam; k++)
            {
                if(listado[k].idChofer == listadoCamiones[i].idChofer)
                {

                    printf("\t\t\t\tNombre de chofer: %s %s\t\t\t\t Legajo Chofer: %s\n",listado[k].nombre,listado[k].apellido,listado[k].legajo);

                }

            }



        }

    }


}




void mostrarCamionConPesoMenorYDuenio(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones)
{


    float pesosDeCamiones[tamCamiones];
    float menorCantidadPeso;


    for(int i = 0; i<tamCamiones; i++)
    {

        pesosDeCamiones[i] = 0;




    }



    for(int i =0; i<tamCamiones ; i++)
    {

        if(listadoCamiones[i].estado == OCUPADO)
        {


            pesosDeCamiones[i] = listadoCamiones[i].peso;









        }


    }


    menorCantidadPeso = retornarMenorFlotante(pesosDeCamiones,tamCamiones,0);


    for(int i = 0; i<tamCamiones; i++)
    {

        if(listadoCamiones[i].peso== menorCantidadPeso )
        {

            mostrarCamion(listadoCamiones[i]);

            for(int k = 0; k<tam; k++)
            {
                if(listado[k].idChofer == listadoCamiones[i].idChofer)
                {

                    printf("\t\t\t\tNombre de chofer: %s %s\t\t\t\t Legajo Chofer: %s\n",listado[k].nombre,listado[k].apellido,listado[k].legajo);

                }

            }



        }

    }











}


void camionesDeDuenosMujeresOrdenadosPorPeso(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones)
{


    eCamion aux;





    for(int i = 0; i<tamCamiones-1; i++)
    {



        for(int j = i+1; j<tamCamiones; j++)
        {

            if(listadoCamiones[i].peso > listadoCamiones[j].peso  )
            {



                aux = listadoCamiones[i];
                listadoCamiones[i] = listadoCamiones[j];
                listadoCamiones[j] = aux;



            }


        }


    }


    for(int i =0; i<tamCamiones; i++)
    {



        for(int k=0; k<tam ; k++)
        {


            if(listadoCamiones[i].idChofer == listado[k].idChofer && listado[k].sexo == 'f'&& listado[k].estado == OCUPADO)
            {
                mostrarCamion(listadoCamiones[i]);


            }


        }




    }









}

void MostrarCamionesQueSuperenElPesoYtenganAntiguedadMayorA15anios(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones)
{

    float peso;
    int flag = 0;

    peso = getFloat("\nIngrese peso minimo: ");

    for(int i =0; i<tamCamiones; i++)
    {
        if(2020 -listadoCamiones[i].anio >15 && listadoCamiones[i].peso >peso&& listadoCamiones[i].estado == OCUPADO)
        {
            mostrarCamion(listadoCamiones[i]);
            flag = 1;


        }
    }

    if(flag == 0)
    {
        printf("\nNo hay camiones que superen ese peso\n");
    }

}


void MostrarCamionConMayorPesoDependiendoLaMarca(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones)
{
    //1-ford 2-fiat 3-wv
    int marca;
    float peso[tamCamiones];
    float pesoMayor;

    marca = getNumberWithDefinedRange("\n1-ford \n2-fiat \n3-wv\nIngrese Marca",3,1,"\nError!Ingrese marca correcta");

    for(int i= 0; i<tamCamiones; i++)
    {
        peso[i] = 0;
    }


    for(int i = 0; i<tam; i++)
    {
        if(listadoCamiones[i].idMarca == marca)
        {
            peso[i] = listadoCamiones[i].peso;
        }


    }
    pesoMayor = retornarMayorFlotante(peso,tamCamiones);



    for(int i= 0; i<tamCamiones; i++)
    {

        if(listadoCamiones[i].peso == pesoMayor)
        {
            mostrarCamion(listadoCamiones[i]);
        }
    }







}

void promedioDellantasQueUsaCadaChoferEnSuFlota(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones)
{


    int cantidadDeLlantasPorUsuario[tam];
    int cantidadDeCamionesPorUsuario[tam];
    int flag;


    float promedios[tam];


    for(int i = 0; i<tam; i++)
    {

        cantidadDeLlantasPorUsuario[i] =0;
        cantidadDeCamionesPorUsuario[i] =0;


    }



    for(int i =0; i<tam; i++)
    {



        for(int k=0; k<tamCamiones ; k++)
        {


            if(listadoCamiones[k].idChofer == listado[i].idChofer && listado[i].estado == OCUPADO)
            {

                cantidadDeLlantasPorUsuario[i] += listadoCamiones[k].cantidadRuedas;
                cantidadDeCamionesPorUsuario[i]++;


            }


        }




    }

    for(int k =0; k<tam; k++)
    {

        if(listado[k].estado == OCUPADO)
        {

            promedios[k] = (float)cantidadDeLlantasPorUsuario[k] /cantidadDeCamionesPorUsuario[k];

            flag = 0;
            mostrarChofer(listado[k]);
            for(int i = 0; i<tamCamiones; i++)
            {


                if(listadoCamiones[i].estado == OCUPADO && cantidadDeLlantasPorUsuario[k] != 0)
                {


                    flag =1;

                    break;




                }

            }

            if(flag == 1)
            {
                printf("\npromedio de ruedas: %.2f\n",promedios[k]);
            }
            if(flag == 0)
            {

                printf("\nChofer sin camiones.\n");
            }
        }



    }


}

void choferConMayorCantidadDeRuedasEnSuFlota(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones)
{

    int cantidadDeLlantasPorUsuario[tam];

    int maximaCantidadDeRuedasDeUnUsuario;





    for(int i = 0; i<tam; i++)
    {

        cantidadDeLlantasPorUsuario[i] =0;



    }



    for(int i =0; i<tam; i++)
    {



        for(int k=0; k<tamCamiones ; k++)
        {


            if(listadoCamiones[k].idChofer == listado[i].idChofer && listado[i].estado == OCUPADO && listadoCamiones[k].estado == OCUPADO)
            {

                cantidadDeLlantasPorUsuario[i] += listadoCamiones[k].cantidadRuedas;
                //  cantidadDeCamionesPorUsuario[i]++;


            }


        }


        maximaCantidadDeRuedasDeUnUsuario = retornarMayor(cantidadDeLlantasPorUsuario,tam);





    }

    for(int k =0; k<tam; k++)
    {

        if(listado[k].estado == OCUPADO)
        {

            // promedios[k] = (float)cantidadDeLlantasPorUsuario[k] /cantidadDeCamionesPorUsuario[k];

            //   flag = 0;
            //  mostrarChofer(listado[k]);
            for(int i = 0; i<tamCamiones; i++)
            {


                if(listadoCamiones[i].estado == OCUPADO && cantidadDeLlantasPorUsuario[k] == maximaCantidadDeRuedasDeUnUsuario)
                {


                    mostrarChofer(listado[k]);
                    printf("\nTiene una cantidad de %d ruedas \n",maximaCantidadDeRuedasDeUnUsuario);
                    break;






                }

            }


        }



    }

}

void mostrarCamionLargaDistanciaConMayorPeso(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones)
{


    float mayorPeso = 0;
    float PesosDeCamiones[tamCamiones];

    for(int i =0; i<tamCamiones ; i++)
    {


        PesosDeCamiones[i] =0;




    }

    for(int i =0; i<tamCamiones ; i++)
    {

        if(listadoCamiones[i].estado == OCUPADO && listadoCamiones[i].tipo == 0 )
        {
            PesosDeCamiones[i] = listadoCamiones[i].peso;



        }


    }


    mayorPeso = retornarMayorFlotante(PesosDeCamiones,tamCamiones);





    for(int i =0; i<tamCamiones ; i++)
    {

        if(listadoCamiones[i].estado == OCUPADO && listadoCamiones[i].peso == mayorPeso  )
        {




            mostrarCamion(listadoCamiones[i]);


        }


    }


}









