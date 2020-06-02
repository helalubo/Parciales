

/**
* \brief Valida respuesta 's' o 'n' sin permitir *otros valores
* \param char[] Mensaje de lo que se desea dar *indicaciones de si o no
* \return int respuesta de tipo char *correspondiente a 's' o 'n'
*
*/
char verificarSN(char mensaje[]);

/**
* \brief Valida respuesta 'f'(femenino) o 'm'(masculino)  sin permitir *otros valores
* \param char[] Mensaje de lo que se desea dar *indicaciones de si o no
* \return int respuesta de tipo char *correspondiente a 's' o 'n'
*
*/
char verificarMF(char mensaje[]);



/**
*\brief Verifica si un string es un email o no
*\param char[] string a verificar
*\return int devuelve 1 como true y 0 como false
*/
int isEmail (char cadena[]);




/** \brief Verifica si un string solo contiene numeros
 *
 * \param cadena[] char cadena a verificar
 * \return int resultado 1 = true 0 = false
 *
 */
int onlyNumbers(char cadena[]);
/** \brief Verifica si un string solo contiene letras
 *
 * \param cadena[] char cadena a verificar
 * \return int resultado 1 = true 0 = false
 *
 */
int onlyLetters(char cadena[]);
/** \brief Verifica si un string solo contiene letras y numeros
 *
 * \param cadena[] char cadena a verificar
 * \return int resultado 1 = true 0 = false
 *
 */
int onlyAlphanumeric(char cadena[]);
/** \brief Verifica si un string es un telefono
 *
 * \param cadena[] char cadena a verificar
 * \return int resultado 1 = true 0 = false
 *
 */
int onlyPhoneNumbers(char cadena[]);

/** \brief Verifica si el tamanio de un array supera un determinado tamanio
 *
 * \param [] char cadena string a verificar
 * \param tam int tamanio determinado con el que juzgaremos a la cadena
 * \return int devuelve 1 si la cadena es menor y 0 si es mayor
 *
 */
int isStringWithDefinedSize(char cadena [],int tam);


/** \brief Verifica si el numero esta dentro del rango indicado
 *
 * \param number int Numero a verificar
 * \param maximo int Hasta que numero
 * \param minimo int Desde que numero
 * \return int  numero con el rango precisado.
 *
 */
int isNumberWithDefinedRange(int number, int maximo, int minimo);


////////////////////////////////////////////////////////

/** \brief Verifica si un string es un cuil
 *
 * \param cadena[] char cadena a verificar
 * \return int devuelve 1 si cumple la condicion 0 si no la cumple
 *
 */
int onlyCuil(char cadena[]);

/** \brief Verifica si un string es un nombre de archivo
 *
 * \param cadena[] char cadena a verificar
 * \return int devuelve 1 si cumple la condicion 0 si no la cumple
 *
 */
int isArchivo(char cadena[]);


/** \brief Verificar si un string es un DNI
 *
 * \param cadena[] char cadena a verificar
 * \return int int devuelve 1 si cumple la condicion 0 si no la cumple
 *
 */
int onlyDNI(char cadena[]);
