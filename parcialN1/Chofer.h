
#include "input.h"
#include "validate.h"

#define OCUPADO 1
#define LIBRE 0

//tamanios

#define T 12

#include <string.h>
#include <limits.h>
#include "arrays.h"






typedef struct
{
    int idChofer;
    char nombre[51];
    char apellido[51];
    char dni[51];
    char legajo[51];
    char nacionalidad[20];
    char telefono[20];
    int edad;
    char sexo;
    int estado;

} eChofer;
//nombre, apellido,localidad,teléfono,edad,sexo)

/** \brief Hardcodea un listado definido
 *
 * \param listado[] eAbonado donde se carga el hardcodeo
 * \param tam int tamanio del array
 * \return void
 *
 */
void Hardcodeo(eChofer listado[], int tam);
/** \brief Inicializa un array poniendolo como estado LIBRE 0
 *
 * \param listado[] eAbonado listado a inicializar
 * \param tam int tamanio
 * \return void
 *
 */
void inicializarEstado(eChofer listado[], int tam);
/** \brief Busca indice libre
 *
 * \param listado[] eAbonado listado donde buscar
 * \param tam int tamanio de listado
 * \return int retorna el indice libre o -1 si todos los indices estan ocupados
 *
 */
int buscarIndiceLibre(eChofer listado[], int tam);

/** \brief Muestra una entidad
 *
 * \param abonado eAbonado entidad a mostrar
 * \return void
 *
 */
void mostrarChofer(eChofer abonado);

/** \brief Busca un legajo/ id
 *
 * \param listado[] eAbonado listado donde buscara
 * \param tam int tamanio de listado
 * \return int retorna posicion en el array donde se encuentra el id o -1 si no lo encuentra.
 *
 */
int buscarId(eChofer listado[], int tam);



/** \brief Muestra una entidad ingresando el legajo
 *
 * \param listado[] eAbonado listado donde buscar
 * \param tam int   tamanio de entidad
 * \return int devuelve posicion donde se encuentra el legajo de la entidad o -1 si no la encuentra
 *
 */
int MostrarChoferPorLegajo(eChofer listado[], int tam);



//int retornarMayor(int numeros[], int cant);

/** \brief Muestra lista de cliente con choferes
 *
 * \param listado[] eChofer listado de choferes
 * \param tam int tamanio de listado
 * \return void
 *
 */
void mostrarListaDeChoferes(eChofer listado[],int tam);

/** \brief Alta de un chofer
 *
 * \param listado[] eChofer listado de choferes
 * \param tam int tamanio de listado
 * \return void
 *
 */
void Alta(eChofer listado[], int tam);

/** \brief modifica chofer
 *
 * \param listado[] eChofer listado de choferes
 * \param tam int tamanio de listado
 * \return void
 *
 */
void modificarChofer(eChofer listado[], int tam);

/** \brief muestra el promedio de la edad entre los  choferes
 *
 * \param listado[] eChofer lista de choferes
 * \param tam int tamanio de listado de choferes
 * \return void
 *
 */
void promedioDeEdadChoferes(eChofer listado[], int tam);


/** \brief promedio que hay entre masculinos y femeninos en el total del listado de choferes
 *
 * \param listado[] eChofer listado de choferes
 * \param tam int   tamanio
 * \return void
 *
 */
void promedioDeMoFentreChoferes(eChofer listado[], int tam);



