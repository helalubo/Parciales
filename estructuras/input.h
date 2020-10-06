
/** \brief Obtiene un entero
 *
 * \param char[]  mensaje[] char mensaje a mostrar al pedir el entero
 * \return int numero pedido
 *
 */
int getInt(char mensaje[]);


/** \brief Verifica si es un flotante
 *
 * \param float number flotante a verificar
 * \return int 1 si es flotante 0 si no
 *
 */
int isFloat(float number);



/** \brief Obtener un flotante
 *
 * \param char mensaje[]  mensaje al pedir el flotante
 * \return float flotante obtenido
 *
 */
float getFloat(char mensaje[]);




/** \brief  obtiene un caracter
 *
 * \param char mensaje[] char mensaje al pedir el caracter
 * \return char caracter obtenido
 *
 */
char getChar(char mensaje[]);






/** \brief Obtiene un string
 *
 * \param char array donde sera copiado el string
 * \param char mensaje al pedir el string
 *
 *
 */
void getString(char cadena[], char mensaje[]);


/**
*\brief Verifica si un string es un numero o no
*\param char[] string a verificar
*\return devuelve 1 como true y 0 como false
*/
int isNumber(char numero[]);
