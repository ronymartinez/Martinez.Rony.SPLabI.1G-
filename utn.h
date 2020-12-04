#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED


/** \brief Verifica si es el dato ingresado es un numero
 *
 * \param Numero ingresado
 * \return 1 si es numerica, -1 si no lo es
 *
 */
int esNumerica(char* cadena);

/** \brief Verifica si el dato ingresado es alfanumerico
 *
 * \param Numero ingresado
 * \return 0 si es alfanumerico, 1 si no lo es
 *
 */
int esAlfaNumerica(char *str);

/** \brief Guarda un numero ingresado
 *
 * \param Variable en donde se va a guardar el dato
 * \param Mensaje para pedir dato
 * \param mensaje de error
 * \param Numero minimom aceptado
 * \param Numero maximo aceptado
 * \param Cantidad de intentos
 * \return 0 si pudo guardar el dato, 1 si no lo hizo
 *
 */
int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);

/** \brief Convierte un texto a numero
 *
 * \param Texto ingresado
 * \return 1 si se hizo la conversion, -1 si no se hizo
 *
 */
int getInt(int* pResultado);

/** \brief Verifica la cantidad de digitos ingresados
 *
 * \param String a verificar
 * \param Longitud permitida
 * \return 0 si es correcta la longitud, 1 si no lo es
 *
 */
int myGets(char* cadena, int longitud);

/** \brief Convierte un flotante a char
 *
 * \param Flotante a convertir
 * \return 0 si se hizo la conversion, 1 si no se hizo
 *
 */
int getFloat(float* pResultado);

/** \brief Guarda un flotante ingresado por el usuario
 *
 * \param Puntero donde se guardara el dato
 * \param Mensaje para pedir el dato
 * \param Mensaje de error
 * \param Flotante minimo permitido
 * \param Flotante maximo permitido
 * \param Cantidad de intentos
 * \return 0 si pudo guardar el dato, 1 si no guardo
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/** \brief Verifica si el numero ingresado es flotante
 *
 * \param Numero ingresado
 * \return 0 si es flotante, 1 si no lo es
 *
 */
int esFlotante(char* cadena);

/** \brief Convierte string en minuscula
 *
 * \param String a convertir
 * \return 0 si pudo convertur, 1 si no lo hizo
 *
 */
void strlwrLinux(char* cadena);

/** \brief Verifica la longitud de un string
 *
 * \param String a verificar
 * \param Longitud permitida
 * \return 0 si la longitud es correcta, 1 si no lo es
 *
 */
int getNombre(char* pResultado, int longitud);

/** \brief Verifica si el dato ingresa es un string
 *
 * \param String a verificar
 * \param Longitud permitida
 * \return 0 si es correcta, 1 si no lo es
 *
 */
int esNombre(char* cadena,int longitud);

/** \brief Guarda el nombre ingresado por el usuario
 *
 * \param Variable donde se guardara el dato ingresado por el usuario
 * \param Longitud permitida
 * \param Mensaje para pedir el dato
 * \param Mensaje de error
 * \param Cantida de intentos
 * \return 0 si se guardo, 1 si no guardo
 *
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

/** \brief Guarda un string ingresado
 *
 * \param Cadena a guardar
 * \param Longitud permitida
 * \return 0 si pudo guardar, 1 si no lo hizo
 *
 */
int getString(char* cadena, int longitud);

/** \brief Guarda un caracter ingresado por el usuario
 *
 * \param Variable que guardara el dato
 * \param Mensaje para pedir el dato
 * \param Mensjae de error
 * \param Caracter minimo
 * \param Caracter maximo
 * \param Cantidad de intentos
 * \return 0 si pudo guardar, 1 si no guarda
 *
 */
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos);


#endif // UTN_H_INCLUDED
