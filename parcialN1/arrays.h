
/** \brief Inicializar el array
 *
 * \param numeros[] int array a ser inicializado
 * \param cant int tamanio de array
 * \param valorDeInicio int valor con el cual inicializar
 * \return void
 *
 */
void inicializarArray(int numeros[], int cant, int valorDeInicio);
/** \brief
 *
 * \param numeros[] int array a mostrar
 * \param cant int tamanio del array
 * \return void
 *
 */
void mostrarArray(int numeros[], int cant);

/** \brief Muestra la cantidad cargada en el array
 *
 * \param estados[] int array a verificar
 * \param tam int tamanio del array
 * \param valorDeInicio int valor con el cual fue inicializado
 * \return int cantidad cargada
 *
 */
int CantidadCargadaArray(int estados[], int tam,int valorDeInicio);
/** \brief
 *
 * \param numeros[] int Muestra la cantidad no cargada en el array
 * \param cant int tamanio de array
 * \param valorDeInicio int valor con el cual fue inicializado
 * \return int cantidad no cargada del array
 *
 */
int CantidadNoCargadaArray(int numeros[], int cant,int valorDeInicio);
/** \brief Retornar mayor de un array
 *
 * \param numeros[] int array a verificar
 * \param cant int tamanio del array
 * \return int numero mayor
 *
 */
int retornarMayor(int numeros[], int cant);
/** \brief Retornar menor de un array
 *
 * \param numeros[] int array a verificar
 * \param cant int tamanio del array
 * \return int numero menor
 *
 */
int retornarMenor(int numeros[], int cant);
/** \brief Busca cual es el indice libre del array y devuelve posicion
 *
 * \param numeros[] int array a verificar
 * \param cant int tamanio
 * \return int indice libre
 *
 */
int indiceLibre(int numeros[],int cant);


/** \brief Obtener un suma de un array de int
 *
 * \param int[] array a utilizar
 * \param int[] estados del array (solo se sumaran los no vacios)
 * \param int tamanio del array
 * \param int valorDeInicio valor de array inicializado
 * \return int total de la suma de array
 *
 */
int sumarTotalEnArray(int array[],int estados[],int tam, int valorDeInicio);






/** \brief Saca el promedio del array
 *
 * \param estados[] estado del array
 * \param numeros[] int Array a verificar
 * \param cant int tamanio
 * \param valorDeInicio int valor de inicio del array
 * \return float
 *
 */
float promedioDeArray(int estados[], int array[],int tam, int valorDeInicio );



/** \brief configura el valor en un array segun indice
 *
 * \param posicion int indice a sobrescribir
 * \param array[] int array a utilizar
 * \param nuevoValor int nuevo valor para la posicion en el array
 * \return void
 *
 */
void modificarPorIndex(int posicion,int array[],int nuevoValor);



float retornarMayorFlotante(float numeros[], float cant);
float retornarMenorFlotante(float numeros[], float cant,int valorInicial);
