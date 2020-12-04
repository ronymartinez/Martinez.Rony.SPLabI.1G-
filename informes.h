#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED


/** \brief Menu principal
 *
 * \return int - Entero de la opcion elegida
 *
 */
int menu();

/** \brief - Muestra la lista cargada por pantalla
 *
 * \param lista LinkedList*
 * \return int - Retorna 0 si pudo hacer la impresion o -1 si no lo hizo
 *
 */
int listarBicicletas(LinkedList* lista);

/** \brief - Muentra una estructura bicicleta
 *
 * \param bici eBicicleta* - Puntero a una estructura bicicleta
 * \return int - Retorna 0 si pudo hacer la impresion o -1 si no lo hizo
 *
 */
int listarBici(eBicicleta* bici);

/** \brief Filtra una lista por el tipo BMX
 *
 * \param elemento void* - Puntero a la lista
 * \return int - Retorna 1 si pudo hacer el filtro o 0 si no lo hizo
 *
 */
int filtrarTipoBMX(void* elemento);

/** \brief Filtra una lista por el tipo Playera
 *
 * \param elemento void* - Puntero a la lista
 * \return int - Retorna 1 si pudo hacer el filtro o 0 si no lo hizo
 *
 */
int filtrarTipoPlayera(void* elemento);

/** \brief Filtra una lista por el tipo MTB
 *
 * \param elemento void* - Puntero a la lista
 * \return int - Retorna 1 si pudo hacer el filtro o 0 si no lo hizo
 *
 */
int filtrarTipoMTB(void* elemento);

/** \brief Filtra una lista por el tipo MTB
 *
 * \param elemento void* - Puntero a la lista
 * \return int - Retorna 1 si pudo hacer el filtro o 0 si no lo hizo
 *
 */
int filtrarTipoPaseo(void* elemento);

/** \brief Crea una lista completa ordenada
 *
 * \param elemento void*
 * \return int - Retorna 1 si pudo hacer el filtro o 0 si no lo hizo
 *
 */
int filtrarOrdenado(void* elemento);

/** \brief Muestra por pantalla una lista ordenada
 *
 * \param lista LinkedList* - Punero a la lista ordenada
 * \return int  - Retorna 1 si pudo hacer la impresion o 0 si no lo hizo
 *
 */
int listarOrdenado(LinkedList* lista);
