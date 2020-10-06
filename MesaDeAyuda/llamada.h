
typedef struct
{

    int idLlamada;
    int idAbonado;
    int motivo;
    int estado;
    int demora;



} eLlamada;
#include "abonado.h"

#define TLLAMADAS 100
#define FALLA3G 1
#define FALLALTE 2
#define FALLAEQUIPO 3
//estados
#define LIBRE 0
#define ENCURSO 1
#define SOLUCIONADO 2
#define NOSOLUCIONADO 3

#include "input.h"
#include "validate.h"
#include "numbers.h"









/** \brief Ingresar una nueva llamada
 *
 * \param listado[] eLlamada lista de llamadas
 * \param tamLlamadas int  tamanio llamadas
 * \param listadoAbonados[] eAbonado listado abonados
 * \param tam int tam abonados
 * \return void
 *
 */
void NuevaLlamada(eLlamada listado[],int tamLlamadas,eAbonado listadoAbonados[],int tam);

/** \brief Inicializa todas las llamadas poniendolas en estado LIBRE 0
 *
 * \param listado[] eLlamada lista de llamadas
 * \param tam int tamanio de lista e llamadas
 * \return void
 *
 */
void inicializarEstadoLlamada(eLlamada listado[], int tam);

/** \brief finaliza una llamada permitiendole cargar el estado
 *
 * \param listado[] eLlamada listado de llamadas
 * \param tamLlamadas int tamanio de lista de llamadas
 * \param listadoAbonados[] eAbonado listado de abonados
 * \param tam int tamanio de listado de abonados
 * \return void
 *
 */
void finLlamada(eLlamada listado[],int tamLlamadas,eAbonado listadoAbonados[],int tam);
/** \brief Menu mostrando diferentes motivos de la llamada
 *
 * \return void
 *
 */
void menuMotivo();
/** \brief harcodeo
 *
 * \param listado[] eLlamada lista de llamadas
 * \param tam int tamanio de lista
 * \return void
 *
 */
void HardcodeoLlamadas(eLlamada listado[], int tam);
/** \brief verifica y retorna la cantidad de llamadas que se an generado verificando que el estado sea diferente a LIBRE 0
 * \param listadoLlamadas[] eLlamada lista de llamadas
 * \param tamLlamadas int tamanio de lista
 * \return int cantidad de reclamos gestionados
 *
 */
int cantidadDeReclamosGestionados(eLlamada listadoLlamadas[], int tamLlamadas);

/** \brief Nos muestra datos(nombre,apellido) del abonado que tiene MAS reclamos,
 *
 * \param listado[] eLlamada listado de llamadas
 * \param tamLlamadas int  tamanio de listado de llamas
 * \param listadoAbonados[] eAbonado listado de abonados
 * \param tam int tamanio de listado de abonados
 * \return void
 *
 */
void nombreYApellidoDelAbonadoConMasReclamos(eLlamada listado[],int tamLlamadas,eAbonado listadoAbonados[],int tam);
/** \brief  muestra cual fue el reclamo mas realizado
 *
 * \param listado[] eLlamada listado de llamadas
 * \param tamLlamadas int tamanio de listado
 * \return void
 *
 */
void reclamoMasRealizado(eLlamada listado[],int tamLlamadas);
/** \brief reclamo con el promedio de demora mas alto
 *
 * \param listado[] eLlamada listado de llamada
 * \param tamLlamadas int tamanio de llamada
 * \return void
 *
 */
void reclamoMasDemoroEnPromedio(eLlamada listado[],int tamLlamadas);

int retornarMayor(int numeros[], int cant);

//hacer promedio

