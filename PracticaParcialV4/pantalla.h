
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
    int idPantalla;
    char nombre[20];
    char direccion[20];
    float precioPublicidad;
    int estado;

} ePantalla;

/** \brief Hardcodea un listado definido
 *
 * \param listado[] eAbonado donde se carga el hardcodeo
 * \param tam int tamanio del array
 * \return void
 *
 */
void Hardcodeo(ePantalla listado[], int tam);
/** \brief Inicializa un array poniendolo como estado LIBRE 0
 *
 * \param listado[] eAbonado listado a inicializar
 * \param tam int tamanio
 * \return void
 *
 */
void inicializarEstado(ePantalla listado[], int tam);
/** \brief Busca indice libre
 *
 * \param listado[] eAbonado listado donde buscar
 * \param tam int tamanio de listado
 * \return int retorna el indice libre o -1 si todos los indices estan ocupados
 *
 */
int buscarIndiceLibre(ePantalla listado[], int tam);
/** \brief Da de alta una entidad
 *
 * \param listado[] eAbonado listado donde se agregara la entidad
 * \param tam int tamanio de listado
 * \return void
 *
 */
void Alta(ePantalla listado[], int tam);
/** \brief Muestra una entidad
 *
 * \param abonado eAbonado entidad a mostrar
 * \return void
 *
 */
void mostrarPantalla(ePantalla abonado);
/** \brief muestra toda la lista de abonados
 *
 * \param listado[] eAbonado lista a mostrar
 * \param tam int   tamanio de la lista
 * \return void
 *
 */
void mostrarListaDeApantallas(ePantalla listado[],int tam);
/** \brief Busca un legajo/ id
 *
 * \param listado[] eAbonado listado donde buscara
 * \param tam int tamanio de listado
 * \return int retorna posicion en el array donde se encuentra el id o -1 si no lo encuentra.
 *
 */
int buscarId(ePantalla listado[], int tam);
/** \brief Modifica la entidad
 *
 * \param listado[] eAbonado lista donde se encuentra la entidad a modificar
 * \param tam int tamanio de listado
 * \return void
 *
 */
void modificarPantalla(ePantalla listado[], int tam);
/** \brief Da de baja una entidad cambiando su estado de OCUPADO 1 a LIBRE 0
 *
 * \param listado[] eAbonado listado donde buscar entidad
 * \param tam int   tamanio de listado
 * \return void
 *
 */
void baja(ePantalla listado[], int tam);
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
int MostrarPantallaPorLegajo(ePantalla listado[], int tam);

/** \brief Indica la cantidad de abonados en estado ocupado
 *
 * \param listadoAbonados[] eAbonado lista a verificar
 * \param tam int tamanio de listado
 * \return int cantidad de abonados activos
 *
 */
int cantidadDePantallasActivas(ePantalla listadoPantallas[],int tam);

int retornarMayor(int numeros[], int cant);

