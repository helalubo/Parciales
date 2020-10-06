
#define OCUPADO 1
#define LIBRE 0

//tamanios

#define TCAMIONES 25

#include <string.h>
#include <limits.h>
#include "Chofer.h"





//) (nombre,tipo{gato,perro,raro},raza,edad,peso,sexo) (

typedef struct
{
    int idCamion;
    int idChofer;
    char patente[21];
    int marca;
    int anio;
    float peso;
    int cantidadRuedas;
    int tipo;
    int estado;

} eCamion;






/** \brief inicializa el listado de camiones poniendolo en estado LIBRE 0
 *
 * \param listado[] eCamion listado de camiones
 * \param tam int tamanio de listado
 * \return void
 *
 */
void inicializarEstadoCamion(eCamion listado[], int tam);
/** \brief busca el primer indice libre en el array de camiones
 *
 * \param listado[] eCamion listado de camiones
 * \param tam int tamanio de listado de array de camiones
 * \return int primer indice libre
 *
 */
int buscarIndiceLibreCamion(eCamion listado[], int tam);


/** \brief Muestra un camion
 *
 * \param camion eCamion camion a mostrar
 * \return void
 *
 */
void  mostrarCamion(eCamion camion);

/** \brief Busca un camion por id
 *
 * \param listado[] eCamion listado de camiones
 * \param tam int tamanio de listado de camiones
 * \return int indice donde se encuetra el camion
 *
 */
int buscarPorIdCamion(eCamion listado[], int tam);





/** \brief Harcodea el array de camiones
 *
 * \param listado[] eCamion listado de camiones
 * \param tam int tamanio de listado
 * \return void
 *
 */
void HardcodeoCamiones(eCamion listado[], int tam);



/** \brief Muestra listado de camiones con sus conductores
 *
 * \param listado[] eCamion listado de camiones
 * \param tam int tamanio listado de camiones
 * \param listadoChoferes[] eChofer listado de choferes
 * \param tamChoferes int tamanio listado de choferes
 * \return void
 *
 */
void mostrarChoferConCamiones(eCamion listado[], int tam, eChofer listadoChoferes[],int tamChoferes);



/** \brief muestra lista de camiones con el nombre del chofer
 *
 * \param listado[] eCamion listado de camiones
 * \param tam int tamanio listado de camiones
 * \param listadoChoferes[] eChofer listado de choferes
 * \param tamChoferes int tamanio listado de choferest
 * \return void
 *
 */
void mostrarListaDeCamionesConChofer(eCamion listado[],int tam, eChofer listadoChofer[],int tamChofer);



/** \brief Aniade un camion al listado de camiones
 *
 * \param listado[] eCamion listado de camiones
 * \param tam int tamanio listado de camiones
 * \param listadoChoferes[] eChofer listado de choferes
 * \param tamChoferes int tamanio listado de choferes
 * \return void
 *
 */
void AltaCamion(eCamion listado[], int tam, eChofer listadoChoferes[],int tamChoferes);



/** \brief modifica un camion
 *
 * \param listado[] eCamion listado de camiones
 * \param tam int tamanio listado de camiones
 * \param listadoChoferes[] eChofer listado de choferes
 * \param tamChoferes int tamanio listado de choferes
 * \return void
 *
 */
void modificarCamion(eCamion listado[], int tam,eChofer listadoChoferes[],int tamChoferes);



/** \brief Da de baja un chofer y todos los camiones que maneja
 *
 * \param listado[] eCamion listado de camiones
 * \param tam int tamanio listado de camiones
 * \param listadoChoferes[] eChofer listado de choferes
 * \param tamChoferes int tamanio listado de choferes
 * \return void
 *
 */
void bajaChofer(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones);






/** \brief Muestra los choferes ordenados por tipo
 *
 * \param listado[] eChofer listado choferes
 * \param tam int    tamanio listado
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void mostrarChoferesPorTipo(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones);


/** \brief Da de baja a un camion
 *
 * \param listado[] eCamion listado camiones
 * \param tam int tamanio listado camioens
 * \return void
 *
 */
void bajaCamion(eCamion listado[], int tam);



/** \brief eChofer muestra choferes con mas de un camion
 *
 * \param listado[] eChofer listado choferes
 * \param tam int    tamanio listado
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void mostrarChoferesConMasDeUnCamion(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones);



/** \brief muestra camiones con mas de 10 anios de antiguedad
 *
 * \param listado[] eChofer listado choferes
 * \param tam int    tamanio listado
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void mostrarCaminionesConMasDe10Anios(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones);





/** \brief Muestra camiones por marca
 *
 * \param list[] eCamion lista de camiones
 * \param tam int tamanio de listado
 * \return void
 *
 */
void mostrarCamionesPorMarca(eCamion list[], int tam);


/** \brief Ordena choferes por cantidad de camiones
 *
 * \param listado[] eChofer listado choferes
 * \param tam int    tamanio listado
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void odenarChoferesPorCantidadDeCamiones(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones);





void odenarChoferesPorCantidadDeCamionesYAlfabeticamente(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones);


void promedioDeAniosDeAntiguedadDeCamiones(eCamion listadoCamiones[], int tamCamiones);



