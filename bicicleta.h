#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int id_bike;
    char nombre[20];
    char tipo[20];
    int tiempo;

}eBicicleta;

#endif // BICICLETA_H_INCLUDED

/** \brief Reserva un espacio para una estructura bicicleta en la memoria dinamica
 *
 * \return eBicicleta* Retorna un puntero a la estructura bicicleta
 *
 */
eBicicleta* bici_new();

/** \brief Asigna los parametros de la estructura bicicleta
 *
 * \param id char* - ID de la estructura bicicleta
 * \param nombre char* - Nombre de la estructura bicicleta
 * \param tipo char* - Tipo de la estructura bicicleta
 * \param tiempo char* - Tiempo de la estructura bicicleta
 * \return eBicicleta* - Puntero a la estructura bicicleta
 *
 */
eBicicleta* bici_newParam(char* id, char* nombre, char* tipo, char* tiempo);

/** \brief Setea el Id
 *
 * \param bici eBicicleta* - Puntero a la estructura bicicleta
 * \param id int - Entero que se copiara en el ID de la estructura bicicleta
 * \return int - Retorna 0 si copio los datos correctamente o -1 si no lo hizo bien
 *
 */
int bici_setId(eBicicleta* bici, int id);

/** \brief Setea el nombre
 *
 * \param bici eBicicleta* - Puntero a la estructura bicicleta
 * \param char* nombre - String que se copiara en el nombre de la estructura bicicleta
 * \return int - Retorna 0 si copio los datos correctamente o -1 si no lo hizo bien
 *
 */
int bici_setNombre(eBicicleta* bici, char* nombre);

/** \brief Setea el tipo
 *
 * \param bici eBicicleta* - Puntero a la estructura bicicleta
 * \param tipo char* - String que se copiara en el tipo de la estructura bicicleta
 * \return int - Retorna 0 si copio los datos correctamente o -1 si no lo hizo bien
 *
 */
int bici_setTipo(eBicicleta* bici, char* tipo);

/** \brief Setea el tiempo
 *
 * \param bici eBicicleta* - Puntero a la estructura bicicleta
 * \param tiempo int - Entero que se copiara tiempo de la estructura bicicleta
 * \return int - Retorna 0 si copio los datos correctamente o -1 si no lo hizo bien
 *
 */
int bici_setTiempo(eBicicleta* bici, int tiempo);

/** \brief Asigna valores aleatorios al parametro tiempo de la estructura bicicleta
 *
 * \param bici void* - Puntero a una estructura bicicleta
 * \return void* - Puntero a una estructura bicicleta
 *
 */
void* asignarAleatorios(void* bici);

/** \brief Filtra y guarda os archivos por tipo
 *
 * \param lista LinkedList* - Puntero a una lista del Linkedlist
 * \return int - Retorna 0 si realizo el filtro correctamente o -1 si no lo hizo bien
 *
 */
int menuFiltrar(LinkedList* lista);

/** \brief Obtiene el id de la estructura bicicleta
 *
 * \param bici eBicicleta* - Puntero a la estructura bicicleta
 * \param id int* - Entero que recibira el ID de la estructura bicicleta
 * \return int - Retorna 0 si copio los datos correctamente o -1 si no lo hizo bien
 *
 */
int bici_getId(eBicicleta* bici, int* id);

/** \brief Obtiene el tipo de la estructura bicicleta
 *
 * \param bici eBicicleta* - Puntero a la estructura bicicleta
 * \param tipo char* - String que recibira el tipo de la estructura bicicleta
 * \return int - Retorna 0 si copio los datos correctamente o -1 si no lo hizo bien
 *
 */
int bici_getTipo(eBicicleta* bici, char* tipo);

/** \brief Obtiene el Tiempo de la estuctura bicicleta
 *
 * \param bici eBicicleta* - Puntero a la estructura bicicleta
 * \param tiempo int* - Entero que recibira el tiempo de al estructura bicicleta
 * \return int - Retorna 0 si copio los datos correctamente o -1 si no lo hizo bien
 *
 */
int bici_getTiempo(eBicicleta* bici, int* tiempo);

/** \brief Guarda y crea un archivo en modo texto
 *
 * \param path char* - Puntero al archivo
 * \param lista LinkedList* -  Puntero a una lista del Linkedlist
 * \return int - Retorna 0 si guardo la lista correctamente o -1 si no lo hizo bien
 *
 */
int guardarArchivo(char* path, LinkedList* lista);

