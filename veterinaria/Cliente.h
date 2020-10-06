
#include "input.h"
#include "validate.h"

#define OCUPADO 1
#define LIBRE 0

//tamanios

#define T 10

#include <string.h>
#include <limits.h>






typedef struct
{
    int idCliente;
    char nombre[51];
    char apellido[51];
    char localidad[51];
    char telefono[20];
    int edad;
    char sexo;
    int estado;

} eCliente;
//nombre, apellido,localidad,teléfono,edad,sexo)

/** \brief Hardcodea un listado definido
 *
 * \param listado[] eAbonado donde se carga el hardcodeo
 * \param tam int tamanio del array
 * \return void
 *
 */
void Hardcodeo(eCliente listado[], int tam);
/** \brief Inicializa un array poniendolo como estado LIBRE 0
 *
 * \param listado[] eAbonado listado a inicializar
 * \param tam int tamanio
 * \return void
 *
 */
void inicializarEstado(eCliente listado[], int tam);
/** \brief Busca indice libre
 *
 * \param listado[] eAbonado listado donde buscar
 * \param tam int tamanio de listado
 * \return int retorna el indice libre o -1 si todos los indices estan ocupados
 *
 */


int buscarIndiceLibre(eCliente** listado);
/** \brief Da de alta una entidad
 *
 * \param listado[] eAbonado listado donde se agregara la entidad
 * \param tam int tamanio de listado
 * \return void
 *
 */
//void Alta(eCliente** listado);
/** \brief Muestra una entidad
 *
 * \param abonado eAbonado entidad a mostrar
 * \return void
 *
 */
void mostrarCliente(eCliente abonado);
/** \brief muestra toda la lista de abonados
 *
 * \param listado[] eAbonado lista a mostrar
 * \param tam int   tamanio de la lista
 * \return void
 *
 */
void mostrarListaDeClientes(eCliente listado[],int tam);
/** \brief Busca un legajo/ id
 *
 * \param listado[] eAbonado listado donde buscara
 * \param tam int tamanio de listado
 * \return int retorna posicion en el array donde se encuentra el id o -1 si no lo encuentra.
 *
 */
int buscarId(eCliente listado[], int tam);
/** \brief Modifica la entidad
 *
 * \param listado[] eAbonado lista donde se encuentra la entidad a modificar
 * \param tam int tamanio de listado
 * \return void
 *
 */
//void modificarCliente(eCliente listado[], int tam);
/** \brief Da de baja una entidad cambiando su estado de OCUPADO 1 a LIBRE 0
 *
 * \param listado[] eAbonado listado donde buscar entidad
 * \param tam int   tamanio de listado
 * \return void
 *
 */
void baja(eCliente listado[], int tam);
/** \brief Menu de modificacion de netidades
 *
 * \return void
 *
 */
void menuModificacion();
/** \brief Muestra una entidad ingresando el legajo
 *
 * \param listado[] eAbonado listado donde buscar
 * \param tam int   tamanio de entidad
 * \return int devuelve posicion donde se encuentra el legajo de la entidad o -1 si no la encuentra
 *
 */
int MostrarClientePorLegajo(eCliente listado[], int tam);

/** \brief Indica la cantidad de abonados en estado ocupado
 *
 * \param listadoAbonados[] eAbonado lista a verificar
 * \param tam int tamanio de listado
 * \return int cantidad de abonados activos
 *
 */
int cantidadDeClientesActivas(eCliente listado[],int tam);

int retornarMayor(int numeros[], int cant);



////////////////////////

void mostrarCantidadDeDueniosConMasDe50Anios(eCliente listado[],int tam);
void mostrarDueniosConMasDe50AniosAlfabeticamente(eCliente listado[],int tam);
void promedioDeDueniosMujeres(eCliente listado[],int tam);



void mostrarClienteConMayorEdad(eCliente listaCliente[], int tamCliente);

///***************************
///***************************
///***************************
///***************************
///***************************

//eCliente** cliente_crearLista();
//int initArray(eCliente** listaDeClientes, int valor);
//int imprimirClientes(eCliente** pListaCliente);
//eCliente* eCliente_new();
//eCliente* eCliente_newConParametros(eCliente* cliente);
int eCliente_inicializarPunteros(eCliente** listadoCliente, int len); //1
int eCliente_getEmplyIndex(eCliente** listadoCliente, int len);
void eCliente_show(eCliente* pCliente);
void eCliente_printList(eCliente** listadoCliente, int len);
eCliente* eCliente_new();
eCliente* eCliente_newParametros(char* nombre,char* apellido,char* telefono, char* localidad,int edad, char sexo);

int eCliente_deleteIndexInArray(eCliente** listadoCliente,int limite, int indice);

int eCliente_buscarPorIdArray(eCliente** listadoCliente,int limite,int id);


void Alta(eCliente* listado[], int tam);
int eCliente_borrarPorIdArray(eCliente** listadoCliente,int limite);


