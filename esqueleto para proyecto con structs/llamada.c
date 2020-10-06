
#include "llamada.h"

int contLlamadas = 0;

int cantidadDeReclamosGestionados(eLlamada listadoLlamadas[], int tamLlamadas)
{


    int cantLlamadasCargadas = 0;

    for(int i = 0; i<tamLlamadas; i++)
    {

        if(listadoLlamadas[i].estado != LIBRE)
        {
            cantLlamadasCargadas ++;

        }
    }

    return cantLlamadasCargadas;
}




void NuevaLlamada(eLlamada listado[],int tamLlamadas,eAbonado listadoAbonados[],int tam)
{

    eLlamada aux;
    int index;
    int opc;

    index=  buscarLegajo(listadoAbonados,tam);

    if(index != -1)
    {

        aux.idLlamada = contLlamadas;
        aux.idAbonado = listadoAbonados[index].id;
        menuMotivo();
        opc= getInt("\nIngrese Motivo:");

        switch(opc)
        {

        case 1:
            aux.motivo = FALLA3G;
            break;

        case 2:
            aux.motivo = FALLALTE;
            break;


        case 3:
            aux.motivo = FALLAEQUIPO;
            break;

        default:
            printf("\nOpcion invalida\n");



        }


        aux.estado = ENCURSO;
        listado[contLlamadas] = aux;
        contLlamadas++;


    }






}

void menuMotivo()
{

    printf("\n1-Falla 3G\n2-Falla LTE\n3-Falla equipo ");



}





void inicializarEstadoLlamada(eLlamada listado[], int tam)
{
    int i;
    for( i = 0; i< tam; i++)
    {


        listado[i].estado = LIBRE;

    }


}

void finLlamada(eLlamada listado[],int tamLlamadas,eAbonado listadoAbonados[],int tam)
{





    eLlamada aux;
    int index;
    int opc;
    char rta;

    if(contLlamadas - listado[contLlamadas-1].idLlamada == 1)
    {



        index=  buscarLegajo(listadoAbonados,tam);

        if(index != -1)
        {


            aux.demora = getInt("\nIngrese tiempo de resolucion del llamado: ");
            printf("\n1-Solucionado\n2-No solucionado");
            opc= getInt("\nIngrese Motivo:");

            switch(opc)
            {

            case 1:
                aux.estado = SOLUCIONADO;
                break;

            case 2:
                aux.estado = NOSOLUCIONADO;
                break;



            default:
                printf("\nOpcion invalida\n");



            }


            rta= verificarSN("\nSeguro que desea cerrar llamada? s/n: ");


            if(rta == 's')
            {

                listado[contLlamadas-1].demora = aux.demora;
                listado[contLlamadas-1].estado = aux.estado;

                printf("\nLlamada a sido cerrada.\n");

            }
            else
            {


                printf("\nSe aborto el cierre de llamada");

            }



        }
        else
        {


            printf("\nLegajo no encontrado");
        }


    }
    else
    {

        printf("\nNo tienes llamadas a cerrar.\n");
    }



}


void HardcodeoLlamadas(eLlamada listado[], int tam)
{


    /*  int idLlamada
      int idAbonado;
      int motivo;
      int estado;
      int demora;

    */
    int idLlamadas[5] = {1,2,3,4,5};
    int idAbonados[5] = {1,2,2,4,4};
    int motivos[5] = {FALLA3G,FALLA3G,FALLA3G,FALLA3G,FALLALTE};
    int estados[5] = {SOLUCIONADO,SOLUCIONADO,SOLUCIONADO,SOLUCIONADO,SOLUCIONADO};
    int demoras[5] = {110,100,55,15,12};

    for(int i =0; i<5; i++)
    {

        listado[i].idLlamada = idLlamadas[i];
        listado[i].idAbonado = idAbonados[i];
        listado[i].motivo = motivos[i];
        listado[i].estado = estados[i];
        listado[i].demora = demoras[i];


    }


}


void nombreYApellidoDelAbonadoConMasReclamos(eLlamada listadoLlamadas[],int tamLlamadas,eAbonado listadoAbonados[],int tam)
{

    int max = INT_MIN;
    int cantLlamadasCargadas ;
    int cantAbonadosCargadas ;

    cantLlamadasCargadas = cantidadDeReclamosGestionados(listadoLlamadas,tamLlamadas);
    cantAbonadosCargadas = cantidadDeAbonadosActivos(listadoAbonados,tam);




    int cont[cantAbonadosCargadas];

    char nombresAbonados[cantAbonadosCargadas][20];
    char apellidosAbonados[cantAbonadosCargadas][20];


    int cantidadMax;
    char nombreAbonadoConMasReclamos[20];
    char apellidoAbonadoConMasReclamos[20];



    for(int i = 0; i<cantAbonadosCargadas; i++)
    {

        strcpy(nombresAbonados[i],listadoAbonados[i].nombre);
        strcpy(apellidosAbonados[i],listadoAbonados[i].apellido);

        cont[i] = 0;


    }




    for(int i = 0; i< cantAbonadosCargadas; i++)
    {

        for(int k = 0; k<cantLlamadasCargadas; k++)
        {

            if(listadoLlamadas[k].idAbonado == listadoAbonados[i].id )
            {
                cont[i]++;

            }
        }

    }



    cantidadMax =  retornarMayor(cont,cantAbonadosCargadas);
    cantidadMax = getMax(cont,max,cantAbonadosCargadas);

    for(int i = 0; i<cantAbonadosCargadas; i++)
    {

        if(cantidadMax == cont[i])
        {

            strcpy(nombreAbonadoConMasReclamos,nombresAbonados[i]);
            strcpy(apellidoAbonadoConMasReclamos,apellidosAbonados[i]);
            break;


        }


    }
    printf("\nEl abonado con mas reclamos es %s %s con %d reclamos\n",nombreAbonadoConMasReclamos,apellidoAbonadoConMasReclamos,cantidadMax);

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


void reclamoMasRealizado(eLlamada listado[],int tamLlamadas)
{


    int cantidadDeReclamos;
    cantidadDeReclamos = cantidadDeReclamosGestionados(listado,tamLlamadas);

    int cont3g = 0;
    int contEquipo=0;
    int contLte=0;



    char nombreDeMayorFalla[20];
    int cantidadMayor;


    for(int i =0; i<cantidadDeReclamos; i++)
    {
        if(listado[i].motivo == FALLA3G)
        {
            cont3g++;
        }
        else
        {
            if(listado[i].motivo == FALLAEQUIPO)
            {
                contEquipo++;
            }
            else
            {

                contLte++;
            }
        }
    }
    int  cantidades[3]= {cont3g,contEquipo,contLte};


    cantidadMayor = retornarMayor(cantidades,3);

    for(int i =0; i<3; i++)
    {


        if(cont3g ==cantidadMayor)
        {

            strcpy(nombreDeMayorFalla,"falla 3G");

        }
        else
        {

            if(contEquipo == cantidadMayor)
            {

                strcpy(nombreDeMayorFalla,"falla equipo");

            }
            else
            {

                strcpy(nombreDeMayorFalla,"falla LTE");

            }
        }

    }

    printf("\nEl reclamo con mas resgistro es de %s con %d gestiones\n",nombreDeMayorFalla,cantidadMayor);

}

void reclamoMasDemoroEnPromedio(eLlamada listado[],int tamLlamadas)
{


    int cantidadDeReclamos;
    cantidadDeReclamos = cantidadDeReclamosGestionados(listado,tamLlamadas);

    int cont3gDemora = 0;
    int contEquipoDemora=0;
    int contLteDemora=0;

    int cont3g = 0;
    int contEquipo=0;
    int contLte=0;



    char nombreDeMayorFalla[20];
    float tiempopromedioMayorDemora;

    int max = INT_MIN;


    for(int i =0; i<cantidadDeReclamos; i++)
    {
        if(listado[i].motivo == FALLA3G)
        {
            cont3gDemora += listado[i].demora;
            cont3g++;
        }
        else
        {
            if(listado[i].motivo == FALLAEQUIPO)
            {
                contEquipoDemora+= listado[i].demora;
                contEquipo++;
            }
            else
            {

                contLteDemora+= listado[i].demora;
                contLte++;
            }
        }
    }
    int  cantidadDemoras[3]= {cont3gDemora,contEquipoDemora,contLteDemora};

    int  cantidades[3]= {cont3g,contEquipo,contLte};

    float promedios[3];

    for(int i= 0; i<3; i++)
    {

        promedios[i] = (float)cantidadDemoras[i]/cantidades[i];


    }



    tiempopromedioMayorDemora = getMaxF(promedios,max,3);


    if(promedios[0] == tiempopromedioMayorDemora)
    {
        strcpy(nombreDeMayorFalla,"falla 3G");
    }
    else
    {

        if(promedios[1] == tiempopromedioMayorDemora)
        {
            strcpy(nombreDeMayorFalla,"falla equipo");
        }else{

        strcpy(nombreDeMayorFalla,"falla LTE");

        }

    }


    printf("\nEl reclamo con mas demora es de %s con %.2f gestiones\n",nombreDeMayorFalla,tiempopromedioMayorDemora);


}








