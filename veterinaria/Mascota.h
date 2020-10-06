
#define OCUPADO 1
#define LIBRE 0

//tamanios

#define TMascotas 20

#include <string.h>
#include <limits.h>
#include "Cliente.h"





//) (nombre,tipo{gato,perro,raro},raza,edad,peso,sexo) (

typedef struct
{
    int idMascota;
    int idCliente;
    char nombre[365];
    int tipo;
    char raza[20];
    int edad;
    float peso;
    char sexo;
    int estado;

} eMascota;





int cantidadDeMascotasActivas(eMascota listado[],int tam);
void inicializarEstadoMascota(eMascota listado[], int tam);
int buscarIndiceLibreMascotas(eMascota listado[], int tam);
void AltaMascotas(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes);

void  mostrarMascota(eMascota mascota);

int buscarPorIdMascota(eMascota listado[], int tam);


void bajaMascota(eMascota listado[], int tam);

void HardcodeoMascota(eMascota listado[], int tam);


void menuModificacionMascota();
void mostrarListaDeMascotas(eMascota listado[],int tam, eCliente listadoCliente[],int tamClientes);



////////////
void modificarMascota(eMascota listado[], int tam);
void mostrarClienteConMascota(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes);





void mostrarDueniosConPerros(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes);



void mostrarDueniosConGatos(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes);


void nombresMascotasYsusDuenios(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes);






void duenosConGatosOrdenadosAlfabeticamente(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes);



void mostrarDueniosLaBocaConMasDeUnaMascota(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes);







void mostrarCantidadDeMascotaConRazaOtra(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes);




void mostrarMascotasCon7aniosOMas(eMascota listado[], int tam);





void mostrarCantidadDeMascotasMacho(eMascota lista [], int tam);





////////////////

void mostrarDueniosDeGatosConMasDe30Anios(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes);




void promedioDueniosConMascotasGatos(eMascota listado[], int tam, eCliente listadoClientes[],int tamClientes);




