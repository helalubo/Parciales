
#define OCUPADO 1
#define LIBRE 0

//tamanios

#define TContratacion 10

#include <string.h>
#include <limits.h>
//#include "pantalla.h"






typedef struct
{
    int idContratacion;
    int idPantalla;
    char contenidoPublicitario[365];
    char cuilCliente[20];
    int cantidadDeDias;
    char nombreArchivoVideo[50];
    int estado;

} eContratacion;





int cantidadDeContratacionesActivas(eContratacion listadoPantallas[],int tam);
void inicializarEstadoContratacion(eContratacion listado[], int tam);
int buscarIndiceLibreContrataciones(eContratacion listado[], int tam);
void AltaContrataciones(eContratacion listado[], int tam);

void  mostrarContrataciones(eContratacion contrato);

int buscarPorCuil(eContratacion listado[], int tam);


void bajaContratacion(eContratacion listado[], int tam);

void HardcodeoContratacion(eContratacion listado[], int tam);


void menuModificacionContratacion();






















































