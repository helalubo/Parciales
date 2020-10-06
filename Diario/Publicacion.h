
#define OCUPADO 1
#define LIBRE 0

//tamanios

#define TMascotas 20
#define PAUSA 2

#include <string.h>
#include <limits.h>
#include "Cliente.h"





//) (nombre,tipo{gato,perro,raro},raza,edad,peso,sexo) (

typedef struct
{
    int idPublicacion;
    int idCliente;
    int numeroRubro;
    char textoDeAviso[365];
    int estado;

} ePublicacion;





/** \brief Retorna la cantidad de publicaciones Activas
 *
 * \param listado[] ePublicacion lista de publicaciones
 * \param tam int tamanio de lista
 * \return int cantidad de publicaciones activas estado != 0
 *
 */
int cantidadDePublicacionesActivas(ePublicacion listado[],int tam);
/** \brief Inicializa el estado de la publicacion
 *
 * \param listado[] ePublicacion listado de publicaciones
 * \param tam int tamanio publicaciones
 * \return void
 *
 */
void inicializarEstadoPublicacion(ePublicacion listado[], int tam);
/** \brief Retorna el primer indice libre que se encuenta en el listado de publicaciones
 *
 * \param listado[] ePublicacion listado de publicaciones
 * \param tam int tamanio de listado
 * \return int indice libre
 *
 */
int buscarIndiceLibrePublicacion(ePublicacion listado[], int tam);

/** \brief Da de alta una publicacion
 *
 * \param listado[] ePublicacion lista de publicaciones
 * \param tam int tamanio publicaciones
 * \param listadoClientes[] eCliente listado de clientes
 * \param tamClientes int tamanio listado de clientes
 * \return void
 *
 */
void AltaPublicacion(ePublicacion listado[], int tam, eCliente listadoClientes[],int tamClientes);

/** \brief Muesta una publicacion
 *
 * \param publicacion ePublicacion publicacion a mostrar
 * \return void
 *
 */
void  mostrarPublicacion(ePublicacion publicacion);

/** \brief Busca una publicacion por el ID
 *
 * \param listado[] ePublicacion lista de publicaciones
 * \param tam int tamanio de publicacion
 * \return int retorna indice donde esta el id
 *
 */
int buscarPorIdPublicacion(ePublicacion listado[], int tam);


/** \brief da de baja una publicacion
 *
 * \param listado[] ePublicacion lista de publicaciones
 * \param tam int tamanio publicaciones
 * \return void
 *
 */
void bajaPublicacion(ePublicacion listado[], int tam);

/** \brief Harcodear una publicacion
 *
 * \param listado[] ePublicacion  lista de publicaciones
 * \param tam int tamanio
 * \return void
 *
 */
void HardcodeoPublicacion(ePublicacion listado[], int tam);


/** \brief Muestra el menu de modificacion de una publicacion
 *
 * \return void
 *
 */
void menuModificacionPublicacion();
/** \brief muestra lista de publicacion con cuil de cliente
 *
 * \param listado[] ePublicacion lista de publicacion
 * \param tam int tamanio lista publicacion
 * \param listadoCliente[] eCliente lista cliente
 * \param tamClientes int tamanio lista cliente
 * \return void
 *
 */
void mostrarListaDePublicacion(ePublicacion listado[],int tam, eCliente listadoCliente[],int tamClientes);



////////////
/** \brief Modifica publicacion en su estado (PAUSADO OCUPADO)
 *
 * \param listado[] ePublicacion lista de publicacion
 * \param tam int tamanio lista publicacion
 * \param listadoCliente[] eCliente lista cliente
 * \param tamClientes int tamanio lista cliente
 * \return void
 *
 */
void modificarPublicacion(ePublicacion listado[], int tam, eCliente listadoClientes[], int tamCliente);
/** \brief Muestra clientes con sus publicaciones
 *
 * \param listado[] ePublicacion lista de publicacion
 * \param tam int tamanio lista publicacion
 * \param listadoCliente[] eCliente lista cliente
 * \param tamClientes int tamanio lista cliente
 * \return void
 *
 */
void mostrarClienteConPublicacion(ePublicacion listado[], int tam, eCliente listadoClientes[],int tamClientes);




/** \brief Da de baja a un cliente y todas las publicaciones hechas por el
 *
 * \param listado[] ePublicacion lista de publicacion
 * \param tam int tamanio lista publicacion
 * \param listadoCliente[] eCliente lista cliente
 * \param tamClientes int tamanio lista cliente
 * \return void
 *
 */
void bajaCliente(eCliente listado[], int tam,ePublicacion listadoPublicacion[], int tamPublicaciones);




/** \brief muestra las publicaciones con el cuil
 *
 * \param listado[] ePublicacion lista de publicacion
 * \param tam int tamanio lista publicacion
 * \param listadoCliente[] eCliente lista cliente
 * \param tamClientes int tamanio lista cliente
 * \return void
 *
 */
void mostrarPublicacionConCuil(ePublicacion listado[], int tam, eCliente listadoClientes[],int tamClientes);


/** \brief Informa sobre clientes maximo de avisos pausados, activos y totales
 *
 * \param listado[] ePublicacion lista de publicacion
 * \param tam int tamanio lista publicacion
 * \param listadoCliente[] eCliente lista cliente
 * \param tamClientes int tamanio lista cliente
 * \return void
 *
 */
void informacionesClientes(ePublicacion listado[], int tam, eCliente listadoClientes[],int tamClientes);



/** \brief Informa sobre publicaciones cual rubro tiene mas publicaciones, cual menos y cuanto tiene un rubro segun el que le pidamos saber por su ID
 *
 * \param listado[] ePublicacion lista de publicacion
 * \param tam int tamanio lista publicacion
 * \param listadoCliente[] eCliente lista cliente
 * \param tamClientes int tamanio lista cliente
 * \return void
 *
 */
void informacionesPublicaciones(ePublicacion listado[], int tam, eCliente listadoClientes[],int tamClientes);



































