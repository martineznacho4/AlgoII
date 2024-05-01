#include "aeropuerto.h"
#include "ABB.h"
#include "Nodo.h"
#include "lista.h"
#include "nodo_lista.h"
#include <fstream>

class MENU{
    private:
        /*
        PRE: Recibe como parametro un puntero a una lista de punteros a string y un ABB por referencia. 
        POST: Genera el ABB, lo carga de los datos dados por el archivo .txt. Este archivo debe estar en su correcto formato dado por:
        codigo_IATA nombre ciudad pais superficie cantidad_terminales destinos_nacionales destinos_internacionales, en el que cada uno
        no puede contener espacios. Ej: si la ciudad es Buenos Aires, en el .txt debe ser Buenos-Aires. 
        */
        void generar_abb(Lista<Lista<string>*>* lista_codigo_ciudad, ABB<std::string> &abb);

        /*
        PRE: Recibe como parametro un puntero a una lista de punteros a string y un ABB por referencia. 
        Cuando el usuario ingrese el nombre de la ciudad lo debe ingresar poniéndo énfasis en la ortografía del mismo y teniendo en cuenta
        que no debe contener espacios. Ej: Si se consulta por la ciudad de Los Ángeles, debe ingresar: Los-Ángeles
        POST: Muestra por pantalla si el aeropuerto consultado se encuentra en el ABB o no, y da la opción de consultar sus datos.
        */
        void consulta_aeropuerto(Lista<Lista<string>*>* lista_codigo_ciudad, ABB<std::string> &abb);

        /*
        PRE: Recibe un ABB por referencia. El código IATA que debe ingresar el usuario para consultar debe ser correcto, todo en mayúscula. 
        POST: Agrega el aeropuerto al ABB y lo agrega al archivo .txt.
        */
        void alta_aeropuerto(Lista<Lista<string>*>* lista_codigo_ciudad, ABB<std::string> &abb);

        /*
        PRE: Recibe un ABB por referencia. El código IATA que debe ingresar el usuario para consultar debe ser correcto, todo en mayúscula.
        POST: Elimina el aeropuerto del ABB y a su vez agrega la lista de aeropuertos corregida al archivo .txt.
        */
        void baja_aeropuerto(Lista<Lista<string>*>* lista_codigo_ciudad, ABB<std::string> &abb);

        /*
        PRE: Recibe como parametro los datos de clave, nombre, ciudad y pais, los cuales son strings, el dato de superficie, que es double, 
        y los datos de cantidad de terminales, destinos nacionales y destinos internacionales que son de tipo int.
        POST: Corrije el archivo aeropuertos.txt según una alta de aeropuerto.
        */
        void corregir_archivo_alta(std::string clave, std::string nombre, std::string ciudad, std::string pais, double superficie, int cantidad_terminales, int destinos_nacionales, int destinos_internacionales);

        /*
        PRE: Recibe como parámetro un ABB de string por referencia y un string.
        POST: Corrije el archivo aeropuertos.txt según una baja de aeropuerto.
        */
        void corregir_archivo_baja(ABB<std::string> &abb, string iata);

        /*
        PRE: Recibe como parámetro un puntero a una lista de punteros a strings.
        POST: Corrije la lista pasada por parámetro según una baja de aeropuerto.
        */
        void corregir_lista_baja(Lista<Lista<string>*>* lista_codigo_ciudad);
    
    public:
        MENU();

        /*
        PRE: - 
        POST: Antes de su llamado se debe verificar que el archivo .txt se encuentre en el correcto formato. 
        Pide al usuario elegir entre las opciones disponibles y las ejecuta. 
        */
        void menu_abb();

        ~MENU();
};