
#define OCUPADO 1
#define LIBRE 0

//tamanios

#define TCAMIONES 25

#include <string.h>
#include <limits.h>
#include "Chofer.h"
#include "marca.h"





//ahora(Ford de eeuu, FIAT italia,VW alemania)
//) (nombre,tipo{gato,perro,raro},raza,edad,peso,sexo) (

typedef struct
{
    int idCamion;
    int idChofer;
    char patente[21];
    int idMarca;
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





/** \brief Ordena choferes por cantidad de camiones y alfabeticamente
 *
 * \param listado[] eChofer listado choferes
 * \param tam int    tamanio listado
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void odenarChoferesPorCantidadDeCamionesYAlfabeticamente(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones);


/** \brief Promedio de anios de antiguedad de camiones
 *
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void promedioDeAniosDeAntiguedadDeCamiones(eCamion listadoCamiones[], int tamCamiones);

////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/** \brief Muestra los camiones al seleccionar una marca
 *
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void MostrarCamionesDelMarcaSeleccionada(eCamion listadoCamiones[], int tamCamiones, eChofer listado[], int TamChofer);
//

/** \brief Muestra los camiones con mas antiguedad
 *
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void mostrarCamionesMasViejos(eCamion listadoCamiones[], int tamCamiones);

/** \brief Muestra lista de camiones separados por marca
 *
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void MostrarCamionesSeparadasPorMarca(eCamion listadoCamiones[], int tamCamiones);


/** \brief Muesta la cantidad de un tipo y de una marca que ingresemos al mismo
 *
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void mostrarCantidadDeUnTipoYUnaMarcaAlMismoTiempo(eCamion listadoCamiones[], int tamCamiones);

/** \brief Muestra la marca que fue mas elegida por los choferes
 *
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void mostrarMarcaMasElegidaPorLosChoferes(eCamion listadoCamiones[], int tamCamiones);

/** \brief Muestra anios de antiguedad acumulados entra todos los camiones
 *
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return int
 *
 */
int mostrarAniosDeAntiguedadAcumuladoDeTodosLosCamiones(eCamion listadoCamiones[], int tamCamiones);

/** \brief Muestra los camiones por mayor cantidad de ruedas y nombre del duenio
 *
 * \param listado[] eChofer listado choferes
 * \param tam int    tamanio listado
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void mostrarCamionesConMayorCantidadDeRuedasYNombreDeDuenio(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones);

/** \brief Muestra el camion con peso menor y cual es su duenio
 *
 * \param listado[] eChofer listado choferes
 * \param tam int    tamanio listado
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void mostrarCamionConPesoMenorYDuenio(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones);

/** \brief Camiones de duenios mujeres ordenados de acuerdo a su peso.
 *
 * \param listado[] eChofer listado choferes
 * \param tam int    tamanio listado
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void camionesDeDuenosMujeresOrdenadosPorPeso(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones);

/** \brief muestra los camiones que superen el peso ingresado por el usuario y que tengan mas de 15 anios //se puede cambiar para que tambien pida el anio.
 *
 * \param listado[] eChofer listado choferes
 * \param tam int    tamanio listado
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void MostrarCamionesQueSuperenElPesoYtenganAntiguedadMayorA15anios(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones);


/** \brief Muestra el camion con mas peso y que sea de la marca que se indica.
 *
 * \param listado[] eChofer listado choferes
 * \param tam int    tamanio listado
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void MostrarCamionConMayorPesoDependiendoLaMarca(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones);

/** \brief Lista el promedio de la cantidad de llantas tiene cada uno en su flota
 *
 * \param listado[] eChofer listado choferes
 * \param tam int    tamanio listado
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void promedioDellantasQueUsaCadaChoferEnSuFlota(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones);

/** \brief Muestra el chofer con mayor cantidad de ruedas en su flota
 *
 * \param listado[] eChofer listado choferes
 * \param tam int    tamanio listado
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void choferConMayorCantidadDeRuedasEnSuFlota(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones);

/** \brief muestra el mayor de larga distancia con mayor peso entre esta categoria
 *
 * \param listado[] eChofer listado choferes
 * \param tam int    tamanio listado
 * \param listadoCamiones[] eCamion listado camiones
 * \param tamCamiones int tamanio listado camiones
 * \return void
 *
 */
void mostrarCamionLargaDistanciaConMayorPeso(eChofer listado[], int tam,eCamion listadoCamiones[], int tamCamiones);
